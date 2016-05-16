#include "computeCellValues.h"
#include "LBDefinitions.h"
#include <stdio.h>

void computeDensity(const double *const currentCell, double *density)                    // computing the density of the cell which is actually the sum of all the 19 pdf's of 
{                                                                                        // that cell.
  printf("\n");                                                                           
  *density = 0;
  for (int i = 0; i<19; i++)
    {
         *density = *density + (*(currentCell + i));
    }
   printf("density = %f ", *density);
}

void computeVelocity(const double * const currentCell, const double * const density, double *velocity)   // computing the velocity of the cell which is the sum of multiplication
{                                                                                                        // of all the 19 pdf ditribution and the corresponding directions for 
  for (int m = 0;m<3;m++)                                                                                // for the 3 components of velocity.
      { 
          velocity[m] = 0 ;
          for (int i = 0; i<19; i++)
            {
                 velocity[m] = velocity[m] + (*(currentCell + i))*LATTICEVELOCITIES[i][m];
            }
           velocity[m] = velocity[m]/(*density);
      }
}

void computeFeq(const double * const density, const double * const velocity, double *feq)   // computing the equilibrium pdf of the cell
{
   
   for (int i = 0; i<19; i++)
          {
             double ci_u = LATTICEVELOCITIES[i][0]*velocity[0] + LATTICEVELOCITIES[i][1]*velocity[1] + LATTICEVELOCITIES[i][2]*velocity[2];
             double u_u = velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2];
             feq[i] = LATTICEWEIGHTS[i]*(*density)*(1+ci_u/(C_S*C_S) + (ci_u*ci_u)/(C_S*C_S*C_S*C_S*2) - u_u/((C_S*C_S)*2));
          }
}
	
