#ifndef GenSimTrackingAction_h
#define GenSimTrackingAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "G4RandomDirection.hh"

#include "GenSimUserInformation.hh"
#include "GenSimTrackInformation.hh"

class GenSimTrackInformation;
class GenSimUserInformation;

class GenSimTrackingAction : public G4UserTrackingAction
{

public:

   GenSimTrackingAction(GenSimUserInformation*);
  ~GenSimTrackingAction();

  void  PreUserTrackingAction(const G4Track* aTrack);
  void PostUserTrackingAction(const G4Track* aTrack);

private:
  
  GenSimUserInformation*  myUserInfo;

};

#endif
