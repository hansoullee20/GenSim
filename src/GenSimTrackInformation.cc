#include "GenSimTrackInformation.hh"

// based on http://geant4.slac.stanford.edu/Tips/index.html

G4Allocator<GenSimTrackInformation> aTrackInformationAllocator;

GenSimTrackInformation::GenSimTrackInformation()
{
  Initialize();
}

GenSimTrackInformation::~GenSimTrackInformation()
{
  //G4cout << "Track info with ID " << GetTrackID() << " is being deleted." << G4endl;
}

GenSimTrackInformation::GenSimTrackInformation(const G4Track* aTrack)
{
  Initialize();

  stepNumber             = 0; 
  TrackID                = aTrack->GetTrackID();
  particleDefinition     = aTrack->GetDefinition();
  if(!aTrack->GetCreatorProcess())
    ParticleCreatorProcess = "Primary";
  else
    ParticleCreatorProcess = aTrack->GetCreatorProcess()->GetProcessName();
  InitialPosition        = aTrack->GetPosition();
  InitialMomentum        = aTrack->GetMomentum();
  InitialEnergy          = aTrack->GetTotalEnergy();
  InitialKineticEnergy   = aTrack->GetKineticEnergy();
  InitialTime            = aTrack->GetGlobalTime();
//   G4double X = InitialMomentum.x();
//   G4double Y = InitialMomentum.y();
//   G4double Z = InitialMomentum.z();
  InitialTheta           = InitialMomentum.cosTheta();//*TMath::RadToDeg();//(TMath::ATan2(TMath::Sqrt(X*X+Y*Y),Z))*TMath::RadToDeg();
  InitialPhi             = InitialMomentum.phi()*TMath::RadToDeg();//(TMath::ATan2(Y,X))*TMath::RadToDeg();
  if(InitialPhi < 0) InitialPhi += 360;
}


GenSimTrackInformation::GenSimTrackInformation(const GenSimTrackInformation* aTrackInfo)
{
  Initialize();

  stepNumber             = aTrackInfo->stepNumber; 
  TrackID                = aTrackInfo->TrackID;
  particleDefinition     = aTrackInfo->particleDefinition;
  ParticleCreatorProcess = aTrackInfo->ParticleCreatorProcess;
  InitialPosition        = aTrackInfo->InitialPosition;
  InitialMomentum        = aTrackInfo->InitialMomentum;
  InitialEnergy          = aTrackInfo->InitialEnergy;
  InitialKineticEnergy   = aTrackInfo->InitialKineticEnergy;
  InitialTime            = aTrackInfo->InitialTime;
  InitialTheta           = aTrackInfo->InitialTheta;
  InitialPhi             = aTrackInfo->InitialPhi;
  eventNumber            = aTrackInfo->eventNumber;
  ParentEnergy           = aTrackInfo->ParentEnergy;
  ParentTrackID          = aTrackInfo->ParentTrackID;

  for(int i = 0; i < aTrackInfo->stepNumber; i++){
    StepEnergyLoss.push_back(aTrackInfo->StepEnergyLoss[i]);
    StepVertex.push_back(aTrackInfo->StepVertex[i]);
    StepFinalEnergy.push_back(aTrackInfo->StepFinalEnergy[i]);
    StepLength.push_back(aTrackInfo->StepLength[i]);
    StepVolume.push_back(aTrackInfo->StepVolume[i]);
    TrackRangeIntegral.push_back(aTrackInfo->TrackRangeIntegral[i]);
    TrackdEdxIntegral.push_back(aTrackInfo->TrackdEdxIntegral[i]);
    StepdEdx.push_back(aTrackInfo->StepdEdx[i]);
    StepDefinedProcess.push_back(aTrackInfo->StepDefinedProcess[i]);
  }
}

