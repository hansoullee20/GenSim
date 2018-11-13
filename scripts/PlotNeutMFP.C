void plot(const char *FileName)
{
  char var[2][50];
  char name[1000];
  char data[1000];
  char cut[1000];

  Double_t EBins = 15;
  Double_t Emin  = 0.0;
  Double_t Emax  = 5.0;
  Double_t Einc  = (Emax-Emin)/EBins;

  Double_t *MFPVal = new Double_t[EBins];
  Double_t *MFPEng = new Double_t[EBins];
  Double_t *MFPWvl = new Double_t[EBins];
  Double_t *MFPWvE = new Double_t[EBins];
  Double_t *MFPErX = new Double_t[EBins];
  Double_t *MFPErY = new Double_t[EBins];

  Int_t NEvents = 0;
  Int_t ZBins = 40;
  Int_t CthBins = 100;

  TH1D **PrjHst = new TH1D * [ZBins];

  strcpy(var[0],"N3HeSimTarDetEvent.CaptureVertexPositionZ");
  strcpy(var[1],"N3HeSimPrimEvent.OriginVertexKineticEnergy");

  TFile f2(FileName,"READ");
  TTree *tv__tree = (TTree *) gROOT->FindObject("N3HeSimTree");//(TTree*)f2.Get("QweakSimG4_Tree");  
  
  sprintf(data,"%s >> tmpHst",var[0]);
  for(int i = 0; i < EBins; i++){
    sprintf(cut,"%s > %f && %s <= %f",var[1],(Emin+i*Einc)*1.0e-3,var[1],(Emin+(i+1)*Einc)*1.0e-3);
    printf("%s > %f && %s <= %f",var[1],(Emin+i*Einc)*1.0e-3,var[1],(Emin+(i+1)*Einc)*1.0e-3);
    tv__tree->Draw(data,cut,"goff");
    
    tmpHst->Fit("expo","+");
    MFPVal[i] = fabs(1.0/tmpHst->GetFunction("expo")->GetParameter(1));
    MFPErY[i] = 4.0*tmpHst->GetFunction("expo")->GetParError(1)/MFPVal[i];
    MFPErX[i] = Einc/2;
    MFPEng[i] = (Emin+i*Einc) + Einc/2;
    MFPWvl[i] = sqrt(0.841/MFPEng[i]);
    MFPWvE[i] = sqrt(0.841/MFPErX[i]);

    printf("E = %f, MFP = %f, dE = %f, dMFP = %f, FitQ = %f\n",MFPEng[i],MFPVal[i],MFPErX[i],MFPErY[i],
	   tmpHst->GetFunction("expo")->GetChisquare()/tmpHst->GetFunction("expo")->GetNDF());
  }
  f2.Close();

  TGraphErrors *gr = new TGraphErrors(EBins,MFPEng,MFPVal,0,MFPErY);
  TGraphErrors *gr2 = new TGraphErrors(EBins,MFPWvl,MFPVal,0,MFPErY);

  gr->Draw("ap");

  TCanvas *c2 = new TCanvas("c2");
  
  gr2->Draw("ap");
  
}

