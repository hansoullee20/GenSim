#include <math.h>


class DataMatrix{

  int rows;
  int cols;
  double error = 1e15;

public:

  double **m;

  DataMatrix(int r, int c) {
    
    rows = r;
    cols = c;
    
    m = new double*[rows];
    for(int i = 0; i < rows; i ++)
      m[i] = new double[cols];
  }
  ~DataMatrix() {

    for(int i = 0; i < rows; ++i) {
      delete [] m[i];
    }
    
    delete [] m;
  }
  
  void SetElement(int r, int c, double val = 0.0){
    if(r < 0 || r >= rows) return;
    if(c < 0 || c >= cols) return;
      
    m[r][c] = val;
  }
  void AddToElement(int r, int c, double val = 0.0){
    if(r < 0 || r >= rows) return;
    if(c < 0 || c >= cols) return;
      
    m[r][c] += val;
  }

  double GetElement(int r, int c){
    if(r < 0 || r >= rows) return error;
    if(c < 0 || c >= cols) return error;
    return m[r][c];
  }

};

//This is a modified Numerical Recipes routine used here for matrix inversion 

//   Linear equation solution by Gauss-Jordan elimination. a[0..n-1][0..n-1]
//   is the input matrix. A[0..n-1][0..m-1] is input containing the m right-hand side vectors. On
//   output, a is replaced by its matrix inverse, and b is replaced by the corresponding set of solution
//   vectors. 

void gaussj(DataMatrix *A, int n, DataMatrix *B, int m)
{
  int *indxc,*indxr,*ipiv;
  int i,icol,irow,j,k,l,ll;
  double big,dum,pivinv,temp;

  indxc = new int[n];     //The integer arrays ipiv, indxr, and indxc are 
  indxr = new int[n];     //used for bookkeeping on the pivoting.         
  ipiv  = new int[n];

  for (j=0;j<n;j++) ipiv[j]=0;
  for (i=0;i<n;i++) {                       //This is the main loop over the columns to be reduced.   
    big=0.0;                   		     
    for (j=0;j< n;j++)                     //This is the outer loop of the search for a pivot element.
      if (ipiv[j] != 1)                
	for (k=0;k< n;k++) {
	  if (ipiv[k] == 0) {
	    if (fabs(A->m[j][k]) >= big) {
	      big=fabs(A->m[j][k]);
	      irow=j;
	      icol=k;
	    }
	  }
	}
    ++(ipiv[icol]);
    /*    We now have the pivot element, so we interchange rows, if needed, to put the pivot
	  element on the diagonal. The columns are not physically interchanged, only relabeled:
	  indxc[i], the column of the ith pivot element, is the ith column that is reduced, while
	  indxr[i] is the row in which that pivot element was originally located. If indxr[i] does not equal
	  indxc[i] there is an implied column interchange. With this form of bookkeeping, the
	  solution b's will end up in the correct order, and the inverse matrix will be scrambled
	  by columns.*/

    if (irow != icol) {
      for (l=0;l< n;l++) { temp = A->m[irow][l]; A->m[irow][l] = A->m[icol][l]; A->m[icol][l] = temp; };
      for (l=0;l< m;l++) { temp = B->m[irow][l]; B->m[irow][l] = B->m[icol][l]; B->m[icol][l] = temp; };
    }
    indxr[i]=irow;                                                             //We are now ready to divide the pivot row by the
    indxc[i]=icol;                                                             //pivot element, located at irow and icol.
    if (A->m[icol][icol] == 0.0){ 
      cout << "This matrix is singular and does not have an inverse!" << endl << "Stopping ..." << endl;
      exit(1);
    }
    pivinv=1.0/A->m[icol][icol];
    A->m[icol][icol]=1.0;
    for (l=0;l< n;l++) A->m[icol][l] *= pivinv;
    for (l=0;l< m;l++) B->m[icol][l] *= pivinv; 
    
    for (ll=0;ll< n;ll++)                                                       //Next, we reduce the rows...
      if (ll != icol) {                                                         //...except for the pivot one, of course.
	dum=A->m[ll][icol];
	A->m[ll][icol]=0.0;
	for (l=0;l< n;l++) A->m[ll][l] -= A->m[icol][l]*dum;
	for (l=0;l< m;l++) B->m[ll][l] -= B->m[icol][l]*dum;
      }
    cout << " i = " << i << endl;
  }
  /*This is the end of the main loop over columns of the reduction. It only remains to unscramble
the solution in view of the column interchanges. We do this by interchanging pairs of
columns in the reverse order that the permutation was built up.*/
  for (l=n-1;l>=0;l--) {
    if (indxr[l] != indxc[l])
      for (k=0;k< n;k++){
	temp = A->m[k][indxr[l]];
	A->m[k][indxr[l]] = A->m[k][indxc[l]];
	A->m[k][indxc[l]] = temp;
	// SWAP(A->m[k][indxr[l]],A->m[k][indxc[l]]);
      }
  } //And we are done.

  delete[] ipiv;
  delete[] indxr;
  delete[] indxc;
}


