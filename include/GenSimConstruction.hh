#ifndef GenSimConstruction_h
#define GenSimConstruction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "G4VUserDetectorConstruction.hh"

#include "GenSimADetMessenger.hh"
#include "GenSimMaterial.hh"
#include "GenSimADet.hh"
#include "GenSimMessenger.hh"
#include "GenSimUserInformation.hh"

class GenSimADetMessenger;
class GenSimMaterial;
class GenSimADet;
class GenSimMessenger;
class GenSimUserInformation;

class GenSimConstruction : public G4VUserDetectorConstruction
{
  public:
  
     GenSimConstruction(GenSimUserInformation*);
    ~GenSimConstruction();

public:
  
  G4VPhysicalVolume* Construct();

  void UpdateGeometry();

  G4double   GetWorldFullLengthInX()    {return fWorldLengthInX;}
  G4double   GetWorldFullLengthInY()    {return fWorldLengthInY;}
  G4double   GetWorldFullLengthInZ()    {return fWorldLengthInZ;}

private:

  GenSimUserInformation *myUserInfo;
  G4VPhysicalVolume* ConstructExp();  
  
  void DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth=0);
  
  GenSimMaterial*    Material;
  GenSimADet*        ADet;

  GenSimMessenger*  Messenger;  

  G4Box*             World_Solid;     
  G4LogicalVolume*   World_Logical;   
  G4VPhysicalVolume* World_Physical;  
  G4Material*        World_Material; 
  
  G4double fWorldLength;    
  G4double fWorldLengthInX; 
  G4double fWorldLengthInY; 
  G4double fWorldLengthInZ; 
};

#endif
