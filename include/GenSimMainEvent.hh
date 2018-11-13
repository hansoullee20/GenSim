#ifndef GenSimMainEvent_h
#define GenSimMainEvent_h

#include "cpp_include.h"
#include "Root_include.h"

// #ifndef __CINT__
// #include "Geant4_include.hh" 
// #endif

// user includes
#include "GenSimPrimaryEvent.hh"
#include "GenSimADetEvent.hh"    

class GenSimPrimaryEvent;   
class GenSimEvent;    

class GenSimMainEvent 
{

private:

public:
    
  GenSimPrimaryEvent        GenSimPrimEvent;

  GenSimADetEvent         GenSimEvent;

  Float_t TrackVertexPositionX;
  Float_t TrackVertexPositionY;
  Float_t TrackVertexPositionZ;
  Float_t TrackVertexTotalKineticEnergy;


  void SetTrackVertexPositionX       (Float_t val){TrackVertexPositionX       = val;};      
  void SetTrackVertexPositionY       (Float_t val){TrackVertexPositionY       = val;};      
  void SetTrackVertexPositionZ       (Float_t val){TrackVertexPositionZ       = val;};      

  // void CalculateVertexTotalKineticEnergy() {TrackVertexTotalKineticEnergy = TrackVertexTritonKineticEnergy + TrackVertexProtonKineticEnergy;};

  void Initialize();


public:

  GenSimMainEvent();

  virtual ~GenSimMainEvent();
  
  ClassDef(GenSimMainEvent,2)

};

#endif 
