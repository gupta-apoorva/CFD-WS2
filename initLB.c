#include "initLB.h"
#include "LBDefinitions.h"

#define FLUID 0
#define NO_SLIP 1
#define MOVING_WALL 2

int readParameters(int *xlength, double *tau, double *velocityWall, int *timesteps, int *timestepsPerPlotting, int argc, char *arg)
{

// Making sure that only 1 arguments are provided (input parameter file: cavity.dat)

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

// First initializing the entire flagfield with 1 (NO SLIP) then in the next loop initializing all the interior cells with 0 (fluid) and in the last loop initializing all the moving wall cells with the value 2 (moving wall).

  int x,y,z, i;
 
// Initializing the flag field

  for (x =0;x<(xlength+2);x++)                                                    
     {                                                                           
       for (y =0;y<(xlength+2);y++)                                               
         {
            for (z =0;z<(xlength+2);z++)
             {
                flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] = NO_SLIP;
             }
         }
      }
                                                           
  for (z =1;z<(xlength+1);z++)
     {
       for (y =1;y<(xlength+1);y++)
         {
            for (x =1;x<(xlength+1);x++)
             {
                flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] = FLUID;
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
                flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] = MOVING_WALL;
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

