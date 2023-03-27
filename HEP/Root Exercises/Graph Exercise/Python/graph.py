from ROOT import TGraph, kFullSquare, kRed, kOrange
import numpy as np

x = np.array([1,2,3],dtype=np.double)
y = np.array([0,3,4],dtype=np.double)

gr = TGraph(3,x,y)
gr.SetTitle("My graph")
gr.GetXaxis().SetTitle("myX")
gr.GetYaxis().SetTitle("myY")
gr.SetMarkerStyle(kFullSquare)
gr.SetMarkerColor(kRed)
gr.SetLineColor(kOrange)
gr.Draw()
