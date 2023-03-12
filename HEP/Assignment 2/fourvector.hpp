 #ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <string>
#include <iostream>
#include <cmath>
#include <typeinfo>

template <class T>
class FourVec
{
private:
	T components_[4];
public:
	//constructor
	FourVec(T px=0, T py=0, T pz =0, T E=0)
	{
		T p[4] = {px,py,pz,E};
		for(int i=0;i<4;i++)
		{
			components_[i] = p[i];
		}
	}
	
	//setter
	void setFourMomentum(T p, int i)
	{
		if(i<0 or i>3)
			throw std::invalid_argument("Please insert an interger from 0 to 3");
		else
		components_[i] = p;
	}
	
	//define accessor
	T operator [](int i) const
	{
		if(i<0 or i>3)
			throw std::invalid_argument("Index out of bound");
		
		return components_[i];
	}

	//print full vector
	void print() const
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
	
	//evaluate different things
	T m() const
	{
		T res = pow(components_[3],2);
		for(int i=2; i>=0; i--)
		{
			res -= pow(components_[i],2);
		}
		
		if(res < 0)
			throw std::invalid_argument("The square of the invariant mass is negative. Unless we discovered imaginary masses, the data inserted is wrong.");
		
		res = sqrt(res);
		return res;
	}
	
	T pT() const
	{
		T res=0;
		for(int i=0;i<2;i++)
		{
			res += pow(components_[i],2);
		}
		res = sqrt(res);
		return res;
	}
	//sum of four-vectors
	template<class T2>
	FourVec<T> operator + (FourVec<T2> const &obj) const
	{
		FourVec<T> res;
		for(int i=0;i<4;i++)
		{
			res.setFourMomentum(components_[i] + T(obj[i]),i);
		}
		return res;
	}

	//parity operator
	FourVec operator - () const
	{
		FourVec<T> res;
		for(int i=0;i<3;i++)
		{
			res.setFourMomentum(-components_[i],i);
		}
		res.setFourMomentum(components_[3],3);
		return res;
	}
};

#endif
