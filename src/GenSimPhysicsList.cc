#include "GenSimPhysicsList.hh"
#include "GenSimPhysicsListMessenger.hh"

#include "G4EmLivermorePhysics.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BosonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"


GenSimPhysicsList::GenSimPhysicsList()
: G4VModularPhysicsList(),
  GSPhysicsList(0),fMessenger(0)
{
  SetVerboseLevel(1);

  // //add new units
  // //
  new G4UnitDefinition( "millielectronVolt", "meV", "Energy", 1.e-3*eV);
  new G4UnitDefinition( "mm2/g",  "mm2/g", "Surface/Mass", mm2/g);
  new G4UnitDefinition( "um2/mg", "um2/mg","Surface/Mass", um*um/mg);

  // // Neutron Physics
  // RegisterPhysics( new GenSimNeutronHPPhysics("neutronHP"));
  ////*****

  fMessenger = new GenSimPhysicsListMessenger(this);
  GSPhysicsList = new G4EmLivermorePhysics();

}


GenSimPhysicsList::~GenSimPhysicsList()
{
  delete fMessenger;
}
// Bosons
#include "G4ChargedGeantino.hh"
#include "G4Geantino.hh"
#include "G4Gamma.hh"
#include "G4OpticalPhoton.hh"

// leptons
#include "G4MuonPlus.hh"
#include "G4MuonMinus.hh"
#include "G4NeutrinoMu.hh"
#include "G4AntiNeutrinoMu.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4NeutrinoE.hh"
#include "G4AntiNeutrinoE.hh"

// Mesons
#include "G4PionPlus.hh"
#include "G4PionMinus.hh"
#include "G4PionZero.hh"
#include "G4Eta.hh"
#include "G4EtaPrime.hh"

#include "G4KaonPlus.hh"
#include "G4KaonMinus.hh"
#include "G4KaonZero.hh"
#include "G4AntiKaonZero.hh"
#include "G4KaonZeroLong.hh"
#include "G4KaonZeroShort.hh"

// Baryons
#include "G4Proton.hh"
#include "G4AntiProton.hh"
#include "G4Neutron.hh"
#include "G4AntiNeutron.hh"

// Nuclei
#include "G4Deuteron.hh"
#include "G4Triton.hh"
#include "G4Alpha.hh"
#include "G4GenericIon.hh"

void GenSimPhysicsList::ConstructParticle()
{
  // pseudo-particles
    G4Geantino::GeantinoDefinition();
    G4ChargedGeantino::ChargedGeantinoDefinition();

  // gamma
    G4Gamma::GammaDefinition();

  // optical photon
    G4OpticalPhoton::OpticalPhotonDefinition();

  // leptons
    G4Electron::ElectronDefinition();
    G4Positron::PositronDefinition();
    // G4MuonPlus::MuonPlusDefinition();
    // G4MuonMinus::MuonMinusDefinition();
    //
    // G4NeutrinoE::NeutrinoEDefinition();
    // G4AntiNeutrinoE::AntiNeutrinoEDefinition();
    // G4NeutrinoMu::NeutrinoMuDefinition();
    // G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();

  // mesons
    // G4PionPlus::PionPlusDefinition();
    // G4PionMinus::PionMinusDefinition();
    // G4PionZero::PionZeroDefinition();
    // G4Eta::EtaDefinition();
    // G4EtaPrime::EtaPrimeDefinition();
    // G4KaonPlus::KaonPlusDefinition();
    // G4KaonMinus::KaonMinusDefinition();
    // G4KaonZero::KaonZeroDefinition();
    // G4AntiKaonZero::AntiKaonZeroDefinition();
    // G4KaonZeroLong::KaonZeroLongDefinition();
    // G4KaonZeroShort::KaonZeroShortDefinition();

  // barions
    G4Proton::ProtonDefinition();
    G4AntiProton::AntiProtonDefinition();
    G4Neutron::NeutronDefinition();
    G4AntiNeutron::AntiNeutronDefinition();

  // ions
    // G4Deuteron::DeuteronDefinition();
    // G4Triton::TritonDefinition();
    // G4Alpha::AlphaDefinition();
    G4GenericIon::GenericIonDefinition();

  // G4BosonConstructor  pBosonConstructor;
  // pBosonConstructor.ConstructParticle();
  //
  // G4LeptonConstructor pLeptonConstructor;
  // pLeptonConstructor.ConstructParticle();
  //
  // G4MesonConstructor pMesonConstructor;
  // pMesonConstructor.ConstructParticle();
  //
  // G4BaryonConstructor pBaryonConstructor;
  // pBaryonConstructor.ConstructParticle();
  //
  // G4IonConstructor pIonConstructor;
  // pIonConstructor.ConstructParticle();
  //
  // G4ShortLivedConstructor pShortLivedConstructor;
  // pShortLivedConstructor.ConstructParticle();
}

// void PhysicsList::ConstructParticle()
// {

// }

void GenSimPhysicsList::ConstructProcess()
{
  AddTransportation();
  GSPhysicsList -> ConstructProcess();
  //G4EmProcessOptions emOptions;
  // emOptions.SetBuildCSDARange(true);
  // emOptions.SetMaxEnergyForCSDARange(50*MeV);

}

void GenSimPhysicsList::SetCuts()
{
//  SetCutValue(0*mm, "proton");
  G4VUserPhysicsList::SetCuts();
}
