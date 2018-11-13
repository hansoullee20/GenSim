#ifndef GenSimRunActionMessenger_h
#define GenSimRunActionMessenger_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "GenSimRunAction.hh"

class GenSimRunAction;

class GenSimRunActionMessenger: public G4UImessenger
{
public:
    GenSimRunActionMessenger(GenSimRunAction*);
  ~GenSimRunActionMessenger();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  GenSimRunAction*          RunAction;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;

};

#endif
