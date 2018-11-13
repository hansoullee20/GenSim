#include "GenSimUserInformation.hh"

GenSimUserInformation::GenSimUserInformation()
{
  Initialize();
}

GenSimUserInformation::~GenSimUserInformation()
{
}

void GenSimUserInformation::Print() const
{
  if(primaryEventNumber%100 == 0)
    G4cout << "Run " << myRunID << " Capture Event# " << primaryEventNumber << G4endl;

}


void GenSimUserInformation::Initialize()
{
  myRunID = 0;
  primaryEnergy                  = 0.0;
  primaryEventNumber             = 0;
}




