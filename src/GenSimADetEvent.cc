#include "GenSimADetEvent.hh"

ClassImp(GenSimADetEvent);

GenSimADetEvent::GenSimADetEvent() 
{
  Initialize();
} 

GenSimADetEvent::~GenSimADetEvent()
{ 

}

void GenSimADetEvent::Initialize()
{
  // for(int i = 0; i < 144; i++){

  //   cellData[i].ProtonEnergyDeposit = -1.;
  //   cellData[i].TritonEnergyDeposit = -1.;
  //   cellData[i].ProtonCosineZ = 0.;
  //   cellData[i].ProtonCosineY = 0.;
  //   cellData[i].TritonCosineZ = 0.;
  //   cellData[i].TritonCosineY = 0.;
  //   cellData[i].Event = -1;
  //   cellData[i].Cell = -1;
  // }   

  KinE_p.clear();
  KinE_p.resize(0);
  dEdx_p.clear();
  dEdx_p.resize(0);
  dE_p.clear();
  dE_p.resize(0);
  dx_p.clear();
  dx_p.resize(0);
  x_p.clear();
  x_p.resize(0);
  EdgeEvent_p = 0;

  KinE_t.clear();
  KinE_t.resize(0);
  dEdx_t.clear();
  dEdx_t.resize(0);
  dE_t.clear();
  dE_t.resize(0);
  dx_t.clear();
  dx_t.resize(0);
  x_t.clear();
  x_t.resize(0);
  EdgeEvent_t = 0;
  EventVertexCell = -10;

}	

//These are defined in "TrackInformation"
// #define myElectron 1
// #define myPositron 2
// #define myGamma    3  //as in non-optical photon including x-ray
// #define myProton   4
// #define myNeutron  5
// #define myTriton   6
// #define myAlpha    7
// #define myHelium3  8
// #define myNucleus  9

void GenSimADetEvent::SetEdgeEvent(Int_t edge, Int_t particle) 
{
  if(particle == 4) //a proton
    EdgeEvent_p += edge; 
  if(particle == 6) //a triton
    EdgeEvent_t += edge; 
}

void GenSimADetEvent::SetdEdx(Float_t dE, Float_t kE, Float_t dx, Int_t particle) 
{
  // Int_t n = 0;
  
}

void GenSimADetEvent::SetData(Int_t cell, Float_t eDep_p, Float_t eDep_t, 
				 Float_t cosZ_p, Float_t cosY_p, Float_t cosZ_t, 
				 Float_t cosY_t, Int_t evt)
{
  // if(cell < 0 || cell > 143) return;
  
  // cellData[cell].ProtonEnergyDeposit = eDep_p;
  // cellData[cell].TritonEnergyDeposit = eDep_t;
  // cellData[cell].ProtonCosineZ = cosZ_p;
  // cellData[cell].ProtonCosineY = cosY_p;
  // cellData[cell].TritonCosineZ = cosZ_t;
  // cellData[cell].TritonCosineY = cosY_t;
  // cellData[cell].Event = evt;
  // cellData[cell].Cell = cell;
  
}

