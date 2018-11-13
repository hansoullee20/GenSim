#ifndef GenSimEventAction_h
#define GenSimEventAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "GenSimAnalysis.hh"
#include "GenSimUserInformation.hh"
#include "GenSimADetHit.hh"
#include "GenSimTrajectory.hh"


class GenSimAnalysis;
class GenSimUserInformation;

class GenSimEventAction : public G4UserEventAction
{
public:

    GenSimEventAction(GenSimAnalysis* AN, GenSimUserInformation* myUI);
    ~GenSimEventAction();
  
public:

  void BeginOfEventAction(const G4Event* evt);
  void EndOfEventAction(const G4Event* evt);
  
private:

  void Initialize();


  GenSimAnalysis*             analysis;
  GenSimUserInformation*      myUserInfo;

  
};

#endif

