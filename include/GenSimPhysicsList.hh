#ifndef GenSimPhysicsList_h
#define GenSimPhysicsList_h 1


//#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"

// user includes
//#include "LYSODetNeutronHPPhysics.hh"
//#include "LYSODetPhysicsListMessenger.hh"


// user classes
class GenSimPhysicsListMessenger;
class G4VPhysicsConstructor;

class GenSimPhysicsList: public G4VModularPhysicsList
{
public:

  GenSimPhysicsList();
  ~GenSimPhysicsList();

  virtual void ConstructParticle();
  virtual void ConstructProcess();

  void AddPhysicsList(const G4String& name);

  virtual void SetCuts();

private:
  G4VPhysicsConstructor*  GSPhysicsList;
  GenSimPhysicsListMessenger* fMessenger;
};


#endif
