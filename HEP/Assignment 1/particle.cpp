#include "particle.hpp"

//defining constructor
Particle::Particle(std::string id, const FourVec& p, float charge, float tau) : FourVec(p)
{
	id_ = id;
	charge_ = charge;
	tau_ = tau;
}

//accessors
std::string Particle::id() const {return id_;}
float Particle::charge() const {return charge_;}
float Particle::tau() const {return tau_;}