void analyze(const char *FileName)
{

  // char var[15][50];
  // char name[1000];
  // char data[1000];
  // char cut[1000];
  // Long64_t NEvents = 0;
  // Long64_t TotalEvnts = 0;
  // Int_t ZBins = 16;
  // Int_t YBins = 9;
  // Int_t evR = 0;
  // Int_t x,y;

  // Float_t PEDep = 0;
  // Float_t PGFacZ = 0;
  // Float_t PGFacY = 0;
  // Float_t TEDep = 0;
  // Float_t TGFacZ = 0;
  // Float_t TGFacY = 0;
  // Float_t EDep = 0;
  // Float_t GFacZ = 0;
  // Float_t GFacY = 0;

  // vector <Float_t> CellEventEdep[144]; 
  // vector <Float_t> CellEventPEdep[144]; 
  // vector <Float_t> CellEventTEdep[144]; 
  // Float_t CellSumSq[144];
  // Float_t CellMean[144];

  // strcpy(var[0],"ProtonEnergyDeposit"); 
  // strcpy(var[1],"TritonEnergyDeposit"); 
  // strcpy(var[2],"ProtonCosineZ"); 
  // strcpy(var[3],"ProtonCosineY"); 
  // strcpy(var[4],"TritonCosineZ"); 
  // strcpy(var[5],"TritonCosineY"); 
  // strcpy(var[6],"N3HeSimPrimEvent.OriginVertexKineticEnergy");
  // strcpy(var[7],"Event"); 
  // strcpy(var[8],"Cell"); 
  // strcpy(var[9],"N3HeSimTarDetEvent.cellData");



  // TH2D *ProtonEDep = new TH2D("ProtonEDep","Proton Energy Deposit",ZBins,0,16,YBins,0,9);  
  // ProtonEDep->GetZaxis()->SetTitle("Total Energy Deposit [MeV]");
  // ProtonEDep->GetZaxis()->CenterTitle();
  // ProtonEDep->SetDirectory(0);

  // TH2D *ProtonGFacZ = new TH2D("ProtonGFacZ","Proton Longitudinal G-Factor",ZBins,0,16,YBins,0,9);  
  // ProtonGFacZ->GetZaxis()->SetTitle("< cos(#theta_Z) >");
  // ProtonGFacZ->GetZaxis()->CenterTitle();
  // ProtonGFacZ->SetDirectory(0);

  // TH2D *ProtonGFacY = new TH2D("ProtonGFacY","Proton Transverse G-Factor",ZBins,0,16,YBins,0,9);  
  // ProtonGFacY->GetZaxis()->SetTitle("< cos(#theta_Y) >");
  // ProtonGFacY->GetZaxis()->CenterTitle();
  // ProtonGFacY->SetDirectory(0);

  // TH2D *TritonEDep = new TH2D("TritonEDep","Triton Energy Deposit",ZBins,0,16,YBins,0,9);  
  // TritonEDep->GetZaxis()->SetTitle("Total Energy Deposit [MeV]");
  // TritonEDep->GetZaxis()->CenterTitle();
  // TritonEDep->SetDirectory(0);

  // TH2D *TritonGFacZ = new TH2D("TritonGFacZ","Triton Longitudinal G-Factor",ZBins,0,16,YBins,0,9);  
  // TritonGFacZ->GetZaxis()->SetTitle("< cos(#theta_Z) >");
  // TritonGFacZ->GetZaxis()->CenterTitle();
  // TritonGFacZ->SetDirectory(0);

  // TH2D *TritonGFacY = new TH2D("TritonGFacY","Triton Transverse G-Factor",ZBins,0,16,YBins,0,9);  
  // TritonGFacY->GetZaxis()->SetTitle("< cos(#theta_Y) >");
  // TritonGFacY->GetZaxis()->CenterTitle();
  // TritonGFacY->SetDirectory(0);

  // TH2D *TotalEDep = new TH2D("TotalEDep","Total Energy Deposit",ZBins,0,16,YBins,0,9);  
  // TotalEDep->GetZaxis()->SetTitle("< cos(#theta_Z) >");
  // TotalEDep->GetZaxis()->CenterTitle();
  // TotalEDep->SetDirectory(0);

  // TH2D *TotalGFacZ = new TH2D("TotalGFacZ","Total Longitudinal G-Factor",ZBins,0,16,YBins,0,9);  
  // TotalGFacZ->GetZaxis()->SetTitle("< cos(#theta_Z) >");
  // TotalGFacZ->GetZaxis()->CenterTitle();
  // TotalGFacZ->SetDirectory(0);

  // TH2D *TotalGFacY = new TH2D("TotalGFacY","Total Transverse G-Factor",ZBins,0,16,YBins,0,9);  
  // TotalGFacY->GetZaxis()->SetTitle("< cos(#theta_Y) >");
  // TotalGFacY->GetZaxis()->CenterTitle();
  // TotalGFacY->SetDirectory(0);

  // //TProfile *CorrPlots[

  // sprintf(cut,"");

  // for(int cl = 0; cl < 144; cl++){

  //   y = (Int_t)(9 - floor(cl/16));
  //   x = (Int_t)(cl-16*floor(cl/16))+1;
  //   PEDep = 0;
  //   TEDep = 0;
  //   EDep  = 0;
  //   PGFacZ = 0;
  //   PGFacY = 0;
  //   TGFacZ = 0;
  //   TGFacY = 0;
  //   GFacZ = 0;
  //   GFacY = 0;
    

  //   sprintf(data,"%s[%d].%s:%s[%d].%s:%s[%d].%s",
  // 	    var[9],cl,var[0],var[9],cl,var[2],var[9],cl,var[3]);
  //   cout << "reading: " << data << endl; 
  //   evR =  tree->Draw(data,cut,"goff");
  //   cout << "evR =  " << evR << endl; 
  //   for(int i = 0; i < evR; i++){
   
  //     PEDep += tree->GetV1()[i];
  //     PGFacZ += tree->GetV1()[i]*tree->GetV2()[i]; 
  //     PGFacY += tree->GetV1()[i]*tree->GetV3()[i]; 
  //   }

  //   // sprintf(data,"%s[%d]:%s[%d]:%s[%d]", var[1],cl,var[4],cl,var[5],cl);
  //   sprintf(data,"%s[%d].%s:%s[%d].%s:%s[%d].%s",
  // 	    var[9],cl,var[1],var[9],cl,var[4],var[9],cl,var[5]);
  //   cout << "reading: " << data << endl; 
  //   evR =  tree->Draw(data,cut,"goff");
  //   cout << "evR =  " << evR << endl; 
  //   for(int i = 0; i < evR; i++){
   
  //     TEDep += tree->GetV1()[i];
  //     TGFacZ += tree->GetV1()[i]*tree->GetV2()[i]; 
  //     TGFacY += tree->GetV1()[i]*tree->GetV3()[i]; 
  //   }

  //   ProtonEDep->SetBinContent(x,y,PEDep);
  //   ProtonGFacZ->SetBinContent(x,y,PGFacZ/PEDep);
  //   ProtonGFacY->SetBinContent(x,y,PGFacY/PEDep);

  //   TritonEDep->SetBinContent(x,y,TEDep);
  //   TritonGFacZ->SetBinContent(x,y,TGFacZ/TEDep);
  //   TritonGFacY->SetBinContent(x,y,TGFacY/TEDep);

  //   TotalEDep->SetBinContent(x,y,PEDep + TEDep);
  //   TotalGFacZ->SetBinContent(x,y,(PGFacZ + TGFacZ)/(PEDep+TEDep));
  //   TotalGFacY->SetBinContent(x,y,(PGFacY + TGFacY)/(PEDep+TEDep));
   
  // }

  gStyle->SetPalette(1);
  
  TFile f2(FileName,"READ");
  TVectorD *p = (TVectorD*)f2.Get("Pressure");
  Double_t pressure = (*p)[0];  
  TTree *tree = (TTree*)f2.Get("N3HeSimTree");
  if(!tree) return;
  tree->Print();
  Long64_t capEvnts = tree->GetEntries();
  TVectorD *vec = (TVectorD*)f2.Get("NumberOfPrimaries");
  Long64_t events = (*vec)[0];
  TVectorD *cl = (TVectorD*)f2.Get("Collimation");
  Double_t collimation = (*cl)[0];


  // char buffer[50];
  // strcpy(buffer,"N3HeSimPrimEvent.PrimaryEventNumber");
  // Long64_t capEvnts = tree->Draw(buffer,"","goff");
  // Long64_t events = (Long64_t)tree->GetV1()[0];


  TH2D *covM = (TH2D*)(((TH2D*)f2.Get("CovMatrix"))->Clone("covM"));
  TH2D *EDep = (TH2D*)(((TH2D*)f2.Get("TotalEDepos"))->Clone("EDep"));
  TH2D *GFacZ = (TH2D*)(((TH2D*)f2.Get("TotalGeoFactorsZ"))->Clone("GFacZ"));
  TH2D *GFacY = (TH2D*)(((TH2D*)f2.Get("TotalGeoFactorsY"))->Clone("GFacY"));

  covM->SetDirectory(0);
  EDep->SetDirectory(0); 
  GFacZ->SetDirectory(0);
  GFacY->SetDirectory(0);

  f2.Close();

  DataMatrix *A = new DataMatrix(144,144);    //The covariance matrix
  DataMatrix *B = new DataMatrix(144,144);    //Copy of the covariance matrix
  DataMatrix *C = new DataMatrix(144,1);      //The solutions (not needed here)
  DataMatrix *I = new DataMatrix(144,144);    //Inverse Test

  TH1D *CellCov[144];
  char buffer[100];
  
  for(int r = 0; r < 144; r++){
    sprintf(buffer,"CellCov_%02d",r+1);
    CellCov[r] = new TH1D(buffer,"",144,0,144);
    
    for(int c = 0; c < 144; c++){
      I->SetElement(r,c);  //initialize I
      B->SetElement(r,c,covM->GetBinContent(r+1,c+1));
      A->SetElement(r,c,covM->GetBinContent(r+1,c+1));
      cout << r << " , " <<  c << " , " << A->GetElement(r,c) << endl;
      CellCov[r]->SetBinContent(c+1,covM->GetBinContent(r+1,c+1));
      
    }
  }
    
  gaussj(A,144,C,1);  //A now contains the inverse after this routine


  //Test the inverse
  TH2D *InvTest = new TH2D("InvTest","",144,0,144,144,0,144);  
  InvTest->SetDirectory(0);
  TH2D *InvCovM = new TH2D("InvCovM","",144,0,144,144,0,144);  
  InvCovM->SetDirectory(0);

  Double_t REALLYSMALL = 1e-11;

  for(int i = 0; i < 144; i++)
    for(int k = 0; k < 144; k++){

      for(int j = 0; j < 144; j++)
	I->AddToElement(i,k, A->GetElement(i,j)*B->GetElement(j,k));
      
      cout << i << " , " << k << " = " << I->GetElement(i,k) << endl;
      if( i != k && I->GetElement(i,k) > REALLYSMALL) {

	cout << "Inverse doesn't pass identity test! Stopping ...!" << endl;
	return 0;
      }
      InvCovM->SetBinContent(i+1,k+1,A->GetElement(i,k));
      InvTest->SetBinContent(i+1,k+1,I->GetElement(i,k));
    }

  Double_t sumY = 0;
  Double_t sumZ = 0;
  Double_t xi,yi,xk,yk;

  for(i = 1; i <= 144; i++){  
    for(k = 1; k <= 144; k++){

      yi = (Int_t)(9 - floor((i-1)/16));
      xi = (Int_t)((i-1)-16*floor((i-1)/16))+1;
      yk = (Int_t)(9 - floor((k-1)/16));
      xk = (Int_t)((k-1)-16*floor((k-1)/16))+1;

      
      sumY += (EDep->GetBinContent(xi,yi)*GFacY->GetBinContent(xi,yi)*
	       EDep->GetBinContent(xk,yk)*GFacY->GetBinContent(xk,yk)*
	       InvCovM->GetBinContent(i,k));
      sumZ += (EDep->GetBinContent(xi,yi)*GFacZ->GetBinContent(xi,yi)*
	       EDep->GetBinContent(xk,yk)*GFacZ->GetBinContent(xk,yk)*
	       InvCovM->GetBinContent(i,k));
      
      cout << i << "," << k << "  ,  " << xi << "," << yi << "  ,  " <<  xk << "," << yk  << "  ,  " <<  sumY << "," << sumZ << endl;

    }  
  }

  Double_t errorY = 1.0/sqrt(sumY) * sqrt(events/capEvnts);
  Double_t DilutionY  = sqrt(capEvnts)*errorY;

  Double_t errorZ = 1.0/sqrt(sumZ) * sqrt(events/capEvnts);
  Double_t DilutionZ  = sqrt(capEvnts)*errorZ;
  
  FILE *fp = NULL;
  fp = fopen("ErrorAnalysis.dat","a");
  if(fp){
    fprintf(fp,"%f\t%f\t%f\t%f\t%f\t%f\t%d\n",errorY, DilutionY,errorZ,DilutionZ,pressure,collimation,capEvnts);
    fclose(fp);
  }
  

  cout << "Error Y: " << errorY << endl;
  cout << "Error Z: " << errorZ << endl;
  cout << "Dilution Y: " << DilutionY << endl;
  cout << "Dilution Z: " << DilutionZ << endl;
  cout << "Capture Events: " << capEvnts << endl;

  

  char buffer[100];
  sprintf(buffer,"Results_%s",FileName);
  TFile f1(buffer,"RECREATE");
  
  // ProtonEDep->Write();
  // ProtonGFacZ->Write();
  // ProtonGFacY->Write();

  // TritonEDep->Write(); 
  // TritonGFacZ->Write();
  // TritonGFacY->Write();
  
  // TotalEDep->Write(); 
  // TotalGFacZ->Write();
  // TotalGFacY->Write();
  covM->Write();
  InvCovM->Write();
  InvTest->Write();
  EDep->Write(); 
  GFacZ->Write();
  GFacY->Write();

  for( r = 0; r < 144; r++)
    CellCov[r]->Write();
  
  f1.Close();

  
}


//Below code needed for matrix inversion. Taken from Numerical Recipes. 

