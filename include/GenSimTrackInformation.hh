#ifndef GenSimTrackInformation_h
#define GenSimTrackInformation_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#define myElectron 1
#define myPositron 2
#define myGamma    3  //as in non-optical photon including x-ray
#define myProton   4
#define myNeutron  5
#define myTriton   6
#define myAlpha    7
#define myHelium3  8
#define myNucleus  9

class GenSimTrackInformation : public G4VUserTrackInformation 
{

public:

  GenSimTrackInformation();
  GenSimTrackInformation(const G4Track* aTrack);
  GenSimTrackInformation(const GenSimTrackInformation* aTrackInfo);
  virtual ~GenSimTrackInformation();
  
  inline void *operator new(size_t);
  inline void  operator delete(void *aTrackInfo);
  inline int   operator ==(const GenSimTrackInformation& right) const
  {return (this==&right);}
  
private:

  G4bool NewSecondaryFlag;

  //This is information for this (current) track 
  
  // TrackInfo which can derived from G4Track
  G4int                 TrackID;
  G4String              ParticleCreatorProcess;
  G4ParticleDefinition* particleDefinition;
  G4ThreeVector         InitialPosition;
  G4ThreeVector         InitialMomentum;
  G4double              InitialEnergy;
  G4double              InitialKineticEnergy;
  G4double              InitialTime;
  G4double              InitialTheta;
  G4double              InitialPhi;

  // TrackInfo which can *not* be derived from G4Track
  G4double              ParentEnergy;
  G4int                 ParentTrackID;
  G4int                 stepNumber;
  G4int                 eventNumber;

  vector <G4double> StepEnergyLoss;
  vector <G4ThreeVector> StepVertex;
  vector <G4double> StepFinalEnergy;
  vector <G4double> StepLength;
  vector <G4String> StepVolume;
  vector <G4String> StepDefinedProcess;
  vector <G4double> TrackRangeIntegral;
  vector <G4double> TrackdEdxIntegral;
  vector <G4double> StepdEdx;

 public:

  void Print() const;
  void PrintTrackInfo();
  void Initialize();

  G4int                 GetTrackID()                 {return TrackID;};
  G4String              GetCreatorProcess()          {return ParticleCreatorProcess;};
  G4ParticleDefinition* GetParticleDefinition()      {return particleDefinition;};
  G4ThreeVector         GetInitialPosition()         {return InitialPosition;};
  G4ThreeVector         GetInitialMomentum()         {return InitialMomentum;};
  G4double              GetInitialEnergy()           {return InitialEnergy;};
  G4double              GetInitialKineticEnergy()    {return InitialKineticEnergy;};
  G4double              GetInitialTime()             {return InitialTime;};
  G4double              GetInitialTheta()            {return InitialTheta;};
  G4double              GetInitialPhi()              {return InitialPhi;};

  G4double              GetParentEnergy()            {return ParentEnergy;};
  G4int                 GetParentTrackID()           {return ParentTrackID;};
  G4int                 GetCurrentStepNumber()       {return stepNumber;};
  G4int                 GetEventNumber()             {return eventNumber;};
  G4int                 GetTrackStepHistoryLength()  {return stepNumber;};

  G4double              GetStepEnergyLoss(G4int id); 
  G4ThreeVector         GetStepVertex(G4int id);     
  G4double              GetStepFinalEnergy(G4int id);
  G4double              GetStepLength(G4int id);        
  G4String              GetStepVolume(G4int id);        
  G4String              GetStepDefinedProcess(G4int id);
  G4double              GetTrackRangeIntegral(G4int id);
  G4double              GetTrackdEdxIntegral(G4int id);
  G4double              GetStepdEdx(G4int id);
  G4bool                GetNewSecondaryFlag() {return NewSecondaryFlag;};

  void StoreTrackInfo(const G4Track* aTrack);
  void StoreTrackID(G4int ID)             {TrackID = ID;};
  void StoreParentEnergy(G4double eng)    {ParentEnergy = eng;};
  void StoreParentTrackID(G4int ID)       {ParentTrackID = ID;};
  void StoreEventNumber(G4int num)        {eventNumber = num;};
  void StoreStepInformation(G4double el, G4ThreeVector vec, G4double eng, G4double len, G4String vol, G4String stDP);
  void SetNewSecondaryFlag(G4bool flg) {NewSecondaryFlag = flg;};

};

extern G4Allocator<GenSimTrackInformation> aTrackInformationAllocator;

inline void* GenSimTrackInformation::operator new(size_t)
{ 
  void*  aTrackInfo;
         aTrackInfo = (void*) aTrackInformationAllocator.MallocSingle();
  return aTrackInfo;
}

inline void GenSimTrackInformation::operator delete(void *aTrackInfo)
{ aTrackInformationAllocator.FreeSingle((GenSimTrackInformation*)aTrackInfo);}

#endif
