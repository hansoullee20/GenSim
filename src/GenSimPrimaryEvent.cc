#include "GenSimPrimaryEvent.hh"

ClassImp(GenSimPrimaryEvent);

GenSimPrimaryEvent::GenSimPrimaryEvent()   
{
  Initialize();
} 

GenSimPrimaryEvent::~GenSimPrimaryEvent()
{

}

void GenSimPrimaryEvent::Initialize()
{
  TrackID                        = 0;
  GlobalTime                     = 0.0;
  OriginVertexPositionX          = 0.0;
  OriginVertexPositionY          = 0.0;
  OriginVertexPositionZ          = 0.0;
  OriginVertexMomentumX          = 0.0;
  OriginVertexMomentumY          = 0.0;
  OriginVertexMomentumZ          = 0.0;
  OriginVertexThetaAngle         = 0.0;
  OriginVertexPhiAngle           = 0.0;
  OriginVertexKineticEnergy      = 0.0;
}

void GenSimPrimaryEvent::PrintData()
{
  printf("TrackID                   = %d\n",TrackID                   );
  printf("GlobalTime                = %f\n",GlobalTime                );
  printf("OriginVertexPositionX     = %f\n",OriginVertexPositionX     );
  printf("OriginVertexPositionY     = %f\n",OriginVertexPositionY     );
  printf("OriginVertexPositionZ     = %f\n",OriginVertexPositionZ     );
  printf("OriginVertexMomentumX     = %f\n",OriginVertexMomentumX     );
  printf("OriginVertexMomentumY     = %f\n",OriginVertexMomentumY     );
  printf("OriginVertexMomentumZ     = %f\n",OriginVertexMomentumZ     );
  printf("OriginVertexThetaAngle    = %f\n",OriginVertexThetaAngle    );
  printf("OriginVertexPhiAngle      = %f\n",OriginVertexPhiAngle      );
  printf("OriginVertexKineticEnergy = %f\n",OriginVertexKineticEnergy );
}
