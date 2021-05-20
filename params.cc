#include "params.h"  // access to declarations of global parameter values

map<string, string> read_parameters_file(const string &parameters_fn)
{
	//map<int, map<string, string> > params_by_block;
	map<string,string> params;
	ifstream paramfile(parameters_fn.c_str());
	string line;
	while(getline(paramfile, line)) {
		istringstream iss(line.c_str());
		string key, nextone, value;
		iss >> key;
		while (iss >> nextone)
			value += nextone + " ";
		params[key] = value;
	}
	return params;
}

map<string, string> parameters = read_parameters_file("parameters");

// variable names
int popsize, sampsize, seqlength, sampfreq;
double mutrate;
bool useMS;
string mscommand;

int process_parameters() {
	popsize = atoi(parameters["popsize"].c_str());
  mutrate = atof(parameters["mutrate"].c_str());
	sampsize = atoi(parameters["sampsize"].c_str());
	seqlength = atof(parameters["seqlength"].c_str()); // covernsion using atof() enables use of e notation in parameters file
	sampfreq = atoi(parameters["sampfreq"].c_str());
  useMS = atoi(parameters["useMS"].c_str());
  mscommand = parameters["mscommand"];
	return 1;
}

int good_parameters = process_parameters();
