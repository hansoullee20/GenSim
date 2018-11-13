#ifndef GenSimUserInformation_h
#define GenSimUserInformation_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "GenSimTrackInformation.hh"


class GenSimUserInformation 
{
public:
  
   GenSimUserInformation();
  ~GenSimUserInformation();

private:

  G4double primaryEnergy;
  G4int    myRunID;
  G4int    primaryEventNumber;

 public:

  void Print() const;
  void Initialize();

  void SetMyRunID(G4int ID){ myRunID = ID;};

  void     SetPrimaryEnergy(G4double pE)   {primaryEnergy = pE;}
  G4double GetPrimaryEnergy() const {return primaryEnergy;}

  void     SetPrimaryEventNumber(G4int en)      {primaryEventNumber = en;}
  G4int    GetPrimaryEventNumber() const {return primaryEventNumber;}
  
};

#endif
