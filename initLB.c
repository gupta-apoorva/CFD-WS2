#include "initLB.h"
#include "LBDefinitions.h"

int readParameters(int *xlength, double *tau, double *velocityWall, int *timesteps, int *timestepsPerPlotting, int argc, char *arg)
{

if (argc==2)                                                                // Making sure that only 2 arguments are provided...one being the filename and other being the file
{                                                                           // from which the data has to be read.
READ_INT    ( arg, *xlength );
READ_DOUBLE ( arg, *tau );
READ_DOUBLE( arg, *velocityWall );
READ_INT    ( arg, *timesteps);
READ_INT   ( arg, *timestepsPerPlotting );
}

else if(argc == 1)
{
printf ("ERROR: File Name not provided.\n");
}
else
{
printf ("ERROR: Too many input arguments.\n");
}
return 0;
}


void initialiseFields(double *collideField, double *streamField, int *flagField, int xlength)
{
  int x,y,z, i;
 
// Initializing the flag field

  for (x =0;x<(xlength+2);x++)                                                   // First initializing the entire flagfield with 1 (NO SLIP) then in the next loop initializing 
     {                                                                           // all the interior cells with 0 (fluid) and in the last loop initializing all the moving wall 
       for (y =0;y<(xlength+2);y++)                                              // cells with the value 2 (moving wall).
         {
            for (z =0;z<(xlength+2);z++)
             {
                flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] = 1;
             }
         }
      }
                                                            // FLUID = 0, NO_SLIP = 1 , MOVING_WALL = 2
  for (z =1;z<(xlength+1);z++)
     {
       for (y =1;y<(xlength+1);y++)
         {
            for (x =1;x<(xlength+1);x++)
             {
                flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] = 0;
             }
         }
      }
   z = xlength+1;
   while (z > xlength)
     {
       for (x =0;x<(xlength+2);x++)
         {
            for (y =0;y<(xlength+2);y++)
             {
                flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] = 2;
             }
         }
      --z;
      }

// Initializing the collideField with the latticeweights

  for (z =0;z<(xlength+2);z++)
     {
       for (y =0;y<(xlength+2);y++)
         {
            for (x =0;x<(xlength+2);x++)
             {
                 for( i =0 ; i<Q ; i++)
                  {
                    collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + i] =LATTICEWEIGHTS[i];
                  }
             }
         }
      }

// Initializing the streamfield with the lattice weights

  for (z =0;z<(xlength+2);z++)
     {
       for (y =0;y<(xlength+2);y++)
         {
            for (x =0;x<(xlength+2);x++)
             {
                 for( i =0 ; i<Q ; i++)
                  {
                    streamField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + i] = LATTICEWEIGHTS[i];
                  }
             }
         }
      }

}

