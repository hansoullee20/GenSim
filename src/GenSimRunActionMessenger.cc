#include "GenSimRunActionMessenger.hh"

GenSimRunActionMessenger::GenSimRunActionMessenger(GenSimRunAction* theRunAction)
  :RunAction(theRunAction)
{ 

  Dir = new G4UIdirectory("/RunAction/");
  Dir -> SetGuidance("My Run Action Control");

  MyRunIDCmd = new G4UIcmdWithAnInteger("/RunAction/SetID",this);
  MyRunIDCmd->SetGuidance("Set the run ID.");
  MyRunIDCmd->SetParameterName("choice",false);
  MyRunIDCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}

GenSimRunActionMessenger::~GenSimRunActionMessenger()
{
  if (MyRunIDCmd)   delete MyRunIDCmd;
  if (Dir) delete Dir;
}

void GenSimRunActionMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == MyRunIDCmd ){
    if(RunAction)
      RunAction->SetMyRunID(MyRunIDCmd->GetNewIntValue(newValue)); 
  }
}
