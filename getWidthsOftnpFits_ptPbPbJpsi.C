
void getWidthsOftnpFits_ptPbPbJpsi(int RD0MC1=0) {
  TString RDorMC;
  if (RD0MC1==0) RDorMC = "RD";
  else if (RD0MC1==1) RDorMC = "MC";

  gStyle->SetOptStat(0);
  const static int numParams = 2;
  double ptbins[10] = {1.4,2.1,2.6,3.1,3.6,4.6,6.4,8.5,11.0,20};
  const static int numbins = sizeof(ptbins)/sizeof(double)-1;

  TH1D* hsigma1Pass = new TH1D("hsigma1Pass","hsigma1Pass",numbins,ptbins);
  TH1D* hsigma2Pass = new TH1D("hsigma2Pass","hsigma2Pass",numbins,ptbins);
  TH1D* hsigmaC = new TH1D("hsigmaC","hsigmaC",numbins,ptbins);
  TH1D* hmass = new TH1D("hmass","hmass",numbins,ptbins);

  TString filename;
  if (RDorMC=="MC") filename = "PbPbJpsi/mine/tnp_Ana_MC_PbPb_Trg_L3Jpsi_cbGausPassFailPol1_TagMu5Filter_3.root";
  else if (RDorMC=="RD") filename = "PbPbJpsi/mine/tnp_Ana_RD_PbPb_Trg_L3Jpsi_mass2834_TagMu5Filter_fixedfracS_3.root";
  TFile* f1 = TFile::Open(filename,"READ");

  cout << "starting loop" << endl;
   for (int i=0; i<numbins; i++) {
     //Change this to match whatever is in the file you're using.
     TString fitResPath;
     if (RDorMC=="MC") fitResPath = Form("tpTree/Trg_abseta21_24/abseta_bin0__pt_bin%i__InAcceptance_2018_Tight_true__isHybridSoftMuon2018_true__tag_HLT_HIL3Mu5_NHitQ10_true__cbGausPassFailPol1/fitresults;1",i);
     else if (RDorMC=="RD") fitResPath = Form("tpTree/Trg_abseta21_24/abseta_bin0__pt_bin%i__InAcceptance_2018_Tight_true__isHybridSoftMuon2018_true__isUnprescaled_true__tag_HLT_HIL3Mu5_NHitQ10_true__cbGausPassFailPol1/fitresults;1",i);
     RooFitResult* fitRes = (RooFitResult*)f1->Get(fitResPath);

      fitRes->Print("v");

      //sigma1Pass
      RooRealVar* sigma1Pass_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("sigma1Pass");
      //RooRealVar* sigma1Pass_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("sigma1");
      double sigma1Passval = sigma1Pass_fitRes->getVal();
      double sigma1Passerr = sigma1Pass_fitRes->getError();

      cout << "sigma1Pass" << " = " << sigma1Passval << " +/- " << sigma1Passerr << " (" << abs(sigma1Passerr/sigma1Passval)*100 << "%)" << endl;

      hsigma1Pass->SetBinContent(i+1,sigma1Passval);
      hsigma1Pass->SetBinError(i+1,sigma1Passerr);

      //sigma2Pass
      //RooRealVar* fracS_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("fracS");
      //double fracSval = fracS_fitRes->getVal();
      //double fracSerr = fracS_fitRes->getError();
      double fracSval = 2.06;
      double fracSerr = 0.0;

      double sigma2Passval = fracSval*sigma1Passval;
      double sigma2Passerr = sigma2Passval*sqrt(pow(sigma1Passerr/sigma1Passval,2)+pow(fracSerr/fracSval,2));

      cout << "sigma2Pass" << " = " << sigma2Passval << " +/- " << sigma2Passerr << " (" << abs(sigma2Passerr/sigma2Passval)*100 << "%)" << endl;

      hsigma2Pass->SetBinContent(i+1,sigma2Passval);
      hsigma2Pass->SetBinError(i+1,sigma2Passerr);

    RooRealVar* numTot_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("numTot");
    double numTotval = numTot_fitRes->getVal();
    double numToterr = numTot_fitRes->getError();
    RooRealVar* fSigAll_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("fSigAll");
    double fSigAllval = fSigAll_fitRes->getVal();
    double fSigAllerr = fSigAll_fitRes->getError();
    RooRealVar* efficiency_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("efficiency");
    double efficiencyval = efficiency_fitRes->getVal();
    double efficiencyerr = efficiency_fitRes->getError();
    RooRealVar* frac_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("frac");
    double fracval = frac_fitRes->getVal();
    double fracerr = frac_fitRes->getError();

    double numSigPass = efficiencyval*fSigAllval*numTotval;
    double num1Pass = numSigPass*fracval/(fracval+1);
    double num2Pass = numSigPass/(fracval+1);

    cout << "num1Pass = " << num1Pass << endl;
    cout << "num2Pass = " << num2Pass << endl;
    cout << "numSigPass = " << numSigPass << " = " << num1Pass+num2Pass << endl;

    double sigmaC = (sigma1Passval*num1Pass + sigma2Passval*num2Pass)/numSigPass;
    double sigmaCerr = sqrt( pow(num1Pass*sigma1Passerr,2) + pow(num2Pass*sigma2Passerr,2) )/numSigPass;

    cout << "sigmaCombined" << " = " << sigmaC << " +/- " << sigmaCerr << " (" << abs(sigmaCerr/sigmaC)*100 << "%)" << endl;

    hsigmaC->SetBinContent(i+1,sigmaC);
    hsigmaC->SetBinError(i+1,sigmaCerr);

      //mean
      RooRealVar* mean_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("mean");
      double meanval = mean_fitRes->getVal();
      double meanerr = mean_fitRes->getError();

      cout << "mean" << " = " << meanval << " +/- " << meanerr << " (" << abs(meanerr/meanval)*100 << "%)" << endl;

      hmass->SetBinContent(i+1,meanval);
      hmass->SetBinError(i+1,meanerr);


    delete fitRes;
  }

  hsigma1Pass->Scale(1/3.0969);//Divide by mass of Jpsi
  hsigma2Pass->Scale(1/3.0969);//Divide by mass of Jpsi
  hsigmaC->Scale(1/3.0969);//Divide by mass of Jpsi

  TCanvas* c1 = new TCanvas("c1","c1",0,0,400,400);
  c1->cd();
  hsigma1Pass->SetTitle("Mass Res. at J/#psi peak (PbPb 5.02 TeV)");
  hsigmaC->SetTitle("Mass Res. at J/#psi peak (PbPb 5.02 TeV)");
  hsigma1Pass->SetMinimum(0);
  hsigma1Pass->SetMaximum(0.03);
  hsigma1Pass->GetXaxis()->SetTitle("p_{T} (|#eta|<2.4)");
  hsigma1Pass->Draw();
  hsigma2Pass->SetLineColor(kGreen+3);
  hsigma2Pass->Draw("same");
  hsigmaC->SetLineColor(kRed);
  hsigmaC->Draw("same");

  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  leg->SetTextSize(19);
  leg->SetTextFont(43);
  //leg->SetBorderSize(0);
  leg->AddEntry(hsigma1Pass,"#sigma_{cb}/m_{J/#psi}","pel");
  leg->AddEntry(hsigma2Pass,"sigma gaussian","pel");
  leg->AddEntry(hsigmaC,"sigma combined","pel");
  leg->Draw("same");

  c1->SaveAs(Form("Results/ptMassResJpsiPbPb%s.pdf",RDorMC.Data()));

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

  c2->SaveAs(Form("Results/ptMassScaleJpsiPbPb%s.pdf",RDorMC.Data()));

  //Set up the output tree.
  TString outFileName = Form("Results/ptMassResJpsiPbPb%s.root",RDorMC.Data());
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

  //Make TGraphAsymmErrorss converted to Ntracks:
  TGraphAsymmErrors* gsigma = new TGraphAsymmErrors(hsigmaC);
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
