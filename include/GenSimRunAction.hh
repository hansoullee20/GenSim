#ifndef GenSimRunAction_h
#define GenSimRunAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "GenSimAnalysis.hh"
// #include "GenSimUserInformation.hh"
#include "GenSimRunActionMessenger.hh"

class GenSimRunActionMessenger;
class GenSimAnalysis;

class GenSimRunAction : public G4UserRunAction
{
public:
  GenSimRunAction(GenSimAnalysis* AN, GenSimUserInformation* UI);
  ~GenSimRunAction();

public:
  void BeginOfRunAction(const G4Run*);
  void EndOfRunAction(const G4Run*);
  G4int  getRunID();
  void SetMyRunID(G4int id) {MyRunID = id;};
  
private:

  G4int runID;
  G4int MyRunID;
  GenSimAnalysis* analysis;
  GenSimUserInformation* userInfo;
  GenSimRunActionMessenger *RunActionMessenger;

};

#endif
