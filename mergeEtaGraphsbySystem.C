
void removeXerrors(TGraphAsymmErrors* graph) {

  cout << "removing X errors..." << endl;
  int numPoints = graph->GetN();
  for (int i=0; i<numPoints; i++) {
    graph->SetPointEXhigh(i,0);
    graph->SetPointEXlow(i,0);
  }

}

void mergeEtaGraphsbySystem(bool zoom=kFALSE) {
  TString zoomString = "";
  if (zoom) zoomString = "_zoom";

  gStyle->SetErrorX(0);//This doesn't do anything.

  cout << "Loading graphs from RD files..." << endl;
  TFile* fZPbPbRD = TFile::Open("Results/etaMassResZPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hmass");
  TFile* fZpPbRD = TFile::Open("Results/etaMassResZpPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hmass");
  TFile* fZppRD = TFile::Open("Results/etaMassResZppRD.root","READ");
  TGraphAsymmErrors* gsigmaZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hmass");
  TFile* fJpsiPbPbRD = TFile::Open("Results/etaMassResJpsiPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hmass");
  TFile* fJpsipPbRD = TFile::Open("Results/etaMassResJpsipPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hmass");
  TFile* fJpsippRD = TFile::Open("Results/etaMassResJpsippRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hmass");

  cout << "Loading graphs from MC files..." << endl;
  TFile* fZPbPbMC = TFile::Open("Results/etaMassResZPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hmass");
  TFile* fZpPbMC = TFile::Open("Results/etaMassResZpPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hmass");
  TFile* fZppMC = TFile::Open("Results/etaMassResZppMC.root","READ");
  TGraphAsymmErrors* gsigmaZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hmass");
  TFile* fJpsiPbPbMC = TFile::Open("Results/etaMassResJpsiPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hmass");
  TFile* fJpsipPbMC = TFile::Open("Results/etaMassResJpsipPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hmass");
  TFile* fJpsippMC = TFile::Open("Results/etaMassResJpsippMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hmass");


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
  TString outFileName = "FinalPlots/etaMassResCombinedbySystem.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

//******** MASS RESOLUTION ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c1PbPb = new TCanvas("c1PbPb","c1PbPb",0,0,400,400);
  c1PbPb->cd();
  gsigmaJpsiPbPbRD->SetTitle("Mass Res. (PbPb 5.02 TeV)");
  gsigmaJpsiPbPbRD->SetMinimum(0);
  gsigmaJpsiPbPbRD->SetMaximum(0.035);
  gsigmaJpsiPbPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG})");
  if (zoom) gsigmaJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsiPbPbRD->SetMarkerStyle(20);
  gsigmaJpsiPbPbRD->SetMarkerColor(kBlack);
  gsigmaJpsiPbPbRD->SetLineColor(kBlack);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsiPbPbMC->SetMarkerStyle(24);
  gsigmaJpsiPbPbMC->SetMarkerColor(kBlack);
  gsigmaJpsiPbPbMC->SetLineColor(kBlack);
  gsigmaJpsiPbPbMC->Draw("same P");
  //********* PbPb Z ***********//
  gsigmaZPbPbRD->SetMarkerStyle(21);
  gsigmaZPbPbRD->SetMarkerColor(kBlue);
  gsigmaZPbPbRD->SetLineColor(kBlue);
  gsigmaZPbPbRD->Draw("same P");
  gsigmaZPbPbMC->SetMarkerStyle(25);
  gsigmaZPbPbMC->SetMarkerColor(kBlue);
  gsigmaZPbPbMC->SetLineColor(kBlue);
  gsigmaZPbPbMC->Draw("same P");
  TLegend* leg1 = new TLegend(0.2,0.7,0.55,0.89);
  leg1->SetTextSize(0.04);
  leg1->SetBorderSize(0);
  leg1->AddEntry(gsigmaJpsiPbPbRD,"J/#psi Data","pe");
  leg1->AddEntry(gsigmaJpsiPbPbMC,"J/#psi MC","pe");
  leg1->AddEntry(gsigmaZPbPbRD,"Z Data","pe");
  leg1->AddEntry(gsigmaZPbPbMC,"Z MC","pe");
  leg1->Draw("same");
  c1PbPb->SetLeftMargin(0.15);
  c1PbPb->SetRightMargin(0.05);
  c1PbPb->SaveAs(Form("FinalPlots/etaMassResPbPb%s.pdf",zoomString.Data()));
  c1PbPb->SaveAs(Form("FinalPlots/etaMassResPbPb%s.png",zoomString.Data()));


  //********* pPb Jpsi ***********//
  TCanvas* c1pPb = new TCanvas("c1pPb","c1pPb",0,0,400,400);
  c1pPb->cd();
  gsigmaJpsipPbRD->SetTitle("Mass Res. (pPb 8.16 TeV)");
  gsigmaJpsipPbRD->SetMinimum(0);
  gsigmaJpsipPbRD->SetMaximum(0.035);
  gsigmaJpsipPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gsigmaJpsipPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
  gsigmaJpsipPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG})");
  if (zoom) gsigmaJpsipPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsipPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsipPbRD->Draw("AP");
  gsigmaJpsipPbRD->SetMarkerStyle(20);
  gsigmaJpsipPbRD->SetMarkerColor(kBlack);
  gsigmaJpsipPbRD->SetLineColor(kBlack);
  gsigmaJpsipPbRD->Draw("AP");
  gsigmaJpsipPbMC->SetMarkerStyle(24);
  gsigmaJpsipPbMC->SetMarkerColor(kBlack);
  gsigmaJpsipPbMC->SetLineColor(kBlack);
  gsigmaJpsipPbMC->Draw("same P");
  //********* pPb Z ***********//
  gsigmaZpPbRD->SetMarkerStyle(21);
  gsigmaZpPbRD->SetMarkerColor(kBlue);
  gsigmaZpPbRD->SetLineColor(kBlue);
  gsigmaZpPbRD->Draw("same P");
  gsigmaZpPbMC->SetMarkerStyle(25);
  gsigmaZpPbMC->SetMarkerColor(kBlue);
  gsigmaZpPbMC->SetLineColor(kBlue);
  gsigmaZpPbMC->Draw("same P");
  TLegend* leg1pPb = new TLegend(0.2,0.7,0.55,0.89);
  leg1pPb->SetTextSize(0.04);
  leg1pPb->SetBorderSize(0);
  leg1pPb->AddEntry(gsigmaJpsipPbRD,"J/#psi Data","pe");
  leg1pPb->AddEntry(gsigmaJpsipPbMC,"J/#psi MC","pe");
  leg1pPb->AddEntry(gsigmaZpPbRD,"Z Data","pe");
  leg1pPb->AddEntry(gsigmaZpPbMC,"Z MC","pe");
  leg1pPb->Draw("same");
  c1pPb->SetLeftMargin(0.15);
  c1pPb->SetRightMargin(0.05);
  c1pPb->SaveAs(Form("FinalPlots/etaMassRespPb%s.pdf",zoomString.Data()));
  c1pPb->SaveAs(Form("FinalPlots/etaMassRespPb%s.png",zoomString.Data()));


  //********* pp Jpsi ***********//
  TCanvas* c1pp = new TCanvas("c1pp","c1pp",0,0,400,400);
  c1pp->cd();
  gsigmaJpsippRD->SetTitle("Mass Res. (pp 5.02 TeV)");
  gsigmaJpsippRD->SetMinimum(0);
  gsigmaJpsippRD->SetMaximum(0.035);
  gsigmaJpsippRD->GetXaxis()->SetLimits(0.0,2.4);
  //gsigmaJpsippRD->SetMinimum(0.02);
  //gsigmaJpsippRD->SetMaximum(0.08);
  gsigmaJpsippRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
  gsigmaJpsippRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG})");
  //gsigmaJpsippRD->GetYaxis()->SetTitle("#sigma_{avg} (GeV)");
  if (zoom) gsigmaJpsippRD->GetXaxis()->SetRangeUser(0.0,8);
  else gsigmaJpsippRD->GetXaxis()->SetRangeUser(0.0,30);
  gsigmaJpsippRD->Draw("AP");
  gsigmaJpsippRD->SetMarkerStyle(20);
  gsigmaJpsippRD->SetMarkerColor(kBlack);
  gsigmaJpsippRD->SetLineColor(kBlack);
  gsigmaJpsippRD->Draw("AP");
  gsigmaJpsippMC->SetMarkerStyle(24);
  gsigmaJpsippMC->SetMarkerColor(kBlack);
  gsigmaJpsippMC->SetLineColor(kBlack);
  gsigmaJpsippMC->Draw("same P");
  //********* pp Z ***********//
  gsigmaZppRD->SetMarkerStyle(21);
  gsigmaZppRD->SetMarkerColor(kBlue);
  gsigmaZppRD->SetLineColor(kBlue);
  gsigmaZppRD->Draw("same P");
  gsigmaZppMC->SetMarkerStyle(25);
  gsigmaZppMC->SetMarkerColor(kBlue);
  gsigmaZppMC->SetLineColor(kBlue);
  gsigmaZppMC->Draw("same P");
  TLegend* leg1pp = new TLegend(0.2,0.7,0.55,0.89);
  leg1pp->SetTextSize(0.04);
  leg1pp->SetBorderSize(0);
  leg1pp->AddEntry(gsigmaJpsippRD,"J/#psi Data","pe");
  leg1pp->AddEntry(gsigmaJpsippMC,"J/#psi MC","pe");
  leg1pp->AddEntry(gsigmaZppRD,"Z Data","pe");
  leg1pp->AddEntry(gsigmaZppMC,"Z MC","pe");
  leg1pp->Draw("same");
  c1pp->SetLeftMargin(0.15);
  c1pp->SetRightMargin(0.05);
  c1pp->SaveAs(Form("FinalPlots/etaMassRespp%s.pdf",zoomString.Data()));
  c1pp->SaveAs(Form("FinalPlots/etaMassRespp%s.png",zoomString.Data()));



