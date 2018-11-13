#ifndef GenSimMessenger_h
#define GenSimMessenger_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "GenSimConstruction.hh"

class GenSimConstruction;

class GenSimMessenger: public G4UImessenger
{
  public:
    GenSimMessenger(GenSimConstruction*);
   ~GenSimMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    GenSimConstruction* Construction;
    
    G4UIdirectory*             GenSimDir;
    G4UIcmdWithoutParameter*   UpdateCmd;

};

#endif
