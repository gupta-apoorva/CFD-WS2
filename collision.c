#include "collision.h"
#include "LBDefinitions.h"

  double density;
  double velocity[3];
  double feq[19];
  double* currentCell;

// saving the pdf after the collision has taken place and the pdf has changed
void computePostCollisionDistributions(double *currentCell, const double * const tau, const double *const feq)
{
  for (int i= 0 ; i<19 ; i++)
      {
          *(currentCell+i) =  *(currentCell+i) - 1.0/(*tau)*(*(currentCell+i)-feq[i]);
      }

}

// Starting the collide step of lattice boltzmann
void doCollision(double *collideField, int *flagField,const double * const tau,int xlength)             
{

  
  for (int z = 1; z<=xlength; z++)                                                                      // Looping only on the fluid particles and not on the boundary.
      {
        for (int y = 1; y<=xlength; y++)
          {
            for(int x = 1; x<=xlength; x++)
               {
                  currentCell = &collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x)];       // Pointing the current cell to the start of the probability distribution
                  computeDensity (currentCell,&density);                                                // function of that cell...after that calculating density, velocity and 
                  computeVelocity(currentCell,&density,velocity);                                       // the equilibrium pdf of that cell and based on that updating the value 
                  computeFeq(&density,velocity,feq);                                                    // in the collidefield in the computepostcollisiondistribution function.
                  computePostCollisionDistributions(currentCell, tau, feq);                             // all other functions are implemented in collision.c
               }
           }
        }

}

