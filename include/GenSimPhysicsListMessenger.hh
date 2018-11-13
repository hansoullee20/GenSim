#ifndef GenSimPhysicsListMessenger_h
#define GenSimPhysicsListMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "GenSimPhysicsList.hh"

#include "G4UImessenger.hh"
#include "globals.hh"

class GenSimPhysicsList;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAString;

class GenSimPhysicsListMessenger: public G4UImessenger
{
  public:
    GenSimPhysicsListMessenger(GenSimPhysicsList* );
   ~GenSimPhysicsListMessenger();

  // void SetNewValue(G4UIcommand*, G4String);

  private:
    GenSimPhysicsList*     pPhysicsList;

    G4UIdirectory*        Dir;
    G4UIcmdWithAString* fListCmd;
    //G4UIcmdWithAnInteger* verboseCmd;
    //G4UIcmdWithAnInteger* cerenkovCmd;
};

#endif
