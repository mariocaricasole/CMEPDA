#ifndef TWOBODIES_HPP
#define TWOBODIES_HPP
#include "particle.hpp"
class TwoBodies : public Particle
{
private:
	Particle m_p1;
	Particle m_p2;
public:
	//constructor
	TwoBodies(const Particle& p1, const Particle& p2, std::string id, float tau=-1) : Particle(id, p1+p2, p1.charge() + p2.charge(), tau), m_p1(p1), m_p2(p2) {};
	//print
	void printAll() const;
};

#endif
