#include "GenSimMaterial.hh"

GenSimMaterial::GenSimMaterial(GenSimUserInformation *UI)
  :userInfo(UI)
{

}

GenSimMaterial::~GenSimMaterial()
{

}

void GenSimMaterial::DefineMaterials()
{

  // Define required materials

  G4double A;        // atomic mass
  G4double Z;        // atomic number
  G4double density;  // density

  G4double temperature; 
  G4double pressure;
  G4double fractionmass;

  G4String name;
  G4String symbol;
  
  G4int natoms; 
  G4int ncomponents;
  G4int nelements;
 
  //
  // Define general elements
  //

  // G4Element describes the properties of the atoms:
  // atomic number, number of nucleons, atomic mass, shell energy ...


  //---------------------------------------------------------
  name   = "Element_Hydrogen";
  symbol = "H"; 
  Z      = 1.;
  A      = 1.00794*g/mole;
  G4Element* elH = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Helium_3";
  symbol = "3He"; 
  Z      = 2.;
  A      = 3.016023*g/mole;
//   G4Element* elHe3 = new G4Element(name, symbol, Z, A);

  G4Isotope* He3Iso = new G4Isotope("3HeIso", (G4int)Z,3,A);
  G4Element* elHe3 = new G4Element(name,symbol,1);
  elHe3->AddIsotope(He3Iso,100.0*perCent);

  //---------------------------------------------------------
  name   = "Element_Helium";
  symbol = "He"; 
  Z      = 2.;
  A      = 4.0026*g/mole;
  G4Element* elHe = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------

  name =  "Element_Lithium_6";
  symbol = "Li";
  Z = 3.;
  A = 6.0151*g/mole;
  G4Isotope* Li6Iso = new G4Isotope("6LiIso", (G4int)Z,6,A);
  G4Element* elLi6 = new G4Element(name, symbol,1);
  elLi6->AddIsotope(Li6Iso,100.0*perCent);
  

//   name   = "Element_Boro";
//   symbol = "B"; 
//   Z      = 5.;
//   A      = 10.811*g/mole;
//   G4Element* elB = new G4Element(name, symbol, Z, A);
   //---------------------------------------------------------
  name   = "Element_Carbon";
  symbol = "C"; 
  Z      = 6.;
  A      = 12.011*g/mole;
  G4Element* elC = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Nitrogen";
  symbol = "N"; 
  Z      = 7.;
  A      = 14.01*g/mole;
  G4Element* elN = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Oxygen";
  symbol = "O"; 
  Z      = 8.;
  A      = 16.00*g/mole;
  G4Element* elO = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
//   name   = "Element_Fluorine";
//   symbol = "F"; 
//   Z      = 9.;
//   A      = 19.00*g/mole;
//   G4Element* elF = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Sodium";
  symbol = "Na"; 
  Z      = 11.;
  A      = 22.99*g/mole;
  G4Element* elNa = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
//   name   = "Element_Magnesium";
//   symbol = "Mg"; 
//   Z      = 12.;
//   A      = 24.305*g/mole;
//   G4Element* elMg = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Aluminum";
  symbol = "Al"; 
  Z      = 13.;
  A      = 26.981539*g/mole;
  G4Element* elAl = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Silicon";
  symbol = "Si"; 
  Z      = 14.;
  A      = 28.09*g/mole;
  G4Element* elSi  = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
//   name   = "Element_Chlorine";
//   symbol = "Cl"; 
//   Z      = 17.;
//   A      = 35.453*g/mole;
//   G4Element* elCl = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Argon";
  symbol = "Ar"; 
  Z      = 18.;
  A      = 39.95*g/mole;
  G4Element* elAr  = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Potassium";
  symbol = "K"; 
  Z      = 19.;
  A      = 39.0983*g/mole;
  G4Element* elK = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Calcium";
  symbol = "Ca"; 
  Z      = 20.;
  A      = 40.08*g/mole;
  G4Element* elCa = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Iron";
  symbol = "Fe";
  Z      = 26.;
  A      = 55.85*g/mole;
  G4Element* elFe  = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
  name   = "Element_Xenon";
  symbol = "Xe";
  Z      = 52.;
  A      = 131.29*g/mole;
  G4Element* elXe  = new G4Element(name, symbol, Z, A);
  //---------------------------------------------------------
 
  //
  // define simple materials
  //
  //
  // The G4Material class describes the macroscopic properties of the matter:
  // density, state, temperature, pressure, radiation length, mean free path,
  // dE/dx ...
  // 
  // My name convention: all materials start with matXyz
  //
  // Sorted by Z
 
  // Liquid H2
  name     = "H2Liquid";
  density  = 0.0708*g/cm3;
  nelements = 1;
  G4Material* matLiquidHydrogen = new G4Material(name, density, nelements);
  matLiquidHydrogen -> AddElement(elH,1); 
  
  // Helium 3 Gas
  name     = "He3Gas";
  density  = 0.1340*mg/cm3;
  nelements = 1;
  G4Material* matHelium3Gas = new G4Material(name,density,nelements,kStateGas,273.15*kelvin,1.*atmosphere);
  matHelium3Gas->AddElement(elHe3,100.0*perCent);

  // Helium gas
  name     = "HeGas";
  density  = 0.1787*mg/cm3;
  nelements = 1;
  G4Material* matGasHelium = new G4Material(name,density,nelements, kStateGas, 273.15*kelvin,1.*atmosphere);
              matGasHelium ->AddElement(elHe,1);

  //Liquid  Helium 4
  name     = "HeLiquid";
  density  = 0.1249*g/cm3;
  nelements = 1;
  G4Material* matLiquidHelium = new G4Material(name, density, nelements);
  matLiquidHelium -> AddElement(elHe,1); 
  

    // Al material
  name     = "Aluminum";
  density  = 2.700*g/cm3;
  nelements = 1;
  G4Material* matAl = new G4Material(name,density,nelements);
              matAl -> AddElement(elAl,1);


  // gaseous Argon
  name      = "ArgonGas";
  density   = 1.7836*mg/cm3 ;       // STP
  nelements = 1;
  G4Material* matArgonGas = new G4Material(name,density,nelements, kStateGas, 273.15*kelvin,1.*atmosphere);
  matArgonGas ->AddElement(elAr, 1);

  // Lithium 6 material
  name =  "Lithium6";
  density = 0.534*g/cm3;
  // Z = 3.;
  // A = 6.0151*g/mole;
  nelements = 1;
  // G4Material* matLithium6 = new G4Material(name, Z, A, density);
  G4Material* matLithium6 = new G4Material(name,density,nelements);
  matLithium6 ->AddElement(elLi6, 1);


  // Iron material
//   name    = "Iron";
//   A       = 55.85*g/mole;
//   Z       = 26.;
//   density = 7.87*g/cm3;
//   G4Material* matIron = new G4Material(name,Z,A,density);

  // Copper material
  name    = "Copper";
  A       = 63.54*g/mole;
  Z       = 29.;
  density = 8.96*g/cm3;
  G4Material* matCopper = new G4Material(name,Z,A,density);

  // Tin material
  name    = "Tin";
  A       = 118.69*g/mole;
  Z       = 50.;
  density =  7.28*g/cm3;
  G4Material* matSn = new G4Material(name,Z,A,density);

  // Lead material
  name    = "Lead";
  A       = 207.19*g/mole;
  Z       = 82.;
  density = 11.35*g/cm3;
  G4Material* matPb = new G4Material(name,Z,A,density);




 // photocathode material, approximated as elemental cesium
  name      = "Photocathode";
  density   = 5.0*g/cm3; // true??
  nelements = 1;
  G4Material * matPhotocathode =  new G4Material(name,density,nelements);
               matPhotocathode -> AddElement(elK, 1);

  //=============================================================
  //
  // define a material from elements.   case 1: chemical molecule
  //
  //=============================================================




   // Xe gas
  name        = "XenonGas";
  density     = 5.458*mg/cm3;
  ncomponents = 1;
  G4Material* matXe =  new G4Material(name,density, ncomponents, kStateGas,273.15*kelvin,1.*atmosphere);
              matXe -> AddElement(elXe,1);
             
  // CO2 , STP
  name        = "CO2";
  density     = 1.818*mg/cm3;
  ncomponents = 2;
  G4Material* matCO2 = new G4Material(name,density, ncomponents, kStateGas,273.15*kelvin,1.*atmosphere);
              matCO2->AddElement(elC, natoms=1);
              matCO2->AddElement(elO, natoms=2);
	      
  name        = "N2";
  density     = 1.166*mg/cm3;
  ncomponents = 1;
  G4Material* matN2 = new G4Material(name,density, ncomponents, kStateGas,293.0*kelvin,1.*atmosphere);
              matN2->AddElement(elN, natoms=2);

  
  // Water
  name        = "Water" ;
  density     = 1.000*g/cm3;
  ncomponents = 2;
  G4Material* matH2O = new G4Material(name,density ,ncomponents);
              matH2O -> AddElement(elH,natoms=2);
              matH2O -> AddElement(elO,natoms=1);
              matH2O -> GetIonisation() -> SetMeanExcitationEnergy(75.0*eV);

  // Scintillator
  name        = "Scintillator";
  density     = 1.032*g/cm3;
  ncomponents = 2;
  G4Material* matScint = new G4Material(name, density, ncomponents);
              matScint->AddElement(elC, natoms=9);
              matScint->AddElement(elH, natoms=10);


  // Quartz SiO2 (e.g. Spectrosil 2000), optical properties will be added 
  name        = "Quartz";
  density     = 2.200*g/cm3;
  ncomponents = 2;
  G4Material* matQuartz = new G4Material(name,density, ncomponents);
              matQuartz->AddElement(elSi, natoms=1);
              matQuartz->AddElement(elO , natoms=2);

  // Quartz SiO2 (e.g. Spectrosil 2000) without optical properties
  name        = "SiO2";
  density     = 2.200*g/cm3;
  ncomponents = 2;
  G4Material* matSiO2 = new G4Material(name,density, ncomponents);
              matSiO2->AddElement(elSi, natoms=1);
              matSiO2->AddElement(elO , natoms=2);


  // SiElast_Glue  The glue used to glue together the quartz pieces
  name        = "SiElast_Glue";
  density     = 2.200*g/cm3;
  ncomponents = 2;
  G4Material* matSiElast = new G4Material(name,density, ncomponents);
              matSiElast->AddElement(elSi, natoms=1);
              matSiElast->AddElement(elO , natoms=2);

  // Lime Glass
  name        = "LimeGlass";
  density     = 2.200*g/cm3;
  ncomponents = 2;
  G4Material* matLimeGlass = new G4Material(name,density, ncomponents);
              matLimeGlass->AddElement(elSi, natoms=1);
              matLimeGlass->AddElement(elO , natoms=2);


  //Mylar
  name        = "Mylar";
  density     = 1.397 *g/cm3;
  ncomponents = 3;
  G4Material* matMylar = new G4Material(name,density , ncomponents);
              matMylar -> AddElement(elH, natoms= 8);
              matMylar -> AddElement(elC, natoms=10);
              matMylar -> AddElement(elO, natoms= 4);

  //Mirror
  name        = "Mirror";
  density     = 1.397 *g/cm3;
  ncomponents = 3;
  G4Material* matMirror = new G4Material(name,density , ncomponents);
              matMirror -> AddElement(elH, natoms= 8);
              matMirror -> AddElement(elC, natoms=10);
              matMirror -> AddElement(elO, natoms= 4);


  // Tyvek (High density Polyethylene)
  //  (...-CH2-CH2-...)*n
  name        = "Tyvek";
  density     = 0.96 *g/cm3;
  ncomponents = 2;
  G4Material* matTyvek = new G4Material(name,density , ncomponents);
              matTyvek -> AddElement(elH, natoms= 2);
              matTyvek -> AddElement(elC, natoms= 1);

  // Kevlar
  // (-NH-C6H4-NH-CO-C6H4-CO-)*n
  name        =	"Kevlar";
  density     = 1.44 *g/cm3;
  ncomponents = 4;
  G4Material* matKevlar = new G4Material(name,density , ncomponents);
              matKevlar -> AddElement(elH, natoms=10 );
              matKevlar -> AddElement(elC, natoms=14);
              matKevlar -> AddElement(elO, natoms= 2);
              matKevlar -> AddElement(elN, natoms= 2);

  //
  //    ---  H        O  -----
  //        -N-(CH2)5-C-
  //  
  name        = "Nylon";
  density     = 0.805*g/cm3;
  ncomponents = 4;
  G4Material* matNylon = new G4Material(name,density , ncomponents);
              matNylon -> AddElement(elH, natoms=11 );
              matNylon -> AddElement(elC, natoms= 6);
              matNylon -> AddElement(elO, natoms= 1);
              matNylon -> AddElement(elN, natoms= 1);



  //     H H 
  //  ---C-C--- 
  //     H COOCH3
  name        = "Acrylic";
  density     = 1.14*g/cm3;
  ncomponents = 3;
  G4Material* matAcrylic = new G4Material(name,density , ncomponents);
              matAcrylic -> AddElement(elH, natoms= 6);
              matAcrylic -> AddElement(elC, natoms= 4);
              matAcrylic -> AddElement(elO, natoms= 2);

  //   
  //  Nema grade G10 or FR4
  //  
  name        = "NemaG10";
  density     = 1.70*g/cm3;
  ncomponents = 4;
  G4Material* matG10 = new G4Material(name,density , ncomponents);
  matG10 -> AddElement(elSi, natoms=1);
  matG10 -> AddElement(elO , natoms=2);
  matG10 -> AddElement(elC , natoms=3);
  matG10 -> AddElement(elH , natoms=3);


  //======================================================================
  //
  // define a material from elements.   case 2: mixture by fractional mass
  //
  //======================================================================

  //Neutron Beam Monitor gas mixture

  name        = "NMonitorGas";
  density     = 0.373*mg/cm3;
  ncomponents = 3;
  G4Material* matNMonGas = new G4Material(name,density,ncomponents);
  matNMonGas -> AddMaterial(matHelium3Gas,fractionmass=0.01);
  matNMonGas -> AddMaterial(matGasHelium,fractionmass=0.21);
//   matNMonGas -> AddMaterial(matCO2,fractionmass=0.78);
  matNMonGas -> AddMaterial(matN2,fractionmass=0.78);

  // Air material: Air 18 degr.C and 58% humidity
  name        = "Air";
  density     = 1.214*mg/cm3;
  ncomponents = 4;
  G4Material* matAir = new G4Material(name,density,ncomponents);
  matAir -> AddElement(elN,  fractionmass=0.7494);
  matAir -> AddElement(elO,  fractionmass=0.2369);
  matAir -> AddElement(elAr, fractionmass=0.0129);
  matAir -> AddElement(elH,  fractionmass=0.0008);
  

  // Kapton
  name        = "Kapton";
  density     = 1.42*g/cm3;
  ncomponents = 4;
  G4Material* matKapton = new G4Material(name,density, ncomponents);
              matKapton->AddElement(elH, fractionmass = 0.0273);
              matKapton->AddElement(elC, fractionmass = 0.7213);
              matKapton->AddElement(elN, fractionmass = 0.0765);
              matKapton->AddElement(elO, fractionmass = 0.1749);


   
  // Polyethylene
  name        = "Polyethylene";
  density     = 0.94 * g/cm3;
  ncomponents = 2;
  G4Material* matPolyethylene = new G4Material(name,density, ncomponents);
              matPolyethylene -> AddElement(elH, fractionmass=0.14);
              matPolyethylene -> AddElement(elC, fractionmass=0.86);
  
  // Polyacrylate
  name        = "Polyacrylate";
  density     = 1.19 * g/cm3;
  ncomponents = 3;
  G4Material* matPolyacrylate = new G4Material(name,density,ncomponents);
              matPolyacrylate -> AddElement(elH, fractionmass=0.08);
              matPolyacrylate -> AddElement(elC, fractionmass=0.60);
              matPolyacrylate -> AddElement(elO, fractionmass=0.32);
 
  // VDC ArCO2 80/20
  name        = "ArCO2";
  density     = 0.0018*g/cm3; // to be checked
  ncomponents = 2;
  G4Material* matArCO2 = new G4Material(name,density,ncomponents);
              matArCO2->AddMaterial(matArgonGas, fractionmass = 0.8);
              matArCO2->AddMaterial(matCO2,      fractionmass = 0.2);


  // ShieldingConcrete: must  check recipe for concrete

  name        = "ShieldingConcrete";
  density     = 2.5*g/cm3;
  ncomponents = 6;
  G4Material* matConcrete = new G4Material(name,density,ncomponents);
              matConcrete->AddElement(elO,  fractionmass = 0.520);
              matConcrete->AddElement(elSi, fractionmass = 0.325);
              matConcrete->AddElement(elCa, fractionmass = 0.060);
              matConcrete->AddElement(elNa, fractionmass = 0.015);
              matConcrete->AddElement(elFe, fractionmass = 0.040);
              matConcrete->AddElement(elAl, fractionmass = 0.040);


  // material for the collimators: High Leaded Tin Bronze 
  // Copper Alloy No. C94300
  // see http://www/anchorbronze.com/c94300.html
  name        = "CDA943";
  density     = 9.29 * g/cm3;
  ncomponents = 3;
  G4Material* matCollimator = new G4Material(name,density,ncomponents);
              matCollimator-> AddMaterial(matCopper, fractionmass = 0.695);
              matCollimator-> AddMaterial(matPb    , fractionmass = 0.25);
              matCollimator-> AddMaterial(matSn    , fractionmass = 0.055);



   // TRT_CH2
   name        = "CH2";
   density     = 0.935*g/cm3;
   ncomponents = 2;
   G4Material* matCH2 = new G4Material(name, density, ncomponents);
               matCH2->AddElement(elC, natoms=1);
               matCH2->AddElement(elH, natoms=2);


  //vacuum
  name        = "Vacuum";
  A           = 1.01*g/mole;
  Z           = 1.;
  density     = 1.e-25 *g/cm3;
  pressure    = 3.e-18*pascal;
  temperature = 2.73*kelvin;
  G4Material* matVacuum = new G4Material("Vacuum", Z, A, density,kStateGas,temperature,pressure);
  pressure = matVacuum->GetPressure();
//               matVacuum -> AddElement(elHe,  fractionmass=1);


//========================================
// Hydrocarbones, metane and others
//========================================

  // CH4: Metane, STP
  name        = "Methane";
  density     = 0.7174*mg/cm3 ;
  ncomponents = 2;
  G4Material* matMetane = new G4Material(name,density,ncomponents);
              matMetane->AddElement(elC, natoms= 1) ;
              matMetane->AddElement(elH, natoms= 4) ;
 
  // C3H8: Propane, STP
  name        = "Propane";
  density     = 2.005*mg/cm3 ;
  ncomponents = 2;
  G4Material* matPropane = new G4Material(name,density,ncomponents);
              matPropane->AddElement(elC, natoms= 3) ;
              matPropane->AddElement(elH, natoms= 8) ;
 
   // C4H10 : iso-Butane (methylpropane), STP
   name        = "IsoButane";
   density     = 2.67*mg/cm3 ;
   ncomponents = 2;
   G4Material* matIsobutane = new G4Material(name,density,ncomponents);
               matIsobutane->AddElement(elC,natoms=  4) ;
               matIsobutane->AddElement(elH,natoms= 10) ;

  // C2H6 : Ethane, STP
   name        = "Ethane";
   density     = 1.356*mg/cm3 ;
   ncomponents = 2;
   G4Material* matEthane = new G4Material(name,density,ncomponents);
               matEthane->AddElement(elC, natoms= 2) ;
               matEthane->AddElement(elH, natoms= 6) ;



// Argon-Ethane 40-60 by mass, STP
   name        = "Ar-C2H6_40-60";
   density     = 1.46920*mg/cm3 ;
   ncomponents = 2;
   G4Material* matVDCGas = new G4Material(name,density,ncomponents);
               matVDCGas -> AddMaterial(matArgonGas , fractionmass = 0.40) ;
               matVDCGas -> AddMaterial(matEthane   , fractionmass = 0.60) ;


  // print out Material Table
  //G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  //============================================================================================
  //                          Optical Propeties
  //============================================================================================

  const G4int nEntries = 9;

  G4double PhotonEnergy[nEntries] =
    { 1.54986*eV,  // 800 nm 
      1.77127*eV,  // 700 nm
      2.06648*eV,  // 600 nm
      2.47978*eV,  // 500 nm
      3.09973*eV,  // 400 nm
      4.13297*eV,  // 300 nm
      4.95956*eV,  // 250 nm
      5.51063*eV,  // 225 nm
      5.90424*eV   // 210 nm
    };

//===========================
//  Optical Properties of Air
//===========================

// exact values can be taken from KamLAND code

  G4double RefractiveIndex_Air[nEntries] =
            {     1.00, // 800 nm 
	          1.00, // 700 nm
	          1.00, // 600 nm
	          1.00, // 500 nm
	          1.00, // 400 nm
	          1.00, // 300 nm
	          1.00, // 250 nm
                  1.00, // 225 nm
	          1.00  // 210 nm
	    };

  // normally air is very transparent to light in the visual spectrum,
  // but there I'm suppressing the optical tracking in air:
  // Don't show the cerenkov light leakage (detector->air)
//   G4double  AbsorptionCoeff_Air[nEntries] =
//     {     1e-3*m, //800 nm 
// 	  1e-3*m, //700 nm
// 	  1e-3*m, //600 nm
// 	  1e-3*m, //500 nm
// 	  1e-3*m, //400 nm
// 	  1e-3*m, //300 nm
// 	  1e-3*m, //250 nm
// 	  1e-3*m, //225 nm
// 	  1e-3*m  //210 nm
//     };
  G4double  AbsorptionCoeff_Air[nEntries] ={
    1e1*m, // 800 nm 
    1e1*m, // 700 nm
    1e1*m, // 600 nm
    1e1*m, // 500 nm
    1e1*m, // 400 nm
    1e1*m, // 300 nm
    1e1*m, // 250 nm
    1e1*m, // 225 nm
    1e1*m  // 210 nm
  };
  

  G4MaterialPropertiesTable* myMPT_Air = new G4MaterialPropertiesTable();
  myMPT_Air->AddProperty("RINDEX",    PhotonEnergy, RefractiveIndex_Air, nEntries);
  myMPT_Air->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionCoeff_Air, nEntries);

   matAir->SetMaterialPropertiesTable(myMPT_Air);


