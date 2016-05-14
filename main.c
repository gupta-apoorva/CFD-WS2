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
    
    collideField = (double*) malloc(Q*(xlength+2)*(xlength+2)*(xlength+2)*sizeof(double));     // Allocating the size on the heap for collidefield, streamfield and flagfield
    streamField = (double*) malloc(Q*(xlength+2)*(xlength+2)*(xlength+2)*sizeof(double));
    flagField = (int*) malloc((xlength+2)*(xlength+2)*(xlength+2)*sizeof(int));

    initialiseFields(collideField, streamField, flagField, xlength);             // Initializing the collidefield, streamfield and flagfield with the function implemented 
                                                                                 // in initLB
 /* for (int x =0;x<(xlength+2);x++)
     {
       for (int y =0;y<(xlength+2);y++)
         {
            for (int z =0;z<(xlength+2);z++)
             {
                 for( int i =0 ; i<Q ; i++)
                  {

                      //printf("%d",5);
                    printf("%f",collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + i]);
                  }
             printf("\n");
             }
         }
      }
*/
   for(int t = 0; t < timesteps; t++)                                           // starting the time stepping loop to successively update the values in each cell.
      {
        double *swap = NULL;
        doStreaming(collideField,streamField,flagField,xlength);                // Streaming the values...Function immplemented in streaming.c
        swap = collideField;                                                    // Swapping the values of collide field and streamfield
        collideField = streamField;
        streamField = swap;

        doCollision(collideField,flagField,&tau,xlength);                       // Doing the collision step of lattice boltzmann.
        treatBoundary(collideField,flagField,&velocityWall,xlength);            // Updating the boundary values in collide field based on the type of boundary. 

       // if(t % timestepsPerPlotting == 0)
         //  {
           //   writeVtkOutput(collideField,flagField,argv[0],t,xlength);
           //}
      }

 //printf("%d",Q);
//printf("%f",LATTICEWEIGHTS[0]);

/*    for( int i =0 ; i<Q ; i++)
                  {

                     
                    printf("%f",LATTICEWEIGHTS[i]);
printf("  ");                
  }
 */   
    free(collideField);                                                          // Freeing the space allocated on heap for collidefield  streamfield and flagfield.
    free (streamField);
    free (flagField);
  return 0;
}

#endif








