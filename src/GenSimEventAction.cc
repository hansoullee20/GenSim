#include "GenSimEventAction.hh"

GenSimEventAction::GenSimEventAction(GenSimAnalysis* AN, GenSimUserInformation* myUI)
{
  analysis    = AN;
  myUserInfo  = myUI;
}


GenSimEventAction::~GenSimEventAction()
{

}


void GenSimEventAction::BeginOfEventAction(const G4Event* evt)
{
 
  // G4SDManager * SDman = G4SDManager::GetSDMpointer();

}

void GenSimEventAction::EndOfEventAction(const G4Event* evt)
{
  Initialize();

//=======================================================================
// Save the Ntuple periodically so we have some data in case of a crash

  G4int eventNumber = evt->GetEventID();
  
  if (eventNumber%10000 == 1) analysis->AutoSaveRootNtuple();
//=======================================================================


} // end of  GenSimEventAction::EndOfEventAction()

void GenSimEventAction::Initialize()
{	  
	  
}

