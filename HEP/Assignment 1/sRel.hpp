#ifndef SREL_HPP
#define SREL_HPP
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
	//evaluate different things
	float invariantMass();
	float transverseMomentum();
	//sum of four-vectors
	FourVec operator + (FourVec const &obj);
};
#endif
