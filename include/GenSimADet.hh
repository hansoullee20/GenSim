#ifndef GenSimADet_h
#define GenSimADet_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "GenSimADetMessenger.hh"
#include "GenSimADetSD.hh"

#include "GenSimMaterial.hh"
#include "GenSimUserInformation.hh"

class GenSimADetMessenger;

class GenSimADet 
{
public:
  GenSimADet(GenSimUserInformation*);
  ~GenSimADet();

  void ConstructComponent(G4VPhysicalVolume* MotherVolume);
  void DefineMaterial(G4double pre = 1.0);
  void DefineGeometry();
  void DestroyComponent();
  void SetMaterial(G4String materialName);
  void SetPressure(G4double pr);

  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos) ;

  // void SetCollimatorPositionInZ(G4double zPos);
  // void SetCollimatorSize(G4double zPos);

  // void SetCollimatorLowX(G4double xLow)  ;
  // void SetCollimatorHighX(G4double xHigh);
  // void SetCollimatorLowY(G4double yLow)  ;
  // void SetCollimatorHighY(G4double yHigh);

  void GeometryUpdate();

  G4LogicalVolume*   GetLogicalVolume()    {return ADetLogical;} 
  G4VPhysicalVolume* GetPhysicalVolume()   {return ADetPhysical;} 

private:

  GenSimUserInformation *myUserInfo;

  GenSimADetMessenger* ADetMessenger;

  GenSimMaterial*  Material;

  G4VPhysicalVolume* dMotherVolume;

  G4LogicalVolume*   ADetLogical; 
  G4VPhysicalVolume* ADetPhysical; 
  G4Material*        ADetMaterial;

  G4LogicalVolume*   CellLogical[9]; 

  G4LogicalVolume*   TestLogical;                                      
  G4VPhysicalVolume* TestPhysical;
  G4Material*        TestMaterial;

  G4double ADetFullLengthX;
  G4double ADetFullLengthY;
  G4double ADetFullLengthZ;

  G4double ADetCenterZPosition;

  G4ThreeVector     PositionADet;
  G4RotationMatrix* RotationADet;  

  G4double PositionADetX;
  G4double PositionADetY;
  G4double PositionADetZ;

  G4VSensitiveDetector* ADetSD;

};
#endif
