#include "initLB.h"

int readParameters(int *xlength, double *tau, double *velocityWall, int *timesteps, int *timestepsPerPlotting, int argc, char *arg)
{

if (argc==2)
{
READ_INT    ( arg, *xlength );
READ_DOUBLE ( arg, *tau );
READ_DOUBLE( arg, *velocityWall );
READ_INT    ( arg, *timesteps);
READ_INT   ( arg, *timestepsPerPlotting );
}

else if(argc == 1)
{
printf ("ERROR: File Name not provided.");
}
else
{
printf ("ERROR: Too many input arguments.");
}
return 0;
}


void initialiseFields(double *collideField, double *streamField, int *flagField, int xlength){
  /* TODO */
}

