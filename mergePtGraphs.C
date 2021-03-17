
void removeXerrors(TGraphAsymmErrors* graph) {

  cout << "removing X errors..." << endl;
  int numPoints = graph->GetN();
  for (int i=0; i<numPoints; i++) {
    graph->SetPointEXhigh(i,0);
    graph->SetPointEXlow(i,0);
  }

}

void mergePtGraphs(bool zoom=kTRUE) {
  TString zoomString = "";
  if (zoom) zoomString = "_zoom";

  gStyle->SetErrorX(0);//This doesn't do anything.

  cout << "Loading graphs from RD files..." << endl;
  TFile* fZPbPbRD = TFile::Open("Results/ptMassResZPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hmass");
  TFile* fZpPbRD = TFile::Open("Results/ptMassResZpPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hmass");
  TFile* fZppRD = TFile::Open("Results/ptMassResZppRD.root","READ");
  TGraphAsymmErrors* gsigmaZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hmass");
  TFile* fJpsiPbPbRD = TFile::Open("Results/ptMassResJpsiPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hmass");
  TFile* fJpsipPbRD = TFile::Open("Results/ptMassResJpsipPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hmass");
  TFile* fJpsippRD = TFile::Open("Results/ptMassResJpsippRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hmass");
  TFile* fJpsippRD_midrap = TFile::Open("Results/ptMassResJpsippRD_midrap.root","READ");
  TGraphAsymmErrors* gsigmaJpsippRD_midrap = (TGraphAsymmErrors*)fJpsippRD_midrap->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippRD_midrap = (TGraphAsymmErrors*)fJpsippRD_midrap->Get("Graph_from_hmass");

  cout << "Loading graphs from MC files..." << endl;
  TFile* fZPbPbMC = TFile::Open("Results/ptMassResZPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hmass");
  TFile* fZpPbMC = TFile::Open("Results/ptMassResZpPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hmass");
  TFile* fZppMC = TFile::Open("Results/ptMassResZppMC.root","READ");
  TGraphAsymmErrors* gsigmaZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hmass");
  TFile* fJpsiPbPbMC = TFile::Open("Results/ptMassResJpsiPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hmass");
  TFile* fJpsipPbMC = TFile::Open("Results/ptMassResJpsipPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hmass");
  TFile* fJpsippMC = TFile::Open("Results/ptMassResJpsippMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hmass");
  TFile* fJpsippMC_midrap = TFile::Open("Results/ptMassResJpsippMC_midrap.root","READ");
  TGraphAsymmErrors* gsigmaJpsippMC_midrap = (TGraphAsymmErrors*)fJpsippMC_midrap->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippMC_midrap = (TGraphAsymmErrors*)fJpsippMC_midrap->Get("Graph_from_hmass");


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
  TString outFileName = "FinalPlots/ptMassResCombined.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

//******** MASS RESOLUTION ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c1PbPb = new TCanvas("c1PbPb","c1PbPb",0,0,400,400);
  c1PbPb->cd();
  gsigmaJpsiPbPbRD->SetTitle("Mass Res. at J/#psi peak (PbPb 5.02 TeV)");
  gsigmaJpsiPbPbRD->SetMinimum(0);
  gsigmaJpsiPbPbRD->SetMaximum(0.035);
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu} (2.1<|#eta|<2.4)");
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG}) at J/#psi peak");
  if (zoom) gsigmaJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsiPbPbRD->SetMarkerStyle(20);
  gsigmaJpsiPbPbRD->SetMarkerColor(kRed);
  gsigmaJpsiPbPbRD->SetLineColor(kRed);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsiPbPbMC->SetMarkerStyle(24);
  gsigmaJpsiPbPbMC->SetMarkerColor(kRed);
  gsigmaJpsiPbPbMC->SetLineColor(kRed);
  gsigmaJpsiPbPbMC->Draw("same P");

  c1PbPb->SetLeftMargin(0.15);
  c1PbPb->SetRightMargin(0.05);
  c1PbPb->SaveAs(Form("FinalPlots/ptMassResJpsiPbPb%s.pdf",zoomString.Data()));
  c1PbPb->SaveAs(Form("FinalPlots/ptMassResJpsiPbPb%s.png",zoomString.Data()));


  //********* PbPb Z ***********//
  TCanvas* c2PbPb = new TCanvas("c2PbPb","c2PbPb",0,0,400,400);
  c2PbPb->cd();
  gsigmaZPbPbRD->SetMinimum(0);
  gsigmaZPbPbRD->SetMaximum(0.035);
  gsigmaZPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gsigmaZPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{CB}/m_{PDG}) at Z peak");
  gsigmaZPbPbRD->Draw("AP");
  gsigmaZPbPbRD->SetMarkerStyle(20);
  gsigmaZPbPbRD->SetMarkerColor(kRed);
  gsigmaZPbPbRD->SetLineColor(kRed);
  gsigmaZPbPbRD->Draw("AP");
  gsigmaZPbPbMC->SetMarkerStyle(24);
  gsigmaZPbPbMC->SetMarkerColor(kRed);
  gsigmaZPbPbMC->SetLineColor(kRed);
  gsigmaZPbPbMC->Draw("same P");

  c2PbPb->SetLeftMargin(0.15);
  c2PbPb->SetRightMargin(0.05);
  c2PbPb->SaveAs("FinalPlots/ptMassResZPbPb.pdf");
  c2PbPb->SaveAs("FinalPlots/ptMassResZPbPb.png");


  //********* pPb Jpsi ***********//
  TCanvas* c1pPb = new TCanvas("c1pPb","c1pPb",0,0,400,400);
  c1pPb->cd();
  gsigmaJpsipPbRD->SetTitle("Mass Res. at J/#psi peak (pPb 8.16 TeV)");
  gsigmaJpsipPbRD->SetMinimum(0);
  gsigmaJpsipPbRD->SetMaximum(0.035);
  gsigmaJpsipPbRD->GetXaxis()->SetTitle("p_{T}^{#mu} (2.1<|#eta|<2.4)");
  gsigmaJpsipPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG}) at J/#psi peak");
  if (zoom) gsigmaJpsipPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsipPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsipPbRD->Draw("AP");
  gsigmaJpsipPbRD->SetMarkerStyle(21);
  gsigmaJpsipPbRD->SetMarkerColor(kBlue);
  gsigmaJpsipPbRD->SetLineColor(kBlue);
  gsigmaJpsipPbRD->Draw("AP");
  gsigmaJpsipPbMC->SetMarkerStyle(25);
  gsigmaJpsipPbMC->SetMarkerColor(kBlue);
  gsigmaJpsipPbMC->SetLineColor(kBlue);
  gsigmaJpsipPbMC->Draw("same P");

  c1pPb->SetLeftMargin(0.15);
  c1pPb->SetRightMargin(0.05);
  c1pPb->SaveAs(Form("FinalPlots/ptMassResJpsipPb%s.pdf",zoomString.Data()));
  c1pPb->SaveAs(Form("FinalPlots/ptMassResJpsipPb%s.png",zoomString.Data()));


  //********* pPb Z ***********//
  TCanvas* c2pPb = new TCanvas("c2pPb","c2pPb",0,0,400,400);
  c2pPb->cd();
  gsigmaZpPbRD->SetMinimum(0);
  gsigmaZpPbRD->SetMaximum(0.035);
  gsigmaZpPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gsigmaZpPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{CB}/m_{PDG}) at Z peak");
  gsigmaZpPbRD->Draw("AP");
  gsigmaZpPbRD->SetMarkerStyle(21);
  gsigmaZpPbRD->SetMarkerColor(kBlue);
  gsigmaZpPbRD->SetLineColor(kBlue);
  gsigmaZpPbRD->Draw("AP");
  gsigmaZpPbMC->SetMarkerStyle(25);
  gsigmaZpPbMC->SetMarkerColor(kBlue);
  gsigmaZpPbMC->SetLineColor(kBlue);
  gsigmaZpPbMC->Draw("same P");

  c2pPb->SetLeftMargin(0.15);
  c2pPb->SetRightMargin(0.05);
  c2pPb->SaveAs("FinalPlots/ptMassResZpPb.pdf");
  c2pPb->SaveAs("FinalPlots/ptMassResZpPb.png");

  //********* pp Jpsi ***********//
  TCanvas* c1pp = new TCanvas("c1pp","c1pp",0,0,400,400);
  c1pp->cd();
  gsigmaJpsippRD->SetTitle("Mass Res. at J/#psi peak (pp 5.02 TeV)");
  gsigmaJpsippRD->SetMinimum(0);
  gsigmaJpsippRD->SetMaximum(0.035);
  //gsigmaJpsippRD->SetMinimum(0.02);
  //gsigmaJpsippRD->SetMaximum(0.08);
  gsigmaJpsippRD->GetXaxis()->SetTitle("p_{T}^{#mu} (2.1<|#eta|<2.4)");
  gsigmaJpsippRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG}) at J/#psi peak");
  //gsigmaJpsippRD->GetYaxis()->SetTitle("#sigma_{avg} at J/#psi peak (GeV)");
  if (zoom) gsigmaJpsippRD->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsippRD->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsippRD->Draw("AP");
  gsigmaJpsippRD->SetMarkerStyle(33);
  gsigmaJpsippRD->SetMarkerColor(kBlack);
  gsigmaJpsippRD->SetLineColor(kBlack);
  gsigmaJpsippRD->Draw("AP");
  gsigmaJpsippMC->SetMarkerStyle(27);
  gsigmaJpsippMC->SetMarkerColor(kBlack);
  gsigmaJpsippMC->SetLineColor(kBlack);
  gsigmaJpsippMC->Draw("same P");

  c1pp->SetLeftMargin(0.15);
  c1pp->SetRightMargin(0.05);
  c1pp->SaveAs(Form("FinalPlots/ptMassResJpsipp%s.pdf",zoomString.Data()));
  c1pp->SaveAs(Form("FinalPlots/ptMassResJpsipp%s.png",zoomString.Data()));

  //********* pp Jpsi midrap***********//
  TCanvas* c1pp_midrap = new TCanvas("c1pp_midrap","c1pp_midrap",0,0,400,400);
  c1pp_midrap->cd();
  gsigmaJpsippRD_midrap->SetTitle("Mass Res. at J/#psi peak (pp 5.02 TeV)");
  //gsigmaJpsippRD_midrap->SetMinimum(0);
  //gsigmaJpsippRD_midrap->SetMaximum(0.035);
  gsigmaJpsippRD_midrap->SetMinimum(0.02);
  gsigmaJpsippRD_midrap->SetMaximum(0.08);
  gsigmaJpsippRD_midrap->GetXaxis()->SetTitle("p_{T}^{#mu} (0.0<|#eta|<0.9)");
  //gsigmaJpsippRD_midrap->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG}) at J/#psi peak");
  gsigmaJpsippRD_midrap->GetYaxis()->SetTitle("#sigma_{avg} at J/#psi peak (GeV)");
  if (zoom) gsigmaJpsippRD_midrap->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsippRD_midrap->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsippRD_midrap->Draw("AP");
  gsigmaJpsippRD_midrap->SetMarkerStyle(33);
  gsigmaJpsippRD_midrap->SetMarkerColor(kBlack);
  gsigmaJpsippRD_midrap->SetLineColor(kBlack);
  gsigmaJpsippRD_midrap->Draw("AP");
  gsigmaJpsippMC_midrap->SetMarkerStyle(27);
  gsigmaJpsippMC_midrap->SetMarkerColor(kBlack);
  gsigmaJpsippMC_midrap->SetLineColor(kBlack);
  gsigmaJpsippMC_midrap->Draw("same P");

  c1pp_midrap->SetLeftMargin(0.15);
  c1pp_midrap->SetRightMargin(0.05);
  c1pp_midrap->SaveAs(Form("FinalPlots/ptMassResJpsipp%s_midrap.pdf",zoomString.Data()));
  c1pp_midrap->SaveAs(Form("FinalPlots/ptMassResJpsipp%s_midrap.png",zoomString.Data()));


  //********* pp Z ***********//
  TCanvas* c2pp = new TCanvas("c2pp","c2pp",0,0,400,400);
  c2pp->cd();
  gsigmaZppRD->SetMinimum(0);
  gsigmaZppRD->SetMaximum(0.035);
  gsigmaZppRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gsigmaZppRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{CB}/m_{PDG}) at Z peak");
  gsigmaZppRD->Draw("AP");
  gsigmaZppRD->SetMarkerStyle(33);
  gsigmaZppRD->SetMarkerColor(kBlack);
  gsigmaZppRD->SetLineColor(kBlack);
  gsigmaZppRD->Draw("AP");
  gsigmaZppMC->SetMarkerStyle(27);
  gsigmaZppMC->SetMarkerColor(kBlack);
  gsigmaZppMC->SetLineColor(kBlack);
  gsigmaZppMC->Draw("same P");

  c2pp->SetLeftMargin(0.15);
  c2pp->SetRightMargin(0.05);
  c2pp->SaveAs("FinalPlots/ptMassResZpp.pdf");
  c2pp->SaveAs("FinalPlots/ptMassResZpp.png");


