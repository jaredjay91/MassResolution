


void getWidthsOftnpFits_pPbJpsi(TString RDorMC="RD") {

  gStyle->SetOptStat(0);
  const static int numParams = 2;
  double ntracksbins[8] = {0,35,60,90,120,155,200,400};
  const static int numbins = sizeof(ntracksbins)/sizeof(double)-1;

  TH1D* hsigma1Pass = new TH1D("hsigma1Pass","hsigma1Pass",numbins,ntracksbins);
  TH1D* hsigma2Pass = new TH1D("hsigma2Pass","hsigma2Pass",numbins,ntracksbins);
  TH1D* hsigmaC = new TH1D("hsigmaC","hsigmaC",numbins,ntracksbins);
  TH1D* hmass = new TH1D("hmass","hmass",numbins,ntracksbins);

  TString filename;
  if (RDorMC=="RD") filename = "pPbJpsi/tnp_Ana_RD_Trig_pPb_cbGausPassFailExppt35_8.root";
  else if (RDorMC=="MC") filename = "pPbJpsi/tnp_Ana_MC_Trig_pPb_cbGausExp_8.root";

  TFile* f1 = TFile::Open(filename,"READ");

  cout << "starting loop" << endl;
    for (int i=0; i<numbins; i++) {
      TString fitResPath;
      if (RDorMC=="RD") fitResPath = Form("tpTree/Trig_centdep/eta_bin0__pt_bin0__tag_hiNtracks_bin%i__tag_nVertices_bin0__SoftID_true__probe_trg_acceptance_true__tag_HLT_PAL3Mu3_true__cbGausPassFailExp/fitresults;1",i);
      //if (RDorMC=="RD") fitResPath = Form("tpTree/Trig_centdep/eta_bin0__pt_bin0__tag_hiNtracks_bin%i__tag_nVertices_bin0__SoftID_true__probe_trg_acceptance_true__tag_HLT_PAL3Mu3_true__cbGausExp/fitresults;1",i);
      else if (RDorMC=="MC") fitResPath = Form("tpTree/Trig_centdep/eta_bin0__pt_bin0__tag_hiNtracks_bin%i__tag_nVertices_bin0__SoftID_true__TM_true__probe_trg_acceptance_true__tag_HLT_PAL3Mu3_true__cbGausExp/fitresults;1",i);
      RooFitResult* fitRes = (RooFitResult*)f1->Get(fitResPath);//Change this to match whatever is in the file you're using.

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
      RooRealVar* fracS_fitRes = (RooRealVar*)fitRes->floatParsFinal().find("fracS");
      double fracSval = fracS_fitRes->getVal();
      double fracSerr = fracS_fitRes->getError();

      double sigma2Passval = fracSval*sigma1Passval;
      double sigma2Passerr = sigma2Passval*sqrt(pow(sigma1Passerr/sigma1Passval,2)+pow(fracSerr/fracSval,2));

      cout << "sigma2Pass" << " = " << sigma2Passval << " +/- " << sigma2Passerr << " (" << abs(sigma2Passerr/sigma2Passval)*100 << "%)" << endl;

      hsigma2Pass->SetBinContent(i+1,sigma2Passval);
      hsigma2Pass->SetBinError(i+1,sigma2Passerr);

/*    cbGausPassFailExp = cms.vstring(
        "CBShape::signal1Pass(mass, mean[3.08,3.00,3.3], sigma1Pass[0.03, 0.01, 0.10], alpha[1.8, 0.1, 50], n[1.53])",
        "CBShape::signal1Fail(mass, mean, sigma1Fail[0.03, 0.01, 0.10], alpha, n)",
        "RooFormulaVar::sigma2Pass('@0*@1',{fracS[2.0,1.2,2.4],sigma1Pass})",
        "Gaussian::signal2Pass(mass, mean, sigma2Pass)",
        "RooFormulaVar::sigma2Fail('@0*@1',{fracS,sigma1Fail})",
        "Gaussian::signal2Fail(mass, mean, sigma2Fail)",
        "SUM::signalPass(frac[0.8,0.5,1.]*signal1Pass,signal2Pass)",
        "SUM::signalFail(frac*signal1Fail,signal2Fail)",
        "Exponential::backgroundPass(mass, lp[0,-5,5])",
        "Exponential::backgroundFail(mass, lf[0,-5,5])",
        "efficiency[0.9,0,1]",
        "signalFractionInPassing[0.9]"
    ),
    not defined: effBkg, fSigAll, numTot

    From observation:
    effBkg = numBkgPass/numBkgTot
    fSigAll = fraction of probes that are in the signal
    numTot = Total number of probes in the fit (passing or failing, signal or bkg)

    numBkgTot = (1-fSigAll)*numTot

    numSigTot = fSigAll*numTot
    numSigPass = efficiency*numSigTot

    We have signalPass = frac*signal1Pass + signal2Pass where signal1Pass and signal2Pass are normalized pdfs. That means they're the same size. So the total number of passing probes in each part of the signal is:
    num1Pass = numSigPass*frac/(frac+1)
    num2Pass = numSigPass*1/(frac+1)
    so we have num1Pass + num2Pass = numSigPass = efficiency*fSigAll*numTot
*/

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
  hsigma1Pass->SetTitle("Mass Res. at J/#psi peak (pPb 8.16 TeV)");
  hsigma1Pass->SetMinimum(0);
  hsigma1Pass->SetMaximum(0.03);
  hsigma1Pass->GetXaxis()->SetTitle("Ntracks");
  hsigma1Pass->Draw();
  hsigma2Pass->SetLineColor(kGreen+3);
  hsigma2Pass->Draw("same");
  hsigmaC->SetLineColor(kRed);
  hsigmaC->Draw("same");

  TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
  leg->SetTextSize(0.04);
  //leg->SetTextFont(43);
  //leg->SetBorderSize(0);
  leg->AddEntry(hsigma1Pass,"#sigma_{cb}/m_{J/#psi}","pel");
  leg->AddEntry(hsigma2Pass,"#sigma_{gaus}/m_{J/#psi}","pel");
  leg->AddEntry(hsigmaC,"combined","pel");
  leg->Draw("same");

  c1->SaveAs(Form("MassResJpsipPb%s.pdf",RDorMC.Data()));

  TCanvas* c2 = new TCanvas("c2","c2",400,0,400,400);
  c2->cd();
  hmass->Scale(1/3.0969);//Divide by mass of Jpsi.
  hmass->SetTitle("Mass Scale at J/#psi peak (pPb 8.16 TeV)");
  hmass->SetMinimum(0.99);
  hmass->SetMaximum(1.01);
  hmass->GetXaxis()->SetTitle("Ntracks");
  hmass->Draw();
  TLine* l1 = new TLine(0,1,400,1);
  l1->SetLineColor(kRed);
  l1->SetLineStyle(2);
  l1->Draw("same");

  TLegend* leg2 = new TLegend(0.7,0.8,0.9,0.9);
  leg2->SetTextSize(19);
  leg2->SetTextFont(43);
  //leg2->SetBorderSize(0);
  leg2->AddEntry(hmass,"#mu/m_{J/#psi}","pel");
  leg2->Draw("same");

  c2->SaveAs(Form("MassScaleJpsipPb%s.pdf",RDorMC.Data()));

  //Set up the output tree.
  TString outFileName = Form("MassResJpsipPb%s.root",RDorMC.Data());
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

  //Make TGraphAsymmErrors:
  TGraphAsymmErrors* gsigma = new TGraphAsymmErrors(hsigmaC);
  TCanvas* c3 = new TCanvas("c3","c3",0,0,400,400);
  c3->cd();
  gsigma->SetMinimum(0);
  gsigma->Draw("AP");

  TGraphAsymmErrors* gmass = new TGraphAsymmErrors(hmass);
  TCanvas* c4 = new TCanvas("c4","c4",0,0,400,400);
  c4->cd();
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
