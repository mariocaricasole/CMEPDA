#include<TFile.h>
#include<TTree.h>
#include<TRandom.h>
#include<TSystem.h>
#include<vector>
#include "fourvector.h"

int main(){
	//create file and empty tree, variables declaration
	TFile f("FourVectorTree.root","RECREATE");
	TTree data("tree","Example TTree");
	//declare variables
	int n;
	std::vector<FourVec> particles;
	//generate dictionary to classes
	gInterpreter->GenerateDictionary("FourVec", "fourvector.h");
	gInterpreter->GenerateDictionary("std::vector<FourVec>","fourvector.h");
	//define branches
	data.Branch("particles", &particles,32000,0);
	//populate branches
	for(int i=0;i<100;i++){		//loop over events
		n = (int)(gRandom->Uniform(50));
		particles.clear();
		particles.resize(n);
		for(int j=0; j<n;j++){		//loop over particles per event
			 particles[j] =FourVec((float)gRandom->Gaus(0,5),(float)gRandom->Exp(20), (float)gRandom->Gaus(2,3), (float)gRandom->Uniform(50,100));
		}
		data.Fill();
	}
	data.Write();
	f.Close();
}
