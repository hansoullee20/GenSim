#ifndef GenSimADetSD_h
#define GenSimADetSD_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "GenSimADetHit.hh"
#include "GenSimTrackInformation.hh"

class G4Step;
class G4HCofThisEvent;

class GenSimADetSD : public G4VSensitiveDetector
{

public:
  GenSimADetSD(G4String name, G4int cell);
  virtual ~GenSimADetSD();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

  G4int GetCellNumber() {return Cell;};

private:
  
  GenSimADetHitsCollection*  HitsCollection;
  G4String theCollectionName;
  G4int theCollectionID;
  G4int Cell;

};
#endif


