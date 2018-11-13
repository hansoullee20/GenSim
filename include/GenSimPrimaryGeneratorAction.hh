#ifndef GenSimPrimaryGeneratorAction_h
#define GenSimPrimaryGeneratorAction_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "GenSimPrimaryGeneratorActionMessenger.hh"
#include "GenSimPrimaryEventGenerator.hh"
#include "GenSimUserInformation.hh"

class GenSimPrimaryGeneratorActionMessenger;
 
class GenSimPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
   GenSimPrimaryGeneratorAction( GenSimUserInformation* myUI);    
  ~GenSimPrimaryGeneratorAction();
  
public:

  void GeneratePrimaries(G4Event* anEvent);
  void ResetNtupleEventCounter() {myEventCounter = 0;};
  void SetNtupleEventCounter(G4int cnt) {myEventCounter = cnt;};


  G4int             myEventCounter;
  
private:

  GenSimPrimaryEventGenerator*      eventGenerator;
  G4ParticleGun*                     particleGun;
  GenSimUserInformation*            myUserInfo;

  GenSimPrimaryGeneratorActionMessenger* myMessenger;
};

#endif