void GenSimTrackInformation::StoreTrackInfo(const G4Track* aTrack)
{
  stepNumber             = 0; 
  TrackID                = aTrack->GetTrackID();
  particleDefinition     = aTrack->GetDefinition();
  if(!aTrack->GetCreatorProcess())
    ParticleCreatorProcess = "Primary";
  else
    ParticleCreatorProcess = aTrack->GetCreatorProcess()->GetProcessName();
  InitialPosition        = aTrack->GetPosition();
  InitialMomentum        = aTrack->GetMomentum();
  InitialEnergy          = aTrack->GetTotalEnergy();
  InitialKineticEnergy   = aTrack->GetKineticEnergy();
  InitialTime            = aTrack->GetGlobalTime();
//   G4double X = InitialMomentum.x();
//   G4double Y = InitialMomentum.y();
//   G4double Z = InitialMomentum.z();
  InitialTheta           = InitialMomentum.cosTheta();//*TMath::RadToDeg();//(TMath::ATan2(TMath::Sqrt(X*X+Y*Y),Z))*TMath::RadToDeg();
  InitialPhi             = InitialMomentum.phi()*TMath::RadToDeg();//(TMath::ATan2(Y,X))*TMath::RadToDeg();
  if(InitialPhi < 0) InitialPhi += 360;
}

void GenSimTrackInformation::Print() const
{
}


void GenSimTrackInformation::PrintTrackInfo()
{
  printf("\n\n********** Event %d Track %d Information ************\n\n",eventNumber,TrackID);
  printf("Particle Name   %s  *** Creator Process %s\n\n",particleDefinition->GetParticleName().data(),ParticleCreatorProcess.data());
  printf("Parent Track ID %d  *** Parent Energy %f\n",ParentTrackID,ParentEnergy);

  printf("Initial Position       (%f,%f,%f) [cm]\n",InitialPosition.x()/cm,InitialPosition.y()/cm,InitialPosition.z()/cm);
  printf("Initial Momentum       (%f,%f,%f) [eV]\n",InitialMomentum.x()/eV,InitialMomentum.y()/eV,InitialMomentum.z()/eV);
  printf("Initial Energy                %f  [eV]\n",InitialEnergy/eV);
  printf("Initial Kinetic Energy        %f  [eV]\n",InitialKineticEnergy/eV);
  printf("Initial Time                  %f  [s]\n", InitialTime/s);
  printf("Initial Theta                 %f  [deg]\n",InitialTheta);
  printf("Initial Phi                   %f  [deg]\n",InitialPhi);

  for(int i = 0; i < stepNumber; i++){
    printf("Step %02d\n\n",i+1);
    printf("Position         (%f,%f,%f) [cm]\n",StepVertex[i].x()/cm,StepVertex[i].y()/cm,StepVertex[i].z()/cm);
    printf("Energy deposit          %f  [eV]\n",StepEnergyLoss[i]/eV);
    printf("Length                  %f  [cm]\n",StepLength[i]/cm);
    printf("Track Energy after step %f  [eV]\n",StepFinalEnergy[i]/eV);
    printf("Volume                  %s      \n",StepVolume[i].data());
    printf("Step limiting process   %s      \n",StepDefinedProcess[i].data());
  }
  
}

void GenSimTrackInformation::Initialize()
{

  NewSecondaryFlag       = false;
  stepNumber             = 0;
  TrackID                = 0;
  particleDefinition     = NULL;
  ParticleCreatorProcess = "None";
  InitialPosition        = G4ThreeVector(-2000*m,-2000*m,-2000*m);
  InitialMomentum        = G4ThreeVector(-2000*m,-2000*m,-2000*m);
  InitialEnergy          = 0;
  InitialKineticEnergy   = 0;
  InitialTime            = 0;
  InitialPhi             = 0;
  InitialTheta           = 0;
  ParentEnergy           = -1.0;
  ParentTrackID          = 0;
  eventNumber            = 0;

  StepEnergyLoss.clear();
  StepEnergyLoss.resize(0);
  StepVertex.clear();
  StepVertex.resize(0);
  StepFinalEnergy.clear();
  StepFinalEnergy.resize(0);
  StepLength.clear();
  StepLength.resize(0);
  StepVolume.clear();
  StepVolume.resize(0);
  TrackRangeIntegral.clear();
  TrackRangeIntegral.resize(0);
  TrackdEdxIntegral.clear();
  TrackdEdxIntegral.resize(0);
  StepdEdx.clear();
  StepdEdx.resize(0);
  StepDefinedProcess.clear();
  StepDefinedProcess.resize(0);
}

