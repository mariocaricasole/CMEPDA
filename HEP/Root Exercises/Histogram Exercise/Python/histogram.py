import ROOT

h = ROOT.TH1D("h","Histogram",64,0,16)
h.FillRandom("pol1")
h.SetLineWidth(2)
h.Draw()