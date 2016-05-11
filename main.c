#ifndef _MAIN_C_
#define _MAIN_C_

#include "collision.h"
#include "streaming.h"
#include "initLB.h"
#include "visualLB.h"
#include "boundary.h"

int main(int argc, char *argv[]){
    
    int Q = 19;
    int xlength;                       /* reads domain size. Parameter name: "xlength" */
    double tau;                        /* relaxation parameter tau. Parameter name: "tau" */
    double velocityWall;               /* velocity of the lid. Parameter name: "characteristicvelocity" */
    int timesteps;                     /* number of timesteps. Parameter name: "timesteps" */
    int timestepsPerPlotting;
    double* collideField; 
    double* streamField;
    int* flagField;

    readParameters(&xlength, &tau, &velocityWall, &timesteps, &timestepsPerPlotting, argc, argv[1]);
    //printf("%d\n",xlength);
    
    collideField = (double*) malloc(Q*(xlength+2)*(xlength+2)*(xlength+2)*sizeof(double));
    streamField = (double*) malloc(Q*(xlength+2)*(xlength+2)*(xlength+2)*sizeof(double));
    flagField = (int*) malloc((xlength+2)*(xlength+2)*(xlength+2)*sizeof(int));

    initialiseFields(collideField, streamField, flagField, xlength);

  for (int x =0;x<(xlength+2);x++)
     {
       for (int y =0;y<(xlength+2);y++)
         {
            for (int z =0;z<(xlength+2);z++)
             {
                 for( int i =0 ; i<Q ; i++)
                  {
                    printf("%f",collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + i]);
                  }
            
             }
         printf("\n");
         }
      printf("\n");
      }

    free(collideField);
    free (streamField);
    free (flagField);
  return 0;
}

#endif







