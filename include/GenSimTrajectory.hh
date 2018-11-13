#ifndef GenSimTrajectory_h
#define GenSimTrajectory_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

typedef std::vector<G4VTrajectoryPoint*> GenSimTrajectoryPointContainer;

class GenSimTrajectory : public G4VTrajectory
{

//--------
   public:
//--------

   GenSimTrajectory();

   GenSimTrajectory(const G4Track* aTrack);
   GenSimTrajectory(GenSimTrajectory &);
   virtual ~GenSimTrajectory();


   inline void* operator new(size_t);
   inline void  operator delete(void*);
   inline int operator == (const GenSimTrajectory& right) const
   {return (this==&right);}

// Get/Set functions
   inline G4int GetTrackID() const
   { return fTrackID; }
   inline G4int GetParentID() const
   { return fParentID; }
   inline G4String GetParticleName() const
   { return ParticleName; }
   inline G4double GetCharge() const
   { return PDGCharge; }
   inline G4int GetPDGEncoding() const
   { return PDGEncoding; }
   inline G4ThreeVector GetInitialMomentum() const
   { return InitialMomentum; }

// Other member functions
   virtual void ShowTrajectory() const;
   virtual void ShowTrajectory(std::ostream& o) const;
   virtual void DrawTrajectory(G4int i_mode=0) const;
   virtual void AppendStep(const G4Step* aStep);
   virtual void MergeTrajectory(G4VTrajectory* secondTrajectory);

   // From LXe example
   void SetDrawTrajectory(G4bool b){drawit=b;}
   void SetForceDrawTrajectory(G4bool b){forceDraw=b;}
   void SetForceNoDrawTrajectory(G4bool b){forceNoDraw=b;}

   G4ParticleDefinition* GetParticleDefinition();

//---------
   private:
//---------

  GenSimTrajectoryPointContainer* positionRecord;
  G4int fTrackID;
  G4int fParentID;
  G4ParticleDefinition* fpParticleDefinition;
  G4String ParticleName;
  G4double PDGCharge;
  G4int    PDGEncoding;
// FIXME not initialized !!!
  G4ThreeVector InitialMomentum;

// From LXe example
  G4bool drawit;
  G4bool forceNoDraw;
  G4bool forceDraw;

//---------
   public:
//---------
   virtual int GetPointEntries() const
   { return positionRecord->size(); }
   virtual G4VTrajectoryPoint* GetPoint(G4int i) const
   { return (*positionRecord)[i]; }
};

extern G4Allocator<GenSimTrajectory> myTrajectoryAllocator;

inline void* GenSimTrajectory::operator new(size_t)
{
  void* aTrajectory;
  aTrajectory = (void*)myTrajectoryAllocator.MallocSingle();
  return aTrajectory;
}

inline void GenSimTrajectory::operator delete(void* aTrajectory)
{
  myTrajectoryAllocator.FreeSingle((GenSimTrajectory*)aTrajectory);
}

#endif
