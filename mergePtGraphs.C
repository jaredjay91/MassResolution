
void removeXerrors(TGraphAsymmErrors* graph) {

  cout << "removing X errors..." << endl;
  int numPoints = graph->GetN();
  for (int i=0; i<numPoints; i++) {
    graph->SetPointEXhigh(i,0);
    graph->SetPointEXlow(i,0);
  }

}

void mergePtGraphs() {

  gStyle->SetErrorX(0);//This doesn't do anything.

  cout << "Loading graphs from RD files..." << endl;
  TFile* fZPbPbRD = TFile::Open("ptMassResZPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hmass");
  TFile* fZpPbRD = TFile::Open("ptMassResZpPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hmass");
  TFile* fZppRD = TFile::Open("ptMassResZppRD.root","READ");
  TGraphAsymmErrors* gsigmaZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hmass");
  TFile* fJpsiPbPbRD = TFile::Open("ptMassResJpsiPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hmass");
  TFile* fJpsipPbRD = TFile::Open("ptMassResJpsipPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hmass");
  TFile* fJpsippRD = TFile::Open("ptMassResJpsippRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hmass");

  cout << "Loading graphs from MC files..." << endl;
  TFile* fZPbPbMC = TFile::Open("ptMassResZPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hmass");
  TFile* fZpPbMC = TFile::Open("ptMassResZpPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hmass");
  TFile* fZppMC = TFile::Open("ptMassResZppMC.root","READ");
  TGraphAsymmErrors* gsigmaZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hmass");
  TFile* fJpsiPbPbMC = TFile::Open("ptMassResJpsiPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hmass");
  TFile* fJpsipPbMC = TFile::Open("ptMassResJpsipPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hmass");
  //TFile* fJpsippMC = TFile::Open("ptMassResJpsippMC.root","READ");
  //TGraphAsymmErrors* gsigmaJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hsigmaC");
  //TGraphAsymmErrors* gmassJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hmass");


  //Remove X error bars:
  /*removeXerrors(gsigmaZPbPbRD);
  removeXerrors(gsigmaZpPbRD);
  removeXerrors(gsigmaZppRD);
  removeXerrors(gsigmaJpsiPbPbRD);
  removeXerrors(gsigmaJpsipPbRD);
  removeXerrors(gsigmaJpsippRD);

  removeXerrors(gmassZPbPbRD);
  removeXerrors(gmassZpPbRD);
  removeXerrors(gmassZppRD);
  removeXerrors(gmassJpsiPbPbRD);
  removeXerrors(gmassJpsipPbRD);
  removeXerrors(gmassJpsippRD);

  removeXerrors(gsigmaZPbPbMC);
  removeXerrors(gsigmaZpPbMC);
  removeXerrors(gsigmaZppMC);
  removeXerrors(gsigmaJpsiPbPbMC);
  removeXerrors(gsigmaJpsipPbMC);
  //removeXerrors(gsigmaJpsippMC);

  removeXerrors(gmassZPbPbMC);
  removeXerrors(gmassZpPbMC);
  removeXerrors(gmassZppMC);
  removeXerrors(gmassJpsiPbPbMC);
  removeXerrors(gmassJpsipPbMC);
  //removeXerrors(gmassJpsippMC);*/

  cout << "Finished removing X errors." << endl;

  //Set up the output file.
  TString outFileName = "ptMassResCombined.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");


  //********* PbPb Jpsi ***********//
  TCanvas* c1PbPb = new TCanvas("c1PbPb","c1PbPb",0,0,400,400);
  c1PbPb->cd();
  gsigmaJpsiPbPbRD->SetMinimum(0);
  gsigmaJpsiPbPbRD->SetMaximum(0.04);
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitle("p_{T} (2.1<|#eta|<2.4)");
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsiPbPbRD->SetMarkerStyle(20);
  gsigmaJpsiPbPbRD->SetMarkerColor(kRed);
  gsigmaJpsiPbPbRD->SetLineColor(kRed);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsiPbPbMC->SetMarkerStyle(24);
  gsigmaJpsiPbPbMC->SetMarkerColor(kRed);
  gsigmaJpsiPbPbMC->SetLineColor(kRed);
  gsigmaJpsiPbPbMC->Draw("same P");

  c1PbPb->SaveAs("ptMassResJpsiPbPb.pdf");
  c1PbPb->SaveAs("ptMassResJpsiPbPb.png");


  //********* PbPb Z ***********//
  TCanvas* c2PbPb = new TCanvas("c2PbPb","c2PbPb",0,0,400,400);
  c2PbPb->cd();
  gsigmaZPbPbRD->SetMinimum(0);
  gsigmaZPbPbRD->SetMaximum(0.04);
  gsigmaZPbPbRD->GetXaxis()->SetTitle("p_{T}");
  gsigmaZPbPbRD->Draw("AP");
  gsigmaZPbPbRD->SetMarkerStyle(20);
  gsigmaZPbPbRD->SetMarkerColor(kRed);
  gsigmaZPbPbRD->SetLineColor(kRed);
  gsigmaZPbPbRD->Draw("AP");
  gsigmaZPbPbMC->SetMarkerStyle(24);
  gsigmaZPbPbMC->SetMarkerColor(kRed);
  gsigmaZPbPbMC->SetLineColor(kRed);
  gsigmaZPbPbMC->Draw("same P");

  c2PbPb->SaveAs("ptMassResZPbPb.pdf");
  c2PbPb->SaveAs("ptMassResZPbPb.png");


  //********* pPb Jpsi ***********//
  TCanvas* c1pPb = new TCanvas("c1pPb","c1pPb",0,0,400,400);
  c1pPb->cd();
  gsigmaJpsipPbRD->SetMinimum(0);
  gsigmaJpsipPbRD->SetMaximum(0.04);
  gsigmaJpsipPbRD->GetXaxis()->SetTitle("p_{T} (2.1<|#eta|<2.4)");
  gsigmaJpsipPbRD->Draw("AP");
  gsigmaJpsipPbRD->SetMarkerStyle(21);
  gsigmaJpsipPbRD->SetMarkerColor(kBlue);
  gsigmaJpsipPbRD->SetLineColor(kBlue);
  gsigmaJpsipPbRD->Draw("AP");
  gsigmaJpsipPbMC->SetMarkerStyle(25);
  gsigmaJpsipPbMC->SetMarkerColor(kBlue);
  gsigmaJpsipPbMC->SetLineColor(kBlue);
  gsigmaJpsipPbMC->Draw("same P");

  c1pPb->SaveAs("ptMassResJpsipPb.pdf");
  c1pPb->SaveAs("ptMassResJpsipPb.png");


  //********* pPb Z ***********//
  TCanvas* c2pPb = new TCanvas("c2pPb","c2pPb",0,0,400,400);
  c2pPb->cd();
  gsigmaZpPbRD->SetMinimum(0);
  gsigmaZpPbRD->SetMaximum(0.04);
  gsigmaZpPbRD->GetXaxis()->SetTitle("p_{T}");
  gsigmaZpPbRD->Draw("AP");
  gsigmaZpPbRD->SetMarkerStyle(21);
  gsigmaZpPbRD->SetMarkerColor(kBlue);
  gsigmaZpPbRD->SetLineColor(kBlue);
  gsigmaZpPbRD->Draw("AP");
  gsigmaZpPbMC->SetMarkerStyle(25);
  gsigmaZpPbMC->SetMarkerColor(kBlue);
  gsigmaZpPbMC->SetLineColor(kBlue);
  gsigmaZpPbMC->Draw("same P");

  c2pPb->SaveAs("ptMassResZpPb.pdf");
  c2pPb->SaveAs("ptMassResZpPb.png");

  //********* pp Jpsi ***********//
  TCanvas* c1pp = new TCanvas("c1pp","c1pp",0,0,400,400);
  c1pp->cd();
  gsigmaJpsippRD->SetMinimum(0);
  gsigmaJpsippRD->SetMaximum(0.04);
  gsigmaJpsippRD->GetXaxis()->SetTitle("p_{T} (2.1<|#eta|<2.4)");
  gsigmaJpsippRD->Draw("AP");
  gsigmaJpsippRD->SetMarkerStyle(33);
  gsigmaJpsippRD->SetMarkerColor(kBlack);
  gsigmaJpsippRD->SetLineColor(kBlack);
  gsigmaJpsippRD->Draw("AP");
  //gsigmaJpsippMC->SetMarkerStyle(27);
  //gsigmaJpsippMC->SetMarkerColor(kBlack);
  //gsigmaJpsippMC->SetLineColor(kBlack);
  //gsigmaJpsippMC->Draw("same P");

  c1pp->SaveAs("ptMassResJpsipp.pdf");
  c1pp->SaveAs("ptMassResJpsipp.png");


  //********* pp Z ***********//
  TCanvas* c2pp = new TCanvas("c2pp","c2pp",0,0,400,400);
  c2pp->cd();
  gsigmaZppRD->SetMinimum(0);
  gsigmaZppRD->SetMaximum(0.04);
  gsigmaZppRD->GetXaxis()->SetTitle("p_{T}");
  gsigmaZppRD->Draw("AP");
  gsigmaZppRD->SetMarkerStyle(33);
  gsigmaZppRD->SetMarkerColor(kBlack);
  gsigmaZppRD->SetLineColor(kBlack);
  gsigmaZppRD->Draw("AP");
  gsigmaZppMC->SetMarkerStyle(27);
  gsigmaZppMC->SetMarkerColor(kBlack);
  gsigmaZppMC->SetLineColor(kBlack);
  gsigmaZppMC->Draw("same P");

  c2pp->SaveAs("ptMassResZpp.pdf");
  c2pp->SaveAs("ptMassResZpp.png");

  //Write everything to the output file
  cout << "Writing to File " << outFileName << endl;
  outFile->cd();
  c1PbPb->Write();
  c2PbPb->Write();
  c1pPb->Write();
  c2pPb->Write();
  c1pp->Write();
  c2pp->Write();
  outFile->Close();


  cout << "Here's what's left in memory:" << endl;
  gDirectory->ls("-m");

}
