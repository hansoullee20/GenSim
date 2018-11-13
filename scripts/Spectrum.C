void Spectrum()
{
  Int_t ncols = 0;
  Int_t nlines = 0;
  Int_t bin = 0;

  FILE *fp1 = fopen("SNSBeamSpectrum_lout_5.txt","r");
  Float_t v[4];
  Float_t E[1000];
  Float_t I[1000];

//   SNSFNPBSpectrum = new TH1F("hst1","",1000,0.047025,5.997025);
  SNSFNPBSpectrum = new TH1F("hst1","",10000,0.0234,337.0);

  while (1) {
    ncols = fscanf(fp1,"%f %f %f %f",&v[0],&v[1],&v[2],&v[3]);
    if (ncols < 4) break;
    E[nlines]  = v[0];
    I[nlines]  = v[1]*60/120*1.4/2.0/(0.0595/10);


    bin = SNSFNPBSpectrum->FindBin(84.1/(E[nlines]*E[nlines]));

    printf("Wl = %f, E = %f, Bin = %d\n",E[nlines],84.1/(E[nlines]*E[nlines]),bin);

    SNSFNPBSpectrum->SetBinContent(bin,I[nlines]*1.0e-8);

//     SNSFNPBSpectrum->SetBinContent(nlines,I[nlines]*1.0e-8);

    nlines++;
  }
  fclose(fp1);

  SNSFNPBSpectrum->Draw();
}
