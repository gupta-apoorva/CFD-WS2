#include "streaming.h"
#include "LBDefinitions.h"

// Iterating over the fluid cells and coping the values from the  collidefield to the streamfield

void doStreaming(double *collideField, double *streamField,int *flagField,int xlength)
{
   for (int z = 1; z<=xlength; z++)
      {
        for (int y = 1; y<=xlength; y++)
          {
            for(int x = 1; x<=xlength; x++)
               {
                 if (flagField[z*(xlength+2)*(xlength+2) + y*(xlength+2) + x] ==0)
                  for (int i = 0; i<Q; i++)
                     {                       
                        streamField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+ LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i] ;
                      }
                }             
           }
       }
}

