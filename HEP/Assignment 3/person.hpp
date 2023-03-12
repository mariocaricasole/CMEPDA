#ifndef PERSON_HPP
#define PERSON_HPP

#include<iostream>
class Person 
{
private:
	std::string m_name;
	std::string m_number;
	std::string m_email;
public:
	//constructor
	Person(std::string name, std::string number, std::string email) : m_name(name), m_number(number), m_email(email) {};
	//getters
	std::string name() const {return m_name;};
	std::string number() const {return m_number;};
	std::string email() const {return m_email;};
	//setters
	void setName(std::string name) {m_name = name;};
	void setNumber(std::string number) {m_number = number;};
	void setEmail(std::string email) {m_email = email;};
	//print info
	void print() const
	{
		std::cout << name() << "\t" << number() << "\t" << email() << "\n";
	}
};

#endif
