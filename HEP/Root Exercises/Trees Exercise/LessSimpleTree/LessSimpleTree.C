#include<TFile.h>
#include<TTree.h>
#include<TRandom.h>

int main(){
	//create file and empty tree, variables declaration
	TFile f("LessSimpleTree.root","RECREATE");
	TTree data("tree","Example TTree");
	float x[100];
	int n;
	//define branches
	data.Branch("n", &n, "n/I");
	data.Branch("myFloats", x, "x[n]/F");
	//populate branches
	for(int i=0;i<100;i++){		//loop over events
		n = (int)(gRandom->Uniform(50));
		for(int j=0; j<n;j++){		//loop over particles per event
			x[j] = gRandom->Gaus(0,5);
		}
	data.Fill();
	}
	data.Write();
	f.Close();
}
