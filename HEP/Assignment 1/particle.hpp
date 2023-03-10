#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <string>
#include "fourvector.hpp"
class Particle : public FourVec
{
private:
	std::string id_;
	float mass_;
	float charge_;
	float tau_;
public:
	//constructor
	Particle(std::string id, float px, float py, float pz, float E, float charge, float tau = -1);
	//accessor
	std::string id();
	float charge();
	float tau();
};

#endif