//******** MASS SCALING ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c3PbPb = new TCanvas("c3PbPb","c3PbPb",0,0,400,400);
  c3PbPb->cd();
  gmassJpsiPbPbRD->SetMinimum(0.99);
  gmassJpsiPbPbRD->SetMaximum(1.005);
  gmassJpsiPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu} (2.1<|#eta|<2.4)");
  gmassJpsiPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at J/#psi peak");
  if (zoom) gmassJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gmassJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gmassJpsiPbPbRD->Draw("AP");
  gmassJpsiPbPbRD->SetMarkerStyle(20);
  gmassJpsiPbPbRD->SetMarkerColor(kRed);
  gmassJpsiPbPbRD->SetLineColor(kRed);
  gmassJpsiPbPbRD->Draw("AP");
  gmassJpsiPbPbMC->SetMarkerStyle(24);
  gmassJpsiPbPbMC->SetMarkerColor(kRed);
  gmassJpsiPbPbMC->SetLineColor(kRed);
  gmassJpsiPbPbMC->Draw("same P");

  c3PbPb->SetLeftMargin(0.15);
  c3PbPb->SetRightMargin(0.05);
  c3PbPb->SaveAs(Form("FinalPlots/ptMassScaleJpsiPbPb%s.pdf",zoomString.Data()));
  c3PbPb->SaveAs(Form("FinalPlots/ptMassScaleJpsiPbPb%s.png",zoomString.Data()));


  //********* PbPb Z ***********//
  TCanvas* c4PbPb = new TCanvas("c4PbPb","c4PbPb",0,0,400,400);
  c4PbPb->cd();
  gmassZPbPbRD->SetMinimum(0.99);
  gmassZPbPbRD->SetMaximum(1.005);
  gmassZPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gmassZPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at Z peak");
  gmassZPbPbRD->Draw("AP");
  gmassZPbPbRD->SetMarkerStyle(20);
  gmassZPbPbRD->SetMarkerColor(kRed);
  gmassZPbPbRD->SetLineColor(kRed);
  gmassZPbPbRD->Draw("AP");
  gmassZPbPbMC->SetMarkerStyle(24);
  gmassZPbPbMC->SetMarkerColor(kRed);
  gmassZPbPbMC->SetLineColor(kRed);
  gmassZPbPbMC->Draw("same P");

  c4PbPb->SetLeftMargin(0.15);
  c4PbPb->SetRightMargin(0.05);
  c4PbPb->SaveAs("FinalPlots/ptMassScaleZPbPb.pdf");
  c4PbPb->SaveAs("FinalPlots/ptMassScaleZPbPb.png");


  //********* pPb Jpsi ***********//
  TCanvas* c3pPb = new TCanvas("c3pPb","c3pPb",0,0,400,400);
  c3pPb->cd();
  gmassJpsipPbRD->SetMinimum(0.99);
  gmassJpsipPbRD->SetMaximum(1.005);
  gmassJpsipPbRD->GetXaxis()->SetTitle("p_{T}^{#mu} (2.1<|#eta|<2.4)");
  gmassJpsipPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at J/#psi peak");
  if (zoom) gmassJpsipPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gmassJpsipPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gmassJpsipPbRD->Draw("AP");
  gmassJpsipPbRD->SetMarkerStyle(21);
  gmassJpsipPbRD->SetMarkerColor(kBlue);
  gmassJpsipPbRD->SetLineColor(kBlue);
  gmassJpsipPbRD->Draw("AP");
  gmassJpsipPbMC->SetMarkerStyle(25);
  gmassJpsipPbMC->SetMarkerColor(kBlue);
  gmassJpsipPbMC->SetLineColor(kBlue);
  gmassJpsipPbMC->Draw("same P");

  c3pPb->SetLeftMargin(0.15);
  c3pPb->SetRightMargin(0.05);
  c3pPb->SaveAs(Form("FinalPlots/ptMassScaleJpsipPb%s.pdf",zoomString.Data()));
  c3pPb->SaveAs(Form("FinalPlots/ptMassScaleJpsipPb%s.png",zoomString.Data()));


  //********* pPb Z ***********//
  TCanvas* c4pPb = new TCanvas("c4pPb","c4pPb",0,0,400,400);
  c4pPb->cd();
  gmassZpPbRD->SetMinimum(0.99);
  gmassZpPbRD->SetMaximum(1.005);
  gmassZpPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gmassZpPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at Z peak");
  gmassZpPbRD->Draw("AP");
  gmassZpPbRD->SetMarkerStyle(21);
  gmassZpPbRD->SetMarkerColor(kBlue);
  gmassZpPbRD->SetLineColor(kBlue);
  gmassZpPbRD->Draw("AP");
  gmassZpPbMC->SetMarkerStyle(25);
  gmassZpPbMC->SetMarkerColor(kBlue);
  gmassZpPbMC->SetLineColor(kBlue);
  gmassZpPbMC->Draw("same P");

  c4pPb->SetLeftMargin(0.15);
  c4pPb->SetRightMargin(0.05);
  c4pPb->SaveAs("FinalPlots/ptMassScaleZpPb.pdf");
  c4pPb->SaveAs("FinalPlots/ptMassScaleZpPb.png");

  //********* pp Jpsi ***********//
  TCanvas* c3pp = new TCanvas("c3pp","c3pp",0,0,400,400);
  c3pp->cd();
  gmassJpsippRD->SetMinimum(0.99);
  gmassJpsippRD->SetMaximum(1.005);
  gmassJpsippRD->GetXaxis()->SetTitle("p_{T}^{#mu} (2.1<|#eta|<2.4)");
  gmassJpsippRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at J/#psi peak");
  gmassJpsippRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at J/#psi peak");
  if (zoom) gmassJpsippRD->GetXaxis()->SetRangeUser(0.0,8);
  else gmassJpsippRD->GetXaxis()->SetRangeUser(0.0,30);
  gmassJpsippRD->Draw("AP");
  gmassJpsippRD->SetMarkerStyle(33);
  gmassJpsippRD->SetMarkerColor(kBlack);
  gmassJpsippRD->SetLineColor(kBlack);
  gmassJpsippRD->Draw("AP");
  gmassJpsippMC->SetMarkerStyle(27);
  gmassJpsippMC->SetMarkerColor(kBlack);
  gmassJpsippMC->SetLineColor(kBlack);
  gmassJpsippMC->Draw("same P");

  c3pp->SetLeftMargin(0.15);
  c3pp->SetRightMargin(0.05);
  c3pp->SaveAs(Form("FinalPlots/ptMassScaleJpsipp%s.pdf",zoomString.Data()));
  c3pp->SaveAs(Form("FinalPlots/ptMassScaleJpsipp%s.png",zoomString.Data()));


  //********* pp Z ***********//
  TCanvas* c4pp = new TCanvas("c4pp","c4pp",0,0,400,400);
  c4pp->cd();
  gmassZppRD->SetMinimum(0.99);
  gmassZppRD->SetMaximum(1.005);
  gmassZppRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gmassZppRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at Z peak");
  gmassZppRD->Draw("AP");
  gmassZppRD->SetMarkerStyle(33);
  gmassZppRD->SetMarkerColor(kBlack);
  gmassZppRD->SetLineColor(kBlack);
  gmassZppRD->Draw("AP");
  gmassZppMC->SetMarkerStyle(27);
  gmassZppMC->SetMarkerColor(kBlack);
  gmassZppMC->SetLineColor(kBlack);
  gmassZppMC->Draw("same P");

  c4pp->SetLeftMargin(0.15);
  c4pp->SetRightMargin(0.05);
  c4pp->SaveAs("FinalPlots/ptMassScaleZpp.pdf");
  c4pp->SaveAs("FinalPlots/ptMassScaleZpp.png");



  //Write everything to the output file
  cout << "Writing to File " << outFileName << endl;
  outFile->cd();
  c1PbPb->Write();
  c2PbPb->Write();
  c1pPb->Write();
  c2pPb->Write();
  c1pp->Write();
  c2pp->Write();
  c3PbPb->Write();
  c4PbPb->Write();
  c3pPb->Write();
  c4pPb->Write();
  c3pp->Write();
  c4pp->Write();
  outFile->Close();


  cout << "Here's what's left in memory:" << endl;
  gDirectory->ls("-m");

}
