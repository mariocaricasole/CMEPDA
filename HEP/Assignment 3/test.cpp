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
	std::cout << "Test successful!\n" << std::endl;
	return 0;
}

int testPhoneBook(PhoneBook book, Person person)
{
	std::cout<< "Testing phonebook...\n";
	std::cout << "Adding Mario...\n";
	book.addEntry(person);
	std::cout<< "Adding Luigi...\n";
	book.addEntry("Luigi Caricasole","+393453567890","luigicarica@gmail.com");
	std::cout << "\nPrinting whole book\n";
	book.print();
	std::cout << "\nSearching for Mario \n";
	Person res = book.search(person.name()).second;
	res.print();
	std::cout << "\nSearching for Carlo \n";
	res = book.search("Carlo Caricasole").second;
	res.print();
	
	std::cout << "\nSorting book \n";
	book.sort();
	book.print();
	
	std::cout << "\nAdding +39 prefix \n";
	book.addAllItalianPrefix();
	book.print();
	std::cout << "Test successful" << std::endl;
	return 0;
}


int main()
{
	Person mario("Mario Caricasole", "3665803754","mariocarica@gmail.com");
	int res = testPerson(mario);
	//test phonebook
	PhoneBook book;
	res += testPhoneBook(book,mario);
	return res;
}
