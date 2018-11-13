#include "GenSimADetMessenger.hh"

GenSimADetMessenger::GenSimADetMessenger(GenSimADet* theDet)
  :ADet(theDet)
{ 

  Dir = new G4UIdirectory("/ADet/");
  Dir -> SetGuidance("Detector control.");

  ADetZPositionCmd =  new G4UIcmdWithADoubleAndUnit("/ADet/SetCenterPositionInZ",this);
  ADetZPositionCmd->SetGuidance("Set the Z position of the ADet container center"); 
  ADetZPositionCmd->SetParameterName("Size",true);
  ADetZPositionCmd->SetUnitCategory("Length");
  ADetZPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ADetYPositionCmd =  new G4UIcmdWithADoubleAndUnit("/ADet/SetCenterPositionInY",this);
  ADetYPositionCmd->SetGuidance("Set the Y position of the ADet container center"); 
  ADetYPositionCmd->SetParameterName("Size",true);
  ADetYPositionCmd->SetUnitCategory("Length");
  ADetYPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ADetXPositionCmd =  new G4UIcmdWithADoubleAndUnit("/ADet/SetCenterPositionInX",this);
  ADetXPositionCmd->SetGuidance("Set the X position of the ADet container center"); 
  ADetXPositionCmd->SetParameterName("Size",true);
  ADetXPositionCmd->SetUnitCategory("Length");
  ADetXPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ADetMatCmd = new G4UIcmdWithAString("/ADet/SetMaterial",this);
  ADetMatCmd->SetGuidance("Select Material of the ADet.");
  ADetMatCmd->SetParameterName("choice",false);
  ADetMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

GenSimADetMessenger::~GenSimADetMessenger()
{
  if (ADetXPositionCmd)      delete ADetXPositionCmd;
  if (ADetYPositionCmd)      delete ADetYPositionCmd;
  if (ADetZPositionCmd)      delete ADetZPositionCmd;

  if (ADetMatCmd)            delete ADetMatCmd;
  if (Dir)                     delete Dir;
}

void GenSimADetMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == ADetXPositionCmd )
   {
     ADet->SetCenterPositionInX(ADetXPositionCmd->GetNewDoubleValue(newValue));
   }

  if( command == ADetYPositionCmd )
  {
      ADet->SetCenterPositionInY(ADetYPositionCmd->GetNewDoubleValue(newValue));
   }
  
  if( command == ADetZPositionCmd )
  {
      ADet->SetCenterPositionInZ(ADetZPositionCmd->GetNewDoubleValue(newValue));
  }
  
  if( command == ADetMatCmd )
    { 
      ADet->SetMaterial(newValue);
   }
}
