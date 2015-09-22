#include "BLT/BLTAnalysis/interface/AnalysisParameters.hh"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const AnalysisParameters& params) {
    return os << "  suffix   : " << params.suffix    << "\n"
              << "  abcd     : " << params.abcd      << "\n"
              << "  selection: " << params.selection << "\n"
              << "  period   : " << params.period    << "\n"
              << "  dataname : " << params.dataname  << "\n"
              << "  jobcount : " << params.jobcount  << "\n"
              << "  pileup   : " << params.pileup    ;
}
