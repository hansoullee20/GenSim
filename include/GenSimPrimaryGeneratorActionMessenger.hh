#ifndef GenSimPrimaryGeneratorActionMessenger_h
#define GenSimPrimaryGeneratorActionMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "GenSimPrimaryGeneratorAction.hh"

class GenSimPrimaryGeneratorAction;

class GenSimPrimaryGeneratorActionMessenger: public G4UImessenger
{
public:  
   GenSimPrimaryGeneratorActionMessenger(GenSimPrimaryGeneratorAction* );
  ~GenSimPrimaryGeneratorActionMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);
    
private:  
  
  GenSimPrimaryGeneratorAction*     pPrimaryGeneratorAction;
  
  G4UIdirectory*           Dir;
  G4UIcmdWithAnInteger*    verboseCmd;
  G4UIcmdWithoutParameter* resetCmd;
  G4UIcmdWithAnInteger     *InitEventCounterCmd;

};

#endif
