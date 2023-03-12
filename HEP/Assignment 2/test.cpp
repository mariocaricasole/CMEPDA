#include "fourvector.hpp"

template<class T>
int testFourVecFunctions()
{
	std::cout << "Starting 4-vector template test..." << std::endl;
	FourVec<T> p(1.2,3.4,4.5,511);
	std::cout << typeid(p[0]).name() << std::endl;
	p.print();
	float m = p.m();
	float pT = p.pT();
	std::cout << "Invariant mass is: " << m << std::endl;
	std::cout << "Transverse momentum is: " << pT << std::endl;
	std::cout << "Test successful!\n" << std::endl;
	return 0;
}

template<class T>
int testFourVecFunctions(T p)
{
	std::cout << "Starting 4-vector template test..." << std::endl;
	std::cout << typeid(p[0]).name() << std::endl;
	p.print();
	float m = p.m();
	float pT = p.pT();
	std::cout << "Invariant mass is: " << m << std::endl;
	std::cout << "Transverse momentum is: " << pT << std::endl;
	std::cout << "Test successful!\n" << std::endl;
	return 0;
}

int testSum()
{
	std::cout << "Starting sum test..." << std::endl;
	FourVec<float> p(12.12, 34.1,54.4121, 511.12);
	FourVec<double> q(45.123,100.1412,87.5355, 1000.3141);
	
	FourVec<float> res = p+q;
	res.print();
	std::cout << typeid(res[0]).name() << std::endl;
	std::cout << "Test successful!\n" << std::endl;
	return 0;
}

int testParity()
{
	std::cout << "Starting sum test..." << std::endl;
	FourVec<float> p(12.12, 34.1,54.4121, 511.12);
	FourVec<float> q = -p;
	
	testFourVecFunctions(p);
	testFourVecFunctions(q);
	
	std::cout<< "Test successful!\n" << std::endl;
	return 0;
}

int main(){
	int test1 = testFourVecFunctions<float>();
	int test2 = testFourVecFunctions<double>();
	int test3 = testSum();
	int test4 = testParity();
	return 0;
}
