#include "GenSimMessenger.hh"

GenSimMessenger::GenSimMessenger(GenSimConstruction* theConstruction)
  :Construction(theConstruction)
{ 

  GenSimDir = NULL;
  UpdateCmd   = NULL;

  GenSimDir = new G4UIdirectory("/GenSim/");
  GenSimDir->SetGuidance("UI commands specific to this example.");
  
  UpdateCmd = new G4UIcmdWithoutParameter("/GenSim/GeometryUpdate",this);
  UpdateCmd->SetGuidance("Update GenSim geometry.");
  UpdateCmd->SetGuidance("This command MUST be applied before \"beamOn\" ");
  UpdateCmd->SetGuidance("if you changed geometrical value(s).");
  UpdateCmd->AvailableForStates(G4State_Idle);

}

GenSimMessenger::~GenSimMessenger()
{
  if (UpdateCmd)   delete UpdateCmd;
  if (GenSimDir) delete GenSimDir;
}

void GenSimMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{ 
  //G4cout << newValue << endl;

  if( command == UpdateCmd )
   { 
     Construction->UpdateGeometry(); 
   }

}
