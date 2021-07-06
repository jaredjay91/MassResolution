#include "HeaderFiles/tdrstyle.C"
#include "HeaderFiles/CMS_lumi.C"

void drawText(const char *text, float xp, float yp, int textColor=kBlack, int textSize=18, float textFont=43){
   TLatex *tex = new TLatex(xp,yp,text);
   tex->SetTextFont(textFont);
   //   if(bold)tex->SetTextFont(43);
   tex->SetTextSize(textSize);
   tex->SetTextColor(textColor);
   tex->SetLineWidth(1);
   tex->SetNDC();
   tex->Draw();
}

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
  gRD->GetXaxis()->SetTitleOffset(0.8) ;
  gRD->GetXaxis()->SetLabelOffset(0.04) ;
  gRD->GetXaxis()->SetLabelSize(0.16) ; //23
  gRD->GetXaxis()->SetTitleSize(0.18) ;  //28
  //gRD->GetXaxis()->CenterTitle();
  gRD->GetXaxis()->SetTickSize(0.03);
  gRD->GetXaxis()->SetLimits(10,3000);
  gRD->GetXaxis()->SetTitle("N_{tracks}");
}


void mergeGraphs() {

  float markerSize = 1.2;
  float ppmarkerSize = 1.6;
  gStyle->SetErrorX(0);//This doesn't do anything.

  cout << "Loading graphs from RD files..." << endl;
  TFile* fZPbPbRD = TFile::Open("Results/MassResZPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbRD = (TGraphAsymmErrors*)fZPbPbRD->Get("Graph_from_hmass");
  TFile* fZpPbRD = TFile::Open("Results/MassResZpPbRD.root","READ");
  TGraphAsymmErrors* gsigmaZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbRD = (TGraphAsymmErrors*)fZpPbRD->Get("Graph_from_hmass");
  TFile* fZppRD = TFile::Open("Results/MassResZppRD.root","READ");
  TGraphAsymmErrors* gsigmaZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppRD = (TGraphAsymmErrors*)fZppRD->Get("Graph_from_hmass");
  TFile* fJpsiPbPbRD = TFile::Open("Results/MassResJpsiPbPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbRD = (TGraphAsymmErrors*)fJpsiPbPbRD->Get("Graph_from_hmass");
  TFile* fJpsipPbRD = TFile::Open("Results/MassResJpsipPbRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbRD = (TGraphAsymmErrors*)fJpsipPbRD->Get("Graph_from_hmass");
  TFile* fJpsippRD = TFile::Open("Results/MassResJpsippRD.root","READ");
  TGraphAsymmErrors* gsigmaJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippRD = (TGraphAsymmErrors*)fJpsippRD->Get("Graph_from_hmass");

  cout << "Loading graphs from MC files..." << endl;
  TFile* fZPbPbMC = TFile::Open("Results/MassResZPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZPbPbMC = (TGraphAsymmErrors*)fZPbPbMC->Get("Graph_from_hmass");
  TFile* fZpPbMC = TFile::Open("Results/MassResZpPbMC.root","READ");
  TGraphAsymmErrors* gsigmaZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZpPbMC = (TGraphAsymmErrors*)fZpPbMC->Get("Graph_from_hmass");
  TFile* fZppMC = TFile::Open("Results/MassResZppMC.root","READ");
  TGraphAsymmErrors* gsigmaZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hsigma");
  TGraphAsymmErrors* gmassZppMC = (TGraphAsymmErrors*)fZppMC->Get("Graph_from_hmass");
  TFile* fJpsiPbPbMC = TFile::Open("Results/MassResJpsiPbPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsiPbPbMC = (TGraphAsymmErrors*)fJpsiPbPbMC->Get("Graph_from_hmass");
  TFile* fJpsipPbMC = TFile::Open("Results/MassResJpsipPbMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsipPbMC = (TGraphAsymmErrors*)fJpsipPbMC->Get("Graph_from_hmass");
  TFile* fJpsippMC = TFile::Open("Results/MassResJpsippMC.root","READ");
  TGraphAsymmErrors* gsigmaJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hsigmaC");
  TGraphAsymmErrors* gmassJpsippMC = (TGraphAsymmErrors*)fJpsippMC->Get("Graph_from_hmass");


  //Remove X error bars:
  removeXerrors(gsigmaZPbPbRD);
  removeXerrors(gsigmaZpPbRD);
  removeXerrors(gsigmaZppRD);
  cout << gsigmaJpsiPbPbRD->GetN() << endl;
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
  TString outFileName = "FinalPlots/MassResCombined.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");


  //********* Z BOSON MASS RESOLUTION ***********//
  cout << "Plotting Z boson mass resolution..." << endl;
  TCanvas* c1 = new TCanvas("c1","c1",0,0,500,500);
  c1->cd();

  TPad *pad1a = new TPad("pad1a", "pad1a", 0, 0.14, 0.98, 1.0);
  pad1a->SetTicks(1,1);
  pad1a->Draw(); pad1a->cd();
  pad1a->SetLogx();
  //c1->SetBottomMargin(0.04);
  //c1->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  gsigmaZPbPbRD->SetMinimum(0);
  gsigmaZPbPbRD->SetMaximum(0.02);
  gsigmaZPbPbRD->GetXaxis()->SetLimits(10,3000);
  gsigmaZPbPbRD->GetXaxis()->SetTitle("N_{tracks}");
  gsigmaZPbPbRD->SetTitle("");
  //gsigmaZPbPbRD->GetXaxis()->CenterTitle();
  //gsigmaZPbPbRD->GetXaxis()->SetLabelSize(0.05);
  //gsigmaZPbPbRD->GetXaxis()->SetTitleSize(0.05);
  //gsigmaZPbPbRD->GetXaxis()->SetTitleOffset(1.2);
  //gsigmaZPbPbRD->GetYaxis()->SetLabelSize(0.05);
  //gsigmaZPbPbRD->GetYaxis()->SetTitleSize(0.05);
  gsigmaZPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gsigmaZPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gsigmaZPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gsigmaZPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{CB}/m_{PDG})");
  gsigmaZPbPbRD->SetMarkerStyle(20);
  gsigmaZPbPbRD->SetMarkerColor(kRed);
  gsigmaZPbPbRD->SetMarkerSize(markerSize);
  gsigmaZPbPbRD->SetLineColor(kRed);
  gsigmaZPbPbRD->Draw("AP");
  gsigmaZpPbRD->SetMarkerStyle(21);
  gsigmaZpPbRD->SetMarkerColor(kBlue);
  gsigmaZpPbRD->SetMarkerSize(markerSize);
  gsigmaZpPbRD->SetLineColor(kBlue);
  gsigmaZpPbRD->Draw("same P");
  gsigmaZppRD->SetMarkerStyle(33);
  gsigmaZppRD->SetMarkerColor(kBlack);
  gsigmaZppRD->SetMarkerSize(ppmarkerSize);
  gsigmaZppRD->SetLineColor(kBlack);
  gsigmaZppRD->Draw("same P");
  gsigmaZPbPbMC->SetMarkerStyle(24);
  gsigmaZPbPbMC->SetMarkerColor(kRed);
  gsigmaZPbPbMC->SetMarkerSize(markerSize);
  gsigmaZPbPbMC->SetLineColor(kRed);
  gsigmaZPbPbMC->Draw("same P");
  gsigmaZpPbMC->SetMarkerStyle(25);
  gsigmaZpPbMC->SetMarkerColor(kBlue);
  gsigmaZpPbMC->SetMarkerSize(markerSize);
  gsigmaZpPbMC->SetLineColor(kBlue);
  gsigmaZpPbMC->Draw("same P");
  gsigmaZppMC->SetMarkerStyle(27);
  gsigmaZppMC->SetMarkerColor(kBlack);
  gsigmaZppMC->SetMarkerSize(ppmarkerSize);
  gsigmaZppMC->SetLineColor(kBlack);
  gsigmaZppMC->Draw("same P");

  TLegend* leg1 = new TLegend(0.17,0.15,0.45,0.45);
  leg1->SetTextSize(0.04);
  //leg1->SetTextFont(43);
  leg1->SetBorderSize(0);
  //leg1->SetHeader("Mass Res. at Z peak","C");
  leg1->AddEntry(gsigmaZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaZpPbRD,"pPb Data 8.16 TeV","pe");
  leg1->AddEntry(gsigmaZppRD,"pp Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1->AddEntry(gsigmaZpPbMC,"pPb MC 8.16 TeV","pe");
  leg1->AddEntry(gsigmaZppMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  //header1->SetTextAlign(32);
  //header1->SetTextSize(.06);
  leg1->Draw("same");

  float pos_text_x = 0.65;
  float pos_text_y = 0.28;
  float pos_y_diff = 0.06;
  float text_size = 16;
  float peak_text_size = 24;
  int text_color = 1;
  drawText("Z Peak", pos_text_x,pos_text_y,text_color,peak_text_size);
  drawText("15 < p_{T}^{#mu} < 200 GeV/c", pos_text_x,pos_text_y-pos_y_diff,text_color,text_size);
  drawText("|#eta^{#mu}| < 2.4", pos_text_x,pos_text_y-2*pos_y_diff,text_color,text_size);

  TPad *pad1b = new TPad("pad1b", "pad1b", 0, 0, 0.98, 0.2);
  pad1b->SetTopMargin(0); // Upper and lower plot are joined
  pad1b->SetBottomMargin(0.4);
  pad1a->SetLeftMargin(0.14);
  pad1a->SetRightMargin(0.02);
  pad1b->SetRightMargin(0.02);
  pad1b->SetLeftMargin(0.14);
  pad1b->SetTicks(1,1);
  pad1b->cd();
  pad1b->SetLogx();

  TGraphAsymmErrors* gsigmaZPbPbRDsf = (TGraphAsymmErrors*)gsigmaZPbPbRD->Clone("gsigmaZPbPbRDsf");
  DivideGraphs(gsigmaZPbPbRDsf,gsigmaZPbPbMC);
  gsigmaZPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gsigmaZPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gsigmaZPbPbRD->GetYaxis()->CenterTitle();
  gsigmaZPbPbRDsf->SetMinimum(0.75);
  gsigmaZPbPbRDsf->SetMaximum(1.25);
  gsigmaZPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gsigmaZpPbRDsf = (TGraphAsymmErrors*)gsigmaZpPbRD->Clone("gsigmaZpPbRDsf");
  DivideGraphs(gsigmaZpPbRDsf,gsigmaZpPbMC);
  gsigmaZpPbRDsf->Draw("same P");
  TGraphAsymmErrors* gsigmaZppRDsf = (TGraphAsymmErrors*)gsigmaZppRD->Clone("gsigmaZppRDsf");
  DivideGraphs(gsigmaZppRDsf,gsigmaZppMC);
  gsigmaZppRDsf->Draw("same P");
  TLine *l1 = new TLine(10,1,3000,1);
  l1->SetLineStyle(9);
  l1->Draw();


  //********* Z BOSON MASS SCALING ***********//
  cout << "Plotting Z boson mass scaling..." << endl;
  TCanvas* c2 = new TCanvas("c2","c2",0,0,500,500);
  c2->cd();

  TPad *pad2a = new TPad("pad2a", "pad2a", 0, 0.14, 0.98, 1.0);
  pad2a->SetTicks(1,1);
  pad2a->Draw(); pad2a->cd();
  pad2a->SetLogx();
  //c2->SetBottomMargin(0.04);
  //c2->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  gmassZPbPbRD->SetMinimum(0.985);
  gmassZPbPbRD->SetMaximum(1.005);
  gmassZPbPbRD->GetXaxis()->SetLimits(10,3000);
  gmassZPbPbRD->GetXaxis()->SetTitle("N_{tracks}");
  gmassZPbPbRD->SetTitle("Mass Scale at Z peak");
  gmassZPbPbRD->SetTitle("");
  //gmassZPbPbRD->GetXaxis()->CenterTitle();
  //gmassZPbPbRD->GetXaxis()->SetLabelSize(0.05);
  //gmassZPbPbRD->GetXaxis()->SetTitleSize(0.05);
  //gmassZPbPbRD->GetXaxis()->SetTitleOffset(1.2);
  //gmassZPbPbRD->GetYaxis()->SetLabelSize(0.05);
  //gmassZPbPbRD->GetYaxis()->SetTitleSize(0.05);
  gmassZPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gmassZPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gmassZPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gmassZPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
  gmassZPbPbRD->SetMarkerStyle(20);
  gmassZPbPbRD->SetMarkerColor(kRed);
  gmassZPbPbRD->SetMarkerSize(markerSize);
  gmassZPbPbRD->SetLineColor(kRed);
  gmassZPbPbRD->Draw("AP");
  gmassZpPbRD->SetMarkerStyle(21);
  gmassZpPbRD->SetMarkerColor(kBlue);
  gmassZpPbRD->SetMarkerSize(markerSize);
  gmassZpPbRD->SetLineColor(kBlue);
  gmassZpPbRD->Draw("same P");
  gmassZppRD->SetMarkerStyle(33);
  gmassZppRD->SetMarkerColor(kBlack);
  gmassZppRD->SetMarkerSize(ppmarkerSize);
  gmassZppRD->SetLineColor(kBlack);
  gmassZppRD->Draw("same P");
  gmassZPbPbMC->SetMarkerStyle(24);
  gmassZPbPbMC->SetMarkerColor(kRed);
  gmassZPbPbMC->SetMarkerSize(markerSize);
  gmassZPbPbMC->SetLineColor(kRed);
  gmassZPbPbMC->Draw("same P");
  gmassZpPbMC->SetMarkerStyle(25);
  gmassZpPbMC->SetMarkerColor(kBlue);
  gmassZpPbMC->SetMarkerSize(markerSize);
  gmassZpPbMC->SetLineColor(kBlue);
  gmassZpPbMC->Draw("same P");
  gmassZppMC->SetMarkerStyle(27);
  gmassZppMC->SetMarkerColor(kBlack);
  gmassZppMC->SetMarkerSize(ppmarkerSize);
  gmassZppMC->SetLineColor(kBlack);
  gmassZppMC->Draw("same P");

  TLegend* leg2 = new TLegend(0.17,0.15,0.45,0.45);
  leg2->SetTextSize(0.04);
  //leg2->SetTextFont(43);
  leg2->SetBorderSize(0);
  //leg2->SetHeader("Mass Scale at Z peak","C");
  leg2->AddEntry(gmassZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg2->AddEntry(gmassZpPbRD,"pPb Data 8.16 TeV","pe");
  leg2->AddEntry(gmassZppRD,"pp Data 5.02 TeV","pe");
  leg2->AddEntry(gmassZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg2->AddEntry(gmassZpPbMC,"pPb MC 8.16 TeV","pe");
  leg2->AddEntry(gmassZppMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header2 = (TLegendEntry*)leg2->GetListOfPrimitives()->First();
  //header2->SetTextAlign(32);
  //header2->SetTextSize(.06);
  leg2->Draw("same");

  drawText("Z Peak", pos_text_x,pos_text_y,text_color,peak_text_size);
  drawText("15 < p_{T}^{#mu} < 200 GeV/c", pos_text_x,pos_text_y-pos_y_diff,text_color,text_size);
  drawText("|#eta^{#mu}| < 2.4", pos_text_x,pos_text_y-2*pos_y_diff,text_color,text_size);

  TLine* l2a = new TLine(0,1,3000,1);
  l2a->SetLineColor(kBlack);
  l2a->SetLineStyle(2);
  l2a->Draw("same");

  TPad *pad2b = new TPad("pad2b", "pad2b", 0, 0, 0.98, 0.2);
  pad2b->SetTopMargin(0); // Upper and lower plot are joined
  pad2b->SetBottomMargin(0.4);
  pad2a->SetLeftMargin(0.14);
  pad2a->SetRightMargin(0.02);
  pad2b->SetRightMargin(0.02);
  pad2b->SetLeftMargin(0.14);
  pad2b->SetTicks(1,1);
  pad2b->cd();
  pad2b->SetLogx();

  TGraphAsymmErrors* gmassZPbPbRDsf = (TGraphAsymmErrors*)gmassZPbPbRD->Clone("gmassZPbPbRDsf");
  DivideGraphs(gmassZPbPbRDsf,gmassZPbPbMC);
  gmassZPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gmassZPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gmassZPbPbRD->GetYaxis()->CenterTitle();
  gmassZPbPbRDsf->SetMinimum(0.9965);
  gmassZPbPbRDsf->SetMaximum(1.0035);
  gmassZPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gmassZpPbRDsf = (TGraphAsymmErrors*)gmassZpPbRD->Clone("gmassZpPbRDsf");
  DivideGraphs(gmassZpPbRDsf,gmassZpPbMC);
  gmassZpPbRDsf->Draw("same P");
  TGraphAsymmErrors* gmassZppRDsf = (TGraphAsymmErrors*)gmassZppRD->Clone("gmassZppRDsf");
  DivideGraphs(gmassZppRDsf,gmassZppMC);
  gmassZppRDsf->Draw("same P");
  TLine *l2 = new TLine(10,1,3000,1);
  l2->SetLineStyle(9);
  l2->Draw();


  //********* J/PSI MASS RESOLUTION ***********//
  cout << "Plotting J/psi mass resolution..." << endl;
  TCanvas* c3 = new TCanvas("c3","c3",0,0,500,500);
  c3->cd();

  TPad *pad3a = new TPad("pad3a", "pad3a", 0, 0.14, 0.98, 1.0);
  pad3a->SetTicks(1,1);
  pad3a->Draw(); pad3a->cd();
  pad3a->SetLogx();
  //c3->SetBottomMargin(0.04);
  //c3->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  gsigmaJpsiPbPbRD->SetMinimum(0);
  gsigmaJpsiPbPbRD->SetMaximum(0.02);
  gsigmaJpsiPbPbRD->GetXaxis()->SetLimits(10,3000);
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitle("N_{tracks}");
  gsigmaJpsiPbPbRD->SetTitle("Mass Resolution at J/#psi peak");
  gsigmaJpsiPbPbRD->SetTitle("");
  //gsigmaJpsiPbPbRD->GetXaxis()->CenterTitle();
  //gsigmaJpsiPbPbRD->GetXaxis()->SetLabelSize(0.05);
  //gsigmaJpsiPbPbRD->GetXaxis()->SetTitleSize(0.05);
  //gsigmaJpsiPbPbRD->GetXaxis()->SetTitleOffset(1.2);
  //gsigmaJpsiPbPbRD->GetYaxis()->SetLabelSize(0.05);
  //gsigmaJpsiPbPbRD->GetYaxis()->SetTitleSize(0.05);
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gsigmaJpsiPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG})");
  gsigmaJpsiPbPbRD->SetMarkerStyle(20);
  gsigmaJpsiPbPbRD->SetMarkerColor(kRed);
  gsigmaJpsiPbPbRD->SetMarkerSize(markerSize);
  gsigmaJpsiPbPbRD->SetLineColor(kRed);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsipPbRD->SetMarkerStyle(21);
  gsigmaJpsipPbRD->SetMarkerColor(kBlue);
  gsigmaJpsipPbRD->SetMarkerSize(markerSize);
  gsigmaJpsipPbRD->SetLineColor(kBlue);
  gsigmaJpsipPbRD->Draw("same P");
  gsigmaJpsippRD->SetMarkerStyle(33);
  gsigmaJpsippRD->SetMarkerColor(kBlack);
  gsigmaJpsippRD->SetMarkerSize(ppmarkerSize);
  gsigmaJpsippRD->SetLineColor(kBlack);
  gsigmaJpsippRD->Draw("same P");
  gsigmaJpsiPbPbMC->SetMarkerStyle(24);
  gsigmaJpsiPbPbMC->SetMarkerColor(kRed);
  gsigmaJpsiPbPbMC->SetMarkerSize(markerSize);
  gsigmaJpsiPbPbMC->SetLineColor(kRed);
  gsigmaJpsiPbPbMC->Draw("same P");
  gsigmaJpsipPbMC->SetMarkerStyle(25);
  gsigmaJpsipPbMC->SetMarkerColor(kBlue);
  gsigmaJpsipPbMC->SetMarkerSize(markerSize);
  gsigmaJpsipPbMC->SetLineColor(kBlue);
  gsigmaJpsipPbMC->Draw("same P");
  gsigmaJpsippMC->SetMarkerStyle(27);
  gsigmaJpsippMC->SetMarkerColor(kBlack);
  gsigmaJpsippMC->SetMarkerSize(ppmarkerSize);
  gsigmaJpsippMC->SetLineColor(kBlack);
  gsigmaJpsippMC->Draw("same P");

  TLegend* leg3 = new TLegend(0.17,0.15,0.45,0.45);
  leg3->SetTextSize(0.04);
  //leg3->SetTextFont(43);
  leg3->SetBorderSize(0);
  //leg3->SetHeader("Mass Res. at J/#psi peak","C");
  leg3->AddEntry(gsigmaJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg3->AddEntry(gsigmaJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg3->AddEntry(gsigmaJpsippRD,"pp Data 5.02 TeV","pe");
  leg3->AddEntry(gsigmaJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg3->AddEntry(gsigmaJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg3->AddEntry(gsigmaJpsippMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header3 = (TLegendEntry*)leg3->GetListOfPrimitives()->First();
  //header3->SetTextAlign(32);
  //header3->SetTextSize(.06);
  leg3->Draw("same");

  drawText("J/#psi Peak", pos_text_x,pos_text_y,text_color,peak_text_size);
  drawText("3.5 < p_{T}^{#mu} < 30 GeV/c", pos_text_x,pos_text_y-pos_y_diff,text_color,text_size);
  drawText("|#eta^{#mu}| < 2.4", pos_text_x,pos_text_y-2*pos_y_diff,text_color,text_size);

  TPad *pad3b = new TPad("pad3b", "pad3b", 0, 0, 0.98, 0.2);
  pad3b->SetTopMargin(0); // Upper and lower plot are joined
  pad3b->SetBottomMargin(0.4);
  pad3a->SetLeftMargin(0.14);
  pad3a->SetRightMargin(0.02);
  pad3b->SetRightMargin(0.02);
  pad3b->SetLeftMargin(0.14);
  pad3b->SetTicks(1,1);
  pad3b->cd();
  pad3b->SetLogx();

  TGraphAsymmErrors* gsigmaJpsiPbPbRDsf = (TGraphAsymmErrors*)gsigmaJpsiPbPbRD->Clone("gsigmaJpsiPbPbRDsf");
  DivideGraphs(gsigmaJpsiPbPbRDsf,gsigmaJpsiPbPbMC);
  gsigmaJpsiPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gsigmaJpsiPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gsigmaJpsiPbPbRD->GetYaxis()->CenterTitle();
  gsigmaJpsiPbPbRDsf->SetMinimum(0.75);
  gsigmaJpsiPbPbRDsf->SetMaximum(1.25);
  gsigmaJpsiPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gsigmaJpsipPbRDsf = (TGraphAsymmErrors*)gsigmaJpsipPbRD->Clone("gsigmaJpsipPbRDsf");
  DivideGraphs(gsigmaJpsipPbRDsf,gsigmaJpsipPbMC);
  gsigmaJpsipPbRDsf->Draw("same P");
  TGraphAsymmErrors* gsigmaJpsippRDsf = (TGraphAsymmErrors*)gsigmaJpsippRD->Clone("gsigmaJpsippRDsf");
  DivideGraphs(gsigmaJpsippRDsf,gsigmaJpsippMC);
  gsigmaJpsippRDsf->Draw("same P");
  TLine *l3 = new TLine(10,1,3000,1);
  l3->SetLineStyle(9);
  l3->Draw();


  //********* J/PSI MASS SCALING ***********//
  cout << "Plotting J/psi mass scaling..." << endl;
  TCanvas* c4 = new TCanvas("c4","c4",0,0,500,500);
  c4->cd();

  TPad *pad4a = new TPad("pad4a", "pad4a", 0, 0.14, 0.98, 1.0);
  pad4a->SetTicks(1,1);
  pad4a->Draw(); pad4a->cd();
  pad4a->SetLogx();
  //c4->SetBottomMargin(0.04);
  //c4->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  gmassJpsiPbPbRD->SetMinimum(0.985);
  gmassJpsiPbPbRD->SetMaximum(1.005);
  gmassJpsiPbPbRD->GetXaxis()->SetLimits(10,3000);
  gmassJpsiPbPbRD->GetXaxis()->SetTitle("N_{tracks}");
  gmassJpsiPbPbRD->SetTitle("Mass Scale at J/#psi peak");
  gmassJpsiPbPbRD->SetTitle("");
  //gmassJpsiPbPbRD->GetXaxis()->CenterTitle();
  //gmassJpsiPbPbRD->GetXaxis()->SetLabelSize(0.05);
  //gmassJpsiPbPbRD->GetXaxis()->SetTitleSize(0.05);
  //gmassJpsiPbPbRD->GetXaxis()->SetTitleOffset(1.2);
  //gmassJpsiPbPbRD->GetYaxis()->SetLabelSize(0.05);
  //gmassJpsiPbPbRD->GetYaxis()->SetTitleSize(0.05);
  gmassJpsiPbPbRD->GetYaxis()->SetTitleOffset(1.7);
  gmassJpsiPbPbRD->GetYaxis()->SetTitleSize(0.04);
  gmassJpsiPbPbRD->GetYaxis()->SetLabelSize(0.04);
  gmassJpsiPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG})");
  gmassJpsiPbPbRD->SetMarkerStyle(20);
  gmassJpsiPbPbRD->SetMarkerColor(kRed);
  gmassJpsiPbPbRD->SetMarkerSize(markerSize);
  gmassJpsiPbPbRD->SetLineColor(kRed);
  gmassJpsiPbPbRD->Draw("AP");
  gmassJpsipPbRD->SetMarkerStyle(21);
  gmassJpsipPbRD->SetMarkerColor(kBlue);
  gmassJpsipPbRD->SetMarkerSize(markerSize);
  gmassJpsipPbRD->SetLineColor(kBlue);
  gmassJpsipPbRD->Draw("same P");
  gmassJpsippRD->SetMarkerStyle(33);
  gmassJpsippRD->SetMarkerColor(kBlack);
  gmassJpsippRD->SetMarkerSize(ppmarkerSize);
  gmassJpsippRD->SetLineColor(kBlack);
  gmassJpsippRD->Draw("same P");
  gmassJpsiPbPbMC->SetMarkerStyle(24);
  gmassJpsiPbPbMC->SetMarkerColor(kRed);
  gmassJpsiPbPbMC->SetMarkerSize(markerSize);
  gmassJpsiPbPbMC->SetLineColor(kRed);
  gmassJpsiPbPbMC->Draw("same P");
  gmassJpsipPbMC->SetMarkerStyle(25);
  gmassJpsipPbMC->SetMarkerColor(kBlue);
  gmassJpsipPbMC->SetMarkerSize(markerSize);
  gmassJpsipPbMC->SetLineColor(kBlue);
  gmassJpsipPbMC->Draw("same P");
  gmassJpsippMC->SetMarkerStyle(27);
  gmassJpsippMC->SetMarkerColor(kBlack);
  gmassJpsippMC->SetMarkerSize(ppmarkerSize);
  gmassJpsippMC->SetLineColor(kBlack);
  gmassJpsippMC->Draw("same P");

  TLegend* leg4 = new TLegend(0.17,0.15,0.45,0.45);
  leg4->SetTextSize(0.04);
  //leg4->SetTextFont(43);
  leg4->SetBorderSize(0);
  //leg4->SetHeader("Mass Scale at J/#psi peak","C");
  leg4->AddEntry(gmassJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg4->AddEntry(gmassJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg4->AddEntry(gmassJpsippRD,"pp Data 5.02 TeV","pe");
  leg4->AddEntry(gmassJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg4->AddEntry(gmassJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg4->AddEntry(gmassJpsippMC,"pp MC 5.02 TeV","pe");
  //TLegendEntry *header4 = (TLegendEntry*)leg4->GetListOfPrimitives()->First();
  //header4->SetTextAlign(32);
  //header4->SetTextSize(.06);
  leg4->Draw("same");

  drawText("J/#psi Peak", pos_text_x,pos_text_y,text_color,peak_text_size);
  drawText("3.5 < p_{T}^{#mu} < 30 GeV/c", pos_text_x,pos_text_y-pos_y_diff,text_color,text_size);
  drawText("|#eta^{#mu}| < 2.4", pos_text_x,pos_text_y-2*pos_y_diff,text_color,text_size);

  TLine* l4a = new TLine(0,1,3000,1);
  l4a->SetLineColor(kBlack);
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
  pad4b->SetLogx();

  TGraphAsymmErrors* gmassJpsiPbPbRDsf = (TGraphAsymmErrors*)gmassJpsiPbPbRD->Clone("gmassJpsiPbPbRDsf");
  DivideGraphs(gmassJpsiPbPbRDsf,gmassJpsiPbPbMC);
  gmassJpsiPbPbRD->GetXaxis()->SetLabelSize(0) ; //23
  gmassJpsiPbPbRD->GetXaxis()->SetTitleSize(0) ;  //28
  gmassJpsiPbPbRD->GetYaxis()->CenterTitle();
  gmassJpsiPbPbRDsf->SetMinimum(0.9965);
  gmassJpsiPbPbRDsf->SetMaximum(1.0035);
  gmassJpsiPbPbRDsf->Draw("AP");
  TGraphAsymmErrors* gmassJpsipPbRDsf = (TGraphAsymmErrors*)gmassJpsipPbRD->Clone("gmassJpsipPbRDsf");
  DivideGraphs(gmassJpsipPbRDsf,gmassJpsipPbMC);
  gmassJpsipPbRDsf->Draw("same P");
  TGraphAsymmErrors* gmassJpsippRDsf = (TGraphAsymmErrors*)gmassJpsippRD->Clone("gmassJpsippRDsf");
  DivideGraphs(gmassJpsippRDsf,gmassJpsippMC);
  gmassJpsippRDsf->Draw("same P");
  TLine *l4 = new TLine(10,1,3000,1);
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
  c1->SaveAs("FinalPlots/MassResZ.png");
  c1->SaveAs("FinalPlots/MassResZ.pdf");
  c2->cd();
  c2->SaveAs("FinalPlots/MassScaleZ.png");
  c2->SaveAs("FinalPlots/MassScaleZ.pdf");
  c3->cd();
  c3->SaveAs("FinalPlots/MassResJpsi.png");
  c3->SaveAs("FinalPlots/MassResJpsi.pdf");
  c4->cd();
  c4->SaveAs("FinalPlots/MassScaleJpsi.png");
  c4->SaveAs("FinalPlots/MassScaleJpsi.pdf");


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
