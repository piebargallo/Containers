/* Take your implementation of the Person class from exercise 15-4. Add a new module called phone_book, defining
   a PhoneBook class that stores one or more phone numbers as strings for a person. Provide methods to add remove
   person´s phone numbers to/from a phonebook. Also provide a method that returns a vector with all phone numbers
   for a given person. Test your implementation in your main() function. In your tests, use the user-defined person
   literal developed in exercise 15-4. */

import person;
import phone_book;
#include <iostream>
#include <format>
using std::cout;
using std::endl;
using std::format;

int main()
{
	PhoneBook phoneBook;
	phoneBook.addPhoneNumber("John Doe"_p, "123-456-789");
	phoneBook.addPhoneNumber("Jane Doe"_p, "789-456-123");
	phoneBook.addPhoneNumber("John Doe"_p, "999-456-789");
	phoneBook.addPhoneNumber("Marc Gregoire"_p, "258-369-147");
	phoneBook.removePhoneNumber("Marc Gregoire"_p, "258-369-147");
	phoneBook.removePhoneNumber("Marc G"_p, "258-369-147");

	cout << "John Doe's phone numbers:" << endl;
	for (const auto& number : phoneBook.getPhoneNumbers("John Doe"_p)) {
		cout << "\t" << number << endl;
	}
}


