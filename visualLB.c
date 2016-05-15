#include "visualLB.h"
#include "helper.h"
#include "LBDefinitions.h"
#include <stdlib.h>
#include <stdio.h>

void write_vtkPointCoordinates( FILE *fp, int xlength );
void write_vtkHeader( FILE *fp, int xlength);

void writeVtkOutput(const double * const collideField, const int * const flagField, const char * filename, unsigned int t, int xlength) {

int i,j,k;
double* dencity = (double*) calloc((xlength+2)*(xlength+2)*(xlength+2),sizeof(double)) ;
double* Vx = (double*) calloc((xlength+2)*(xlength+2)*(xlength+2),sizeof(double)) ;
double* Vy = (double*) calloc((xlength+2)*(xlength+2)*(xlength+2),sizeof(double)) ;
double* Vz = (double*) calloc((xlength+2)*(xlength+2)*(xlength+2),sizeof(double)) ;
  char szFileName[80];
  FILE *fp=NULL;
  sprintf( szFileName, "%s.%i.vtk", filename, t );
  fp = fopen( szFileName, "w");
  if( fp == NULL )		       
  {
    char szBuff[80];
    sprintf( szBuff, "Failed to open %s", szFileName );
    ERROR( szBuff );
    return;
  }
  //dencity calculation

//Velocity calculations
for (k = 1; k<=xlength; k++){
  	for(j = 1; j <=xlength; j++) {
    	for(i = 1; i <= xlength; i++) {
    		int index = k*(xlength+2)*(xlength+2) + j*(xlength+2) + i;
    		for(int p = 0; p < 19; p++){
    			*(dencity + index) = *(dencity + index) + collideField[19*(index) + p];
    			*(Vx+ index) = *(Vx+index) + collideField[19*(index) + p]*LATTICEVELOCITIES[p][0];
    			*(Vy+ index) = *(Vy+index) + collideField[19*(index) + p]*LATTICEVELOCITIES[p][1];
    			*(Vz+ index) = *(Vz+index) + collideField[19*(index) + p]*LATTICEVELOCITIES[p][2];
    			//printf("%f\n", collideField[19*(index) + p]*LATTICEVELOCITIES[p][2]);
    		}
    		*(Vx+index) = *(Vx+index)/(*(dencity + index));
    		*(Vy+index) = *(Vy+index)/(*(dencity + index));
    		*(Vz+index) = *(Vz+index)/(*(dencity + index));
    	}
    }
}



  write_vtkHeader( fp, xlength);
  write_vtkPointCoordinates(fp, xlength);

  fprintf(fp,"POINT_DATA %i \n", (xlength)*(xlength)*(xlength) );
	
  fprintf(fp,"\n");
  fprintf(fp, "VECTORS velocity float\n");
  for(k = 1; k<=xlength; k++){
	for(j = 1; j <= xlength; j++) {
    	for(i = 1; i <= xlength; i++) {
    		int index = k*(xlength+2)*(xlength+2) + j*(xlength+2) + i;
    		fprintf(fp, "%f %f %f \n", *(Vx+index), *(Vy+index), *(Vz+index));
    		
    }
  }
}

  fprintf(fp,"\n");
  fprintf(fp,"\n");
  fprintf(fp, "SCALARS dencity float \n"); 
  fprintf(fp, "LOOKUP_TABLE default \n");
  for (k = 1; k<=xlength; k++){
  	for(j = 1; j <=xlength; j++) {
    	for(i = 1; i <= xlength; i++) {
    		int index = k*(xlength+2)*(xlength+2) + j*(xlength+2) + i;
      		fprintf(fp, "%f\n", *(dencity+index) );
    }
  }
}

  if( fclose(fp) )
  {
    char szBuff[80];
    sprintf( szBuff, "Failed to close %s", szFileName );
    ERROR( szBuff );
  }
  free(dencity);
  free(Vx);
  free(Vy);
  free(Vz);
}


void write_vtkHeader( FILE *fp, int xlength) {
  if( fp == NULL )		       
  {
    char szBuff[80];
    sprintf( szBuff, "Null pointer in write_vtkHeader" );
    ERROR( szBuff );
    return;
  }

  fprintf(fp,"# vtk DataFile Version 2.0\n");
  fprintf(fp,"generated by CFD-lab course output (written by Group 3) \n");
  fprintf(fp,"ASCII\n");
  fprintf(fp,"\n");	
  fprintf(fp,"DATASET STRUCTURED_GRID\n");
  fprintf(fp,"DIMENSIONS  %i %i %i \n", xlength, xlength, xlength);
  fprintf(fp,"POINTS %i float\n", xlength * xlength * xlength);
  fprintf(fp,"\n");
}


void write_vtkPointCoordinates( FILE *fp, int xlength ) {
  double originX = 0.0;  
  double originY = 0.0;
  double originZ = 0.0;

  int i ;
  int j ;
  int k ;

for(k = 1; k <= xlength; k++)
  for(j = 1; j <= xlength; j++) {
    for(i = 1; i <= xlength; i++) {
      fprintf(fp, "%f %f %f\n", originX+(i), originY+(j), originZ+(k) );
    }
  }
}

