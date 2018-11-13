#ifndef GenSimADetEvent_h
#define GenSimADetEvent_h

#include "cpp_include.h"
#include "Root_include.h"

// #ifndef __CINT__
// #include "Geant4_include.hh" 
// #endif


class GenSimADetEvent 
{

private:
  
  vector <Float_t> KinE_p;
  vector <Float_t> dEdx_p;
  vector <Float_t> dE_p;
  vector <Float_t> dx_p;
  vector <Float_t> x_p;
  
  vector <Float_t> KinE_t;
  vector <Float_t> dEdx_t;
  vector <Float_t> dE_t;
  vector <Float_t> dx_t;
  vector <Float_t> x_t;

  Int_t  EdgeEvent_p;
  Int_t  EdgeEvent_t;
  Int_t  EventVertexCell;


public:

  // Constructor
  GenSimADetEvent();
  // Destructor 
  virtual ~GenSimADetEvent();

  void Initialize();

  void SetData(Int_t cell, Float_t eDep_p, Float_t eDep_t, 
	       Float_t cosZ_p, Float_t cosY_p, Float_t cosZ_t, 
	       Float_t cosY_t, Int_t evt);

  void SetEventVertexCell(Int_t cell){EventVertexCell = cell;};
  Int_t GetEventVertexCell(){return EventVertexCell;};
 
  void SetEdgeEvent(Int_t edge, Int_t particle);
  void SetdEdx(Float_t dE, Float_t kE, Float_t dx, Int_t particle);

  ClassDef(GenSimADetEvent,1)

};

#endif 
