#ifndef GenSimPrimaryEventGenerator_h
#define GenSimPrimaryEventGenerator_h

#include "cpp_include.h"
#include "Root_include.h"

#ifndef __CINT__
#endif

class GenSimPrimaryEventGenerator 
{

private:

  Float_t CurrentEnergy;

  // TH1F *SNSFNPBSpectrum;
  // TH1F *MomentumXDistribution;
  // TH1F *MomentumYDistribution;
  // TH1F *MomentumZDistribution;

public:
  
  GenSimPrimaryEventGenerator();
  virtual ~GenSimPrimaryEventGenerator();

  void     Initialize();

  void    SetRndmSeed(Int_t sd = 0) {gRandom->SetSeed(sd);};

  Float_t GetRandomEnergy(Float_t minE = 2.4e-5 /*eV*/ , Float_t maxE = 0.38 /*eV*/);
  Float_t GetRandomMomentumX();
  Float_t GetRandomMomentumY();
  Float_t GetRandomMomentumZ();
  Float_t GetRandomOriginX();
  Float_t GetRandomOriginY();
  Float_t GetRandomOriginZ();
  

  ClassDef(GenSimPrimaryEventGenerator,1)

};

#endif 
