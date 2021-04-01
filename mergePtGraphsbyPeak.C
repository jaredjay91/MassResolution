#include "HeaderFiles/tdrstyle.C"
#include "HeaderFiles/CMS_lumi.C"

void removeXerrors(TGraphAsymmErrors* graph) {

  cout << "removing X errors..." << endl;
  int numPoints = graph->GetN();
  for (int i=0; i<numPoints; i++) {
    graph->SetPointEXhigh(i,0);
    graph->SetPointEXlow(i,0);
  }

}

void DivideGraphs(TGraphAsymmErrors* gRD, TGraphAsymmErrors* gMC) {
  int numpointsRD = gRD->GetN();
  int numpointsMC = gMC->GetN();
  if (numpointsRD != numpointsMC) {
    cout << "ERROR: RD and MC have different bins!" << endl;
    return;
  }
  for (int i=0; i<numpointsRD; i++) {
    double eyhRD = gRD->GetErrorYhigh(i);
    double eylRD = gRD->GetErrorYhigh(i);
    double exhRD = gRD->GetErrorXhigh(i);
    double exlRD = gRD->GetErrorXlow(i);
    double YRD = 0;
    double XRD = 0;
    gRD->GetPoint(i,XRD,YRD);
    double eyhMC = gMC->GetErrorYhigh(i);
    double eylMC = gMC->GetErrorYhigh(i);
    double exhMC = gMC->GetErrorXhigh(i);
    double exlMC = gMC->GetErrorXlow(i);
    double YMC = 0;
    double XMC = 0;
    gMC->GetPoint(i,XMC,YMC);
    double ratio = YRD/YMC;
    double eyhratio = ratio*sqrt(pow(eyhRD/YRD,2) + pow(eyhMC/YMC,2));
    double eylratio = ratio*sqrt(pow(eylRD/YRD,2) + pow(eylMC/YMC,2));
    gRD->SetPoint(i,XRD,ratio);
    gRD->SetPointError(i, exlRD, exhRD, eylratio, eyhratio);
  }
  gRD->GetYaxis()->SetTitleOffset(0.43) ;
  gRD->GetYaxis()->SetTitle("Data/MC") ;
  gRD->GetYaxis()->SetTitleSize(0.14) ; //19
  gRD->GetYaxis()->SetLabelSize(0.16) ; // 113
  gRD->GetYaxis()->SetRangeUser(-3.8,3.8) ;
  gRD->GetYaxis()->CenterTitle();
  gRD->GetYaxis()->SetTickSize(0.04);
  gRD->GetYaxis()->SetNdivisions(404);
  gRD->GetXaxis()->SetTitleOffset(1.0) ;
  gRD->GetXaxis()->SetLabelOffset(0.04) ;
  gRD->GetXaxis()->SetLabelSize(0.16) ; //23
  gRD->GetXaxis()->SetTitleSize(0.18) ;  //28
  //gRD->GetXaxis()->CenterTitle();
  gRD->GetXaxis()->SetTickSize(0.03);
  //gRD->GetXaxis()->SetLimits(0,50);
  gRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
}


