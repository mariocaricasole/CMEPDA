#ifndef SREL_HPP
#define SREL_HPP
#include <string>
class FourVec
{
private:
	float components_[4];
public:
	//four vector constructor
	FourVec(float px=0, float py=0, float pz=0, float E=0);
	//setter
	void setFourMomentum(float p[4]);
	void setFourMomentum(float p, int i); //single number set
	//accessor
	float operator [](int i) const;
	//print full vector
	void print() const;
	//evaluate different things
	float invariantMass();
	float transverseMomentum();
	//sum of four-vectors
	FourVec operator + (FourVec const &obj);
	//product by a scalar
	FourVec operator * (float const &obj);
};


class Particle : public FourVec
{
private:
	std::string id_;
	float mass_;
	float charge_;
	float decayTime_;
public:
	//constructor
	Particle(std::string id, float px, float py, float pz, float E, float charge, float decaytime = -1);
	//accessor
	std::string id();
	float mass();
	float charge();
	float decayTime();
};

#endif
