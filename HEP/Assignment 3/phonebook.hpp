#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "person.hpp"
#include<vector>
#include<utility>
class PhoneBook
{
private:
	std::vector<Person> m_entries;
public:
	//constructor
	PhoneBook(){};
	//add entry
	void addEntry(std::string name, std::string number, std::string email){m_entries.push_back(Person(name,number,email));};
	void addEntry(Person person){m_entries.push_back(person);};
	//print whole phonebook
	void print()
	{
		std::cout << "Name\t\t\t" << "Number\t\t" << "Email\n";
		for(std::vector<Person>::iterator it = m_entries.begin(); it != m_entries.end();it++)
		{
			it->print();
		};
	};
	//search entry
	std::pair<bool,Person> search(std::string name)
	{
		std::pair<bool,Person> res;
		for(std::vector<Person>::iterator it = m_entries.begin(); it != m_entries.end(); it++)
		{
			if(it->name() == name)
			{
				std::cout << "Contact found!\n";
				res = std::make_pair(true, *it);
			}
			else
			{
				std::cout << name << " not found!\n";
				res = std::make_pair(false,Person());
			}
		}
		return res;
	}
};	

#endif
