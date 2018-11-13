#include "GenSimAnalysis.hh"

GenSimAnalysis::GenSimAnalysis()
{	
    // Initialize 

    MainEvent    = NULL;
    MainBranch   = NULL;

    GenSimNtuple         = NULL;
    GenSimFile           = NULL;
    NumberOfPrimaries     = new TVectorD(1);
    NumberOfPrimaries[0]  = 0;
}

GenSimAnalysis::~GenSimAnalysis() 
{
  Finish();
  delete[] NumberOfPrimaries;
}

void GenSimAnalysis::Init()
{;}                       

void GenSimAnalysis::Finish()
{
  if (MainEvent)         delete MainEvent;
  if (MainBranch)        delete MainBranch;
  if (GenSimNtuple)         {GenSimNtuple->Delete();}
  if (GenSimFile)           delete GenSimFile;
}   

// void GenSimAnalysis::BeginOfRun(G4int runID, G4double pressure, G4double coll) 
void GenSimAnalysis::BeginOfRun(G4int runID, GenSimUserInformation *userInfo) 
{   
  // TString InfoFile;
  // InfoFile.Form("GenSim-%04d-%04d-%04d-%04d-%04d.rndm",(G4int)(userInfo->GetPressure()*100),
  // 		(G4int)(userInfo->GetCollimationXH()*10),(G4int)(userInfo->GetCollimationXL()*10),
  // 		(G4int)(userInfo->GetCollimationYH()*10),(G4int)(userInfo->GetCollimationYL()*10));


  GenSimFile = new TFile("GenSim.root","RECREATE","N3He ROOT file");
  // GenSimFile = new TFile( Form("GenSim-%03d%03d.root",(G4int)(pressure*100),(G4int)(coll*10)),"RECREATE","N3He ROOT file");

  ConstructRootNtuple();
}

void GenSimAnalysis::EndOfRun() 
{
  NumberOfPrimaries->Write("NumberOfPrimaries");
  GenSimFile->Write("",TObject::kOverwrite); // Writing the data to the ROOT file

  GenSimNtuple->Reset(); //This needs to be here, so that the file size doesn't keep growing for new files.
                          //Apparently things are kept in the background, from the previous tree, and then 
                          //written to the new tree, without it being visible or accessible in the new file.
                          //This is only happening or a concern if multiple ROOT files are written in the same
                          //execution of the simulation, but it is a collossally stupid attribute of ROOT.

  GenSimFile->Close();
  if (MainEvent)         delete MainEvent;
  if (GenSimFile)        delete GenSimFile;
  
}

void GenSimAnalysis::EndOfEvent(G4int flag) 
{
  if(!flag) return;
}

void GenSimAnalysis::ConstructRootNtuple() 
{

  GenSimNtuple = new TTree("GenSimTree","GenSimTree");
  MainEvent   = new GenSimMainEvent();
  MainBranch  = GenSimNtuple->Branch("GenSimData", "GenSimMainEvent", &MainEvent, 64000, 10);

}

void GenSimAnalysis::AutoSaveRootNtuple() 
{
    // save the current ntuple:
    // In case your program crashes before closing the file holding this tree,
    // the file will be automatically recovered when you will connect the file
    // in UPDATE mode.
    // The Tree will be recovered at the status corresponding to the last AutoSave.
    //
    // if option contains "SaveSelf", gDirectory->SaveSelf() is called.
    // This allows another process to analyze the Tree while the Tree is being filled.
    //
    // see http://root.cern.ch/root/html/TTree.html#TTree:AutoSave

    //GenSimG4_RootNtuple -> AutoSave("SaveSelf");
    GenSimNtuple->AutoSave();

}
