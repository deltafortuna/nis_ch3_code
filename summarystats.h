#ifndef SUMMARYSTATS_H
#define SUMMARYSTATS_H

#include "params.h"

// declarations
double get_pi (vector<bitset<bitlength>> &sample);
double get_watterson (vector<bitset<bitlength>> &sample, int S);

// definitions
double get_pi (vector<bitset<bitlength>> &sample) {
	double sumdiffs = 0.;
	double numcomp = 0.;

	#pragma omp parallel for collapse(2)
	for (int i  = 0; i< sample.size() - 1; ++i) {
		for (int j = i+1; j<sample.size(); ++j) {
			sumdiffs += (sample[i] ^ sample[j]).count();
			numcomp+=1.;
		}
	}
	return (sumdiffs/numcomp/seqlength);
}

double get_watterson (vector<bitset<bitlength>> &sample, int S) { 
	double denominator = 0.;
	for (double i=1.; i<sampsize; ++i)
		denominator += 1./i;
	return (S/denominator/seqlength);
}

#endif
