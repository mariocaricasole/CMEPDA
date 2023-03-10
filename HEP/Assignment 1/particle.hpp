#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include "fourvector.hpp"
class Particle : public FourVec
{
private:
	std::string id_;
	float charge_;
	float tau_;
public:
	//constructor
	Particle(std::string id, const FourVec& p, float charge, float tau = -1);
	//accessor
	std::string id() const;
	float charge() const;
	float tau() const;
};

#endif
