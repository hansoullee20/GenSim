#ifndef GenSimSteppingVerbose_h
#define GenSimSteppingVerbose_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

class GenSimSteppingVerbose;

class GenSimSteppingVerbose : public G4SteppingVerbose 
{
 public:
   
  GenSimSteppingVerbose();
 ~GenSimSteppingVerbose();

  void StepInfo();
  void TrackingStarted();

};

#endif
