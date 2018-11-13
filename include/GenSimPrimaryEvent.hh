#ifndef GenSimPrimaryEvent_h
#define GenSimPrimaryEvent_h

#include "cpp_include.h"
#include "Root_include.h"

#ifndef __CINT__
#endif

class GenSimPrimaryEvent 
{

private:

  Int_t   TrackID;
  Float_t GlobalTime;

  Float_t OriginVertexPositionX;
  Float_t OriginVertexPositionY;
  Float_t OriginVertexPositionZ;

  Float_t OriginVertexMomentumX;
  Float_t OriginVertexMomentumY;
  Float_t OriginVertexMomentumZ;

  Float_t OriginVertexThetaAngle;
  Float_t OriginVertexPhiAngle;

  Float_t OriginVertexKineticEnergy;
  Float_t OriginVertexNeutronWavelength;

  Float_t PrimaryEnergy;
  Int_t   PrimaryEventNumber;

public:
  
  GenSimPrimaryEvent();
  virtual ~GenSimPrimaryEvent();

  void     Initialize();
  void     PrintData();

  void     StoreTrackID(Int_t tid)    { TrackID = tid; }
  Int_t      GetTrackID() const {return TrackID;}

  void     StoreGlobalTime(Float_t gtime) { GlobalTime = gtime; }
  Float_t    GetGloablTime()  const {return GlobalTime;}

  //-----------------
  void     StoreOriginVertexPositionX(Float_t vx)   { OriginVertexPositionX = vx; }
  Float_t    GetOriginVertexPositionX() const {return OriginVertexPositionX;}

  void     StoreOriginVertexPositionY(Float_t vy)   { OriginVertexPositionY = vy; }
  Float_t    GetOriginVertexPositionY() const {return OriginVertexPositionY;}

  void     StoreOriginVertexPositionZ(Float_t vz)   { OriginVertexPositionZ = vz; }
  Float_t    GetOriginVertexPositionZ() const {return OriginVertexPositionZ;}
  //-----------------
  void     StoreOriginVertexMomentumX(Float_t vx)   { OriginVertexMomentumX = vx; }
  Float_t    GetOriginVertexMomentumX() const {return OriginVertexMomentumX;}

  void     StoreOriginVertexMomentumY(Float_t vy)   { OriginVertexMomentumY = vy; }
  Float_t    GetOriginVertexMomentumY() const {return OriginVertexMomentumY;}

  void     StoreOriginVertexMomentumZ(Float_t vz)   { OriginVertexMomentumZ = vz; }
  Float_t    GetOriginVertexMomentumZ() const {return OriginVertexMomentumZ;}
  //-----------------
  void     StoreOriginVertexThetaAngle(Float_t theta) { OriginVertexThetaAngle = theta; }
  Float_t    GetOriginVertexThetaAngle() const  {return OriginVertexThetaAngle;}

  void     StoreOriginVertexPhiAngle(Float_t phi)  { OriginVertexPhiAngle = phi; }
  Float_t    GetOriginVertexPhiAngle() const {return OriginVertexPhiAngle;}
  //-----------------
  void     StoreOriginVertexKineticEnergy(Float_t ekin) { OriginVertexKineticEnergy = ekin; }
  Float_t    GetOriginVertexKineticEnergy() const {return OriginVertexKineticEnergy;}

  void     StoreOriginVertexNeutronWavelength(Float_t wvl) { OriginVertexNeutronWavelength = wvl; }
  Float_t    GetOriginVertexNeutronWavelength() const {return OriginVertexNeutronWavelength;}

  //-----------------
  void     StorePrimaryEventNumber(Int_t pen)    { PrimaryEventNumber = pen; }
  Int_t      GetPrimaryEventNumber() const {return PrimaryEventNumber; }
  //-----------------

  ClassDef(GenSimPrimaryEvent,1)

};

#endif 
