#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>
#include "sRel.hpp"

//defining the constructor of the class
FourVec::FourVec(float px, float py, float pz, float E)
{
	float p[4] = {E,px,py,pz};
	setFourMomentum(p);
}

//define setter
void FourVec::setFourMomentum(float p[4])
{
	for(int i=0;i<4;i++)
	{
		components_[i] = p[i];
	}
}

void FourVec::setFourMomentum(float p, int i)
{
	if(i<0 or i>3)
		throw std::invalid_argument("Please insert an interger from 0 to 3");
	else
		components_[i] = p;
}

//define accessor
float FourVec::operator [](int i) const
{
	if(i<0 or i>3)
		throw std::invalid_argument("Index out of bound");
	
	return components_[i];
}

//define print
void FourVec::print() const
{
	std::cout << "[";
	for(int i=0;i<4;i++)
	{
		std::cout << components_[i];
		if(i<3)
			std::cout<< ", ";
	}
	std::cout << "]" << std::endl;
}

//define invariantMass
float FourVec::invariantMass()
{
	float res = pow(components_[0],2);
	for(int i=1; i<4; i++)
	{
		res -= pow(components_[i],2);
	}
	
	if(res < 0)
		throw std::invalid_argument("The square of the invariant mass is negative. Unless we discovered imaginary masses, the data inserted is wrong.");
	
	res = sqrt(res);
	return res;
}

//define transverseMomentum
float FourVec::transverseMomentum()
{
	float res=0;
	for(int i=1;i<3;i++)
	{
		res += pow(components_[i],2);
	}
	res = sqrt(res);
	return res;
}

// define sum between four vectors
FourVec FourVec::operator + (FourVec const &obj)
{
	FourVec res;
	float temp;
	for(int i=0;i<4;i++)
	{
		temp = components_[i] + obj[i];
		res.setFourMomentum(temp, i);
	}
	return res;
}

//define multiplication by scalar
FourVec FourVec::operator * (float const &obj)
{
	FourVec res;
	float temp;
	for(int i=0; i<4; i++)
	{
		temp = components_[i]*obj;
		res.setFourMomentum(temp,i);
	}
	return res;
}

///// PARTICLE CLASS /////

//defining constructor
Particle::Particle(std::string id, float px, float py, float pz, float E, float charge, float decayTime) : FourVec(px,py,pz,E)
{
	id_ = id;
	mass_ = invariantMass();
	charge_ = charge;
	decayTime_ = decayTime;
}

std::string Particle::id()
{
	return id_;
}

//accessor for mass attribute
float Particle::mass()
{
	return mass_;
}

//accessor for charge attribute
float Particle::charge()
{
	return charge_;
}

//accessor template for decay decayTime
float Particle::decayTime()
{
	return decayTime_;
}