//******** MASS SCALING ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c3PbPb = new TCanvas("c3PbPb","c3PbPb",0,0,400,400);
  c3PbPb->cd();
  gmassJpsiPbPbRD->SetTitle("Mass Scale (PbPb 5.02 TeV)");
  gmassJpsiPbPbRD->SetMinimum(0.99);
  gmassJpsiPbPbRD->SetMaximum(1.005);
  gmassJpsiPbPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gmassJpsiPbPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
  gmassJpsiPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
  if (zoom) gmassJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gmassJpsiPbPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gmassJpsiPbPbRD->Draw("AP");
  gmassJpsiPbPbRD->SetMarkerStyle(20);
  gmassJpsiPbPbRD->SetMarkerColor(kBlack);
  gmassJpsiPbPbRD->SetLineColor(kBlack);
  gmassJpsiPbPbRD->Draw("AP");
  gmassJpsiPbPbMC->SetMarkerStyle(24);
  gmassJpsiPbPbMC->SetMarkerColor(kBlack);
  gmassJpsiPbPbMC->SetLineColor(kBlack);
  gmassJpsiPbPbMC->Draw("same P");
  //********* PbPb Z ***********//
  gmassZPbPbRD->SetMarkerStyle(21);
  gmassZPbPbRD->SetMarkerColor(kBlue);
  gmassZPbPbRD->SetLineColor(kBlue);
  gmassZPbPbRD->Draw("same P");
  gmassZPbPbMC->SetMarkerStyle(25);
  gmassZPbPbMC->SetMarkerColor(kBlue);
  gmassZPbPbMC->SetLineColor(kBlue);
  gmassZPbPbMC->Draw("same P");
  TLegend* leg3 = new TLegend(0.2,0.7,0.55,0.89);
  leg3->SetTextSize(0.04);
  leg3->SetBorderSize(0);
  leg3->AddEntry(gmassJpsiPbPbRD,"J/#psi Data","pe");
  leg3->AddEntry(gmassJpsiPbPbMC,"J/#psi MC","pe");
  leg3->AddEntry(gmassZPbPbRD,"Z Data","pe");
  leg3->AddEntry(gmassZPbPbMC,"Z MC","pe");
  leg3->Draw("same");
  TLine* l3PbPb = new TLine(0,1,2.4,1);
  l3PbPb->SetLineColor(kRed);
  l3PbPb->SetLineStyle(2);
  l3PbPb->Draw("same");

  c3PbPb->SetLeftMargin(0.15);
  c3PbPb->SetRightMargin(0.05);
  c3PbPb->SaveAs(Form("FinalPlots/etaMassScalePbPb%s.pdf",zoomString.Data()));
  c3PbPb->SaveAs(Form("FinalPlots/etaMassScalePbPb%s.png",zoomString.Data()));



  //********* pPb Jpsi ***********//
  TCanvas* c3pPb = new TCanvas("c3pPb","c3pPb",0,0,400,400);
  c3pPb->cd();
  gmassJpsipPbRD->SetTitle("Mass Scale (pPb 8.16 TeV)");
  gmassJpsipPbRD->SetMinimum(0.99);
  gmassJpsipPbRD->SetMaximum(1.005);
  gmassJpsipPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gmassJpsipPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
  gmassJpsipPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
  if (zoom) gmassJpsipPbRD->GetXaxis()->SetRangeUser(0.0,8);
  else gmassJpsipPbRD->GetXaxis()->SetRangeUser(0.0,30);
  gmassJpsipPbRD->Draw("AP");
  gmassJpsipPbRD->SetMarkerStyle(20);
  gmassJpsipPbRD->SetMarkerColor(kBlack);
  gmassJpsipPbRD->SetLineColor(kBlack);
  gmassJpsipPbRD->Draw("AP");
  gmassJpsipPbMC->SetMarkerStyle(24);
  gmassJpsipPbMC->SetMarkerColor(kBlack);
  gmassJpsipPbMC->SetLineColor(kBlack);
  gmassJpsipPbMC->Draw("same P");
  //********* pPb Z ***********//
  gmassZpPbRD->SetMarkerStyle(21);
  gmassZpPbRD->SetMarkerColor(kBlue);
  gmassZpPbRD->SetLineColor(kBlue);
  gmassZpPbRD->Draw("same P");
  gmassZpPbMC->SetMarkerStyle(25);
  gmassZpPbMC->SetMarkerColor(kBlue);
  gmassZpPbMC->SetLineColor(kBlue);
  gmassZpPbMC->Draw("same P");
  TLegend* leg3pPb = new TLegend(0.2,0.7,0.55,0.89);
  leg3pPb->SetTextSize(0.04);
  leg3pPb->SetBorderSize(0);
  leg3pPb->AddEntry(gmassJpsipPbRD,"J/#psi Data","pe");
  leg3pPb->AddEntry(gmassJpsipPbMC,"J/#psi MC","pe");
  leg3pPb->AddEntry(gmassZpPbRD,"Z Data","pe");
  leg3pPb->AddEntry(gmassZpPbMC,"Z MC","pe");
  leg3pPb->Draw("same");
  TLine* l3pPb = new TLine(0,1,2.4,1);
  l3pPb->SetLineColor(kRed);
  l3pPb->SetLineStyle(2);
  l3pPb->Draw("same");

  c3pPb->SetLeftMargin(0.15);
  c3pPb->SetRightMargin(0.05);
  c3pPb->SaveAs(Form("FinalPlots/etaMassScalepPb%s.pdf",zoomString.Data()));
  c3pPb->SaveAs(Form("FinalPlots/etaMassScalepPb%s.png",zoomString.Data()));


  //********* pp Jpsi ***********//
  TCanvas* c3pp = new TCanvas("c3pp","c3pp",0,0,400,400);
  c3pp->cd();
  gmassJpsippRD->SetTitle("Mass Scale (pp 5.02 TeV)");
  gmassJpsippRD->SetMinimum(0.99);
  gmassJpsippRD->SetMaximum(1.005);
  gmassJpsippRD->GetXaxis()->SetLimits(0.0,2.4);
  gmassJpsippRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
  gmassJpsippRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
  if (zoom) gmassJpsippRD->GetXaxis()->SetRangeUser(0.0,8);
  else gmassJpsippRD->GetXaxis()->SetRangeUser(0.0,30);
  gmassJpsippRD->Draw("AP");
  gmassJpsippRD->SetMarkerStyle(20);
  gmassJpsippRD->SetMarkerColor(kBlack);
  gmassJpsippRD->SetLineColor(kBlack);
  gmassJpsippRD->Draw("AP");
  gmassJpsippMC->SetMarkerStyle(24);
  gmassJpsippMC->SetMarkerColor(kBlack);
  gmassJpsippMC->SetLineColor(kBlack);
  gmassJpsippMC->Draw("same P");
  //********* pp Z ***********//
  gmassZppRD->SetMarkerStyle(21);
  gmassZppRD->SetMarkerColor(kBlue);
  gmassZppRD->SetLineColor(kBlue);
  gmassZppRD->Draw("same P");
  gmassZppMC->SetMarkerStyle(25);
  gmassZppMC->SetMarkerColor(kBlue);
  gmassZppMC->SetLineColor(kBlue);
  gmassZppMC->Draw("same P");
  TLegend* leg3pp = new TLegend(0.2,0.7,0.55,0.89);
  leg3pp->SetTextSize(0.04);
  leg3pp->SetBorderSize(0);
  leg3pp->AddEntry(gmassJpsippRD,"J/#psi Data","pe");
  leg3pp->AddEntry(gmassJpsippMC,"J/#psi MC","pe");
  leg3pp->AddEntry(gmassZppRD,"Z Data","pe");
  leg3pp->AddEntry(gmassZppMC,"Z MC","pe");
  leg3pp->Draw("same");
  TLine* l3pp = new TLine(0,1,2.4,1);
  l3pp->SetLineColor(kRed);
  l3pp->SetLineStyle(2);
  l3pp->Draw("same");

  c3pp->SetLeftMargin(0.15);
  c3pp->SetRightMargin(0.05);
  c3pp->SaveAs(Form("FinalPlots/etaMassScalepp%s.pdf",zoomString.Data()));
  c3pp->SaveAs(Form("FinalPlots/etaMassScalepp%s.png",zoomString.Data()));


  //Write everything to the output file
  cout << "Writing to File " << outFileName << endl;
  outFile->cd();
  c1PbPb->Write();
  c1pPb->Write();
  c1pp->Write();
  c3PbPb->Write();
  c3pPb->Write();
  c3pp->Write();
  outFile->Close();


  cout << "Here's what's left in memory:" << endl;
  gDirectory->ls("-m");

}