G4String GenSimTrackInformation::GetStepDefinedProcess(G4int ind)
{
  unsigned uind = (unsigned)ind;

  if(StepDefinedProcess.size() == 0) return "None";
  if(uind >= StepDefinedProcess.size()) return "None";
  return StepDefinedProcess[uind];
}        



G4double GenSimTrackInformation::GetStepdEdx(G4int ind)
{
  unsigned uind = (unsigned)ind;

  if(StepdEdx.size() == 0) return -1.0;
  if(uind >= StepdEdx.size()) return -1.0;
  return StepdEdx[uind];
  
}

G4double GenSimTrackInformation::GetTrackRangeIntegral(G4int ind)
{
  unsigned uind = (unsigned)ind;

  if(TrackRangeIntegral.size() == 0) return -1.0;
  if(uind >= TrackRangeIntegral.size()) return -1.0;
  return TrackRangeIntegral[uind];
  
}

G4double GenSimTrackInformation::GetTrackdEdxIntegral(G4int ind)
{
  unsigned uind = (unsigned)ind;

  if(TrackdEdxIntegral.size() == 0) return -1.0;
  if(uind >= TrackdEdxIntegral.size()) return -1.0;
  return TrackdEdxIntegral[uind];
  
}

G4double GenSimTrackInformation::GetStepEnergyLoss(G4int ind)  
{
  unsigned uind = (unsigned)ind;

  if(StepEnergyLoss.size() == 0) return -1.0;
  if(uind >= StepEnergyLoss.size()) return -1.0;
  return StepEnergyLoss[uind];
}

G4ThreeVector GenSimTrackInformation::GetStepVertex(G4int ind)      
{
  unsigned uind = (unsigned)ind;

  if(StepVertex.size() == 0) return G4ThreeVector(-2000,-2000,-2000);
  if(uind >= StepVertex.size()) return G4ThreeVector(-2000,-2000,-2000);
  return StepVertex[uind];
}

G4double GenSimTrackInformation::GetStepFinalEnergy(G4int ind) 
{
  unsigned uind = (unsigned)ind;

  if(StepFinalEnergy.size() == 0) return -1.0;
  if(uind >= StepFinalEnergy.size()) return -1.0;
  return StepFinalEnergy[uind];
}

G4double GenSimTrackInformation::GetStepLength(G4int ind)      
{
  unsigned uind = (unsigned)ind;

  if(StepLength.size() == 0) return -1.0;
  if(uind >= StepLength.size()) return -1.0;
  return StepLength[uind];

}        

G4String GenSimTrackInformation::GetStepVolume(G4int ind)      
{
  unsigned uind = (unsigned)ind;

  if(StepVolume.size() == 0) return "None";
  if(uind >= StepVolume.size()) return "None";
  return StepVolume[uind];

}        

void GenSimTrackInformation::StoreStepInformation(G4double el, G4ThreeVector vec, 
						   G4double eng, G4double len, 
						   G4String vol, G4String stDP)
{
  
  StepEnergyLoss.push_back(el);
  StepVertex.push_back(vec);
  StepFinalEnergy.push_back(eng);
  StepLength.push_back(len);
  StepVolume.push_back(vol);
  StepDefinedProcess.push_back(stDP);
  if(len > 0) 
    StepdEdx.push_back(el/len);
  else
    StepdEdx.push_back(0.0);
  if(stepNumber == 0) {
    TrackRangeIntegral.push_back(len);
//     TrackdEdxIntegral.push_back(StepdEdx[0]);
    TrackdEdxIntegral.push_back(StepEnergyLoss[0]);
  }
  else{
    TrackRangeIntegral.push_back(TrackRangeIntegral[stepNumber-1]+len);
//     TrackdEdxIntegral.push_back(TrackdEdxIntegral[stepNumber-1]+StepdEdx[stepNumber]);
    TrackdEdxIntegral.push_back(TrackdEdxIntegral[stepNumber-1]+StepEnergyLoss[stepNumber]);
  }

  stepNumber++;
}


