#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <string>
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
	float m();
	float pT();
	//sum of four-vectors
	FourVec operator + (FourVec const &obj);
	//product by a scalar
	FourVec operator * (float const &obj);
};

#endif
