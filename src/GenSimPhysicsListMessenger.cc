#include "GenSimPhysicsListMessenger.hh"
#include "GenSimPhysicsList.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"

GenSimPhysicsListMessenger::GenSimPhysicsListMessenger(GenSimPhysicsList* pPhys)
:G4UImessenger(),
pPhysicsList(pPhys),Dir(0),fListCmd(0)
{
  Dir = new G4UIdirectory("/Physics/");
  Dir->SetGuidance("UI commands of this example");

  fListCmd = new G4UIcmdWithAString("/testem/phys/addPhysics",this);
  fListCmd->SetGuidance("Add modula physics list.");
  fListCmd->SetParameterName("PList",false);
  fListCmd->AvailableForStates(G4State_PreInit);

 // verboseCmd = new G4UIcmdWithAnInteger("/Physics/verbose",this);
// verboseCmd->SetGuidance("set verbose for physics processes");
// verboseCmd->SetParameterName("verbose",true);
// verboseCmd->SetDefaultValue(1);
// verboseCmd->SetRange("verbose>=0");
// verboseCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

//   cerenkovCmd = new G4UIcmdWithAnInteger("/Physics/CerenkovMaxPhotonsPerStep",this);
//   cerenkovCmd->SetGuidance("set max nb of photons per step");
//   cerenkovCmd->SetParameterName("MaxNumber",false);
//   cerenkovCmd->SetRange("MaxNumber>=0");
//   cerenkovCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

GenSimPhysicsListMessenger::~GenSimPhysicsListMessenger()
{
  // delete verboseCmd;
//   delete cerenkovCmd;
  delete fListCmd;
  delete Dir;
}

// void GenSimPhysicsListMessenger::SetNewValue(G4UIcommand* command,
//                                           G4String newValue)
// {
//   // // if( command == verboseCmd )
//   //  { pPhysicsList->SetVerbose(verboseCmd->GetNewIntValue(newValue));}
//
// //   if( command == cerenkovCmd )
// //    {pPhysicsList->SetNbOfPhotonsCerenkov(cerenkovCmd->GetNewIntValue(newValue));}
// }
