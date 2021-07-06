import FWCore.ParameterSet.Config as cms

import sys
args =sys.argv[1:]
if len(args) < 2: scenario = "0"
else: 
   scenario = args[1]
print "Will run scenario ", scenario 
# scenario: 1 pT, 2-3 pT in detailed abseta bins, 4-5 pT in overall abseta bins, 6 abseta, 7, eta, 8 centrality, 0 (or no parameter) run all


process = cms.Process("TagProbe")
process.load('FWCore.MessageService.MessageLogger_cfi')
process.source = cms.Source("EmptySource")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )    
PDFName = "BWFixedResCBExp"



VEFFICIENCYSET =cms.VPSet(
# Order: 0 total, 1 pT, 2-8 pT fits in abseta bins, 9 abseta, 10 eta, 11-12 centrality   NOTE: IS NOT SAME AS SCENARIO
    cms.PSet(
        MuId_1bin = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 200),
                eta = cms.vdouble(-2.4, 2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
         BinToPDFmap = cms.vstring(PDFName)
        )
    ),
    cms.PSet(
       MuId_pt = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30, 40, 50, 75, 100, 200),
                eta = cms.vdouble(-2.4,2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
           ),
           BinToPDFmap = cms.vstring(PDFName)
       )
    ),
    cms.PSet(
        MuId_abseta00_09 = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(0, 0.9),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
        MuId_abseta09_12 = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(0.9, 1.2),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
        MuId_abseta00_12 = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(0, 1.2),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
         MuId_abseta12_16 = cms.PSet(
             EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
             UnbinnedVariables = cms.vstring("mass"),
             BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(1.2,1.6),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
             ),
             BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(         
         MuId_abseta16_21 = cms.PSet(
             EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
             UnbinnedVariables = cms.vstring("mass"),
             BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(1.6,2.1),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
             ),
             BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(         
         MuId_abseta12_21 = cms.PSet(
             EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
             UnbinnedVariables = cms.vstring("mass"),
             BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(1.2,2.1),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
             ),
             BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
        MuId_abseta21_24 = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 20, 30,50, 80, 200),
                abseta = cms.vdouble(2.1,2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
        MuId_absetadep = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 200),
                abseta = cms.vdouble(0,0.3,0.9,1.2,1.6,2.1,2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(      
        MuId_etadep = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 200),
                eta = cms.vdouble(-2.4,-2.1,-1.6,-1.2,-0.9,-0.6,-0.3,0,0.3,0.6,0.9,1.2,1.6,2.1,2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
        MuId_centdep = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15,200),
                eta = cms.vdouble(-2.4,2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                tag_hiNtracks = cms.vdouble(0,30,50,75,100,125,150,175,400),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
        MuId_centdepHF = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15,200),
                eta = cms.vdouble(-2.4,2.4),
#                tag_nVertices    = cms.vdouble(0.9,1.1),
                tag_hiHF = cms.vdouble(0,30,50,75,100,125,150,175,400),
                TightId = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        )
    ), 
    cms.PSet(
       MuId_nPV = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 200),
                eta = cms.vdouble(-2.4,2.4),
                tag_nVertices    = cms.vdouble(0.5,1.5,2.5,10),
                TightId = cms.vstring("true"),
           ),
           BinToPDFmap = cms.vstring(PDFName)
       )
    ),
)

#Actual selection 
if scenario == "1": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[0], VEFFICIENCYSET[1])
if scenario == "2": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[2], VEFFICIENCYSET[3])
if scenario == "3": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[5], VEFFICIENCYSET[6])
if scenario == "4": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[4], VEFFICIENCYSET[7])
if scenario == "5": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[8])
if scenario == "6": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[9])
if scenario == "7": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[10])
if scenario == "8": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[11], VEFFICIENCYSET[12])
if scenario == "9": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[13])
if scenario == "0": EFFICIENCYSET = cms.PSet(VEFFICIENCYSET[0],VEFFICIENCYSET[1],VEFFICIENCYSET[2], VEFFICIENCYSET[3],VEFFICIENCYSET[4], VEFFICIENCYSET[5],VEFFICIENCYSET[6], VEFFICIENCYSET[7],VEFFICIENCYSET[8], VEFFICIENCYSET[9], VEFFICIENCYSET[10],VEFFICIENCYSET[11],VEFFICIENCYSET[12],VEFFICIENCYSET[13])






