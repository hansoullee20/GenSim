#ifndef GenSimADetHit_h
#define GenSimADetHit_h 

//Note: A hit is registered for every step along a track, within a volume

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

class GenSimADetHit : public G4VHit
{
public:

  GenSimADetHit();
  virtual ~GenSimADetHit();

  virtual void Draw();
  virtual void Print();
  
private:
  
  G4double EnergyDeposit;            //Energy deposited for this hit
  G4double StepLength;               //Step length for this hit
  // G4double StepVertex;

  G4double CosineZ;                  //Cosine of original track direction w.r.t Z-axis
  G4double CosineY;                  //Cosine of original track direction w.r.t Y-axis
                                     //Track may change direction after creation 
                                     //we must be careful to calculate the cosines w.r.t
                                     //the original track direction

  G4int CellNumber;                  //This is the copy number from G4VPlacement
                                     //when the volumes were created

  G4int VCellNumber;                  //This is the cell number where the track this hit belongs to was created

 
  G4int Particle;                  //Type of particle that produced this hit; parameterized according to the definitions in TrackingInformation.hh 

  G4ThreeVector TrackVertexMomentumDirection;
  G4ThreeVector TrackVertexPosition;
  G4double      TrackVertexTheta;
  G4double      TrackVertexPhi;
  G4double      TrackVertexKineticEnergy;
  G4double      TrackKineticEnergy;

  G4int EdgeEvent;

public:

  void SetEdgeEvent() {EdgeEvent = 1;};
  G4int GetEdgeEvent() {return EdgeEvent;};
  
  void StoreTrackKineticEnergy(G4double kEng){TrackKineticEnergy = kEng;};
  G4double GetTrackKineticEnergy(){return TrackKineticEnergy;};

  void StoreEnergyDeposit(G4double eDep) { EnergyDeposit = eDep;};
  G4double GetEnergyDeposit() { return EnergyDeposit;};
  
  void StoreStepLength(G4double dx) { StepLength = dx;};
  G4double GetStepLength() { return StepLength;};

  // void StoreStepVertex(G4double v) { StepVertex = v;};
  // G4double GetStepVertex() { return StepVertex;};

  void StoreCosineZ(G4double cos) { CosineZ = cos;};
  G4double GetCosineZ() { return CosineZ;};
  
  void StoreCosineY(G4double cos) { CosineY = cos;};
  G4double GetCosineY() { return CosineY;};

  void  StoreCellNumber(G4int cell) { CellNumber = cell;};
  G4int GetCellNumber(){return CellNumber;};

  void  StoreVertexCellNumber(G4int cell) { VCellNumber = cell;};
  G4int GetVertexCellNumber(){return VCellNumber;};

  void  SetParticleType(G4int type) { Particle = type; }
  G4int GetParticleType(){ return Particle; }

  void StoreTrackVertexMomentumDirection(G4ThreeVector vmom) {TrackVertexMomentumDirection = vmom;};
  void StoreTrackVertexPosition(G4ThreeVector vpos) {TrackVertexPosition = vpos;};
  void StoreTrackVertexKineticEnergy(G4double vEng) {TrackVertexKineticEnergy = vEng;};
  void StoreTrackVertexTheta(G4double vtheta) {TrackVertexTheta = vtheta;};
  void StoreTrackVertexPhi(G4double vphi) {TrackVertexPhi = vphi;};

  G4ThreeVector GetTrackVertexMomentumDirection(){return TrackVertexMomentumDirection;};
  G4ThreeVector GetTrackVertexPosition(){return TrackVertexPosition;};
  G4double GetTrackVertexTheta(){return TrackVertexTheta;};
  G4double GetTrackVertexPhi(){return TrackVertexPhi;};
  G4double GetTrackVertexKineticEnergy(){return TrackVertexKineticEnergy;};
  
};

typedef G4THitsCollection<GenSimADetHit> GenSimADetHitsCollection;

// extern G4Allocator<GenSimADetHit>  GenSimADetHitAllocator;


#endif
