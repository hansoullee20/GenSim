#include "GenSimRunAction.hh"

GenSimRunAction::GenSimRunAction(GenSimAnalysis* AN, GenSimUserInformation* UI)
  :runID(0), analysis(AN), userInfo(UI)
{
  MyRunID = 0;
  RunActionMessenger  = new GenSimRunActionMessenger(this);
}

GenSimRunAction::~GenSimRunAction()
{
  delete RunActionMessenger;
}

void GenSimRunAction::BeginOfRunAction(const G4Run* aRun)
{
  runID =   aRun->GetRunID();

  long seeds[2];
  time_t systime = time(NULL);
  seeds[0] = (long) systime;
  //  seeds[1] = (long) (systime*G4UniformRand());
  seeds[1] = (long) (systime);
  CLHEP::HepRandom::setTheSeeds(seeds);
  CLHEP::HepRandom::showEngineStatus();

  TString InfoFile;
  InfoFile.Form("GenSim.rndm");
  // InfoFile.Form("GenSim-%04d-%04d-%04d-%04d-%04d.rndm",(G4int)(userInfo->GetPressure()*100),
  // 		(G4int)(userInfo->GetCollimationXH()*10),(G4int)(userInfo->GetCollimationXL()*10),
  // 		(G4int)(userInfo->GetCollimationYH()*10),(G4int)(userInfo->GetCollimationYL()*10));

  CLHEP::HepRandom::saveEngineStatus(InfoFile); 
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager* UI = G4UImanager::GetUIpointer();
      UI->ApplyCommand("/vis/scene/notifyHandlers");
    } 

  analysis->BeginOfRun(MyRunID,userInfo);
  userInfo->SetMyRunID(MyRunID);

}

void GenSimRunAction::EndOfRunAction(const G4Run* aRun)
{ 

  //collect infor here ... e.g. from UserInformation class ... and write it to file

  // Example ...

  // TH2D *PEDepos = new TH2D("PEDepos", "", 16, 0, 16, 9, 0, 9);
  // TH2D *TEDepos = new TH2D("TEDepos", "", 16, 0, 16, 9, 0, 9);

  // G4double Pdep_r = 0;
  // G4double Tdep_r = 0;

  // G4long Nevents = userInfo->GetPrimaryEventNumber()+1;

  // for(int r = 1; r <= 144; r++){

  //   y = (G4int)(9 - floor((r-1)/16));
  //   x = ((r-1)-16*floor((r-1)/16))+1;

  //   Pdep_r = userInfo->GetCellEngDeposit(r-1,myProton);
  //   Tdep_r = userInfo->GetCellEngDeposit(r-1,myTriton);      

  //   PEDepos->SetBinContent(x,y,Pdep_r);
  //   TEDepos->SetBinContent(x,y,Tdep_r);`
  // }  

  // analysis->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  //or just writing vectors of numbers to the file

  // TVectorD *wlEdep;
  // TVectorD *wlEvtCnt;

  // for(int n = 0; n < 40; n++){

  //   wlEdep = 0;
  //   wlEdep = new TVectorD(144);  
  //   wlEvtCnt = 0;
  //   wlEvtCnt = new TVectorD(144);  
  //   for(int m = 0; m < 144; m++){
  //     (*wlEdep)[m] = userInfo->GetCellWLEngDeposit(m,n);
  //     (*wlEvtCnt)[m] = userInfo->GetCellWLEventCnt(m,n);
  //   }
  //   wlEdep->Write(Form("WLengthEDeposit%02d",n+1));
  //   wlEvtCnt->Write(Form("WLengthEventCount%02d",n+1));
  // }


  // TVectorD *pr = new TVectorD(1);
  // (*pr)[0] = (Double_t)userInfo->GetPressure();

  // G4cout << "Pressure: " << (*pr)[0] << G4endl;

  // TVectorD *cl = new TVectorD(1);
  // (*cl)[0] = (Double_t)userInfo->GetCollimation();

  // TVectorD *clxh = new TVectorD(1);
  // (*clxh)[0] = (Double_t)userInfo->GetCollimationXH();
  // TVectorD *clxl = new TVectorD(1);
  // (*clxl)[0] = (Double_t)userInfo->GetCollimationXL();
  // TVectorD *clyh = new TVectorD(1);
  // (*clyh)[0] = (Double_t)userInfo->GetCollimationYH();
  // TVectorD *clyl = new TVectorD(1);
  // (*clyl)[0] = (Double_t)userInfo->GetCollimationYL();

  // vector <Float_t> *betas = userInfo->GetBetas();
  // TH1D *betaspc = new TH1D("BetaSpc","",1000,0,10);
  // for(int b = 0; b < betas->size(); b++)
  //   betaspc->Fill((*betas)[b]);


  // pr->Write("Pressure");
  // cl->Write("Collimation");
  // clxh->Write("CollimationXH");
  // clxl->Write("CollimationXL");
  // clyh->Write("CollimationYH");
  // clyl->Write("CollimationXL");

  // userInfo->WriteTheta();
  // userInfo->WritePhi();
  // userInfo->WriteMomDirX();
  // userInfo->WriteMomDirY();
  // userInfo->WriteMomDirZ();


  analysis->EndOfRun();
  userInfo->Initialize();

  CLHEP::HepRandom::showEngineStatus();  
}

G4int GenSimRunAction::getRunID()
{
  return runID;
}


