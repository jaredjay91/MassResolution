void centToNtracks(float hiBin, double* ntracksvalptr, double* ntrackserrloptr, double* ntrackserrhiptr) {

  if (hiBin<20) {
    *ntracksvalptr = 2469;
    *ntrackserrloptr = 297;
    *ntrackserrhiptr = 297;
  }
  else if (hiBin<40) {
    *ntracksvalptr = 1788;
    *ntrackserrloptr = 212;
    *ntrackserrhiptr = 212;
  }
  else if (hiBin<60) {
    *ntracksvalptr = 1261;
    *ntrackserrloptr = 165;
    *ntrackserrhiptr = 165;
  }
  else if (hiBin<80) {
    *ntracksvalptr = 838;
    *ntrackserrloptr = 130;
    *ntrackserrhiptr = 130;
  }
  else if (hiBin<100) {
    *ntracksvalptr = 510;
    *ntrackserrloptr = 95;
    *ntrackserrhiptr = 95;
  }
  else if (hiBin<200) {
    *ntracksvalptr = 73;
    *ntrackserrloptr = 73;
    *ntrackserrhiptr = 102;
  }

  /*if (hiBin<40) {
    *ntracksvalptr = 2129;
    *ntrackserrloptr = 427;
    *ntrackserrhiptr = 427;
  }
  else if (hiBin<80) {
    *ntracksvalptr = 1050;
    *ntrackserrloptr = 258;
    *ntrackserrhiptr = 258;
  }
  else if (hiBin<200) {
    *ntracksvalptr = 129;
    *ntrackserrloptr = 129;
    *ntrackserrhiptr = 178;
  }*/

}


void getWidthsOftnpFits_PbPbZ(int RD0MC1=0) {
  TString RDorMC;
  if (RD0MC1==0) RDorMC = "RD";
  else if (RD0MC1==1) RDorMC = "MC";

  gStyle->SetOptStat(0);
  const static int numParams = 2;
  double centbins[7] = {0,20,40,60,80,100,200};
  const static int numbins = sizeof(centbins)/sizeof(double)-1;

  TH1D* hsigma = new TH1D("hsigma","hsigma",numbins,centbins);
  TH1D* hmass = new TH1D("hmass","hmass",numbins,centbins);

  TString filename;
  if (RDorMC=="RD") filename = "PbPbZ/tnp_Ana_RD_L3Mu12_PbPb_0_v5_paperFixedBWn.root";
  else if (RDorMC=="MC") filename = "PbPbZ/tnp_Ana_MC_L3Mu12_PbPb_0_v5_paperFixedBWn.root";
  TFile* f1 = TFile::Open(filename,"READ");

  cout << "starting loop" << endl;
   for (int i=0; i<numbins; i++) {
     //Change this to match whatever is in the file you're using.
     //RooFitResult* fitRes = (RooFitResult*)f1->Get(Form("tpTreeTrk/Trk_centdep/eta_bin0__pt_bin0__tag_hiBin_bin%i__PF_true__TM_true__TrackCuts_true__BWConvCBExpFixedWidthBW/fitresults;1",i));
     RooFitResult* fitRes = (RooFitResult*)f1->Get(Form("tpTree/Trg_centdep/eta_bin0__pt_bin0__tag_hiBin_bin%i__isTightMuon_true__BWConvCBExpFixedWidthBW/fitresults;1",i));

      fitRes->Print("v");

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
  hsigma->SetTitle("Mass Res. at Z peak (PbPb 5.02 TeV)");
  hsigma->SetMinimum(0);
  hsigma->SetMaximum(0.03);
  hsigma->GetXaxis()->SetTitle("cBin");
  hsigma->Draw();

  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  leg->SetTextSize(19);
  leg->SetTextFont(43);
  //leg->SetBorderSize(0);
  leg->AddEntry(hsigma,"#sigma_{cb}/m_{Z}","pel");
  //leg->AddEntry(hsigma2Pass,"sigma gaussian","pel");
  //leg->AddEntry(hsigmaC,"sigma combined","pel");
  leg->Draw("same");

  c1->SaveAs(Form("Results/MassResZPbPb%s.pdf",RDorMC.Data()));

  TCanvas* c2 = new TCanvas("c2","c2",400,0,400,400);
  c2->cd();
  hmass->Scale(1/91.1876);//Divide by mass of Z boson.
  hmass->SetTitle("Mass Scale at Z peak (PbPb 5.02 TeV)");
  hmass->SetMinimum(0.99);
  hmass->SetMaximum(1.01);
  hmass->GetXaxis()->SetTitle("cBin");
  hmass->Draw();
  TLine* l1 = new TLine(0,1,200,1);
  l1->SetLineColor(kRed);
  l1->SetLineStyle(2);
  l1->Draw("same");

  TLegend* leg2 = new TLegend(0.7,0.8,0.9,0.9);
  leg2->SetTextSize(19);
  leg2->SetTextFont(43);
  //leg2->SetBorderSize(0);
  leg2->AddEntry(hmass,"#mu/m_{Z}","pel");
  leg2->Draw("same");

  c2->SaveAs(Form("Results/MassScaleZPbPb%s.pdf",RDorMC.Data()));

  //Set up the output tree.
  TString outFileName = Form("Results/MassResZPbPb%s.root",RDorMC.Data());
  TFile* outFile = new TFile(outFileName.Data(),"recreate");

  //Make TGraphAsymmErrorss converted to Ntracks:
  double ntracksval = 0;
  double ntrackserrlo = 0;
  double ntrackserrhi = 0;
  double* ntracksvalptr;
  double* ntrackserrloptr;
  double* ntrackserrhiptr;
  ntracksvalptr = &ntracksval;
  ntrackserrloptr = &ntrackserrlo;
  ntrackserrhiptr = &ntrackserrhi;
  TGraphAsymmErrors* gsigma = new TGraphAsymmErrors(hsigma);
  for (int jBin=0; jBin<numbins; jBin++){
    double eyh = gsigma->GetErrorYhigh(jBin);
    double eyl = gsigma->GetErrorYhigh(jBin);
    double effY = 0;
    double effX = 0;
    ntracksval = 0;
    ntrackserrlo = 0;
    ntrackserrhi = 0;
    gsigma->GetPoint(jBin,effX,effY);
    centToNtracks(effX,ntracksvalptr,ntrackserrloptr,ntrackserrhiptr);
    gsigma->SetPoint(jBin,*ntracksvalptr,effY);
    double exh = *ntrackserrhiptr;
    double exl = *ntrackserrloptr;
    gsigma->SetPointError(jBin, exl, exh, eyl, eyh);
  }

  TCanvas* c3 = new TCanvas("c3","c3",0,0,400,400);
  c3->cd();
  gsigma->SetMinimum(0);
  gsigma->Draw("AP");

  TGraphAsymmErrors* gmass = new TGraphAsymmErrors(hmass);
  for (int jBin=0; jBin<numbins; jBin++){
    double eyh = gsigma->GetErrorYhigh(jBin);
    double eyl = gsigma->GetErrorYhigh(jBin);
    double effY = 0;
    double effX = 0;
    ntracksval = 0;
    ntrackserrlo = 0;
    ntrackserrhi = 0;
    gmass->GetPoint(jBin,effX,effY);
    centToNtracks(effX,ntracksvalptr,ntrackserrloptr,ntrackserrhiptr);
    gmass->SetPoint(jBin,*ntracksvalptr,effY);
    double exh = *ntrackserrhiptr;
    double exl = *ntrackserrloptr;
    gmass->SetPointError(jBin, exl, exh, eyl, eyh);
  }

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
