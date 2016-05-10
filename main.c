#ifndef _MAIN_C_
#define _MAIN_C_

#include "collision.h"
#include "streaming.h"
#include "initLB.h"
#include "visualLB.h"
#include "boundary.h"

int main(int argc, char *argv[]){

 int xlength;                       /* reads domain size. Parameter name: "xlength" */
    double tau;                        /* relaxation parameter tau. Parameter name: "tau" */
    double velocityWall;               /* velocity of the lid. Parameter name: "characteristicvelocity" */
    int timesteps;                     /* number of timesteps. Parameter name: "timesteps" */
    int timestepsPerPlotting;



  readParameters(&xlength, &tau, &velocityWall, &timesteps, &timestepsPerPlotting, argc, argv[1]);
  //printf("%d\n",xlength);


  return 0;
}

#endif

