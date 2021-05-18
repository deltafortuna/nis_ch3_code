#include "params.h"  // access to declarations of global parameter values

// returns value of type int for requested parameter key
int getParameter_int(const string &parameters_fn, const string &key)
{
	string item;
	ifstream paramfile;
	int to_return;
	paramfile.open(parameters_fn.c_str());

	while (paramfile >> item)
	{
	    if (item == key) {
	    	paramfile >> item;
	    	paramfile.close();
				to_return = atoi(item.c_str());
	 //   	return(atoi(item.c_str()));
	    } else
	    	paramfile >> item; // read value, which is ignored
	}
	paramfile.close();
	return(to_return); 
}

// returns value of type double for requested parameter key
double getParameter_double(const string &parameters_fn, const string &key)
{
	string item;
	ifstream paramfile;
	double to_return;
	paramfile.open(parameters_fn.c_str());
	// Read in a line
	while (paramfile >> item)
	{
	    if (item == key) {
	    	paramfile >> item;
	    	paramfile.close();
				to_return = atof(item.c_str());
	    	//return (atof(item.c_str()));
	    } else
	    	paramfile >> item; // read value, which is ignored
	}
	paramfile.close();
	return(to_return);
}

string parameters_fn("parameters"); // the name of parameters file

// read in the parameter values from the parameters file
int popsize = getParameter_int (parameters_fn, "popsize");
double mutrate = getParameter_double (parameters_fn, "mutrate");
int sampsize = getParameter_int (parameters_fn, "sampsize");
int seqlength = getParameter_double (parameters_fn, "seqlength");
int sampfreq = getParameter_int (parameters_fn, "sampfreq");
