#include "GenSimPhysicsList.hh"
#include "GenSimPhysicsListMessenger.hh"

#include "GenSimAnalysis.hh"
#include "GenSimUserInformation.hh"
#include "GenSimPrimaryGeneratorAction.hh"
#include "GenSimConstruction.hh"
#include "GenSimEventAction.hh"
#include "GenSimRunAction.hh"
#include "GenSimSteppingAction.hh"
#include "GenSimSteppingVerbose.hh"
#include "GenSimTrackingAction.hh"
#include "GenSimTrackInformation.hh"
#include "G4PhysListFactory.hh"
#include "G4RunManager.hh"
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>
#include <G4UIterminal.hh>

#ifdef G4UI_USE_QT
#include "G4UIQt.hh"
#endif

#ifdef G4UI_USE_XM
#include "G4UIXm.hh"
#endif

#ifdef G4UI_USE_TCSH
#include "G4UItcsh.hh"
#endif

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

int main(int argc,char** argv) {


  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine());

  //my Verbose output class
  G4VSteppingVerbose::SetInstance( new GenSimSteppingVerbose() );

  // Run manager
  G4RunManager * runManager = new G4RunManager();

  // UserInitialization classes (mandatory)
  GenSimUserInformation*       myGenSimUserInformation  = new GenSimUserInformation();
  GenSimConstruction*          myGenSimExperiment       = new GenSimConstruction(myGenSimUserInformation);
  GenSimAnalysis*              myGenSimAnalysis         = new GenSimAnalysis();
  GenSimPhysicsList*           myGenSimPhysicsList      = new GenSimPhysicsList();
  runManager->SetUserInitialization(myGenSimExperiment);
  runManager->SetUserInitialization(myGenSimPhysicsList);

  G4PhysListFactory factory;
  G4VModularPhysicsList* physlist = factory.GetReferencePhysList("QGSP_BERT");

  //  G4VModularPhysicsList* physicsList = new QBBC;
  // G4VModularPhysicsList* physicsList = new LBE;
  physlist->SetVerboseLevel(1);
  runManager->SetUserInitialization(physlist);

  // UserAction classes
  runManager->SetUserAction( new GenSimPrimaryGeneratorAction(myGenSimUserInformation) );
  runManager->SetUserAction( new GenSimRunAction(myGenSimAnalysis, myGenSimUserInformation) );
  runManager->SetUserAction( new GenSimEventAction(myGenSimAnalysis, myGenSimUserInformation) );
  runManager->SetUserAction( new GenSimSteppingAction(myGenSimUserInformation) );
  runManager->SetUserAction( new GenSimTrackingAction(myGenSimUserInformation) );

  //Initialize G4 kernel
  runManager->Initialize();


  G4UIsession * session = 0;


  //get the pointer to the User Interface manager
  G4UImanager * UI = G4UImanager::GetUIpointer();

//   UI->ApplyCommand("/tracking/verbose 11");
//   UI->ApplyCommand("/stepping/verbose 11");

  if(argc==1)
    // Define (G)UI terminal for interactive mode
    {


#if defined(G4UI_USE_QT)
      session = new G4UIQt(argc,argv);
      cout << "defining QT" << endl;
#elif defined(G4UI_USE_XM)
      session = new G4UIXm(argc,argv);
#elif defined(G4UI_USE_TCSH)
      session = new G4UIterminal(new G4UItcsh);
#else
      session = new G4UIterminal();
#endif

    }

#ifdef G4VIS_USE
  // Visualization, if you choose to have it!
  //G4VisManager* visManager = new GenSimVisManager();
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif

  if(session)
    {

#if defined(G4UI_USE_XM) || defined(G4UI_USE_WIN32) || defined(G4UI_USE_QT)
      // Customize the G4UIXm,Win32 menubar with a macro file :
      UI->ApplyCommand("/control/execute macros/gui.mac");
#endif

      // UI->ApplyCommand("/control/execute vis.mac");
      session->SessionStart();
      delete session;
    }
  else
    // Batch mode
    {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UI->ApplyCommand(command+fileName);
    }

#ifdef G4VIS_USE
  delete visManager;
#endif
  delete runManager;

  return 0;
}