void mergePtGraphsbyPeak(bool zoom=kFALSE) {
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
  TString outFileName = "FinalPlots/ptMassResCombinedbyPeak.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

//******** MASS RESOLUTION ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c1 = new TCanvas("c1","c1",0,0,500,500);
  c1->cd();
  TPad *pad1a = new TPad("pad1a", "pad1a", 0, 0.14, 0.98, 1.0);
  pad1a->SetTicks(1,1);
  pad1a->Draw(); pad1a->cd();
  gsigmaJpsiPbPbRD->SetTitle("Mass Res. at J/#psi peak");
  gsigmaJpsiPbPbRD->SetMinimum(0);
  gsigmaJpsiPbPbRD->SetMaximum(0.03);
  gsigmaJpsiPbPbRD->GetXaxis()->SetLimits(0.0,30);
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gsigmaJpsiPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG})");
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
  TLegend* leg1 = new TLegend(0.57,0.15,0.45,0.45);
  leg1->SetTextSize(0.04);
  //leg1->SetTextFont(43);
  leg1->SetBorderSize(0);
  leg1->SetHeader("Mass Res. at J/#psi peak","C");
  leg1->AddEntry(gsigmaJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg1->AddEntry(gsigmaJpsippRD,"pp Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1->AddEntry(gsigmaJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg1->AddEntry(gsigmaJpsippMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  header1->SetTextAlign(12);
  //header1->SetTextColor(2);
  header1->SetTextSize(.06);
  leg1->Draw("same");

  TPad *pad1b = new TPad("pad1b", "pad1b", 0, 0, 0.98, 0.2);
  pad1b->SetTopMargin(0); // Upper and lower plot are joined
  pad1b->SetBottomMargin(0.4);
  pad1a->SetLeftMargin(0.14);
  pad1a->SetRightMargin(0.02);
  pad1b->SetRightMargin(0.02);
  pad1b->SetLeftMargin(0.14);
  pad1b->SetTicks(1,1);
  pad1b->cd();

  TGraphAsymmErrors* gsigmaJpsiPbPbRDsf = (TGraphAsymmErrors*)gsigmaJpsiPbPbRD->Clone("gsigmaJpsiPbPbRDsf");
  DivideGraphs(gsigmaJpsiPbPbRDsf,gsigmaJpsiPbPbMC);
  gsigmaJpsiPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gsigmaJpsiPbPbRD->GetYaxis()->CenterTitle();
  gsigmaJpsiPbPbRDsf->SetMinimum(0.38);
  gsigmaJpsiPbPbRDsf->SetMaximum(1.62);
  gsigmaJpsiPbPbRDsf->GetXaxis()->SetLimits(0.0,30);
  gsigmaJpsiPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gsigmaJpsipPbRDsf = (TGraphAsymmErrors*)gsigmaJpsipPbRD->Clone("gsigmaJpsipPbRDsf");
  DivideGraphs(gsigmaJpsipPbRDsf,gsigmaJpsipPbMC);
  gsigmaJpsipPbRDsf->Draw("same P");
  TGraphAsymmErrors* gsigmaJpsippRDsf = (TGraphAsymmErrors*)gsigmaJpsippRD->Clone("gsigmaJpsippRDsf");
  DivideGraphs(gsigmaJpsippRDsf,gsigmaJpsippMC);
  gsigmaJpsippRDsf->Draw("same P");
  TLine *l1 = new TLine(0,1,30,1);
  l1->SetLineStyle(9);
  l1->Draw();

  //********* PbPb Z ***********//
  TCanvas* c2 = new TCanvas("c2","c2",0,0,500,500);
  c2->cd();
  TPad *pad2a = new TPad("pad2a", "pad2a", 0, 0.14, 0.98, 1.0);
  pad2a->SetTicks(1,1);
  pad2a->Draw(); pad2a->cd();
  gsigmaZPbPbRD->SetTitle("Mass Res. at Z peak");
  gsigmaZPbPbRD->SetMinimum(0);
  gsigmaZPbPbRD->SetMaximum(0.03);
  gsigmaZPbPbRD->GetXaxis()->SetLimits(0.0,200);
  gsigmaZPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gsigmaZPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gsigmaZPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gsigmaZPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gsigmaZPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{CB}/m_{PDG})");
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
  TLegend* leg2 = new TLegend(0.57,0.15,0.45,0.45);
  leg2->SetTextSize(0.04);
  //leg2->SetTextFont(43);
  leg2->SetBorderSize(0);
  leg2->SetHeader("Mass Res. at Z peak","C");
  leg2->AddEntry(gsigmaZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg2->AddEntry(gsigmaZpPbRD,"pPb Data 8.16 TeV","pe");
  leg2->AddEntry(gsigmaZppRD,"pp Data 5.02 TeV","pe");
  leg2->AddEntry(gsigmaZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg2->AddEntry(gsigmaZpPbMC,"pPb MC 8.16 TeV","pe");
  leg2->AddEntry(gsigmaZppMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header2 = (TLegendEntry*)leg2->GetListOfPrimitives()->First();
  header2->SetTextAlign(12);
  //header2->SetTextColor(2);
  header2->SetTextSize(.06);
  leg2->Draw("same");

  TPad *pad2b = new TPad("pad2b", "pad2b", 0, 0, 0.98, 0.2);
  pad2b->SetTopMargin(0); // Upper and lower plot are joined
  pad2b->SetBottomMargin(0.4);
  pad2a->SetLeftMargin(0.14);
  pad2a->SetRightMargin(0.02);
  pad2b->SetRightMargin(0.02);
  pad2b->SetLeftMargin(0.14);
  pad2b->SetTicks(1,1);
  pad2b->cd();

  TGraphAsymmErrors* gsigmaZPbPbRDsf = (TGraphAsymmErrors*)gsigmaZPbPbRD->Clone("gsigmaZPbPbRDsf");
  DivideGraphs(gsigmaZPbPbRDsf,gsigmaZPbPbMC);
  gsigmaZPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gsigmaZPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gsigmaZPbPbRD->GetYaxis()->CenterTitle();
  gsigmaZPbPbRDsf->SetMinimum(0.38);
  gsigmaZPbPbRDsf->SetMaximum(1.62);
  gsigmaZPbPbRDsf->GetXaxis()->SetLimits(0.0,200);
  gsigmaZPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gsigmaZpPbRDsf = (TGraphAsymmErrors*)gsigmaZpPbRD->Clone("gsigmaZpPbRDsf");
  DivideGraphs(gsigmaZpPbRDsf,gsigmaZpPbMC);
  gsigmaZpPbRDsf->Draw("same P");
  TGraphAsymmErrors* gsigmaZppRDsf = (TGraphAsymmErrors*)gsigmaZppRD->Clone("gsigmaZppRDsf");
  DivideGraphs(gsigmaZppRDsf,gsigmaZppMC);
  gsigmaZppRDsf->Draw("same P");
  TLine *l2 = new TLine(0,1,200,1);
  l2->SetLineStyle(9);
  l2->Draw();


//******** MASS SCALING ********\\

  //********* PbPb Jpsi ***********//
  TCanvas* c3 = new TCanvas("c3","c3",0,0,500,500);
  c3->cd();
  TPad *pad3a = new TPad("pad3a", "pad3a", 0, 0.14, 0.98, 1.0);
  pad3a->SetTicks(1,1);
  pad3a->Draw(); pad3a->cd();
  gmassJpsiPbPbRD->SetTitle("Mass Scale at J/#psi peak");
  gmassJpsiPbPbRD->SetMinimum(0.985);
  gmassJpsiPbPbRD->SetMaximum(1.005);
  gmassJpsiPbPbRD->GetXaxis()->SetLimits(0.0,30);
  gmassJpsiPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gmassJpsiPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gmassJpsiPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gmassJpsiPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gmassJpsiPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
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
  TLegend* leg3 = new TLegend(0.17,0.15,0.45,0.45);
  leg3->SetTextSize(0.04);
  //leg3->SetTextFont(43);
  leg3->SetBorderSize(0);
  leg3->SetHeader("Mass Scale at J/#psi peak","C");
  leg3->AddEntry(gmassJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg3->AddEntry(gmassJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg3->AddEntry(gmassJpsippRD,"pp Data 5.02 TeV","pe");
  leg3->AddEntry(gmassJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg3->AddEntry(gmassJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg3->AddEntry(gmassJpsippMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header3 = (TLegendEntry*)leg3->GetListOfPrimitives()->First();
  header3->SetTextAlign(12);
  //header3->SetTextColor(2);
  header3->SetTextSize(.06);
  leg3->Draw("same");
  TLine* l3a = new TLine(0,1,30,1);
  l3a->SetLineColor(kRed);
  l3a->SetLineStyle(2);
  l3a->Draw("same");

  TPad *pad3b = new TPad("pad3b", "pad3b", 0, 0, 0.98, 0.2);
  pad3b->SetTopMargin(0); // Upper and lower plot are joined
  pad3b->SetBottomMargin(0.4);
  pad3a->SetLeftMargin(0.14);
  pad3a->SetRightMargin(0.02);
  pad3b->SetRightMargin(0.02);
  pad3b->SetLeftMargin(0.14);
  pad3b->SetTicks(1,1);
  pad3b->cd();

  TGraphAsymmErrors* gmassJpsiPbPbRDsf = (TGraphAsymmErrors*)gmassJpsiPbPbRD->Clone("gmassJpsiPbPbRDsf");
  DivideGraphs(gmassJpsiPbPbRDsf,gmassJpsiPbPbMC);
  gmassJpsiPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gmassJpsiPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gmassJpsiPbPbRD->GetYaxis()->CenterTitle();
  gmassJpsiPbPbRDsf->SetMinimum(0.9935);
  gmassJpsiPbPbRDsf->SetMaximum(1.0065);
  gmassJpsiPbPbRDsf->GetXaxis()->SetLimits(0.0,30);
  gmassJpsiPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gmassJpsipPbRDsf = (TGraphAsymmErrors*)gmassJpsipPbRD->Clone("gmassJpsipPbRDsf");
  DivideGraphs(gmassJpsipPbRDsf,gmassJpsipPbMC);
  gmassJpsipPbRDsf->Draw("same P");
  TGraphAsymmErrors* gmassJpsippRDsf = (TGraphAsymmErrors*)gmassJpsippRD->Clone("gmassJpsippRDsf");
  DivideGraphs(gmassJpsippRDsf,gmassJpsippMC);
  gmassJpsippRDsf->Draw("same P");
  TLine *l3 = new TLine(0,1,30,1);
  l3->SetLineStyle(9);
  l3->Draw();


  //********* PbPb Z ***********//
  TCanvas* c4 = new TCanvas("c4","c4",0,0,500,500);
  c4->cd();
  TPad *pad4a = new TPad("pad4a", "pad4a", 0, 0.14, 0.98, 1.0);
  pad4a->SetTicks(1,1);
  pad4a->Draw(); pad4a->cd();
  gmassZPbPbRD->SetTitle("Mass Scale at Z peak");
  gmassZPbPbRD->SetMinimum(0.985);
  gmassZPbPbRD->SetMaximum(1.005);
  gmassZPbPbRD->GetXaxis()->SetLimits(0.0,200);
  gmassZPbPbRD->GetXaxis()->SetTitle("p_{T}^{#mu}");
  gmassZPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gmassZPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gmassZPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gmassZPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
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
  TLegend* leg4 = new TLegend(0.17,0.15,0.45,0.45);
  leg4->SetTextSize(0.04);
  //leg4->SetTextFont(43);
  leg4->SetBorderSize(0);
  leg4->SetHeader("Mass Scale at Z peak","C");
  leg4->AddEntry(gmassZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg4->AddEntry(gmassZpPbRD,"pPb Data 8.16 TeV","pe");
  leg4->AddEntry(gmassZppRD,"pp Data 5.02 TeV","pe");
  leg4->AddEntry(gmassZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg4->AddEntry(gmassZpPbMC,"pPb MC 8.16 TeV","pe");
  leg4->AddEntry(gmassZppMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header4 = (TLegendEntry*)leg4->GetListOfPrimitives()->First();
  header4->SetTextAlign(12);
  //header4->SetTextColor(2);
  header4->SetTextSize(.06);
  leg4->Draw("same");
  TLine* l4a = new TLine(0,1,200,1);
  l4a->SetLineColor(kRed);
  l4a->SetLineStyle(2);
  l4a->Draw("same");

  TPad *pad4b = new TPad("pad4b", "pad4b", 0, 0, 0.98, 0.2);
  pad4b->SetTopMargin(0); // Upper and lower plot are joined
  pad4b->SetBottomMargin(0.4);
  pad4a->SetLeftMargin(0.14);
  pad4a->SetRightMargin(0.02);
  pad4b->SetRightMargin(0.02);
  pad4b->SetLeftMargin(0.14);
  pad4b->SetTicks(1,1);
  pad4b->cd();

  TGraphAsymmErrors* gmassZPbPbRDsf = (TGraphAsymmErrors*)gmassZPbPbRD->Clone("gmassZPbPbRDsf");
  DivideGraphs(gmassZPbPbRDsf,gmassZPbPbMC);
  gmassZPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gmassZPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gmassZPbPbRD->GetYaxis()->CenterTitle();
  gmassZPbPbRDsf->SetMinimum(0.9935);
  gmassZPbPbRDsf->SetMaximum(1.0065);
  gmassZPbPbRDsf->GetXaxis()->SetLimits(0.0,200);
  gmassZPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gmassZpPbRDsf = (TGraphAsymmErrors*)gmassZpPbRD->Clone("gmassZpPbRDsf");
  DivideGraphs(gmassZpPbRDsf,gmassZpPbMC);
  gmassZpPbRDsf->Draw("same P");
  TGraphAsymmErrors* gmassZppRDsf = (TGraphAsymmErrors*)gmassZppRD->Clone("gmassZppRDsf");
  DivideGraphs(gmassZppRDsf,gmassZppMC);
  gmassZppRDsf->Draw("same P");
  TLine *l4 = new TLine(0,1,200,1);
  l4->SetLineStyle(9);
  l4->Draw();


  setTDRStyle();
  writeExtraText = false;
  extraText = "Preliminary";

  TString label;
  label="";
  CMS_lumi(pad1a, 0 ,33);
  CMS_lumi(pad2a, 0 ,33);
  CMS_lumi(pad3a, 0 ,33);
  CMS_lumi(pad4a, 0 ,33);

  pad1a->Update();
  pad1b->Update();
  c1->cd();
  pad1a->Draw();
  pad1b->Draw();
  pad1a->Update();
  pad1b->Update();

  pad2a->Update();
  pad2b->Update();
  c2->cd();
  pad2a->Draw();
  pad2b->Draw();
  pad2a->Update();
  pad2b->Update();

  pad3a->Update();
  pad3b->Update();
  c3->cd();
  pad3a->Draw();
  pad3b->Draw();
  pad3a->Update();
  pad3b->Update();

  pad4a->Update();
  pad4b->Update();
  c4->cd();
  pad4a->Draw();
  pad4b->Draw();
  pad4a->Update();
  pad4b->Update();

  c1->cd();
  c1->SaveAs("FinalPlots/ptMassResJpsi.png");
  c1->SaveAs("FinalPlots/ptMassResJpsi.pdf");
  c2->cd();
  c2->SaveAs("FinalPlots/ptMassResZ.png");
  c2->SaveAs("FinalPlots/ptMassResZ.pdf");
  c3->cd();
  c3->SaveAs("FinalPlots/ptMassScaleJpsi.png");
  c3->SaveAs("FinalPlots/ptMassScaleJpsi.pdf");
  c4->cd();
  c4->SaveAs("FinalPlots/ptMassScaleZ.pdf");
  c4->SaveAs("FinalPlots/ptMassScaleZ.png");



  //Write everything to the output file
  cout << "Writing to File " << outFileName << endl;
  outFile->cd();
  c1->Write();
  c2->Write();
  c3->Write();
  c4->Write();
  outFile->Close();


  cout << "Here's what's left in memory:" << endl;
  gDirectory->ls("-m");

}
