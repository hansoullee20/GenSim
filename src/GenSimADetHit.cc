#include "GenSimADetHit.hh"

// G4Allocator<GenSimADetHit> GenSimADetHitAllocator;

GenSimADetHit::GenSimADetHit()
{
  Particle      = -1;
  CosineZ       = 0.;
  CosineY       = 0.;
  EnergyDeposit = 0.;
  CellNumber    = -1;
  StepLength = 0.;
  EdgeEvent = 0;
  TrackKineticEnergy = 0.;
  TrackVertexPhi = -100.;
  TrackVertexTheta = -100.;
  TrackVertexPhi = -100.;
  TrackVertexKineticEnergy = 0.;


}


GenSimADetHit::~GenSimADetHit()
{

}

void GenSimADetHit::Draw()
{
  // G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  // if(pVVisManager)
  // {
    // // draw small yellow balls for the impact point
    // G4Circle circle(worldPos);
    // circle.SetScreenSize(0.01);
    // circle.SetFillStyle(G4Circle::filled);
    // G4Colour colourHit(1.,1.,0.);  // yellow
    // G4VisAttributes attribs(colourHit);
    // circle.SetVisAttributes(attribs);
    // pVVisManager->Draw(circle);
  // }

}

void GenSimADetHit::Print()
{
//   G4cout << " CerenkovDetector[" << DetectorID << "] : time " << time/ns
//          << " (nsec) --- local (x,y,z) [cm] " 
// 	 << localPos.x()/cm << ", " 
// 	 << localPos.y()/cm << ", " 
// 	 << localPos.z()/cm << ", " 
// 	 << G4endl;
}
