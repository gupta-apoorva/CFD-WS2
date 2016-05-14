#include "streaming.h"
#include "LBDefinitions.h"

void doStreaming(double *collideField, double *streamField,int *flagField,int xlength)
{
   for (int z = 1; z<=xlength; z++)
      {
        for (int y = 1; y<=xlength; y++)
          {
            for(int x = 1; x<=xlength; x++)
               {
                  for (int i = 0; i<Q; i++)
                     {
                        //if (flagField[(z-LATTICEVELOCITIES[i][0])*(xlength+2)*(xlength+2) + (y-LATTICEVELOCITIES[i][1])*(xlength+2) + (x-LATTICEVELOCITIES[i][2])] == 0)
                        streamField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+ LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i] ;
                      }
                }             
           }
       }
}