//=======================================
//  Optical Properties of Soda Lime Glass
//=======================================

   //*************************************************
   // could not find anything in the literature + web
   // about the optical properties of lime glass ...
   // so here we have only "educated guesses"
   //**************************************************

// values taken from KamLAND code

  G4double RefractiveIndex_LimeGlass[nEntries] =
        { 1.52, // 800 nm  
	  1.52, // 700 nm
	  1.52, // 600 nm  pretty close
	  1.52, // 500 nm
	  1.52, // 400 nm  pretty close
	  1.52, // 300 nm
	  1.52, // 250 nm
	  1.52, // 225 nm  fiction
	  1.52  // 210 nm
      };


  G4double  AbsorptionCoeff_LimeGlass[nEntries] =
        { 1.0e3*m, // 800 nm 
	  1.0e3*m, // 700 nm
	  1.0e3*m, // 600 nm
	  1.0e3*m, // 500 nm
	  1.0e3*m, // 400 nm
	  1.0e3*m, // 300 nm
	  1.0e3*m, // 250 nm
	  1.0e3*m, // 225 nm
	  1.0e3*m  // 210 nm
	};

  G4MaterialPropertiesTable* myMPT_LimeGlass = new G4MaterialPropertiesTable();
  myMPT_LimeGlass->AddProperty("RINDEX",    PhotonEnergy, RefractiveIndex_LimeGlass , nEntries);
  myMPT_LimeGlass->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionCoeff_LimeGlass , nEntries);

  matLimeGlass->SetMaterialPropertiesTable(myMPT_LimeGlass);


