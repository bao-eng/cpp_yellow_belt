#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct stop_buses {
  string stop;
  vector<string> buses;
};

struct StopsForBusResponse {
	vector<stop_buses> stop_buses_arr;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	map<string, vector<string>> allbuses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
