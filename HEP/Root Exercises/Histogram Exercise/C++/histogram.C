void histogram(){
	TH1D* hist = new TH1D("h","Histogram", 64, 0, 16);
	hist->FillRandom("pol1");
	gStyle->SetHistLineWidth(2);
	hist->Draw();
}
