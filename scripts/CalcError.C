void calc(char *filename)
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
  
  Int_t cnt = 0;

  while(fscanf(fp,"%f %f %f %f %f %f %f",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5],&v[6]) != EOF){

    cout << cnt << ", " << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ", " << v[4] << ", " << v[5] << ", " << v[6]  << endl;

    EssqY += v[0]*v[0];
    EmsY += v[0];
    DssqY += v[1]*v[1];
    DmsY += v[1];

    EssqZ += v[2]*v[2];
    EmsZ += v[2];
    DssqZ += v[3]*v[3];
    DmsZ += v[3];

    cnt++;
  }
  cout << cnt << endl;

  cout << "Y error    -  std: " << sqrt(EssqY/cnt - (EmsY*EmsY)/(cnt*cnt)) << " mean: " << EmsY/cnt << endl;
  cout << "Y dilution -  std: " << sqrt(DssqY/cnt - (DmsY*DmsY)/(cnt*cnt)) << " mean: " << DmsY/cnt << endl;
  cout << "Z error    -  std: " << sqrt(EssqZ/cnt - (EmsZ*EmsZ)/(cnt*cnt)) << " mean: " << EmsZ/cnt << endl;
  cout << "Z dilution -  std: " << sqrt(DssqZ/cnt - (DmsZ*DmsZ)/(cnt*cnt)) << " mean: " << DmsZ/cnt << endl;


}
