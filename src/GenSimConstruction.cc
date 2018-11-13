#include "GenSimConstruction.hh"

GenSimConstruction::GenSimConstruction(GenSimUserInformation *userInfo) 
  : G4VUserDetectorConstruction()
{
  World_Solid    = NULL;  
  World_Logical  = NULL;  
  World_Physical = NULL;
  
  Messenger = NULL;
  Material      = NULL;

  ADet        = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  myUserInfo = userInfo;

  Messenger = new GenSimMessenger(this);

  Material      = new GenSimMaterial(userInfo);
  Material->DefineMaterials();
}

GenSimConstruction::~GenSimConstruction()
{
  if (ADet)         delete ADet;
  if (Material)     delete Material;
  if (Messenger)    delete Messenger;             
}

G4VPhysicalVolume* GenSimConstruction::Construct()
{
  return ConstructExp();
}

G4VPhysicalVolume* GenSimConstruction::ConstructExp()
{
  ADet              = new GenSimADet(myUserInfo);    

  fWorldLengthInX =  15.0*m;
  fWorldLengthInY =  15.0*m;
  fWorldLengthInZ =  30.0*m;

  World_Material   = Material->GetMaterial("Vacuum");

  World_Solid = new G4Box("World_Solid",
			 0.5* fWorldLengthInX , 
			 0.5* fWorldLengthInY ,
			 0.5* fWorldLengthInZ );
  
  World_Logical = new G4LogicalVolume( World_Solid, 
				       World_Material, 
				       "World_Logical", 
				       0, 0, 0);
  World_Physical = new G4PVPlacement(0, // no rotation
				     G4ThreeVector(), // at (0,0,0)
				     World_Logical,  
				     "World_Physical", 
				     0,false,0);             

  //G4tubs* Disk=new G4Tubs("Disk",pRmin,pRMax,pDdz,pSPhi,pDPhi);
  G4double box_x=1.0*m;
  G4double box_y=1.0*m;
  G4double box_z=1.0*m;
  G4RotationMatrix *xRot= new G4RotationMatrix;
 xRot->rotateX(M_PI/4.0*rad);
  G4Box* box= new G4Box("box",box_x,box_y,box_z);
G4Material* box_Material = Material->GetMaterial("Vacuum");
G4LogicalVolume* box_logical= new G4LogicalVolume(box,box_Material,"box_logical");
G4VPhysicalVolume* box_physical= new G4PVPlacement(xRot,G4ThreeVector(box_x,box_y,box_z),box_logical,"box_physical",World_Logical,false,0);

///Sensitive Detector placement 
G4VSensitiveDetector* detector = new GenSimADetSD("detector",1); 
//G4VSensitiveDetector* detector = new GenSimADetSD("detector"); 
  
G4SDManager* SDman = G4SDManager::GetSDMpointer();
 box_logical->SetSensitiveDetector(detector);
 SDman->AddNewDetector(detector);
 
 

  ADet->ConstructComponent(World_Physical);
  //ADet->SetCenterPositionInZ(0.0*cm); 

  World_Logical->SetVisAttributes (G4VisAttributes::Invisible);

  DumpGeometricalTree(World_Physical);

  return World_Physical;
}

void GenSimConstruction::DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth)
{
  for(int isp=0;isp<depth;isp++)
  { G4cout << "  "; }
  G4cout << aVolume->GetName() << "[" << aVolume->GetCopyNo() << "] "
         << aVolume->GetLogicalVolume()->GetName() << " "
         << aVolume->GetLogicalVolume()->GetNoDaughters() << " "
         << aVolume->GetLogicalVolume()->GetMaterial()->GetName();
  if(aVolume->GetLogicalVolume()->GetSensitiveDetector())
  {
    G4cout << " " << aVolume->GetLogicalVolume()->GetSensitiveDetector()
                            ->GetFullPathName();
  }
  G4cout << G4endl;
  for(int i=0;i<aVolume->GetLogicalVolume()->GetNoDaughters();i++)
  { DumpGeometricalTree(aVolume->GetLogicalVolume()->GetDaughter(i),depth+1); }
}


void GenSimConstruction::UpdateGeometry()
{
  G4GeometryManager::GetInstance()->OpenGeometry();

  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();
  G4LogicalBorderSurface::CleanSurfaceTable();


  G4RunManager::GetRunManager()->DefineWorldVolume(ConstructExp());
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
}

