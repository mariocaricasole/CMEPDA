#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "person.hpp"
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<string>
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
	//accessor to entry
	Person operator[](int i) {return m_entries[i];}
	//print whole phonebook
	void print()
	{
		std::cout << "Name\t\t\t" << "Number\t\t" << "Email\n";
		for(std::vector<Person>::iterator it = m_entries.begin(); it != m_entries.end();it++)
		{
			it->print();
		}
	};
	
	//search entry
	std::pair<bool,Person> search(std::string name)
	{
		bool found = false;
		std::pair<bool,Person> res;
		for(std::vector<Person>::iterator it = m_entries.begin(); it != m_entries.end(); it++)
		{
			if(it->name() == name)
			{
				std::cout << "Contact found!\n";
				found = true;
				res = std::make_pair(found, *it);
				break;
			}
		}
		
		if(!found)
		{
			std::cout << name << " not found!\n";
			res = std::make_pair(found,Person());
		}
		
		return res;
	}
	
	//define comparison class
	class CompareNames{
	public:
		bool operator()(const Person& a, const Person& b){return a.name() < b.name();};
	};
	
	//sort algorithm
	void sort()
	{
		std::sort(m_entries.begin(), m_entries.end(),CompareNames());
	}
	
	//transform routine
	static Person addItalianPrefix(const Person& e)
	{
		Person en = e;
		if(en.number().length() == 0) return en;
		if(en.number().find("+") == std::string::npos)
		{
			en.setNumber("+39" + en.number());
		}
		return en;
	}
	
	void addAllItalianPrefix()
	{
		std::transform(m_entries.begin(), m_entries.end(), m_entries.begin(), addItalianPrefix);
	}
};	

#endif