//====================================
//  Optical Properties of Fused Silica
//====================================

  // Fused Silica (Spectrosil 2000) for the Cerenkov Detector
  // See Elog entry #43, Software
  G4double RefractiveIndex_FusedSilica[nEntries] =
    { 1.45338,  // 800 nm 
      1.45536,  // 700 nm
      1.45810,  // 600 nm
      1.46239,  // 500 nm
      1.47018,  // 400 nm
      1.48786,  // 300 nm
      1.50751,  // 250 nm
      1.52422,  // 225 nm
      1.53842   // 210 nm
    };

  // Given by the BaBar Collaboration for the DIRC bar
  // BaBar Note #220
  G4double AbsorptionCoeff_FusedSilica[nEntries] =
           { 263.16*m,   // 800 nm pi*thumb extrapolated 
	     250.00*m,   // 700 nm pi*thumb extrapolated
	     227.27*m,   // 600 nm
	     200.00*m,   // 500 nm
	     131.58*m,   // 400 nm
	      16.13*m,   // 300 nm
	       0.74*m,   // 250 nm
	       0.125*m,   // 225 nm
               0.010*m    // 210 nm
	    };

  #undef lossyquartz
  #ifdef lossyquartz
  for(int i=0;i<nEntries;i++)
    AbsorptionCoeff_FusedSilica[i]=AbsorptionCoeff_FusedSilica[i]/100;
  #endif


  G4MaterialPropertiesTable* myMPT_FusedSilica = new G4MaterialPropertiesTable();
  myMPT_FusedSilica->AddProperty("RINDEX",    PhotonEnergy, RefractiveIndex_FusedSilica , nEntries);
  myMPT_FusedSilica->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionCoeff_FusedSilica , nEntries);

  matQuartz->SetMaterialPropertiesTable(myMPT_FusedSilica);

  //*************************************************************************************************


