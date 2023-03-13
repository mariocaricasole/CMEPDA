#include "phonebook.hpp"

int testPerson(Person person)
{
	std::cout << "Testing Person class...\n";
	std::cout << "Accessing data members individually...\n";
	std::cout << person.name() << std::endl;
	std::cout << person.number() << std::endl;
	std::cout << person.email() << std::endl;
	std::cout << "Setting different name...\n";
	person.setName("Luigi");
	std::cout << "New name is: " << person.name() <<std::endl;
	person.print();
	std::cout << "Test successful!";
	return 0;
}

int testPhoneBook(PhoneBook book, Person person)
{
	book.addEntry(person);
	book.print();
	return 0;
}


int main()
{
	Person mario("Mario", "3665803754","mariocarica@gmail.com");
	int res = testPerson(mario);
	//test phonebook
	PhoneBook book;
	res += testPhoneBook(book,mario);
	return res;
}
