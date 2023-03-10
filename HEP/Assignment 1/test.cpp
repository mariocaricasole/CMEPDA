#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "particle.hpp"
#include "fourvector.hpp"
#include "twobodies.hpp"

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
		m = p.m();
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
		t = p.pT();
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

//unit test for evaluating multiplication by scalar
int testScalarMul(FourVec p, float r)
{
	FourVec q = p*r;
	q.print();
	return 0;
}

//unit test for derived Particle class
int testParticleClass(Particle e)
{
	e.print();
	std::cout << e[0] << std::endl;
	std::cout << e.m() << std::endl;
	std::cout << e.charge() << std::endl;
	std::cout << e.tau() << std::endl;
	std::cout << e.id() << std::endl;
	std::cout << e.pT() << std::endl;
	return 0;
}

//unit test for derived TwoBodies class
int testTwoBodiesClass(TwoBodies f)
{
	int i = testParticleClass(f);
	f.printAll();
	return i;
}

//testing
int main(){
	float component, m, t;
	FourVec p(1.1,2.3,4.2,10.2);
// 	p[0] = 1.2;
// 	p.print();
// 	FourVec q;
	Particle e("electron",p,-1.0);
	Particle f("positron", -p, +1.0);
	TwoBodies photon(e,f,"photon", -1);
// 	component = testComponentAccess(p);
// 	m = testInvariantMass(p);
// 	t = testTransverseMomentum(p);
//	testSumFourVectors(p,p);
//	testScalarMul(p,4);
// 	testParticleClass(e);
	testTwoBodiesClass(photon);
	return 0;
}
