#include "twobodies.hpp"

//define print function
void TwoBodies::printAll() const
{
	std::cout << "First particle has 4-momentum: ";
	m_p1.print();
	std::cout << "Second particle has 4-momentum: ";
	m_p2.print();
	std::cout << "Parent particle had 4-momentum: ";
	print();
	std::cout << "with invariant mass: " << m() << std::endl;
}
