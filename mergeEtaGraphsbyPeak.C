
void removeXerrors(TGraphAsymmErrors* graph) {

  cout << "removing X errors..." << endl;
  int numPoints = graph->GetN();
  for (int i=0; i<numPoints; i++) {
    graph->SetPointEXhigh(i,0);
    graph->SetPointEXlow(i,0);
  }

}

void mergeEtaGraphsbyPeak(bool zoom=kFALSE) {
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
  removeXerrors(gsigmaZPbPbRD);
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
  removeXerrors(gsigmaJpsippMC);

  removeXerrors(gmassZPbPbMC);
  removeXerrors(gmassZpPbMC);
  removeXerrors(gmassZppMC);
  removeXerrors(gmassJpsiPbPbMC);
  removeXerrors(gmassJpsipPbMC);
  removeXerrors(gmassJpsippMC);

  cout << "Finished removing X errors." << endl;

  //Set up the output file.
  TString outFileName = "FinalPlots/etaMassResCombinedbyPeak.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

//******** MASS RESOLUTION ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c1PbPb = new TCanvas("c1PbPb","c1PbPb",0,0,400,400);
  c1PbPb->cd();
  gsigmaJpsiPbPbRD->SetTitle("Mass Res. at J/#psi peak");
  gsigmaJpsiPbPbRD->SetMinimum(0);
  gsigmaJpsiPbPbRD->SetMaximum(0.035);
  gsigmaJpsiPbPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
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
  //********* pPb Jpsi ***********//
  gsigmaJpsipPbRD->SetMarkerStyle(21);
  gsigmaJpsipPbRD->SetMarkerColor(kBlue);
  gsigmaJpsipPbRD->SetLineColor(kBlue);
  gsigmaJpsipPbRD->Draw("same P");
  gsigmaJpsipPbMC->SetMarkerStyle(25);
  gsigmaJpsipPbMC->SetMarkerColor(kBlue);
  gsigmaJpsipPbMC->SetLineColor(kBlue);
  gsigmaJpsipPbMC->Draw("same P");
  //********* pp Jpsi ***********//
  gsigmaJpsippRD->SetMarkerStyle(33);
  gsigmaJpsippRD->SetMarkerColor(kBlack);
  gsigmaJpsippRD->SetLineColor(kBlack);
  gsigmaJpsippRD->Draw("same P");
  gsigmaJpsippMC->SetMarkerStyle(27);
  gsigmaJpsippMC->SetMarkerColor(kBlack);
  gsigmaJpsippMC->SetLineColor(kBlack);
  gsigmaJpsippMC->Draw("same P");
  TLegend* leg1 = new TLegend(0.17,0.6,0.45,0.85);
  leg1->SetTextSize(0.04);
  //leg1->SetTextFont(43);
  leg1->SetBorderSize(0);
  //leg1->SetHeader("Mass Res. at Z peak","C");
  leg1->AddEntry(gsigmaJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg1->AddEntry(gsigmaJpsippRD,"pp Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1->AddEntry(gsigmaJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg1->AddEntry(gsigmaJpsippMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  //header1->SetTextAlign(32);
  //header1->SetTextColor(2);
  //header1->SetTextSize(.06);
  leg1->Draw("same");
  c1PbPb->SetLeftMargin(0.15);
  c1PbPb->SetRightMargin(0.05);
  c1PbPb->SaveAs(Form("FinalPlots/etaMassResJpsi%s.pdf",zoomString.Data()));
  c1PbPb->SaveAs(Form("FinalPlots/etaMassResJpsi%s.png",zoomString.Data()));

  //********* PbPb Z ***********//
  TCanvas* c2PbPb = new TCanvas("c2PbPb","c2PbPb",0,0,400,400);
  c2PbPb->cd();
  gsigmaZPbPbRD->SetTitle("Mass Res. at Z peak");
  gsigmaZPbPbRD->SetMinimum(0);
  gsigmaZPbPbRD->SetMaximum(0.035);
  gsigmaZPbPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gsigmaZPbPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
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
  //********* pPb Z ***********//
  gsigmaZpPbRD->SetMarkerStyle(21);
  gsigmaZpPbRD->SetMarkerColor(kBlue);
  gsigmaZpPbRD->SetLineColor(kBlue);
  gsigmaZpPbRD->Draw("same P");
  gsigmaZpPbMC->SetMarkerStyle(25);
  gsigmaZpPbMC->SetMarkerColor(kBlue);
  gsigmaZpPbMC->SetLineColor(kBlue);
  gsigmaZpPbMC->Draw("same P");
  //********* pp Z ***********//
  gsigmaZppRD->SetMarkerStyle(33);
  gsigmaZppRD->SetMarkerColor(kBlack);
  gsigmaZppRD->SetLineColor(kBlack);
  gsigmaZppRD->Draw("same P");
  gsigmaZppMC->SetMarkerStyle(27);
  gsigmaZppMC->SetMarkerColor(kBlack);
  gsigmaZppMC->SetLineColor(kBlack);
  gsigmaZppMC->Draw("same P");
  TLegend* leg1Z = new TLegend(0.17,0.6,0.45,0.85);
  leg1Z->SetTextSize(0.04);
  //leg1Z->SetTextFont(43);
  leg1Z->SetBorderSize(0);
  //leg1Z->SetHeader("Mass Res. at Z peak","C");
  leg1Z->AddEntry(gsigmaZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1Z->AddEntry(gsigmaZpPbRD,"pPb Data 8.16 TeV","pe");
  leg1Z->AddEntry(gsigmaZppRD,"pp Data 5.02 TeV","pe");
  leg1Z->AddEntry(gsigmaZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1Z->AddEntry(gsigmaZpPbMC,"pPb MC 8.16 TeV","pe");
  leg1Z->AddEntry(gsigmaZppMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  //header1->SetTextAlign(32);
  //header1->SetTextColor(2);
  //header1->SetTextSize(.06);
  leg1Z->Draw("same");
  c2PbPb->SetLeftMargin(0.15);
  c2PbPb->SetRightMargin(0.05);
  c2PbPb->SaveAs("FinalPlots/etaMassResZ.pdf");
  c2PbPb->SaveAs("FinalPlots/etaMassResZ.png");


//******** MASS SCALING ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c3PbPb = new TCanvas("c3PbPb","c3PbPb",0,0,400,400);
  c3PbPb->cd();
  gmassJpsiPbPbRD->SetTitle("Mass Scale at J/#psi peak");
  gmassJpsiPbPbRD->SetMinimum(0.99);
  gmassJpsiPbPbRD->SetMaximum(1.005);
  gmassJpsiPbPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gmassJpsiPbPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
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
  //********* pPb Jpsi ***********//
  gmassJpsipPbRD->SetMarkerStyle(21);
  gmassJpsipPbRD->SetMarkerColor(kBlue);
  gmassJpsipPbRD->SetLineColor(kBlue);
  gmassJpsipPbRD->Draw("same P");
  gmassJpsipPbMC->SetMarkerStyle(25);
  gmassJpsipPbMC->SetMarkerColor(kBlue);
  gmassJpsipPbMC->SetLineColor(kBlue);
  gmassJpsipPbMC->Draw("same P");
  //********* pp Jpsi ***********//
  gmassJpsippRD->SetMarkerStyle(33);
  gmassJpsippRD->SetMarkerColor(kBlack);
  gmassJpsippRD->SetLineColor(kBlack);
  gmassJpsippRD->Draw("same P");
  gmassJpsippMC->SetMarkerStyle(27);
  gmassJpsippMC->SetMarkerColor(kBlack);
  gmassJpsippMC->SetLineColor(kBlack);
  gmassJpsippMC->Draw("same P");
  TLegend* leg1JpsiScale = new TLegend(0.17,0.15,0.45,0.40);
  leg1JpsiScale->SetTextSize(0.04);
  //leg1JpsiScale->SetTextFont(43);
  leg1JpsiScale->SetBorderSize(0);
  //leg1JpsiScale->SetHeader("Mass Res. at Z peak","C");
  leg1JpsiScale->AddEntry(gmassJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1JpsiScale->AddEntry(gmassJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg1JpsiScale->AddEntry(gmassJpsippRD,"pp Data 5.02 TeV","pe");
  leg1JpsiScale->AddEntry(gmassJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1JpsiScale->AddEntry(gmassJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg1JpsiScale->AddEntry(gmassJpsippMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  //header1->SetTextAlign(32);
  //header1->SetTextColor(2);
  //header1->SetTextSize(.06);
  leg1JpsiScale->Draw("same");
  TLine* l3PbPb = new TLine(0,1,2.4,1);
  l3PbPb->SetLineColor(kRed);
  l3PbPb->SetLineStyle(2);
  l3PbPb->Draw("same");

  c3PbPb->SetLeftMargin(0.15);
  c3PbPb->SetRightMargin(0.05);
  c3PbPb->SaveAs(Form("FinalPlots/etaMassScaleJpsi%s.pdf",zoomString.Data()));
  c3PbPb->SaveAs(Form("FinalPlots/etaMassScaleJpsi%s.png",zoomString.Data()));

  //********* PbPb Z ***********//
  TCanvas* c4PbPb = new TCanvas("c4PbPb","c4PbPb",0,0,400,400);
  c4PbPb->cd();
  gmassZPbPbRD->SetTitle("Mass Scale at Z peak");
  gmassZPbPbRD->SetMinimum(0.99);
  gmassZPbPbRD->SetMaximum(1.005);
  gmassZPbPbRD->GetXaxis()->SetLimits(0.0,2.4);
  gmassZPbPbRD->GetXaxis()->SetTitle("|#eta^{#mu}|");
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
  //********* pPb Z ***********//
  gmassZpPbRD->SetMarkerStyle(21);
  gmassZpPbRD->SetMarkerColor(kBlue);
  gmassZpPbRD->SetLineColor(kBlue);
  gmassZpPbRD->Draw("same P");
  gmassZpPbMC->SetMarkerStyle(25);
  gmassZpPbMC->SetMarkerColor(kBlue);
  gmassZpPbMC->SetLineColor(kBlue);
  gmassZpPbMC->Draw("same P");
  //********* pp Z ***********//
  gmassZppRD->SetMarkerStyle(33);
  gmassZppRD->SetMarkerColor(kBlack);
  gmassZppRD->SetLineColor(kBlack);
  gmassZppRD->Draw("same P");
  gmassZppMC->SetMarkerStyle(27);
  gmassZppMC->SetMarkerColor(kBlack);
  gmassZppMC->SetLineColor(kBlack);
  gmassZppMC->Draw("same P");
  TLegend* leg1ZScale = new TLegend(0.17,0.15,0.45,0.40);
  leg1ZScale->SetTextSize(0.04);
  //leg1ZScale->SetTextFont(43);
  leg1ZScale->SetBorderSize(0);
  //leg1ZScale->SetHeader("Mass Res. at Z peak","C");
  leg1ZScale->AddEntry(gmassZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1ZScale->AddEntry(gmassZpPbRD,"pPb Data 8.16 TeV","pe");
  leg1ZScale->AddEntry(gmassZppRD,"pp Data 5.02 TeV","pe");
  leg1ZScale->AddEntry(gmassZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1ZScale->AddEntry(gmassZpPbMC,"pPb MC 8.16 TeV","pe");
  leg1ZScale->AddEntry(gmassZppMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  //header1->SetTextAlign(32);
  //header1->SetTextColor(2);
  //header1->SetTextSize(.06);
  leg1ZScale->Draw("same");
  TLine* l4PbPb = new TLine(0,1,2.4,1);
  l4PbPb->SetLineColor(kRed);
  l4PbPb->SetLineStyle(2);
  l4PbPb->Draw("same");

  c4PbPb->SetLeftMargin(0.15);
  c4PbPb->SetRightMargin(0.05);
  c4PbPb->SaveAs("FinalPlots/etaMassScaleZ.pdf");
  c4PbPb->SaveAs("FinalPlots/etaMassScaleZ.png");



  //Write everything to the output file
  cout << "Writing to File " << outFileName << endl;
  outFile->cd();
  c1PbPb->Write();
  c3PbPb->Write();
  outFile->Close();


  cout << "Here's what's left in memory:" << endl;
  gDirectory->ls("-m");

}
