#ifndef _LBDEFINITIONS_H_
#define _LBDEFINITIONS_H_

#include "math.h"

static const int LATTICEVELOCITIES[19][3] = {{0,-1,-1},                             // Giving the lattice velocties vector
                                             {-1,0,-1},
                                              {0,0,-1},
                                              {1,0,-1},
                                              {0,1,-1},
                                              {-1,-1,0},
                                              { 0,-1,0},
                                              {1,-1,0},
                                              {-1,0,0},
                                              { 0,0,0},
                                              { 1,0,0},
                                              {-1,1,0},
                                              { 0,1,0},
                                              { 1,1,0},
                                              { 0,-1,1},
                                              {-1,0,1},
                                              { 0,0,1},
                                              { 1,0,1},
                                              { 0,1,1}};
static const double LATTICEWEIGHTS[19] = {1.0/36.0,                              // latice weights vector
                                          1.0/36.0,
                                          2.0/36.0,
                                          1.0/36.0,
                                          1.0/36.0,
                                          1.0/36.0,
                                          2.0/36.0, 
                                          1.0/36.0,
                                          2.0/36.0,
                                          12.0/36.0,
                                          2.0/36.0,
                                          1.0/36.0,
                                          2.0/36.0,
                                          1.0/36.0,
                                          1.0/36.0,
                                          1.0/36.0,
                                          2.0/36.0,
                                          1.0/36.0,
                                          1.0/36.0};

static const double C_S = 0.5773502692;//1.0/pow(3.0,0.5);                              // Giving the spped of sound..       
static const int Q = 19;                                                            // Giving the number of lattice velocities.

#endif

