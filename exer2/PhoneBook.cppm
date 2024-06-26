export module phone_book;

import person;
import <utility>;
import <map>;
import <string>;
import <string_view>;
import <vector>;

export class PhoneBook
{
public:
	void addPhoneNumber(const Person& person, std::string_view phoneNumber);
	void removePhoneNumber(const Person& person, std::string_view phoneNumber);
	std::vector<std::string> getPhoneNumbers(const Person& person) const;

private:
	std::multimap<Person, std::string> m_phoneBook;
};
