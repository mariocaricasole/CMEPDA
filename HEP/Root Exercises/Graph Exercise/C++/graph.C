void graph(){
	int n = 3;
	double x[3] = {1,2,3};
	double y[3] = {0,3,4};
	TGraph* gr = new TGraph(n,x,y);
	gr->GetXaxis()->SetTitle("myX");
	gr->GetYaxis()->SetTitle("myY");
	gr->SetTitle("My graph");
	gr->SetMarkerStyle(kFullSquare);
	gr->SetMarkerColor(kRed);
	gr->SetLineColor(kOrange);
	gr->Draw();
}
