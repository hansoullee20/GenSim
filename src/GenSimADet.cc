#include "GenSimADet.hh"

GenSimADet::GenSimADet(GenSimUserInformation *userInfo)
{	    	    
  // initialize some pointers
  myUserInfo = userInfo;

  ADetMessenger = NULL;
  // Material        = NULL;

  ADetLogical  = NULL;
  ADetPhysical = NULL;
  ADetMaterial = NULL;

  RotationADet = NULL;
 
  ADetSD        = NULL;

  ADetMessenger  = new GenSimADetMessenger(this);

  Material = new GenSimMaterial(userInfo);
  Material->DefineMaterials();
  // ADetMaterial = Material->GetMaterial("N3HeTDGas100");  
  // myUserInfo->SetPressure(1.0);

  // DefineMaterial();
  
  ADetFullLengthX =  15.2*cm;
  ADetFullLengthY =  15.2*cm;
  ADetFullLengthZ =  30.4*cm + 1.3*cm;
}

GenSimADet::~GenSimADet()
{
  delete Material;
  delete ADetMessenger;
}

void GenSimADet::DefineMaterial(G4double pres)
{

}

void GenSimADet::DefineGeometry()
{

}

void GenSimADet::ConstructComponent(G4VPhysicalVolume* MotherVolume)
{


} 

void GenSimADet::SetMaterial(G4String materialName)
{
  // search the material by its name 
  G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
  if (pttoMaterial){
    ADetLogical->SetMaterial(pttoMaterial);
  }
}


void GenSimADet::DestroyComponent()
{

}

void GenSimADet::SetCenterPositionInX(G4double xPos)
{
    PositionADetX =xPos;	 

    ADetPhysical->SetTranslation(G4ThreeVector(PositionADetX,
						  PositionADetY, 
						  PositionADetZ));
}

void GenSimADet::SetCenterPositionInY(G4double yPos)
{
    PositionADetY = yPos;

    ADetPhysical->SetTranslation(G4ThreeVector(PositionADetX,
						  PositionADetY, 
						  PositionADetZ));
}

void GenSimADet::SetCenterPositionInZ(G4double zPos)
{
    PositionADetZ = zPos;

    ADetPhysical->SetTranslation(G4ThreeVector(PositionADetX,
						  PositionADetY, 
						  PositionADetZ));
}

void GenSimADet::GeometryUpdate()
{

}