process.TagProbeFitTreeAnalyzer = cms.EDAnalyzer("TagProbeFitTreeAnalyzer",
    # IO parameters:
 #   InputFileNames = cms.vstring("file:/afs/cern.ch/work/o/okukral/TnP_pPb/Data/PASingleMuon_PARun2016C-PromptReco-v1TnpTress_Pbpv1CentralityInfo.root"),
    #InputFileNames = cms.vstring("file:/eos/cms/store/group/phys_heavyions/jaebeom/TnP/TTrees/PASingleMuon_PromptReco_pPb_Pbp_merged_v2.root"),
    InputFileNames = cms.vstring("file:/eos/cms/store/group/phys_heavyions/okukral/TnP_pPb_2016/RD_trees-merged.root"),
    InputDirectoryName = cms.string("tpTree"),
    InputTreeName = cms.string("fitter_tree"),
    OutputFileName = cms.string("tnp_Ana_RD_L3Mu12_MuId_pPb_%s_nominal_noPU.root" % scenario),
    #numbrer of CPUs to use for fitting
    NumCPU = cms.uint32(16),
    # specifies whether to save the RooWorkspace containing the data for each bin and
    # the pdf object with the initial and final state snapshots
    binnedFit = cms.bool(False),
    #binsForFit = cms.uint32(30),
    binsForMassPlots = cms.uint32(50),
    SaveWorkspace = cms.bool(False),
    WeightVariable = cms.string("weight"),
    
    # defines all the real variables of the probes available in the input tree and intended for use in the efficiencies
    Variables = cms.PSet(
                         mass             = cms.vstring("Tag-Probe Mass", "60.0", "120.0", "GeV/c^{2}"), # mass range syst: 2.8-3.4
                         pt               = cms.vstring("Probe p_{T}", "0.0", "1000", "GeV/c"),
                         eta              = cms.vstring("Probe #eta", "-2.4", "2.4", ""),
                         abseta           = cms.vstring("Probe |#eta|", "0", "2.5", ""),
                         tag_hiNtracks    = cms.vstring("N Tracks", "0", "400", ""),
                         tag_hiHF         = cms.vstring("HF", "0", "500", ""),
                         tag_nVertices    = cms.vstring("PU - nVertices", "0", "10", ""),
                         weight           = cms.vstring("weight","0","10",""),
    ),
    # defines all the discrete variables of the probes available in the input tree and intended for use in the efficiency calculations
    Categories = cms.PSet(
                        isTightMuonO = cms.vstring("isTightMuonO", "dummy[true=1,false=0]"),
                        TightId = cms.vstring("TightId", "dummy[true=1,false=0]"),
                        Glb = cms.vstring("Glb", "dummy[true=1,false=0]"),
                        PF = cms.vstring("PF", "dummy[true=1,false=0]"),
                        hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12 = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered12", "dummy[true=1,false=0]"),
                        hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered15 = cms.vstring("hltL3fL1sSingleMu7BptxANDL1f0L2f0L3Filtered15", "dummy[true=1,false=0]"),
                        isIso_3_15 = cms.vstring("isIso_3_15", "dummy[true=1,false=0]"),
    ),
    
    # defines all the PDFs that will be available for the efficiency calculations; uses RooFit's "factory" syntax;
    # each pdf needs to define "signal", "backgroundPass", "backgroundFail" pdfs, "efficiency[0.9,0,1]" and "signalFractionInPassing[0.9]" are used for initial values  
    PDFs = cms.PSet(
	VoigtExp = cms.vstring(
		"BreitWigner::bw(mass, m0[91.2,81.2,101.2], width[2.495,1,10])",
		"RooCBShape::res(mass, peak[0], sigma[1.7,0.01,10], alpha[1.8,0,3], n[0.8,0,10])",
		"FCONV::signal(mass, bw, res)",
		"Exponential::backgroundPass(mass, lp[0,-5,5])",
		"Exponential::backgroundFail(mass, lf[0,-5,5])",
		"efficiency[0.9,0.5,1]",
		"signalFractionInPassing[0.9]",
	),
	BWResCBExp = cms.vstring(
		"BreitWigner::bw(mass, m0[91.2,81.2,101.2], width[2.495,1,10])",
		"RooCBShape::res(mass, peak[0], sigma[1.7,0.01,10], alpha[1.8,0,3], n[0.8,0,10])",
		"FCONV::signal(mass, bw, res)",
		"Exponential::backgroundPass(mass, lp[0,-5,5])",
		"Exponential::backgroundFail(mass, lf[0,-5,5])",
		"efficiency[0.9,0.5,1]",
		"signalFractionInPassing[0.9]",
	),
        BWFixedResCBExp = cms.vstring(
		"BreitWigner::bw(mass, m0[91.2,81.2,101.2], width[2.495])",
		"RooCBShape::res(mass, peak[0], sigma[1.7,0.01,10], alpha[1.8,0,3], n[1.3])",
		"FCONV::signal(mass, bw, res)",
		"Exponential::backgroundPass(mass, lp[0,-5,5])",
		"Exponential::backgroundFail(mass, lf[0,-5,5])",
		"efficiency[0.9,0.5,1]",
		"signalFractionInPassing[0.9]",
	),
	BWResCBCheb = cms.vstring(
		"BreitWigner::bw(mass, m0[91.2,81.2,101.2], width[2.495,1,10])",
		"RooCBShape::res(mass, peak[0], sigma[1.7,0.01,10], alpha[1.8,0,3], n[0.8,0,10])",
		"FCONV::signal(mass, bw, res)",
		"Chebychev::backgroundPass(mass, {c1p[0,-10,10], c2p[0,-10,10], c3p[0,-10,10]})",
		"Chebychev::backgroundFail(mass, {c1f[0,-10,10], c2f[0,-10,10], c3f[0,-10,10]})",
		"efficiency[0.9,0.5,1]",
		"signalFractionInPassing[0.9]",
	),
      #  #nominal:
      #cbPlusPol1 = cms.vstring(
      #  "CBShape::signal(mass, mean[3.08,3.00,3.3], sigma[0.03, 0.01, 0.10], alpha[1.85, 0.1, 50], n[1.7, 0.2, 50])",
      #  "Chebychev::backgroundPass(mass, {cPass[0.,-1.1,1.1]})",
      #  "Chebychev::backgroundFail(mass, {cFail[0.,-1.1,1.1]})",
      #  "efficiency[0.9,0,1]",
      #  "signalFractionInPassing[0.9]"
      #),
      #  #background syst:
      #cbPlusPol2 = cms.vstring(
      #  "CBShape::signal(mass, mean[3.08,3.00,3.2], sigma[0.03, 0.01, 0.10], alpha[1.85, 0.1, 50], n[1.7, 0.2, 50])",
      #  "Chebychev::backgroundPass(mass, {cPass[0.,-1.1,1.1], cPass2[0.,-1.1,1.1]})",
      #  "Chebychev::backgroundFail(mass, {cFail[0.,-1.1,1.1], cFail2[0.,-1.1,1.1]})",
      #  "efficiency[0.9,0,1]",
      #  "signalFractionInPassing[0.9]"
      #),
      #  #signal syst:
      #cbGausPlusPol1 = cms.vstring(
      #  "CBShape::signal1(mass, mean[3.08,3.00,3.3], sigma1[0.03, 0.01, 0.10], alpha[1.85, 0.1, 50], n[1.7, 0.2, 50])",
      #  "RooFormulaVar::sigma2('@0*@1',{fracS[1.8,1.2,2.4],sigma1})",
      #  "Gaussian::signal2(mass, mean, sigma2)",
      #  "SUM::signal(frac[0.8,0.5,1.]*signal1,signal2)",
      #  "Chebychev::backgroundPass(mass, {cPass[0.,-1.1,1.1]})",
      #  "Chebychev::backgroundFail(mass, {cFail[0.,-1.1,1.1]})",
      #  "efficiency[0.9,0,1]",
      #  "signalFractionInPassing[0.9]"
      #),

    ),

    # defines a set of efficiency calculations, what PDF to use for fitting and how to bin the data;
    # there will be a separate output directory for each calculation that includes a simultaneous fit, side band subtraction and counting. 
    Efficiencies = EFFICIENCYSET 
)

process.fitness = cms.Path(
    process.TagProbeFitTreeAnalyzer
)
