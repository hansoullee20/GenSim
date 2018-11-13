void plot(char *filename)
{

  FILE *fp = fopen(filename,"r");
  if(!fp) return;

  Float_t v[7];

  Float_t EssqY = 0;
  Float_t EssqZ = 0;
  Float_t EmsY = 0;
  Float_t EmsZ = 0;
  
  Float_t DssqY = 0;
  Float_t DssqZ = 0;
  Float_t DmsY = 0;
  Float_t DmsZ = 0;

  Float_t pres;
  
  TGraphErrors *ErrGrY = new TGraphErrors();
  ErrGrY->SetName("ErrGrY");
  TGraphErrors *DilGrY = new TGraphErrors();
  DilGrY->SetName("DilGrY");

  TGraphErrors *ErrGrZ = new TGraphErrors();
  ErrGrZ->SetName("ErrGrZ");
  TGraphErrors *DilGrZ = new TGraphErrors();
  DilGrZ->SetName("DilGrZ");

  Int_t cnt = 0;
  Int_t pnt = 1;

  while(fscanf(fp,"%f %f %f %f %f %f %f",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5],&v[6]) != EOF){

    EssqY += v[0]*v[0];
    EmsY += v[0];
    DssqY += v[1]*v[1];
    DmsY += v[1];
    
    EssqZ += v[2]*v[2];
    EmsZ += v[2];
    DssqZ += v[3]*v[3];
    DmsZ += v[3];
    
    cnt++;

    if(cnt == 10){
      
           
      cout << cnt << endl;

      cout << "Y error    -  std: " << sqrt(EssqY/cnt - (EmsY*EmsY)/(cnt*cnt)) << " mean: " << EmsY/cnt << endl;
      cout << "Y dilution -  std: " << sqrt(DssqY/cnt - (DmsY*DmsY)/(cnt*cnt)) << " mean: " << DmsY/cnt << endl;
      cout << "Z error    -  std: " << sqrt(EssqZ/cnt - (EmsZ*EmsZ)/(cnt*cnt)) << " mean: " << EmsZ/cnt << endl;
      cout << "Z dilution -  std: " << sqrt(DssqZ/cnt - (DmsZ*DmsZ)/(cnt*cnt)) << " mean: " << DmsZ/cnt << endl;

      ErrGrY->SetPoint(pnt,v[4],EmsY/cnt);
      ErrGrY->SetPointError(pnt,0,sqrt(EssqY/cnt - (EmsY*EmsY)/(cnt*cnt)));
      DilGrY->SetPoint(pnt,v[4],DmsY/cnt);
      DilGrY->SetPointError(pnt,0,sqrt(DssqY/cnt - (DmsY*DmsY)/(cnt*cnt)));

      ErrGrZ->SetPoint(pnt,v[4],EmsZ/cnt);
      ErrGrZ->SetPointError(pnt,0,sqrt(EssqZ/cnt - (EmsZ*EmsZ)/(cnt*cnt)));
      DilGrZ->SetPoint(pnt,v[4],DmsZ/cnt);
      DilGrZ->SetPointError(pnt,0,sqrt(DssqZ/cnt - (DmsZ*DmsZ)/(cnt*cnt)));

      EssqY = 0;
      EmsY = 0;
      DssqY = 0;
      DmsY = 0;
      
      EssqZ = 0;
      EmsZ = 0;
      DssqZ = 0;
      DmsZ = 0; 

      cnt = 0;
      pnt++;
    }

  }

  TCanvas *c = new TCanvas();

  c->Divide(2,2);
  
  c->cd(1);
  ErrGrY->Draw("ap");
  c->cd(2);
  DilGrY->Draw("ap");
  c->cd(3);
  ErrGrZ->Draw("ap");
  c->cd(4);
  DilGrZ->Draw("ap");

}

