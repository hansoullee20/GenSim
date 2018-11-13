#include "GenSimSteppingAction.hh"

GenSimSteppingAction::GenSimSteppingAction(GenSimUserInformation* myUInfo)
{ 
  fSecondary = NULL;
  myUserInfo = myUInfo;
  ErrorVal = G4ThreeVector(1e6,1e6,1e6);
}

void GenSimSteppingAction::UserSteppingAction(const G4Step* theStep)
{ 
  fSecondary = fpSteppingManager->GetfSecondary();
  G4Track*              theTrack     = theStep->GetTrack();
  // G4StepPoint*          thePrePoint  = theStep->GetPreStepPoint();
  // G4VPhysicalVolume*    thePrePV     = thePrePoint->GetPhysicalVolume();
  // G4StepPoint*          thePostPoint = theStep->GetPostStepPoint();
  // G4ParticleDefinition* particleType = theTrack->GetDefinition();
  
  DrawTracks(true, theTrack);
  
  return;
}   
 

void GenSimSteppingAction::DrawTracks(G4bool drawFlag, G4Track *theTrack)
{
  if(drawFlag)
    {
 
      G4ParticleDefinition *particleType = theTrack->GetDefinition();
      
      G4Colour red      ( 255/255.,   0/255.,   0/255.);
      G4Colour blue     (   0/255.,   0/255., 255/255.);
      G4Colour green    (   0/255., 255/255.,   0/255.);
      G4Colour yellow   ( 255/255., 255/255.,   0/255.);
      
      G4Colour white    ( 255/255., 255/255., 255/255.);
      
      G4Colour orange   ( 255/255., 127/255.,   0/255.);
      G4Colour magenta  ( 237/255., 173/255., 255/255.);           
      G4Colour magenta1 ( 104/255.,  49/255.,  94/255.);
      
      G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
      
      if (pVVisManager) {
	const G4SteppingManager* pSM = fpSteppingManager;
	G4Polyline polyline;
        
	// G4double charge = pSM->GetTrack()->GetDefinition()->GetPDGCharge();
        
	G4Colour colour;
        

	//G4cout<<"ParType:"<<particleType->GetParticleType()<<G4endl;
        if( particleType == G4Gamma::GammaDefinition()){
          colour = green;
          //G4cout<<"GREEN_GAMMA!!"<<G4endl;
        }
        if( particleType == G4Electron  ::ElectronDefinition())
          { 
	    //G4cout<<"ELECTRON_RED!!"<<G4endl;
	    colour = red; 
	  }
        // if( particleType == G4Electron  ::PositronDefinition())
        //   { 
	//     //G4cout<<"ELECTRON_RED!!"<<G4endl;
	//     colour = ble; 
	//   }

	// if      (charge < 0.) colour = red;
	// else if (charge > 0.) colour = blue;
	// else                  colour = green;
                
	G4VisAttributes attribs(colour);
        
	polyline.SetVisAttributes(attribs);
	polyline.push_back(pSM->GetStep()->GetPreStepPoint()->GetPosition());
	polyline.push_back(pSM->GetStep()->GetPostStepPoint()->GetPosition());
        
	pVVisManager -> Draw(polyline);
      }
    }
}


G4int GenSimSteppingAction::GetTrackVectorStartIndex()
{
  if(!fSecondary) return -1;
  return (*fSecondary).size() - GetTotalNumOfSecondaries();
}
G4int GenSimSteppingAction::GetTrackVectorSize()
{
  if(!fSecondary) return 0;
  return (*fSecondary).size();
}

G4ParticleDefinition *GenSimSteppingAction::GetSecondaryParticleDefinition(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return NULL; 
  return (*fSecondary)[idx]->GetDefinition();
}
 
G4String GenSimSteppingAction::GetSecondaryParticleName(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return "undefined"; 
  return (*fSecondary)[idx]->GetDefinition()->GetParticleName();
}

G4double GenSimSteppingAction::GetSecondaryParticleTotalEnergy(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return -1; 
  return (*fSecondary)[idx]->GetTotalEnergy();
}

G4double GenSimSteppingAction::GetSecondaryParticleKineticEnergy(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return -1; 
  return (*fSecondary)[idx]->GetKineticEnergy();
}

G4double GenSimSteppingAction::GetSecondaryParticleXOrigin(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return 1e6; 
  return (*fSecondary)[idx]->GetPosition().x();
}

G4double GenSimSteppingAction::GetSecondaryParticleYOrigin(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return 1e6; 
  return (*fSecondary)[idx]->GetPosition().y();
}

G4double GenSimSteppingAction::GetSecondaryParticleZOrigin(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return 1e6; 
  return (*fSecondary)[idx]->GetPosition().z();
}

G4ThreeVector GenSimSteppingAction::GetSecondaryParticleOrigin(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) {return ErrorVal;} 
  return (*fSecondary)[idx]->GetPosition();
}
      
G4ThreeVector GenSimSteppingAction::GetSecondaryParticleMomentum(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) {return ErrorVal;}  
  return (*fSecondary)[idx]->GetMomentumDirection();
}

G4String GenSimSteppingAction::GetSecondaryCreatorProcessName(G4int idx)
{
  if(!fSecondary || idx >= GetTrackVectorSize() || idx < GetTrackVectorStartIndex()) return "undefined"; 
  return (*fSecondary)[idx]->GetCreatorProcess()->GetProcessName();
}



