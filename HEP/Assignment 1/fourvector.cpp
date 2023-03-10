#include "fourvector.hpp"

//defining the constructor of the class
FourVec::FourVec(float px, float py, float pz, float E)
{
	float p[4] = {px,py,pz,E};
	for(int i=0;i<4;i++)
	{
		components_[i] = p[i];
	}
}

//define setter
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
float FourVec::m() const
{
	float res = pow(components_[3],2);
	for(int i=2; i>=0; i--)
	{
		res -= pow(components_[i],2);
	}
	
	if(res < 0)
		throw std::invalid_argument("The square of the invariant mass is negative. Unless we discovered imaginary masses, the data inserted is wrong.");
	
	res = sqrt(res);
	return res;
}

//define transverseMomentum
float FourVec::pT() const
{
	float res=0;
	for(int i=0;i<2;i++)
	{
		res += pow(components_[i],2);
	}
	res = sqrt(res);
	return res;
}

// define sum between four vectors
FourVec FourVec::operator + (FourVec const &obj) const
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
FourVec FourVec::operator * (float const &obj) const
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

//define opposite operator
FourVec FourVec::operator - () const
{
	FourVec res;
	res.setFourMomentum(components_[3], 3);
		for(int i=0; i<3; i++)
	{
		res.setFourMomentum(-components_[i],i);
	}
	return res;
}
