#ifndef GenSimADetMessenger_h
#define GenSimADetMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "GenSimADet.hh"

class GenSimADet;

class GenSimADetMessenger: public G4UImessenger
{
  public:
    GenSimADetMessenger(GenSimADet*);
   ~GenSimADetMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  GenSimADet*             ADet;
  
  G4UIdirectory*             Dir;

  G4UIcmdWithAString*        ADetMatCmd;
  G4UIcmdWithADoubleAndUnit* ADetXPositionCmd;
  G4UIcmdWithADoubleAndUnit* ADetYPositionCmd;
  G4UIcmdWithADoubleAndUnit* ADetZPositionCmd;

};

#endif
