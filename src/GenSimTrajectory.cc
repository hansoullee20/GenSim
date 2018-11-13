#include "GenSimTrajectory.hh"

G4Allocator<GenSimTrajectory> myTrajectoryAllocator;

GenSimTrajectory::GenSimTrajectory()
{

    drawit       = FALSE;
    forceNoDraw  = FALSE;
    forceDraw    = FALSE;


   fpParticleDefinition = 0;
   ParticleName         = "";
   PDGCharge            = 0;
   PDGEncoding          = 0;
   fTrackID             = 0;
   fParentID            = 0;
   positionRecord       = 0;
}


GenSimTrajectory::GenSimTrajectory(const G4Track* aTrack)
{
   fpParticleDefinition = aTrack->GetDefinition();
   ParticleName         = fpParticleDefinition->GetParticleName();
   PDGCharge            = fpParticleDefinition->GetPDGCharge();
   PDGEncoding          = fpParticleDefinition->GetPDGEncoding();
   fTrackID             = aTrack->GetTrackID();
   fParentID            = aTrack->GetParentID();

   positionRecord =  new GenSimTrajectoryPointContainer();
   positionRecord -> push_back(new G4TrajectoryPoint(aTrack->GetPosition()));
}

GenSimTrajectory::GenSimTrajectory(GenSimTrajectory & right)
    : G4VTrajectory()
{
  ParticleName          = right.ParticleName;
  fpParticleDefinition  = right.fpParticleDefinition;
  PDGCharge             = right.PDGCharge;
  PDGEncoding           = right.PDGEncoding;
  fTrackID              = right.fTrackID;
  fParentID             = right.fParentID;

  positionRecord = new GenSimTrajectoryPointContainer();

  for(int i=0;i<(int)right.positionRecord->size();i++)
  {
    G4TrajectoryPoint* rightPoint = (G4TrajectoryPoint*)((*(right.positionRecord))[i]);

    positionRecord->push_back(new G4TrajectoryPoint(*rightPoint));
  }
}

GenSimTrajectory::~GenSimTrajectory()
{
  size_t i;
  for(i=0;i<positionRecord->size();i++){
    delete  (*positionRecord)[i];
  }
  positionRecord->clear();

  delete positionRecord;
}

void GenSimTrajectory::ShowTrajectory() const
{
  //G4cout << G4endl << "TrackID ="  << fTrackID
  //                << ":ParentID=" << fParentID << G4endl;

  //G4cout << "Particle name : " << ParticleName
  //      << "  Charge : "      << PDGCharge      << G4endl;

  //G4cout << "  Current trajectory has " << positionRecord->size() << " points."  << G4endl;

   // for( size_t i=0 ; i < positionRecord->size() ; i++){
   //     G4TrajectoryPoint* aTrajectoryPoint = (G4TrajectoryPoint*)((*positionRecord)[i]);

   //     //G4cout << "Point[" << i << "]" << " Position= " << aTrajectoryPoint->GetPosition() << G4endl;
   // }
}

void GenSimTrajectory::ShowTrajectory(std::ostream& o) const
{
    G4VTrajectory::ShowTrajectory(o);
}

void GenSimTrajectory::DrawTrajectory(G4int i_mode) const
{
  if(i_mode) {}

  if(!forceDraw && (!drawit || forceNoDraw))
    return;

  // If i_mode>=0, draws a trajectory as a polyline (blue for
  // positive, red for negative, green for neutral) and, if i_mode!=0,
  // adds markers - yellow circles for step points and magenta squares
  // for auxiliary points, if any - whose screen size in pixels is
  // given by abs(i_mode)/1000.  E.g: i_mode = 5000 gives easily
  // visible markers.

   G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

   G4ThreeVector pos;
   G4Polyline    pPolyline;

   for (int i = 0; i < (int)positionRecord->size() ; i++) {

       G4TrajectoryPoint* aTrajectoryPoint = (G4TrajectoryPoint*)((*positionRecord)[i]);
       pos = aTrajectoryPoint->GetPosition();
       pPolyline.push_back( pos );
   }

   G4Colour colour(0.75,0.75,0.75);    // LightGray

   if(fpParticleDefinition==G4Gamma::GammaDefinition())
      colour = G4Colour(0.,1.,1.);     // Cyan
   else if(fpParticleDefinition==G4Electron::ElectronDefinition()
         ||fpParticleDefinition==G4Positron::PositronDefinition())
      colour = G4Colour(1.,1.,0.);      // Yellow
   else if(fpParticleDefinition==G4MuonMinus::MuonMinusDefinition()
         ||fpParticleDefinition==G4MuonPlus::MuonPlusDefinition())
      colour = G4Colour(1.,0.,1.);      // Magenta
   else if(fpParticleDefinition->GetParticleType()=="meson")
   {
      if(PDGCharge!=0.)
         colour = G4Colour(1.,0.,0.);   // Red
      else
         colour = G4Colour(0.5,0.,0.);  // HalfRed
   }
   else if(fpParticleDefinition->GetParticleType()=="baryon")
   {
      if(PDGCharge!=0.)
         colour = G4Colour(1.,0.78,0.); // Orange
      else
         colour = G4Colour(0.5,0.39,0.);// HalfOrange
   }

   G4VisAttributes attribs(colour);
   pPolyline.SetVisAttributes(attribs);

   if(pVVisManager) pVVisManager->Draw(pPolyline);
}

void GenSimTrajectory::AppendStep(const G4Step* aStep)
{
   positionRecord->push_back( new G4TrajectoryPoint(aStep->GetPostStepPoint()->GetPosition() ));
}

G4ParticleDefinition* GenSimTrajectory::GetParticleDefinition()
{
   return (G4ParticleTable::GetParticleTable()->FindParticle(ParticleName));
}

void GenSimTrajectory::MergeTrajectory(G4VTrajectory* secondTrajectory)
{
  if(!secondTrajectory) return;

  GenSimTrajectory* seco = (GenSimTrajectory*)secondTrajectory;
  G4int ent = seco->GetPointEntries();

  for(int i=1;i<ent;i++) // initial point of the second trajectory should not be merged
  {
    positionRecord->push_back((*(seco->positionRecord))[i]);
  }

  delete (*seco->positionRecord)[0];

  seco->positionRecord->clear();

}
