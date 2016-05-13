#include "collision.h"
#include "LBDefinitions.h"

  double density;
  double velocity[3];
  double feq[19];
  double* currentCell;

void computePostCollisionDistributions(double *currentCell, const double * const tau, const double *const feq)
{
  for (int i= 0 ; i<19 ; i++)
      {
          *(currentCell+i) =  *(currentCell+i) - 1.0/(*tau)*(*(currentCell+i)-feq[i]);
      }

}

void doCollision(double *collideField, int *flagField,const double * const tau,int xlength)
{

  
  for (int z = 1; z<=xlength; z++)
      {
        for (int y = 1; y<=xlength; y++)
          {
            for(int x = 1; x<=xlength; x++)
               {
                  currentCell = &collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x)];
                  computeDensity (currentCell,&density);
                  computeVelocity(currentCell,&density,velocity);
                  computeFeq(&density,velocity,feq);
                  computePostCollisionDistributions(currentCell, tau, feq);
               }
           }
        }

}

