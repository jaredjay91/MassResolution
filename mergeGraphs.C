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

void mergeGraphs() {

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
  TCanvas* c1 = new TCanvas("c1","c1",0,0,600,450);
  c1->cd();
  //c1->SetBottomMargin(0.04);
  //c1->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  c1->SetLogx();
  gsigmaZPbPbRD->SetMinimum(0);
  gsigmaZPbPbRD->SetMaximum(0.02);
  gsigmaZPbPbRD->GetXaxis()->SetLimits(10,3000);
  gsigmaZPbPbRD->GetXaxis()->SetTitle("N_{tracks}");
  gsigmaZPbPbRD->SetTitle("Mass Resolution at Z peak");
  gsigmaZPbPbRD->SetTitle("");
  //gsigmaZPbPbRD->GetXaxis()->CenterTitle();
  //gsigmaZPbPbRD->GetXaxis()->SetLabelSize(0.05);
  //gsigmaZPbPbRD->GetXaxis()->SetTitleSize(0.05);
  //gsigmaZPbPbRD->GetXaxis()->SetTitleOffset(1.2);
  //gsigmaZPbPbRD->GetYaxis()->SetLabelSize(0.05);
  //gsigmaZPbPbRD->GetYaxis()->SetTitleSize(0.05);
  gsigmaZPbPbRD->GetYaxis()->SetTitleOffset(1.5);
  gsigmaZPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{CB}/m_{PDG}) at Z peak");
  gsigmaZPbPbRD->SetMarkerStyle(20);
  gsigmaZPbPbRD->SetMarkerColor(kRed);
  gsigmaZPbPbRD->SetLineColor(kRed);
  gsigmaZPbPbRD->Draw("AP");
  gsigmaZpPbRD->SetMarkerStyle(21);
  gsigmaZpPbRD->SetMarkerColor(kBlue);
  gsigmaZpPbRD->SetLineColor(kBlue);
  gsigmaZpPbRD->Draw("same P");
  gsigmaZppRD->SetMarkerStyle(33);
  gsigmaZppRD->SetMarkerColor(kBlack);
  gsigmaZppRD->SetLineColor(kBlack);
  gsigmaZppRD->Draw("same P");
  gsigmaZPbPbMC->SetMarkerStyle(24);
  gsigmaZPbPbMC->SetMarkerColor(kRed);
  gsigmaZPbPbMC->SetLineColor(kRed);
  gsigmaZPbPbMC->Draw("same P");
  gsigmaZpPbMC->SetMarkerStyle(25);
  gsigmaZpPbMC->SetMarkerColor(kBlue);
  gsigmaZpPbMC->SetLineColor(kBlue);
  gsigmaZpPbMC->Draw("same P");
  gsigmaZppMC->SetMarkerStyle(27);
  gsigmaZppMC->SetMarkerColor(kBlack);
  gsigmaZppMC->SetLineColor(kBlack);
  gsigmaZppMC->Draw("same P");

  TLegend* leg1 = new TLegend(0.55,0.15,0.89,0.45);
  leg1->SetTextSize(0.04);
  //leg1->SetTextFont(43);
  leg1->SetBorderSize(0);
  leg1->SetHeader("Mass Res. at Z peak","C");
  leg1->AddEntry(gsigmaZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaZpPbRD,"pPb Data 8.16 TeV","pe");
  leg1->AddEntry(gsigmaZppRD,"pp Data 5.02 TeV","pe");
  leg1->AddEntry(gsigmaZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg1->AddEntry(gsigmaZpPbMC,"pPb MC 8.16 TeV","pe");
  leg1->AddEntry(gsigmaZppMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header1 = (TLegendEntry*)leg1->GetListOfPrimitives()->First();
  header1->SetTextAlign(32);
  //header1->SetTextColor(2);
  header1->SetTextSize(.06);
  leg1->Draw("same");


  //********* Z BOSON MASS SCALING ***********//
  cout << "Plotting Z boson mass scaling..." << endl;
  TCanvas* c2 = new TCanvas("c2","c2",0,0,600,450);
  c2->cd();
  //c2->SetBottomMargin(0.04);
  //c2->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  c2->SetLogx();
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
  gmassZPbPbRD->GetYaxis()->SetTitleOffset(1.5);
  gmassZPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at Z peak");
  gmassZPbPbRD->SetMarkerStyle(20);
  gmassZPbPbRD->SetMarkerColor(kRed);
  gmassZPbPbRD->SetLineColor(kRed);
  gmassZPbPbRD->Draw("AP");
  gmassZpPbRD->SetMarkerStyle(21);
  gmassZpPbRD->SetMarkerColor(kBlue);
  gmassZpPbRD->SetLineColor(kBlue);
  gmassZpPbRD->Draw("same P");
  gmassZppRD->SetMarkerStyle(33);
  gmassZppRD->SetMarkerColor(kBlack);
  gmassZppRD->SetLineColor(kBlack);
  gmassZppRD->Draw("same P");
  gmassZPbPbMC->SetMarkerStyle(24);
  gmassZPbPbMC->SetMarkerColor(kRed);
  gmassZPbPbMC->SetLineColor(kRed);
  gmassZPbPbMC->Draw("same P");
  gmassZpPbMC->SetMarkerStyle(25);
  gmassZpPbMC->SetMarkerColor(kBlue);
  gmassZpPbMC->SetLineColor(kBlue);
  gmassZpPbMC->Draw("same P");
  gmassZppMC->SetMarkerStyle(27);
  gmassZppMC->SetMarkerColor(kBlack);
  gmassZppMC->SetLineColor(kBlack);
  gmassZppMC->Draw("same P");

  TLegend* leg2 = new TLegend(0.55,0.15,0.89,0.45);
  leg2->SetTextSize(0.04);
  //leg2->SetTextFont(43);
  leg2->SetBorderSize(0);
  leg2->SetHeader("Mass Scale at Z peak","C");
  leg2->AddEntry(gmassZPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg2->AddEntry(gmassZpPbRD,"pPb Data 8.16 TeV","pe");
  leg2->AddEntry(gmassZppRD,"pp Data 5.02 TeV","pe");
  leg2->AddEntry(gmassZPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg2->AddEntry(gmassZpPbMC,"pPb MC 8.16 TeV","pe");
  leg2->AddEntry(gmassZppMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header2 = (TLegendEntry*)leg2->GetListOfPrimitives()->First();
  header2->SetTextAlign(32);
  //header2->SetTextColor(2);
  header2->SetTextSize(.06);
  leg2->Draw("same");

  TLine* l2 = new TLine(0,1,3000,1);
  l2->SetLineColor(kRed);
  l2->SetLineStyle(2);
  l2->Draw("same");


  //********* J/PSI MASS RESOLUTION ***********//
  cout << "Plotting J/psi mass resolution..." << endl;
  TCanvas* c3 = new TCanvas("c3","c3",0,0,600,450);
  c3->cd();
  //c3->SetBottomMargin(0.04);
  //c3->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  c3->SetLogx();
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
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitleOffset(1.5);
  gsigmaJpsiPbPbRD->GetYaxis()->SetTitle("Mass Resolution (#sigma_{avg}/m_{PDG}) at J/#psi peak");
  gsigmaJpsiPbPbRD->SetMarkerStyle(20);
  gsigmaJpsiPbPbRD->SetMarkerColor(kRed);
  gsigmaJpsiPbPbRD->SetLineColor(kRed);
  gsigmaJpsiPbPbRD->Draw("AP");
  gsigmaJpsipPbRD->SetMarkerStyle(21);
  gsigmaJpsipPbRD->SetMarkerColor(kBlue);
  gsigmaJpsipPbRD->SetLineColor(kBlue);
  gsigmaJpsipPbRD->Draw("same P");
  gsigmaJpsippRD->SetMarkerStyle(33);
  gsigmaJpsippRD->SetMarkerColor(kBlack);
  gsigmaJpsippRD->SetLineColor(kBlack);
  gsigmaJpsippRD->Draw("same P");
  gsigmaJpsiPbPbMC->SetMarkerStyle(24);
  gsigmaJpsiPbPbMC->SetMarkerColor(kRed);
  gsigmaJpsiPbPbMC->SetLineColor(kRed);
  gsigmaJpsiPbPbMC->Draw("same P");
  gsigmaJpsipPbMC->SetMarkerStyle(25);
  gsigmaJpsipPbMC->SetMarkerColor(kBlue);
  gsigmaJpsipPbMC->SetLineColor(kBlue);
  gsigmaJpsipPbMC->Draw("same P");
  gsigmaJpsippMC->SetMarkerStyle(27);
  gsigmaJpsippMC->SetMarkerColor(kBlack);
  gsigmaJpsippMC->SetLineColor(kBlack);
  gsigmaJpsippMC->Draw("same P");

  TLegend* leg3 = new TLegend(0.55,0.15,0.89,0.45);
  leg3->SetTextSize(0.04);
  //leg3->SetTextFont(43);
  leg3->SetBorderSize(0);
  leg3->SetHeader("Mass Res. at J/#psi peak","C");
  leg3->AddEntry(gsigmaJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg3->AddEntry(gsigmaJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg3->AddEntry(gsigmaJpsippRD,"pp Data 5.02 TeV","pe");
  leg3->AddEntry(gsigmaJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg3->AddEntry(gsigmaJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg3->AddEntry(gsigmaJpsippMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header3 = (TLegendEntry*)leg3->GetListOfPrimitives()->First();
  header3->SetTextAlign(32);
  //header3->SetTextColor(2);
  header3->SetTextSize(.06);
  leg3->Draw("same");


  //********* J/PSI MASS SCALING ***********//
  cout << "Plotting J/psi mass scaling..." << endl;
  TCanvas* c4 = new TCanvas("c4","c4",0,0,600,450);
  c4->cd();
  //c4->SetBottomMargin(0.04);
  //c4->SetTopMargin(gStyle->GetPadTopMargin() / 0.7);
  c4->SetLogx();
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
  gmassJpsiPbPbRD->GetYaxis()->SetTitleOffset(1.5);
  gmassJpsiPbPbRD->GetYaxis()->SetTitle("Mass Scale (m_{Fit}/m_{PDG}) at J/#psi peak");
  gmassJpsiPbPbRD->SetMarkerStyle(20);
  gmassJpsiPbPbRD->SetMarkerColor(kRed);
  gmassJpsiPbPbRD->SetLineColor(kRed);
  gmassJpsiPbPbRD->Draw("AP");
  gmassJpsipPbRD->SetMarkerStyle(21);
  gmassJpsipPbRD->SetMarkerColor(kBlue);
  gmassJpsipPbRD->SetLineColor(kBlue);
  gmassJpsipPbRD->Draw("same P");
  gmassJpsippRD->SetMarkerStyle(33);
  gmassJpsippRD->SetMarkerColor(kBlack);
  gmassJpsippRD->SetLineColor(kBlack);
  gmassJpsippRD->Draw("same P");
  gmassJpsiPbPbMC->SetMarkerStyle(24);
  gmassJpsiPbPbMC->SetMarkerColor(kRed);
  gmassJpsiPbPbMC->SetLineColor(kRed);
  gmassJpsiPbPbMC->Draw("same P");
  gmassJpsipPbMC->SetMarkerStyle(25);
  gmassJpsipPbMC->SetMarkerColor(kBlue);
  gmassJpsipPbMC->SetLineColor(kBlue);
  gmassJpsipPbMC->Draw("same P");
  gmassJpsippMC->SetMarkerStyle(27);
  gmassJpsippMC->SetMarkerColor(kBlack);
  gmassJpsippMC->SetLineColor(kBlack);
  gmassJpsippMC->Draw("same P");

  TLegend* leg4 = new TLegend(0.55,0.15,0.89,0.45);
  leg4->SetTextSize(0.04);
  //leg4->SetTextFont(43);
  leg4->SetBorderSize(0);
  leg4->SetHeader("Mass Scale at J/#psi peak","C");
  leg4->AddEntry(gmassJpsiPbPbRD,"PbPb Data 5.02 TeV","pe");
  leg4->AddEntry(gmassJpsipPbRD,"pPb Data 8.16 TeV","pe");
  leg4->AddEntry(gmassJpsippRD,"pp Data 5.02 TeV","pe");
  leg4->AddEntry(gmassJpsiPbPbMC,"PbPb MC 5.02 TeV","pe");
  leg4->AddEntry(gmassJpsipPbMC,"pPb MC 8.16 TeV","pe");
  leg4->AddEntry(gmassJpsippMC,"pp MC 5.02 TeV","pe");
  TLegendEntry *header4 = (TLegendEntry*)leg4->GetListOfPrimitives()->First();
  header4->SetTextAlign(32);
  //header4->SetTextColor(2);
  header4->SetTextSize(.06);
  leg4->Draw("same");

  TLine* l4 = new TLine(0,1,3000,1);
  l4->SetLineColor(kRed);
  l4->SetLineStyle(2);
  l4->Draw("same");

  setTDRStyle();
  writeExtraText = false;
  extraText = "Preliminary";

  TString label;
  label="";
  CMS_lumi(c1, 0 ,33);
  CMS_lumi(c2, 0 ,33);
  CMS_lumi(c3, 0 ,33);
  CMS_lumi(c4, 0 ,33);

  c1->cd();
  c1->Update();
  c2->cd();
  c2->Update();
  c3->cd();
  c3->Update();
  c4->cd();
  c4->Update();

  c1->cd();
  c1->SaveAs("FinalPlots/MassResZ.pdf");
  c1->SaveAs("FinalPlots/MassResZ.png");
  c2->cd();
  c2->SaveAs("FinalPlots/MassScaleZ.pdf");
  c2->SaveAs("FinalPlots/MassScaleZ.png");
  c3->cd();
  c3->SaveAs("FinalPlots/MassResJpsi.pdf");
  c3->SaveAs("FinalPlots/MassResJpsi.png");
  c4->cd();
  c4->SaveAs("FinalPlots/MassScaleJpsi.pdf");
  c4->SaveAs("FinalPlots/MassScaleJpsi.png");


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
