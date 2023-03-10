#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <string>
#include <iostream>
#include <cmath>
#include <typeinfo>
class FourVec
{
private:
	float components_[4];
public:
	//four vector constructor
	FourVec(float px=0, float py=0, float pz=0, float E=0);
	//setter
	void setFourMomentum(float p, int i); //single number set
	//accessor
	float operator [](int i) const;
	//print full vector
	void print() const;
	//evaluate different things
	float m() const;
	float pT() const;
	//sum of four-vectors
	FourVec operator + (FourVec const &obj) const;
	//product by a scalar
	FourVec operator * (float const &obj) const;
	// opposite operator
	FourVec operator - () const;
	
};

#endif
