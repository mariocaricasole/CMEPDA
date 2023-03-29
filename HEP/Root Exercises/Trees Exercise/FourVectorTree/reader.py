import ROOT

ROOT.gSystem.Load("AutoDict_std__vector_FourVec__cxx.so")
ROOT.gSystem.Load("AutoDict_FourVec_cxx.so")
ROOT.gSystem.Load("libFourVector.so")
f = ROOT.TFile.Open("FourVectorTree.root")
t = f.tree

for evt in t:
	#print(evt.particles.size())
	for p in evt.particles:
		try:
			print(p.m())
		except:
			print("NaN")
