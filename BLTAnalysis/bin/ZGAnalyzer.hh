// =============================================================================
// A simple analysis on Bacon ntuples
//
// Input arguments:
//   argv[1] => input bacon file name
//   argv[2] => number of entries
//   argv[3] => ...
//
// Users should inherit from BLTSelector and implement the three functions:
//   Begin()
//   Process()
//   Terminate()
// =============================================================================


#ifndef DEMOANALYZER_HH
#define DEMOANALYZER_HH

// Analysis tools
#include "BLT/BLTAnalysis/interface/BLTSelector.hh"
#include "BLT/BLTAnalysis/interface/Parameters.hh"
#include "BLT/BLTAnalysis/interface/Cuts.hh"
#include "BLT/BLTAnalysis/interface/TriggerSelector.hh"
#include "BLT/BLTAnalysis/interface/ParticleSelector.hh"

// ROOT headers
#include <TLorentzVector.h>
#include <TVector3.h>

// C++ headers
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <regex>


class ZGAnalyzer: public BLTSelector {
public:
    ZGAnalyzer();
    ~ZGAnalyzer();

    void    Begin(TTree *tree);
    Bool_t  Process(Long64_t entry);
    void    Terminate();

    void    ReportPostBegin();
    void    ReportPostTerminate();

    TFile       *outFile;
    TTree       *outTree;
    std::string  outFileName;
    std::string  outTreeName;

    // Params and cuts
    std::unique_ptr<Parameters>         params;
    std::unique_ptr<Cuts>               cuts;
    std::unique_ptr<TriggerSelector>    triggerSelector;
    std::unique_ptr<ParticleSelector>   particleSelector;

    // Branches in the output file
    TLorentzVector muonOne;
    TLorentzVector muonTwo;
    TLorentzVector photon;
    TLorentzVector three_body;
    TLorentzVector dimuon;

    TLorentzVector genMuonOne;
    TLorentzVector genMuonTwo;
    TLorentzVector genZ;

    //ClassDef(ZGAnalyzer,0);
};


#endif  // DEMOANALYZER_HH
