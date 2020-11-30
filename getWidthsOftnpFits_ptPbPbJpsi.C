
void getWidthsOftnpFits_ptPbPbJpsi() {

  gStyle->SetOptStat(0);
  const static int numParams = 2;
  double ptbins[10] = {1.4,2.1,2.6,3.1,3.6,4.6,6.4,8.5,11.0,20};
  const static int numbins = sizeof(ptbins)/sizeof(double)-1;

  TH1D* hsigma = new TH1D("hsigma","hsigma",numbins,ptbins);
  TH1D* hmass = new TH1D("hmass","hmass",numbins,ptbins);

  //TFile* f1 = TFile::Open("PbPbZ/tnp_Ana_RD_TrkfromTrkM9_PbPb_paper_0.root","READ");
  TFile* f1 = TFile::Open("PbPbJpsi/tnp_Ana_RD_PbPb_Trg_L3Jpsi_cbPlusPol1_TagMu3Filter.root","READ");

  cout << "starting loop" << endl;
   for (int i=0; i<numbins; i++) {
     //Change this to match whatever is in the file you're using.
     //RooFitResult* fitRes = (RooFitResult*)f1->Get(Form("tpTreeTrk/Trk_centdep/eta_bin0__pt_bin0__tag_hiBin_bin%i__PF_true__TM_true__TrackCuts_true__BWConvCBExpFixedWidthBW/fitresults;1",i));
     RooFitResult* fitRes = (RooFitResult*)f1->Get(Form("tpTree/Trg_abseta21_24/abseta_bin0__pt_bin%i__InAcceptance_2018_Tight_true__isHybridSoftMuon2018_true__isUnprescaled_true__tag_HLT_HIL3Mu3_NHitQ10_true__cbPlusPol1/fitresult_simPdf_data_binned;1",i));

      fitRes->Print("v");

      //sigma
      RooRealVar* sigma_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("sigma");
      double sigmaval = sigma_fitRes->getVal();
      double sigmaerr = sigma_fitRes->getError();

      cout << "sigma" << " = " << sigmaval << " +/- " << sigmaerr << " (" << abs(sigmaerr/sigmaval)*100 << "%)" << endl;

      hsigma->SetBinContent(i+1,sigmaval);
      hsigma->SetBinError(i+1,sigmaerr);

      //mean
      RooRealVar* mean_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("mean");
      double meanval = mean_fitRes->getVal();
      double meanerr = mean_fitRes->getError();

      cout << "mean" << " = " << meanval << " +/- " << meanerr << " (" << abs(meanerr/meanval)*100 << "%)" << endl;

      hmass->SetBinContent(i+1,meanval);
      hmass->SetBinError(i+1,meanerr);

    delete fitRes;
  }

  TCanvas* c1 = new TCanvas("c1","c1",0,0,400,400);
  c1->cd();
  hsigma->Scale(1/3.0969);//Divide by mass of J/psi meson.
  hsigma->SetTitle("Mass Res. at J/#psi peak (PbPb 5.02 TeV)");
  hsigma->SetMinimum(0);
  hsigma->SetMaximum(0.03);
  hsigma->GetXaxis()->SetTitle("p_{T} (|#eta|<2.4)");
  hsigma->Draw();

  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  leg->SetTextSize(19);
  leg->SetTextFont(43);
  //leg->SetBorderSize(0);
  leg->AddEntry(hsigma,"#sigma_{cb}/m_{J/#psi}","pel");
  //leg->AddEntry(hsigma2Pass,"sigma gaussian","pel");
  //leg->AddEntry(hsigmaC,"sigma combined","pel");
  leg->Draw("same");

  c1->SaveAs("ptMassResJpsiPbPb.pdf");

  TCanvas* c2 = new TCanvas("c2","c2",400,0,400,400);
  c2->cd();
  hmass->Scale(1/3.0969);//Divide by mass of J/psi meson.
  hmass->SetTitle("Mass Scale at J/#psi peak (PbPb 5.02 TeV)");
  hmass->SetMinimum(0.99);
  hmass->SetMaximum(1.01);
  hmass->GetXaxis()->SetTitle("p_{T} (|#eta|<2.4)");
  hmass->Draw();
  TLine* l1 = new TLine(0,1,20,1);
  l1->SetLineColor(kRed);
  l1->SetLineStyle(2);
  l1->Draw("same");

  TLegend* leg2 = new TLegend(0.7,0.8,0.9,0.9);
  leg2->SetTextSize(19);
  leg2->SetTextFont(43);
  //leg2->SetBorderSize(0);
  leg2->AddEntry(hmass,"#mu/m_{J/#psi}","pel");
  leg2->Draw("same");

  c2->SaveAs("ptMassScaleJpsiPbPb.pdf");

  //Set up the output tree.
  TString outFileName = "ptMassResJpsiPbPb.root";
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

  //Make TGraphAsymmErrorss converted to Ntracks:
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
