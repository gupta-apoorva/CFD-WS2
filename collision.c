#include "collision.h"

void computePostCollisionDistributions(double *currentCell, const double * const tau, const double *const feq){
  /* TODO */
}

void doCollision(double *collideField, int *flagField,const double * const tau,int xlength){
  double density;
  double velocity[3];
  double feq[Q];
  double* currentCell;
  
  for (int z = 1; z<=xlength; z++)
      {
        for (int y = 1; y<=xlength; y++)
          {
            for(int x = 1; x<=xlength; x++)
               {
                  currentCell = collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x)];
                  computeDensity (currentCell,&density);
                  computeVelocity(currentCell,&density,velocity);
                  computeFeq(density,velocity,feq);
                  computePostCollisionDistributions(currentCell, tau, feq);
               }
           }
        }

}

