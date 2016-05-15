#ifndef _LBDEFINITIONS_H_
#define _LBDEFINITIONS_H_

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
static const double LATTICEWEIGHTS[19] = {0.027777,                              // latice weights vector
                                          0.027777,
                                          0.055555,
                                          0.027777,
                                          0.027777,
                                          0.027777,
                                          0.055555, 
                                          0.027777,
                                          0.055555,
                                          0.375000,
                                          0.055555,
                                          0.027777,
                                          0.055555,
                                          0.027777,
                                          0.027777,
                                          0.027777,
                                          0.055555,
                                          0.027777,
                                          0.027777};
static const double C_S = 0.5773502;//(1.0/sqrt(3.0));                              // Giving the spped of sound..       
static const int Q = 19;                                                            // Giving the number of lattice velocities.

#endif

