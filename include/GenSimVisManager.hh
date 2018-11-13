#ifndef GenSimVisManager_h
#define GenSimVisManager_h 1

#ifdef G4VIS_USE

#include "G4VisManager.hh"

class GenSimVisManager: public G4VisManager {

public:

  GenSimVisManager ();

private:

  void RegisterGraphicsSystems ();

};

#endif

#endif
