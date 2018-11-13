void plot(const char *FileName)
{
  gStyle->SetPalette(1);

  char var[9][50];
  char name[1000];
  char data[1000];
  char cut[1000];
  Long64_t NEvents = 0;
  Long64_t TotalEvnts = 0;
  Int_t ZBins = 20;
  Int_t CthBins = 100;
  Int_t eBins = 10;
  Double_t ZSum = 0;
  Double_t ESum = 0;
  Double_t En_min = 0.0; //meV
  Double_t En_max = 5.0; //meV
  Double_t eInc   = (En_max - En_min)/eBins;

  Int_t *ZEvnts = new Int_t[ZBins+1];
  Int_t *EEvents = new Double_t[eBins];
  Double_t *TDil = new Double_t[eBins];
  Double_t *En = new Double_t[eBins];
  Double_t *EA_sm  = new Double_t[ZBins];
  Double_t *EZtot  = new Double_t[ZBins];
  Double_t *Dilu   = new Double_t[ZBins];
  Double_t *ZPos   = new Double_t[ZBins];
  Double_t *E_tot  = new Double_t[eBins];

  TH1D **PrjHstP = new TH1D * [ZBins];
  TH1D **PrjHstT = new TH1D * [ZBins];
  TGraph **gr = new TGraph * [eBins];

  strcpy(var[0],"N3HeSimTarDetEvent.SecPartGlobalStepPositionZ");
  strcpy(var[1],"N3HeSimTarDetEvent.SecPartGlobalTheta");
//   strcpy(var[1],"SecPartGlobalPhi");
  strcpy(var[2],"N3HeSimTarDetEvent.SecPartStepEnergyDeposition");
  strcpy(var[3],"N3HeSimTarDetEvent.SecPartGlobalOriginX");
  strcpy(var[4],"N3HeSimTarDetEvent.SecPartGlobalOriginY");
  strcpy(var[5],"N3HeSimTarDetEvent.SecPartGlobalOriginZ");
  strcpy(var[6],"N3HeSimTarDetEvent.SecPartEdgeEventFlag");
  strcpy(var[7],"N3HeSimTarDetEvent.SecPartType");
  strcpy(var[8],"N3HeSimPrimEvent.OriginVertexKineticEnergy");

  TFile f2(FileName,"READ");
  TTree *tv__tree = (TTree *) gROOT->FindObject("N3HeSimTree");
  
  if(!tv__tree) return;

  TH2D **hEDepTHZ_P = new TH2D[eBins];
  TH2D **hEDepTHZ_T = new TH2D[eBins];

  TH2D *hDilEnZ = new TH2D("hDilEnZ","",ZBins,0,20,eBins,En_min,En_max);   //Z pos versus neutron energy versus dilution
  hDilEnZ->GetZaxis()->SetTitle("Error Dilution");
  hDilEnZ->GetZaxis()->CenterTitle();

  TH2D *hEDepEnZ = new TH2D("hEDepEnZ","",ZBins,0,20,eBins,En_min,En_max);   //Z pos versus neutron energy versus energy deposition per plane
  hEDepEnZ->GetZaxis()->SetTitle("Relative Energy Deposit [MeV/MeV max]");
  hEDepEnZ->GetZaxis()->CenterTitle();

  for(int e = 0; e < eBins; e++){

    for(int i = 0; i <= ZBins; i++) ZEvnts[i] = 0;

    sprintf(name,"hEDepTHZ_P_%02d",e);
    hEDepTHZ_P[e] = new TH2D(name,"",ZBins,0,20,CthBins,-1,1);   //Z pos versus theta angle versus energy deposition 
    hEDepTHZ_P[e]->GetZaxis()->SetTitle("Energy deposit [MeV]");
    hEDepTHZ_P[e]->GetZaxis()->CenterTitle();

    sprintf(name,"hEDepTHZ_T_%02d",e);
    hEDepTHZ_T[e] = new TH2D(name,"",ZBins,0,20,CthBins,-1,1);   //Z pos versus theta angle versus energy deposition 
    hEDepTHZ_T[e]->GetZaxis()->SetTitle("Energy deposit [MeV]");
    hEDepTHZ_T[e]->GetZaxis()->CenterTitle();

    En[e] = En_min+eInc*(2*e+1)/2;

    sprintf(data,"%s:%s:%s:N3HeSimTarDetEvent.SecPartType",var[0],var[1],var[2]);

    sprintf(cut,"%s >= -10 && %s <= 10 && %s >= -10 && %s <= 10 && %s > 0 && %s <= 20 && %s == 0 && (%s == 6 || %s == 4) && %s > %f && %s <= %f", //Z pos versus angle
	    var[3],var[3],var[4],var[4],var[5],var[5],var[6],var[7],var[7],var[8],(En_min+eInc*e)*1.0e-3,var[8],(En_min+eInc*(e+1))*1.0e-3);                                             

    NEvents = tv__tree->Draw(data,cut,"goff");
    EEvents[e] = NEvents;
    cout << "Events: " << NEvents << endl;
    TotalEvnts += NEvents;

    for(int t = 0; t < NEvents; t++){

//       cout << t << ": " << Int_t(tv__tree->GetV1()[t]*2.0) << " " << tv__tree->GetV1()[t] << " "<< tv__tree->GetV2()[t] << " "<< tv__tree->GetV3()[t] << endl;
//       cout << "Particle Type = " << tv__tree->GetV4()[t] << endl;
      ZEvnts[Int_t(tv__tree->GetV1()[t]*ZBins/20)]++;

      if(tv__tree->GetV4()[t] == 6)
	hEDepTHZ_T[e]->Fill(tv__tree->GetV1()[t],tv__tree->GetV2()[t],tv__tree->GetV3()[t]);
      else
	hEDepTHZ_P[e]->Fill(tv__tree->GetV1()[t],tv__tree->GetV2()[t],tv__tree->GetV3()[t]);
    }
    cout << "Out of Loop: " << endl;

    hEDepTHZ_P[e]->GetZaxis()->SetTitle("Energy deposit [MeV]");
    hEDepTHZ_P[e]->GetZaxis()->CenterTitle();
    hEDepTHZ_T[e]->GetZaxis()->SetTitle("Energy deposit [MeV]");
    hEDepTHZ_T[e]->GetZaxis()->CenterTitle();

    cout << "Total Events: " << TotalEvnts << endl;

//     hEDepTHZ_P[e]->Draw("colz");

    E_tot[e] = 0;
    ZSum = 0;

    for(int b = 0; b < ZBins; b++){
      cout << ZEvnts[b] << endl;
      sprintf(name,"prf%02d",b+1);
      PrjHstP[b] = hEDepTHZ_P[e]->ProjectionY(name,b+1,b+1);
      PrjHstP[b]->SetDirectory(0);

      PrjHstT[b] = hEDepTHZ_T[e]->ProjectionY(name,b+1,b+1);
      PrjHstT[b]->SetDirectory(0);

      Dilu[b] = 0;
      ZPos[b] = 0;
      EZtot[b] = 0;
      EA_sm[b] = 0;
      
      for(int ab = 0; ab < PrjHstP[b]->GetNbinsX(); ab++){
	
	EA_sm[b] += (PrjHstP[b]->GetBinContent(ab+1)*PrjHstP[b]->GetBinCenter(ab+1) + PrjHstP[b]->GetBinContent(ab+1)*PrjHstP[b]->GetBinCenter(ab+1)/(3.0));
	EZtot[b] += (PrjHstP[b]->GetBinContent(ab+1)+PrjHstT[b]->GetBinContent(ab+1));
      }
      E_tot[e] += EZtot[b];
      if(EA_sm[b] == 0){
	Dilu[b] = 0;
      }
      else{
	Dilu[b] = EZtot[b]/EA_sm[b];
// 	if(b > 3 && fabs(Dilu[b]) <= 10){
	  ZSum += ZEvnts[b]/(Dilu[b]*Dilu[b]);
// 	}
      }
      ZPos[b] = hEDepTHZ_P[e]->GetBinCenter(hEDepTHZ_P[e]->GetBin(b+1,0));
      printf("E_tot = %f, Dilu = %f, ZPos = %f\n",E_tot[e],Dilu[b],ZPos[b]);      

//       if(NEvents) EZtot[b] /= NEvents;

      hDilEnZ->Fill(ZPos[b],En[e],Dilu[b]);
//       hEDepEnZ->Fill(ZPos[b],En[e],EZtot[b]);
    }
    
    for(int b = 0; b < ZBins; b++){
//       cout << b << " " << "Es" << EZtot[b] << " " << E_tot[e] << endl; 
      hEDepEnZ->Fill(ZPos[b],En[e],EZtot[b]/E_tot[e]);
    }

    printf("Error Dilution: %f\n",sqrt(NEvents/ZSum));
    TDil[e] = sqrt(NEvents/ZSum);
    
    ESum += ZSum;    
    
    sprintf(name,"DilGr_En%02d",e);
    gr[e] = new TGraph(ZBins,ZPos,Dilu);
    gr[e]->SetName(name);
    hEDepTHZ_P[e]->SetDirectory(0);
    hEDepTHZ_T[e]->SetDirectory(0);
  }

  printf("Total Error Dilution: %f\n",sqrt(TotalEvnts/ESum));

  
  hDilEnZ->SetDirectory(0);
  hEDepEnZ->SetDirectory(0);
  f2.Close();

  TFile f1("Data.root","RECREATE");
  
  for(int l = 0; l < eBins; l++) {
    hEDepTHZ_P[l]->Write(); 
    hEDepTHZ_T[l]->Write(); 
    gr[l]->Write();
  }

  gr2 = new TGraph(eBins,En,E_tot);
  gr2->SetName("TotalEdep_vs_En");
  gr2->Write();
  
  gr3 = new TGraph(eBins,En,TDil);
  gr3->SetName("ErrorDill_vs_En");
  gr3->Write();

  hDilEnZ->Write();
  hEDepEnZ->Write();
  f1.Close();
  
}

