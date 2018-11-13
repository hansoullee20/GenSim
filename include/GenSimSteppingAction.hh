#ifndef GenSimSteppingAction_h
#define GenSimSteppingAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "GenSimUserInformation.hh"
#include "GenSimSteppingVerbose.hh"
#include "GenSimTrackInformation.hh"

class GenSimSteppingAction : public G4UserSteppingAction
{
  
public:
  GenSimSteppingAction(GenSimUserInformation* myUInfo);
  ~GenSimSteppingAction(){};
  
  void UserSteppingAction(const G4Step*);

  G4int GetNumOfAtRestSecondaries(){return    fpSteppingManager->GetfN2ndariesAtRestDoIt();};
  G4int GetNumOfAlongStepSecondaries(){return fpSteppingManager->GetfN2ndariesAlongStepDoIt();};
  G4int GetNumOfPostStepSecondaries(){return  fpSteppingManager->GetfN2ndariesPostStepDoIt();};
  G4int GetTotalNumOfSecondaries(){return     GetNumOfAtRestSecondaries() + GetNumOfAlongStepSecondaries() + GetNumOfPostStepSecondaries();};

  G4int GetTrackVectorStartIndex();
  G4int GetTrackVectorSize();

  G4ParticleDefinition *GetSecondaryParticleDefinition(G4int idx); 
  G4String              GetSecondaryParticleName(G4int idx); 
  G4double              GetSecondaryParticleTotalEnergy(G4int idx);
  G4double              GetSecondaryParticleKineticEnergy(G4int idx);
  G4double              GetSecondaryParticleXOrigin(G4int idx);
  G4double              GetSecondaryParticleYOrigin(G4int idx);
  G4double              GetSecondaryParticleZOrigin(G4int idx);    
  G4ThreeVector         GetSecondaryParticleOrigin(G4int idx);    
  G4ThreeVector         GetSecondaryParticleMomentum(G4int idx);    
  G4String              GetSecondaryCreatorProcessName(G4int idx);

  G4ThreeVector         ErrorVal;

private:

  void DrawTracks(G4bool, G4Track*);

  G4TrackVector *fSecondary;
  GenSimUserInformation* myUserInfo;
  
};

#endif
