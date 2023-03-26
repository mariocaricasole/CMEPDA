#include<iostream>
#include<TMath.h>

void macro1(){
	std::cout << "3+3 = " << 3+3 << std::endl;
	std::cout << "Gaus(2) = " << TMath::Gaus(2) << std::endl;
}

int main(){
	macro1();
	return 0;
}
