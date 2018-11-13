#include "GenSimPrimaryEventGenerator.hh"

ClassImp(GenSimPrimaryEventGenerator);

GenSimPrimaryEventGenerator::GenSimPrimaryEventGenerator()   
{
  Initialize();
} 

GenSimPrimaryEventGenerator::~GenSimPrimaryEventGenerator()
{
  
}

void GenSimPrimaryEventGenerator::Initialize()
{
  // Int_t ncols = 0;
  // Int_t nlines = 0;

  // FILE *fp1 = fopen("SNSBeamSpectrum_lout_5.txt","r");
  // Float_t v[4];
  // Float_t I[1000];
  // SNSFNPBSpectrum = new TH1F("hst1","",1000,0.047025,5.997025);
  // while (1) {
  //   ncols = fscanf(fp1,"%f %f %f %f",&v[0],&v[1],&v[2],&v[3]);
  //   if (ncols < 4) break;
  //   // E[nlines]  = v[0];
  //   I[nlines]  = v[1]*60/120*1.4/2.0/(0.0595/10);

  //   SNSFNPBSpectrum->SetBinContent(nlines,I[nlines]*1.0e-8);

  //   nlines++;
  // }

  // FILE *fp1 = fopen("SNSBeamSpectrum_Measured.txt","r");
  // Float_t v[3];
  // Float_t I;
  // SNSFNPBSpectrum = new TH1F("hst1","",40,2.7,6.7);
  // while (fscanf(fp1,"%f %f %f",&v[0],&v[1],&v[2]) != EOF) { 
 
  //   SNSFNPBSpectrum->SetBinContent(nlines+1,v[2]);

  //   nlines++;
  // }


  // fclose(fp1);
  // SetRndmSeed();
}

Float_t GenSimPrimaryEventGenerator::GetRandomEnergy(Float_t minE, Float_t maxE)
{
  // if(minE <= 0.0) minE = 2.4e-5;  //default values
  // if(maxE <= 0.0) maxE = 0.38; 

  // Float_t minWvl = sqrt(0.0814/maxE); //E in units of eV and wavelength in units of Angstroms
  // Float_t maxWvl = sqrt(0.0814/minE);
  // Float_t wvl = 0.0;

  // if(minWvl < 2.7 || minWvl > 6.7)  minWvl = 2.7;
  // if(maxWvl < 2.7 || maxWvl > 6.7)  maxWvl = 6.7;

  // do{

  //   wvl = SNSFNPBSpectrum->GetRandom();

  // }
  // while(wvl < minWvl || wvl > maxWvl);

  // CurrentEnergy = 0.0814/(wvl*wvl);

  return 0;
}

Float_t GenSimPrimaryEventGenerator::GetRandomMomentumX()
{
  return 0;
}

Float_t GenSimPrimaryEventGenerator::GetRandomMomentumY()
{
  return 0;
}

Float_t GenSimPrimaryEventGenerator::GetRandomMomentumZ()
{
  return 1;
}

Float_t GenSimPrimaryEventGenerator::GetRandomOriginX()
{
  return 0;
}

Float_t GenSimPrimaryEventGenerator::GetRandomOriginY()
{
  return 0;
}

Float_t GenSimPrimaryEventGenerator::GetRandomOriginZ()
{
  return 1;
}
