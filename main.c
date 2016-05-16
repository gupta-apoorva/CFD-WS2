#ifndef _MAIN_C_st
#define _MAIN_C_

#include "collision.h"
#include "streaming.h"
#include "LBDefinitions.h"
#include "initLB.h"
#include "visualLB.h"
#include "boundary.h"



int main(int argc, char *argv[]){  
  
    int xlength;                       /* reads domain size. Parameter name: "xlength" */
    double tau;                        /* relaxation parameter tau. Parameter name: "tau" */
    double velocityWall;               /* velocity of the lid. Parameter name: "characteristicvelocity" */
    int timesteps;                     /* number of timesteps. Parameter name: "timesteps" */
    int timestepsPerPlotting;
    double* collideField; 
    double* streamField;
    int* flagField;

    readParameters(&xlength, &tau, &velocityWall, &timesteps, &timestepsPerPlotting, argc, argv[1]);
    
    // Allocating the size on the heap for collidefield, streamfield and flagfield
     
    collideField = (double*) malloc(Q*(xlength+2)*(xlength+2)*(xlength+2)*sizeof(double));     
    streamField = (double*) malloc(Q*(xlength+2)*(xlength+2)*(xlength+2)*sizeof(double));
    flagField = (int*) malloc((xlength+2)*(xlength+2)*(xlength+2)*sizeof(int));

    // Initializing the collidefield, streamfield and flagfield with the function implemented in initLB
    initialiseFields(collideField, streamField, flagField, xlength); 

    // printing the initial conditions.            
    writeVtkOutput(collideField,flagField,argv[1],0,xlength); 

   // starting the time stepping loop to successively update the values in each cell.                                                                         
   for(int t = 1; t <= timesteps; t++)                                           
      {
        double *swap = NULL;
        doStreaming(collideField,streamField,flagField,xlength);                // Streaming the values...Function immplemented in streaming.c
        swap = collideField;                                                    // Swapping the values of collide field and streamfield
        collideField = streamField;
        streamField = swap;

        doCollision(collideField,flagField,&tau,xlength);                       // Doing the collision step of lattice boltzmann.
        treatBoundary(collideField,flagField,&velocityWall,xlength);            // Updating the boundary values in collide field based on the type of boundary. 

        if(t % timestepsPerPlotting == 0)
           {
              writeVtkOutput(collideField,flagField,argv[1],t,xlength);
           }
      }
 
   // Freeing the space allocated on heap for collidefield  streamfield and flagfield.
   free(collideField);                                                         
   free (streamField);
   free (flagField);
  return 0;
}

#endif








