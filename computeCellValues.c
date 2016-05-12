#include "computeCellValues.h"

void computeDensity(const double *const currentCell, double *density){
  /* TODO */
}

void computeVelocity(const double * const currentCell, const double * const density, double *velocity){
  for (int m = 0;m<3;m++)
      { 
          velocity[m] = 0 ;
          for (int n = 0; n<19; n++)
            {
                 
            }
      }

}

void computeFeq(const double * const density, const double * const velocity, double *feq){
 /* TODO */
}

