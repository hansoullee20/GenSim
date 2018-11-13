#include "GenSimPrimaryGeneratorAction.hh"

GenSimPrimaryGeneratorAction::GenSimPrimaryGeneratorAction( GenSimUserInformation* myUI)
  : myUserInfo(myUI)
{

  myMessenger = new GenSimPrimaryGeneratorActionMessenger(this);

  myEventCounter = 0;

  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);  
  eventGenerator = new GenSimPrimaryEventGenerator;
}

GenSimPrimaryGeneratorAction::~GenSimPrimaryGeneratorAction()
{
  if (particleGun) delete particleGun;

}

void GenSimPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  // G4ParticleDefinition* particle = particleTable->FindParticle("neutron");
  G4ParticleDefinition* particle = particleTable->FindParticle("e-");
  particleGun->SetParticleDefinition(particle);
  // G4double myEnergy = eventGenerator->GetRandomEnergy(0,15.0e-3)*eV;
  G4double myEnergy = 1.0e9*eV;

  G4double myPositionX =  -8.0*cm + 16.0*cm;
  G4double myPositionY =  -8.0*cm + 16.0*cm;
  G4double myPositionZ =  -200.0*cm;

  particleGun->SetParticlePosition(G4ThreeVector( myPositionX,
						  myPositionY,
						  myPositionZ ));
  // G4double divAngle = TMath::ATan(0.01);
  // G4double phi = 2.0*TMath::Pi()*G4UniformRand();

  G4double myNormMomentumX =  0.;//TMath::Cos(phi)*TMath::Sin(divAngle);
  G4double myNormMomentumY =  0.;//TMath::Sin(phi)*TMath::Sin(divAngle);
  G4double myNormMomentumZ =  1.;//TMath::Cos(divAngle);

  particleGun->SetParticleMomentumDirection(G4ThreeVector( myNormMomentumX ,
							   myNormMomentumY,
							   myNormMomentumZ));

  // G4double pPolX =  0;
  // G4double pPolY =  0;
  // G4double pPolZ =  1;

//   particleGun->SetParticlePolarization(G4ThreeVector(pPolX,pPolY,pPolZ));
  
  particleGun->SetParticleEnergy(myEnergy);

  // finally : fire !!!
  particleGun->GeneratePrimaryVertex(anEvent);

  // fill user track info: store Q2 value of this primary 
  myUserInfo->SetPrimaryEnergy(myEnergy);

  // increase my own event counter for next primary
  myEventCounter += 1;

  // fill user track info: store primary event number 
  myUserInfo->SetPrimaryEventNumber( (G4int) myEventCounter );
  
  // print the stored values
  myUserInfo->Print();
  
  // if(myEventCounter%100 == 0)
  //   G4cout << "Capture Event# " << myEventCounter << G4endl;
}
