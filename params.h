#ifndef PARAMS_H
#define PARAMS_H

// must be constant at compile time
extern const int bitlength = 1000;

// the following are defined by values in the parameters file
extern int popsize;
extern double mutrate;
extern int seqlength;
extern int sampsize;
extern int sampfreq;
extern bool useMS;
extern string mscommand;

#endif
