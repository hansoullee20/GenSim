#include "GenSimMainEvent.hh"

ClassImp(GenSimMainEvent)

GenSimMainEvent::GenSimMainEvent()
{;} 

GenSimMainEvent::~GenSimMainEvent()
{;}

void GenSimMainEvent::Initialize()
{

  TrackVertexPositionX = -20.;
  TrackVertexPositionY = -20.;
  TrackVertexPositionZ = 1000.;

  TrackVertexTotalKineticEnergy = 0.;

  GenSimPrimEvent.Initialize();
  GenSimEvent.Initialize();
}
