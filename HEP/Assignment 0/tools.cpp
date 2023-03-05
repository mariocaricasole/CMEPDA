#include <iostream>
#include "tools.hpp"
#include <cmath>

//function definition
void printHello(){
	std::cout << "Hello World!" << std::endl;
}

float customSqrt(float a){
	float b = sqrt(a);
	std::cout<< "I performed the square root of " << a << " with result "<< b << std::endl;
	return b;
}
