#include "GenSimPrimaryGeneratorActionMessenger.hh"

GenSimPrimaryGeneratorActionMessenger::GenSimPrimaryGeneratorActionMessenger(GenSimPrimaryGeneratorAction* pPhys)
  :pPrimaryGeneratorAction(pPhys)
{
  Dir = new G4UIdirectory("/LYSO/PrimaryGenerator/");
  Dir->SetGuidance("UI commands of this example");
 
  verboseCmd = new G4UIcmdWithAnInteger("/LYSO/PrimaryGenerator/verbose",this);  
  verboseCmd->SetGuidance("set verbose for primary generator");
  verboseCmd->SetParameterName("verbose",true);
  verboseCmd->SetDefaultValue(1);
  verboseCmd->SetRange("verbose>=0");
  verboseCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  resetCmd = new G4UIcmdWithoutParameter("/LYSO/PrimaryGenerator/ResetNtupleEventCounter",this);  
  resetCmd->SetGuidance("resets Ntuple Event Counter");
  resetCmd->AvailableForStates(G4State_Idle);  

  InitEventCounterCmd = new G4UIcmdWithAnInteger("/LYSO/PrimaryGenerator/StartingEvent",this);
  InitEventCounterCmd->SetGuidance("set starting event count for primary generator");
  InitEventCounterCmd->SetParameterName("StartingEvent",true);
  InitEventCounterCmd->SetDefaultValue(1);
  InitEventCounterCmd->SetRange("StartingEvent>=0");
  InitEventCounterCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}

GenSimPrimaryGeneratorActionMessenger::~GenSimPrimaryGeneratorActionMessenger()
{
  delete verboseCmd;
  delete resetCmd;
  delete Dir;
}

void GenSimPrimaryGeneratorActionMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{       
  if( command == resetCmd )
    {pPrimaryGeneratorAction->ResetNtupleEventCounter(); }

  if( command == InitEventCounterCmd )
    { pPrimaryGeneratorAction->SetNtupleEventCounter(InitEventCounterCmd->GetNewIntValue(newValue)); }
}
