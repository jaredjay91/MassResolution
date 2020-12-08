


void getWidthsOftnpFits_ptpPbZ(TString RDorMC="MC") {

  gStyle->SetOptStat(0);
  const static int numParams = 2;
  //double ptbins[6] = {15,20,30,50,80,200};//abseta_21_24
  double ptbins[8] = {15,20,30,40,50,75,100,200};
  const static int numbins = sizeof(ptbins)/sizeof(double)-1;

  TH1D* hsigma = new TH1D("hsigma","hsigma",numbins,ptbins);
  TH1D* hmass = new TH1D("hmass","hmass",numbins,ptbins);

  TString filename = Form("pPbZ/tnp_Ana_%s_L3Mu12_MuId_pPb_0_paper_FixedBWn.root",RDorMC.Data());
  TFile* f1 = TFile::Open(filename,"READ");

  cout << "starting loop" << endl;
   for (int i=0; i<numbins; i++) {
     //Change this to match whatever is in the file you're using.
     //RooFitResult* fitRes = (RooFitResult*)f1->Get(Form("tpTree/MuId_centdep/eta_bin0__pt_bin0__tag_hiNtracks_bin%i__TightId_true__BWFixedResCBExp/fitresults;1",i));
     RooFitResult* fitRes = (RooFitResult*)f1->Get(Form("tpTree/MuId_pt/eta_bin0__pt_bin%i__TightId_true__BWFixedResCBExp/fitresults;1",i));

      //fitRes->Print("v");

      //sigma
      RooRealVar* sigma_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("sigma");
      double sigmaval = sigma_fitRes->getVal();
      double sigmaerr = sigma_fitRes->getError();

      cout << "sigma" << " = " << sigmaval << " +/- " << sigmaerr << " (" << abs(sigmaerr/sigmaval)*100 << "%)" << endl;

      hsigma->SetBinContent(i+1,sigmaval);
      hsigma->SetBinError(i+1,sigmaerr);

      //mean
      RooRealVar* mean_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("m0");
      double meanval = mean_fitRes->getVal();
      double meanerr = mean_fitRes->getError();

      cout << "mean" << " = " << meanval << " +/- " << meanerr << " (" << abs(meanerr/meanval)*100 << "%)" << endl;

      hmass->SetBinContent(i+1,meanval);
      hmass->SetBinError(i+1,meanerr);

    delete fitRes;
  }

  TCanvas* c1 = new TCanvas("c1","c1",0,0,400,400);
  c1->cd();
  hsigma->Scale(1/91.1876);//Divide by mass of Z boson.
  hsigma->SetTitle("Mass Res. at Z peak (pPb 8.16 TeV)");
  hsigma->SetMinimum(0);
  hsigma->SetMaximum(0.03);
  hsigma->GetXaxis()->SetTitle("p_{T} (|#eta|<2.4)");
  hsigma->Draw();

  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  leg->SetTextSize(19);
  leg->SetTextFont(43);
  //leg->SetBorderSize(0);
  leg->AddEntry(hsigma,"#sigma_{cb}/m_{Z}","pel");
  //leg->AddEntry(hsigma2Pass,"sigma gaussian","pel");
  //leg->AddEntry(hsigmaC,"sigma combined","pel");
  leg->Draw("same");

  c1->SaveAs(Form("ptMassResZpPb%s.pdf",RDorMC.Data()));

  TCanvas* c2 = new TCanvas("c2","c2",400,0,400,400);
  c2->cd();
  hmass->Scale(1/91.1876);//Divide by mass of Z boson.
  hmass->SetTitle("Mass Scale at Z peak (pPb 8.16 TeV)");
  hmass->SetMinimum(0.99);
  hmass->SetMaximum(1.01);
  hmass->GetXaxis()->SetTitle("p_{T} (|#eta|<2.4)");
  hmass->Draw();
  TLine* l1 = new TLine(15,1,200,1);
  l1->SetLineColor(kRed);
  l1->SetLineStyle(2);
  l1->Draw("same");

  TLegend* leg2 = new TLegend(0.7,0.8,0.9,0.9);
  leg2->SetTextSize(19);
  leg2->SetTextFont(43);
  //leg2->SetBorderSize(0);
  leg2->AddEntry(hmass,"#mu/m_{Z}","pel");
  leg2->Draw("same");

  c2->SaveAs(Form("ptMassScaleZpPb%s.pdf",RDorMC.Data()));

  //Set up the output tree.
  TString outFileName = Form("ptMassResZpPb%s.root",RDorMC.Data());
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

  //Make TGraphAsymmErrors:
  TGraphAsymmErrors* gsigma = new TGraphAsymmErrors(hsigma);

  TCanvas* c3 = new TCanvas("c3","c3",0,0,400,400);
  c3->cd();
  gsigma->SetMinimum(0);
  gsigma->Draw("AP");

  TGraphAsymmErrors* gmass = new TGraphAsymmErrors(hmass);
  TCanvas* c4 = new TCanvas("c4","c4",0,0,400,400);
  c4->cd();
  //gmass->SetMinimum(0);
  gmass->Draw("AP");

  //Write everything to the output file
  cout << "Writing to File " << outFileName << endl;
  outFile->cd();
  c1->Write();
  c2->Write();
  gsigma->Write();
  gmass->Write();

  f1->Close();
  delete f1;

  cout << "Here's what's left in memory:" << endl;
  gDirectory->ls("-m");

}
