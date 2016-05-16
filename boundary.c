#include "boundary.h"
#include "LBDefinitions.h"

void treatBoundary(double *collideField, int* flagField, const double * const velocityWall, int xlength)
{
     int x,y,z,i;
  
        z = 0;
        for (y = 0; y< xlength+2; y++)                                  //Assigning the pdf to the cells lying on the z=0 plane, which represent the no slip condition i.e 1
                                                                        // The pdf is assigned only those cells which are useful  in the dostreaming step. 
          {                                                             
            for(x = 0; x< xlength+2; x++)                               
               {
                  for (i=0;i<19;i++)
                    {
                      if ( (z+LATTICEVELOCITIES[i][2])>=0 && (y+LATTICEVELOCITIES[i][1])>=0 && (x+LATTICEVELOCITIES[i][0])>=0 && (z+LATTICEVELOCITIES[i][2])<=xlength+1 && (y+LATTICEVELOCITIES[i][1])<=xlength+1 && (x+LATTICEVELOCITIES[i][0])<=xlength+1 && flagField[(z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + x] == 0)
                          {
                             collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + 18-i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i];
                          }
                    }
               }
           }   

        y = 0;                                                          //Assigning the pdf to the cells lying on the y=0 plane, which represent the no slip condition i.e 1
                                                                        // The pdf is assigned only those cells which are useful  in the dostreaming step.
        for (z = 0; z< xlength+2; z++)
          {
            for(x = 0; x< xlength+2; x++)
               {
                  for (i=0;i<19;i++)
                    {
                       if ( (z+LATTICEVELOCITIES[i][2])>=0 && (y+LATTICEVELOCITIES[i][1])>=0 && (x+LATTICEVELOCITIES[i][0])>=0 && (z+LATTICEVELOCITIES[i][2])<=xlength+1 && (y+LATTICEVELOCITIES[i][1])<=xlength+1 && (x+LATTICEVELOCITIES[i][0])<=xlength+1 && flagField[(z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + x] == 0)
                          {
                             collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + 18-i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i];
                          }
                    }
               }
           }   

     y = xlength+1;                                                 //Assigning the pdf to the cells lying on the y=xlength+1 plane, which represent the no slip condition i.e 1
                                                                        // The pdf is assigned only those cells which are useful  in the dostreaming step.
        for (z = 0; z< xlength+2; z++)
          {
            for(x = 0; x< xlength+2; x++)
               {
                  for (i=0;i<19;i++)
                    {
                       if ( (z+LATTICEVELOCITIES[i][2])>=0 && (y+LATTICEVELOCITIES[i][1])>=0 && (x+LATTICEVELOCITIES[i][0])>=0 && (z+LATTICEVELOCITIES[i][2])<=xlength+1 && (y+LATTICEVELOCITIES[i][1])<=xlength+1 && (x+LATTICEVELOCITIES[i][0])<=xlength+1 && flagField[(z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + x] == 0)
                          {
                             collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + 18-i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i];
                          }
                    }
               }
           }   

     x = 0;                                                              //Assigning the pdf to the cells lying on the x=0 plane, which represent the no slip condition i.e 1
                                                                        // The pdf is assigned only those cells which are useful  in the dostreaming step.
        for (z = 0; z< xlength+2; z++)
          {
            for(y = 0; y< xlength+2; y++)
               {
                  for (i=0;i<19;i++)
                    {
                       if ( (z+LATTICEVELOCITIES[i][2])>=0 && (y+LATTICEVELOCITIES[i][1])>=0 && (x+LATTICEVELOCITIES[i][0])>=0 && (z+LATTICEVELOCITIES[i][2])<=xlength+1 && (y+LATTICEVELOCITIES[i][1])<=xlength+1 && (x+LATTICEVELOCITIES[i][0])<=xlength+1 && flagField[(z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + x] == 0)
                          {
                             collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + 18-i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i];
                          }
                    }
               }
           }   

     x = xlength+1;                                                    //Assigning the pdf to the cells lying on the x=xlength+1 plane, which represent the no slip condition 
                                                                        // i.e 1. The pdf is assigned only those cells which are useful  in the dostreaming step.
        for (z = 0; z< xlength+2; z++)
          {
            for(y = 0; y< xlength+2; y++)
               {
                  for (i=0;i<19;i++)
                    {
                       if ( (z+LATTICEVELOCITIES[i][2])>=0 && (y+LATTICEVELOCITIES[i][1])>=0 && (x+LATTICEVELOCITIES[i][0])>=0 && (z+LATTICEVELOCITIES[i][2])<=xlength+1 && (y+LATTICEVELOCITIES[i][1])<=xlength+1 && (x+LATTICEVELOCITIES[i][0])<=xlength+1 && flagField[(z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + x] == 0)
                          {
                             collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + 18-i] = collideField[Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0])) + i];
                          }
                    }
               }
           }  

     z = xlength+1;                                                      //Assigning the pdf to the cells lying on the z=xlength+1 plane, which represent the moving wall 
                                                                         // i.e flagfield value 2       
        for (y = 0; y< xlength+2; y++)                                   // The pdf is assigned only those cells which are useful  in the dostreaming step.
          {
            for(x = 0; x< xlength+2; x++)
               {
                  for (i=0;i<19;i++)
                    {
                       if ( (z+LATTICEVELOCITIES[i][2])>=0 && (y+LATTICEVELOCITIES[i][1])>=0 && (x+LATTICEVELOCITIES[i][0])>=0 && (z+LATTICEVELOCITIES[i][2])<=xlength+1 && (y+LATTICEVELOCITIES[i][1])<=xlength+1 && (x+LATTICEVELOCITIES[i][0])<=xlength+1 && flagField[(z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + x] == 0)  
                          {    
                             int cell_num = Q*((z+LATTICEVELOCITIES[i][2])*(xlength+2)*(xlength+2) + (y+LATTICEVELOCITIES[i][1])*(xlength+2) + (x+LATTICEVELOCITIES[i][0]));
                             double density = 0;
                             for (int n=0;n<19;n++)
                                 {
                                     density = density + collideField[cell_num + n];
                                 }                             
                             collideField[Q*(z*(xlength+2)*(xlength+2) + y*(xlength+2) + x) + 18-i] = collideField[cell_num + i] + 2*LATTICEWEIGHTS[i]*density*LATTICEVELOCITIES[i][0]*(*velocityWall)/(C_S*C_S);

                           }
                    }
               }
           }  

}

