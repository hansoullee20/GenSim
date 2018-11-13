#include "GenSimTrackingAction.hh"

GenSimTrackingAction::GenSimTrackingAction(GenSimUserInformation* myUI)
  : myUserInfo(myUI)
{

}

GenSimTrackingAction::~GenSimTrackingAction()
{

}

void GenSimTrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
  G4Track* theTrack = (G4Track*) aTrack;
  GenSimTrackInformation* anInfo = NULL;

//   if( (aTrack->GetParentID()==0) || (aTrack->GetVertexPosition().z() > 560.0*cm) )
//     {
//       fpTrackingManager->SetStoreTrajectory(true);
//       //fpTrackingManager->SetTrajectory(new G4Trajectory(aTrack));
//     }
//   else
//     {
//       fpTrackingManager->SetStoreTrajectory(false);
//     }

  fpTrackingManager->SetStoreTrajectory(true);

  anInfo = new GenSimTrackInformation(aTrack);

  // if(aTrack->GetUserInformation()==0)
  //   anInfo = new GenSimTrackInformation(aTrack);
  // else{
  //   anInfo = (GenSimTrackInformation*)(aTrack->GetUserInformation());
  //   if(anInfo->GetNewSecondaryFlag())
  //     anInfo->StoreTrackInfo(aTrack);
  // }

  anInfo->StoreEventNumber(myUserInfo->GetPrimaryEventNumber());

  if(aTrack->GetDefinition() == G4Electron::ElectronDefinition() && aTrack->GetCreatorProcess()->GetProcessName() == "RadioactiveDecay" ){
    
    // myUserInfo->AddBeta(aTrack->GetKineticEnergy()/MeV);
    
    //G4cout << "Electron with energy : " << (*secondaries)[i]->GetKineticEnergy()/keV << G4endl;
  
  }



  if(aTrack->GetParentID() == 0){
    anInfo->StoreParentEnergy(-1.0);
    anInfo->StoreParentTrackID(-1);
  }
  
  if(aTrack->GetUserInformation()==0){
     theTrack->SetUserInformation(anInfo);
  }      
}

void GenSimTrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
  if(aTrack != NULL){
    if(aTrack->GetParentID() == 0){
      G4TrackVector* secondaries = fpTrackingManager->GimmeSecondaries();
      if(secondaries)
	{
	  G4int nSeco = secondaries->size();
	  if(nSeco>0)
	    {
	      
	    }
	}
    }
  }
}
