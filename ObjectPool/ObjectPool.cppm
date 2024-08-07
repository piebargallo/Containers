module;

#include <cstddef>
#include <cassert>

export module ObjectPool;

import <memory>;
import <vector>;
import <numeric>;
import <iostream>;

/* Prpvides and object pool that can be used with any class that provides a default constructor.
   acquireObject() returns an object from the list of free objects. If there are no more free objects,
   acquireObject() creates a new chunk of objects. The pool only grows: objects are never removed from 
   the pool, until the pool is destroyed. accquireObject() returns an std::shared_ptr with a custom
   deleter that automatically puts the object back into the oject pool when the shared_ptr is destroyed
   and its reference count reaches 0. */

export 
template <typename T, typename Allocator = std::allocator<T>>
class ObjectPool
{
public:
	ObjectPool() = default;
	explicit ObjectPool(const Allocator& allocator);
	virtual ~ObjectPool();

	// Allow move constructor and move assignment.
	ObjectPool(ObjectPool&& src) noexcept = default;
	ObjectPool& operator=(ObjectPool&& rhs) noexcept = default;

	// Prevent copy constructor and copy assignment.
	ObjectPool(const ObjectPool& src) = delete;
	ObjectPool& operator=(const ObjectPool& rhs) = delete;

	// Reserves and returns an object from the pool. Arguments can be 
	// provided wich are perfectly forwarded to a constructor of T.
	template<typename...Args>
	std::shared_ptr<T> accquireObject(Args...args);

private:
	// Contains chunks of memory in which instances of T will be created.
	// For each chunk, the pointer to its first object is stored.
	std::vector<T*> m_pool;

	// Contains pointers to all free instancies of T that
	// are available in the pool.
	std::vector<T*> m_freeObjects;

	// The number of T instances that should fit in the first allocated chunk.
	static const size_t ms_initialChunkSize { 5 };

	// The number of the instancies that should fit in a newly allocated chunk.
	// This value is doubled after each newly created chunk.
	size_t m_newChunkSize { ms_initialChunkSize };

	// Creates a new block of uninitialized memory, big enough to hold
	// m_newChunkSize instances of T.
	void addChunk();

	// The allocator to use for allocating and deallocating chunks.
	Allocator m_allocator;
};

template <typename T, typename Allocator>
ObjectPool <T, Allocator>::ObjectPool(const Allocator& allocator)
	: m_allocator{ allocator } {}

template <typename T, typename Allocator>
void ObjectPool<T, Allocator>::addChunk()
{
	std::cout << "Allocating new chunk..." << std::endl;

	// Allocate a new chunk of uninitialized memory big enough to hold
	// m_newChunkSize instances of T, and add the chunk to the pool.
	auto* firstNewObject{ m_allocator.allocate(m_newChunkSize) };
	m_pool.push_back(firstNewObject);

	// Create pointers to each individual object in the new chunk
	// and store them in the list og free objects
	auto oldFreeObjectsSize{ m_freeObjects.size() };
	m_freeObjects.resize(oldFreeObjectsSize + m_newChunkSize);
	std::iota(begin(m_freeObjects) + oldFreeObjectsSize, end(m_freeObjects),
		firstNewObject);

	// Double the chunk size for next time
	m_newChunkSize *= 2;
}

template <typename T, typename Allocator>
template <typename...Args>
std::shared_ptr<T> ObjectPool<T, Allocator>::accquireObject(Args...args)
{
	// If there are no free objects, allocate a new chunk.
	if (m_freeObjects.empty()) { addChunk(); }

	// Get a free object.
	T* object{ m_freeObjects.back() };

	// Initialize, i.e. construct, an instance of T in an
	// uninitialized block of memory using placement new, and
	// perfectly forward any provided arguments to the constructor.
	new (object) T{ std::forward<Args>(args)... };

	// Remove the object from the list of free objects.
	m_freeObjects.pop_back();

	// Wrap the initialized object and return it.
	return std::shared_ptr<T> { object, [this](T* object) {
		// Destroy object.
		std::destroy_at(object);
		// Put the object back in the list of free objects.
		m_freeObjects.push_back(object);
	}};
}

template <typename T, typename Allocator>
ObjectPool<T, Allocator>::~ObjectPool()
{
	// Note: this implementation assumes that all objects handed out of this
	// pool have been returned to the pool before the pool is destroyed.
	// The following statement asserts if that is not the case.
	assert(m_freeObjects.size() ==
		ms_initialChunkSize * (std::pow(2, m_pool.size()) - 1));

	// Dellocate all allocated memory
	size_t chunkSize{ ms_initialChunkSize };
	for (auto* chunk : m_pool) {
		m_allocator.deallocate(chunk, chunkSize);
		chunkSize *= 2;
	}
	m_pool.clear();
}
