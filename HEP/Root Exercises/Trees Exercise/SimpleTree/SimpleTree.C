#include<TFile.h>
#include<TTree.h>
#include<TRandom.h>

int main(){
	//create file and empty tree, variables declaration
	TFile f("SimpleTree.root","RECREATE");
	TTree data("tree","Example TTree");
	double x,y,z,t;
	//define branches
	data.Branch("x", &x, "x/D");
	data.Branch("y", &x, "y/D");
	data.Branch("z", &x, "z/D");
	data.Branch("t", &x, "t/D");
	//populate branches
	for(int i=0;i<128;i++){
		x = gRandom->Uniform(-10,10);
		y = gRandom->Gaus(0,5);
		z = gRandom->Exp(10);
		t = gRandom->Landau(0,2);
		data.Fill();
	}
	data.Write();
	f.Close();
}
