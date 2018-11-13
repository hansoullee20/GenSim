#ifndef GenSimAnalysis_h 
#define GenSimAnalysis_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "GenSimMainEvent.hh"
#include "GenSimUserInformation.hh"

class GenSimMainEvent;

class GenSimAnalysis {
public:
  GenSimAnalysis();
  virtual ~GenSimAnalysis();
  
public:

  // void BeginOfRun(G4int runID, G4double pressure, G4double coll);
  void BeginOfRun(G4int runID, GenSimUserInformation *userInfo);
  void EndOfRun();
  void EndOfEvent(G4int flag);

  void Init();
  void Finish();

  void FillRootNtuple() {GenSimNtuple->Fill();}
  void AutoSaveRootNtuple();

  void SetTotalNumberOfPrimaries(Int_t n) {(*NumberOfPrimaries)[0] = (Double_t)n;};

  GenSimMainEvent* MainEvent;


private:

  void ConstructRootNtuple(); 

  TTree*   GenSimNtuple;
  TBranch* MainBranch;
  TFile*   GenSimFile;
  //GenSimMainEvent* MainEvent; 

  TVectorD *NumberOfPrimaries;
};

#endif
