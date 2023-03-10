#include "particle.hpp"
#include "fourvector.hpp"

//defining constructor
Particle::Particle(std::string id, float px, float py, float pz, float E, float charge, float tau) : FourVec(px,py,pz,E)
{
	id_ = id;
	charge_ = charge;
	tau_ = tau;
}

//accessors
std::string Particle::id() {return id_;}
float Particle::charge(){return charge_;}
float Particle::tau(){return tau_;}
