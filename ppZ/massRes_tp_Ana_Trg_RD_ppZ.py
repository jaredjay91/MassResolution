import FWCore.ParameterSet.Config as cms

process = cms.Process("TagProbe")

process.load('FWCore.MessageService.MessageLogger_cfi')

process.source = cms.Source("EmptySource")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )    

PDFName = "BWConvCBExpFixedWidthBW"

process.TagProbeFitTreeAnalyzer = cms.EDAnalyzer("TagProbeFitTreeAnalyzer",
    # IO parameters:
    #InputFileNames = cms.vstring("root://cms-xrd-global.cern.ch//store/group/phys_heavyions/dileptons/TNPTagAndProbe2015/Data2015/pp502TeV/TTrees/tnpJPsi_Data_pp5TeV_AOD.root"),
    InputFileNames = cms.vstring("file:/eos/cms/store/group/phys_heavyions/echapon/TagAndProbe2017/TNP_SingleMu_pp5TeVRun2017G_PromptReco_v1_AOD_20190416/SingleMuon/crab_TNP_SingleMu_pp5TeVRun2017G_PromptReco_v1_AOD_20190416/190816_123631/0000/tnpZ_Data_all_L1flag.root"),
    InputDirectoryName = cms.string("tpTree"),
    InputTreeName = cms.string("fitter_tree"),
    OutputFileName = cms.string("file:tnp_Trigger_RD_pp_BWConvCBExpFixedWidthBW.root"),
    #numbrer of CPUs to use for fitting
    NumCPU = cms.uint32(16),
    # specifies whether to save the RooWorkspace containing the data for each bin and
    # the pdf object with the initial and final state snapshots
    binnedFit = cms.bool(True),
    binsForFit = cms.uint32(90),
    binsForMassPlots = cms.uint32(50),
    SaveWorkspace = cms.bool(False),
    
    # defines all the real variables of the probes available in the input tree and intended for use in the efficiencies
    Variables = cms.PSet(
                         mass             = cms.vstring("Tag-Probe Mass", "60.0", "120.0", "GeV/c^{2}"),
                         pt               = cms.vstring("Probe p_{T}", "0.0", "1000", "GeV/c"),
                         eta              = cms.vstring("Probe #eta", "-2.4", "2.4", ""),
                         abseta           = cms.vstring("Probe |#eta|", "0", "2.5", ""),
                         tag_nVertices    = cms.vstring("Tag nVtx", "0", "30", ""),
    ),
    # defines all the discrete variables of the probes available in the input tree and intended for use in the efficiency calculations
    Categories = cms.PSet(
                          #Glb = cms.vstring("Glb", "dummy[true=1,false=0]"),
                          #TM = cms.vstring("TM", "dummy[true=1,false=0]"),
                          InAcceptance_2018_Tight = cms.vstring("InAcceptance_2018_Tight","dummy[true=1,false=0]"),
                          tag_HLT_HIL3Mu12 = cms.vstring("tag_HLT_HIL3Mu12", "dummy[true=1,false=0]"),
                          TightId = cms.vstring("TightId", "dummy[true=1,false=0]"),
                          HLTL1_DoubleMu0_v0 = cms.vstring("HLTL1_DoubleMu0_v0", "dummy[true=1,false=0]"),
                          HLTL1_DoubleMu0_v2 = cms.vstring("HLTL1_DoubleMu0_v2", "dummy[true=1,false=0]"),
                          HLT_HIL3Mu12 = cms.vstring("HLT_HIL3Mu12", "dummy[true=1,false=0]"),
    ),

    # defines all the PDFs that will be available for the efficiency calculations; uses RooFit's "factory" syntax;
    # each pdf needs to define "signal", "backgroundPass", "backgroundFail" pdfs, "efficiency[0.9,0,1]" and "signalFractionInPassing[0.9]" are used for initial values  
    PDFs = cms.PSet(
    BWConvCBExpFixedWidthBW = cms.vstring( #n fixed to integrated bin in MC
	    	"BreitWigner::bw(mass, m0[91.2,81.2,101.2], width[2.495])",
	    	"RooCBShape::res(mass, peak[0], sigma[1.7,0.01,10], alpha[1.8,0,3], n[1.65])",
	    	"FCONV::signal(mass, bw, res)",
	    	"Exponential::backgroundPass(mass, lp[0,-5,5])",
	    	"Exponential::backgroundFail(mass, lf[0,-5,5])",
	    	"efficiency[0.9,0.5,1]",
	    	"signalFractionInPassing[0.9]",
    	), 
    ),
    # defines a set of efficiency calculations, what PDF to use for fitting and how to bin the data;
    # there will be a separate output directory for each calculation that includes a simultaneous fit, side band subtraction and counting. 
     Efficiencies = cms.PSet(
         Trg_1bin = cms.PSet(
             EfficiencyCategoryAndState = cms.vstring("HLT_HIL3Mu12","true"),
             UnbinnedVariables = cms.vstring("mass"),
             BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 200),
                eta = cms.vdouble(-2.4, 2.4),
                InAcceptance_2018_Tight = cms.vstring("true"),
                TightId = cms.vstring("true"),
                tag_HLT_HIL3Mu12 = cms.vstring("true"),
             ),
             BinToPDFmap = cms.vstring(PDFName)
         ),
        
         Trg_pt = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("HLT_HIL3Mu12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                pt = cms.vdouble(15,20,25,27.5,30,35,40,45,50,80,200),
                abseta = cms.vdouble(0, 2.4),
                InAcceptance_2018_Tight = cms.vstring("true"),
                TightId = cms.vstring("true"),
                tag_HLT_HIL3Mu12 = cms.vstring("true"),
            ),
             BinToPDFmap = cms.vstring(PDFName)
         ),

         Trg_etadep = cms.PSet(
             EfficiencyCategoryAndState = cms.vstring("HLT_HIL3Mu12","true"),
             UnbinnedVariables = cms.vstring("mass"),
             BinnedVariables = cms.PSet(
                 pt = cms.vdouble(15, 200),
                 eta = cms.vdouble(-2.4, -2.1, -1.6, -1.2, -0.9, -0.6, -0.3, 0, 0.3, 0.6, 0.9, 1.2, 1.6, 2.1, 2.4),
                InAcceptance_2018_Tight = cms.vstring("true"),
                TightId = cms.vstring("true"),
                tag_HLT_HIL3Mu12 = cms.vstring("true"),
             ),
             BinToPDFmap = cms.vstring(PDFName)
         ),
         
         Trg_absetadep = cms.PSet(
             EfficiencyCategoryAndState = cms.vstring("HLT_HIL3Mu12","true"),
             UnbinnedVariables = cms.vstring("mass"),
             BinnedVariables = cms.PSet(
                pt = cms.vdouble(15, 200),
                abseta = cms.vdouble(0, 0.3, 0.9, 1.2, 1.6, 2.1, 2.4),
                InAcceptance_2018_Tight = cms.vstring("true"),
                TightId = cms.vstring("true"),
                tag_HLT_HIL3Mu12 = cms.vstring("true"),
             ),
             BinToPDFmap = cms.vstring(PDFName)
         ),
      
         Trg_nVtx = cms.PSet(
            EfficiencyCategoryAndState = cms.vstring("HLT_HIL3Mu12","true"),
            UnbinnedVariables = cms.vstring("mass"),
            BinnedVariables = cms.PSet(
                tag_nVertices = cms.vdouble(0.5,1.5,2.5,3.5,4.5,5.5,7.5,29.5),
                pt = cms.vdouble(15,200),
                InAcceptance_2018_Tight = cms.vstring("true"),
                TightId = cms.vstring("true"),
                tag_HLT_HIL3Mu12 = cms.vstring("true"),
            ),
            BinToPDFmap = cms.vstring(PDFName)
        ),

     )
)


process.fitness = cms.Path(
    process.TagProbeFitTreeAnalyzer
)
