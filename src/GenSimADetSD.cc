#include "GenSimADetSD.hh"

GenSimADetSD::GenSimADetSD(G4String name, G4int cell)
  :G4VSensitiveDetector(name)
{
  char buffer[40];
  sprintf(buffer,"HitCollection_%03d",cell);
  theCollectionName = G4String(buffer);

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
  Cell = cell;
}

GenSimADetSD::~GenSimADetSD()
{

}

void GenSimADetSD::Initialize(G4HCofThisEvent* HCE)
{
  HitsCollection = new GenSimADetHitsCollection(SensitiveDetectorName,collectionName[0]);
  theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
  HCE->AddHitsCollection(theCollectionID , HitsCollection);
}

G4bool GenSimADetSD::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
{

  GenSimADetHit* aHit = new GenSimADetHit();
  //G4int snum = aStep->GetTrack()->GetCurrentStepNumber();

  //examples of filling the hit information:

  // G4ThreeVector vmom = aStep->GetTrack()->GetVertexMomentumDirection();
  // G4ThreeVector vpos = aStep->GetTrack()->GetVertexPosition();
  // G4double eDep = (aStep->GetTotalEnergyDeposit() - aStep->GetNonIonizingEnergyDeposit());
  // G4double x = (aStep->GetTrack()->GetVertexMomentumDirection()).x();
  // G4double y = (aStep->GetTrack()->GetVertexMomentumDirection()).y();
  // G4double z = (aStep->GetTrack()->GetVertexMomentumDirection()).z();
  // G4double phi = TMath::ATan2(y,x);//*TMath::RadToDeg()*degree; 
  // if(phi < 0) phi += 2.0*TMath::Pi();//360*degree; 
  // //phi = phi/degree; 
  // G4double theta = TMath::ATan2(TMath::Sqrt(x*x+y*y),z);//*TMath::RadToDeg()*degree; 
  // //theta = theta/degree; 
  // G4int vertcnum = 0;
  // GenSimADetSD* VertexCell = NULL;
  // const G4LogicalVolume *LVol = NULL; 

  // G4int cnum = aStep->GetPreStepPoint()->GetPhysicalVolume()->GetCopyNo();

  // if(aStep->GetTrack()->GetDefinition() == G4Proton::ProtonDefinition() ||
  //    aStep->GetTrack()->GetDefinition() == G4Triton::TritonDefinition()){
  //   if(aHit){

  //     LVol = aStep->GetTrack()->GetLogicalVolumeAtVertex();
  //     if(LVol)
  // 	VertexCell = (GenSimADetSD*)(LVol->GetSensitiveDetector());
  //     if(VertexCell)
  // 	vertcnum = VertexCell->GetCellNumber();

  //     aHit->StoreEnergyDeposit(eDep);
  //     aHit->StoreCosineZ(vmom.z());
  //     aHit->StoreCosineY(vmom.y());
  //     aHit->StoreVertexCellNumber(vertcnum);
  //     if(aStep->GetTrack()->GetDefinition() == G4Proton::ProtonDefinition())
  // 	aHit->SetParticleType(myProton);
  //     if(aStep->GetTrack()->GetDefinition() == G4Triton::TritonDefinition())
  // 	aHit->SetParticleType(myTriton);
      
  //     if(aStep->GetPostStepPoint()->GetStepStatus() == fGeomBoundary)
  // 	if(aStep->GetTrack()->GetNextVolume()->GetName() == "World_Physical")
  // 	  if(aStep->GetTrack()->GetKineticEnergy()-eDep > 0)
  // 	    {
  // 	      aHit->SetEdgeEvent();
  // 	    }
  //     aHit->StoreStepLength(aStep->GetStepLength());
  //     // aHit->StoreStepVertex(aStep->theStep->GetPreStepPoint()->GetPosition());
  //     aHit->StoreTrackKineticEnergy(aStep->GetTrack()->GetKineticEnergy());
      
  //     aHit->StoreTrackVertexMomentumDirection(vmom);
  //     aHit->StoreTrackVertexPosition(vpos);
  //     // aHit->StoreTrackVertexTheta(acos(vmom.z()));
  //     aHit->StoreTrackVertexTheta(theta);
  //     aHit->StoreTrackVertexPhi(phi);
  //     // aHit->StoreTrackVertexPhi(asin(vmom.y()/(sin(acos(vmom.z())))));
  //     aHit->StoreTrackVertexKineticEnergy(aStep->GetTrack()->GetVertexKineticEnergy());
      
      
      
      
  HitsCollection->insert(aHit);
  
  
  return true;
}

void GenSimADetSD::EndOfEvent(G4HCofThisEvent* )
{

}