//====================================
//  Optical Properties of Silicon Elastomer Glue
//====================================

  // Fused Silica (Spectrosil 2000) for the Cerenkov Detector
  // See Elog entry #43, Software
  G4double RefractiveIndex_SilElast[nEntries] =
    { 1.405,  // 800 nm 
      1.405,  // 700 nm
      1.405,  // 600 nm
      1.405,  // 500 nm
      1.405,  // 400 nm
      1.405,  // 300 nm
      1.405,  // 250 nm
      1.405,  // 225 nm
      1.405   // 210 nm
    };


  G4double AbsorptionCoeff_SilElast[nEntries] =
           { 263.16*m,   // 800 nm pi*thumb extrapolated 
	     250.00*m,   // 700 nm pi*thumb extrapolated
	     227.27*m,   // 600 nm
	     200.00*m,   // 500 nm
	     131.58*m,   // 400 nm
	      16.13*m,   // 300 nm
	       0.74*m,   // 250 nm
	       0.125*m,   // 225 nm
               0.010*m    // 210 nm
	    };

  G4MaterialPropertiesTable* myMPT_SilElast = new G4MaterialPropertiesTable();
  myMPT_SilElast->AddProperty("RINDEX",    PhotonEnergy, RefractiveIndex_SilElast , nEntries);
  myMPT_SilElast->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionCoeff_SilElast , nEntries);

  matSiElast->SetMaterialPropertiesTable(myMPT_SilElast);

  //*************************************************************************************************


  G4double reflind_Mirror[nEntries] ={ 
    1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0
  };
  G4double refrind_Mirror[nEntries] ={ 
    0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0
  };

  G4double abslength_Mirror[nEntries] ={ 
    1.0e3*m,1.0e3*m,1.0e3*m,1.0e3*m,1.0e3*m,1.0e3*m,1.0e3*m,1.0e3*m,1.0e3*m
  };

  G4MaterialPropertiesTable* myMPT_Mirror = new G4MaterialPropertiesTable();
  myMPT_Mirror->AddProperty("REFLECTIVITY", PhotonEnergy, reflind_Mirror, nEntries);
  myMPT_Mirror->AddProperty("RINDEX",    PhotonEnergy, refrind_Mirror, nEntries);
  myMPT_Mirror->AddProperty("ABSLENGTH", PhotonEnergy, abslength_Mirror, nEntries);

  matMirror->SetMaterialPropertiesTable(myMPT_Mirror);

}


G4Material* GenSimMaterial::GetMaterial(G4String material)
{
  G4Material* pttoMaterial = G4Material::GetMaterial(material); 

  // static const G4MaterialTable *tbl = G4Material::GetMaterialTable();
  // G4int num = G4Material::GetNumberOfMaterials();
  
  // for(int l = 0; l < tbl->size(); l++)
  //   G4cout << (*tbl)[l]->GetName() << G4endl;
  
  return pttoMaterial; 
}

