#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "sRel.hpp"

//unit test for accessing components of the four vector
int testComponentAccess(FourVec p)
{
	int choice;
	std::cout << "What component do you want to check?" << std::endl;
	std::cin >> choice;
	try
	{
		float res = p[choice];
		std::cout << std::endl << "Showing the " << choice << "th component: " << res << std::endl;
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}

//unit test for evaluating the invariant mass of the four vector
int testInvariantMass(FourVec p)
{
	float m;
	try
	{
		m = p.invariantMass();
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return -2;
	}
	return 0;
}

//unit test for evaluating transerse momentum
int testTransverseMomentum(FourVec p)
{
	float t;
	try
	{
		t = p.transverseMomentum();
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return -2;
	}
	return 0;
}

//unit test for evaluating sum of four vectors
int testSumFourVectors(FourVec p, FourVec q)
{
	FourVec r = p + q;
	r.print();
	return 0;
}

//testing
int main(){
	float component, m, t;
	FourVec p(1.1,2.3,4.2,10.2);
	FourVec q;
// 	component = testComponentAccess(p);
// 	m = testInvariantMass(p);
// 	t = testTransverseMomentum(p);
	testSumFourVectors(p,p);
	return 0;
}
