#ifndef GenSimMaterial_H
#define GenSimMaterial_H 1

#include "cpp_include.h"
#include "Geant4_include.hh" 
#include "GenSimUserInformation.hh"

class GenSimMaterial
{ 
public:
  GenSimMaterial(GenSimUserInformation*);
  ~ GenSimMaterial();

public:
  void  DefineMaterials();
  G4Material* GetMaterial(G4String);

private:

  GenSimUserInformation *userInfo;
};

#endif
