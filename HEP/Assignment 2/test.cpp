#include "fourvector.hpp"

template<class T>
int testFourVecFunctions()
{
	FourVec<T> p(1.2,3.4,4.5,511);
	std::cout << typeid(p[0]).name() << std::endl;
	p.print();
	float m = p.m();
	float pT = p.pT();
	std::cout << "Invariant mass is: " << m << std::endl;
	std::cout << "Transverse momentum is: " << pT << std::endl;
	return 0;
}

int main(){
	int test1 = testFourVecFunctions<float>();
	int test2 = testFourVecFunctions<double>();
}
