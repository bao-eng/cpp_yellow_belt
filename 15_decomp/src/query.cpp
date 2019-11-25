#include "query.h"
#include <iostream>

istream& operator >> (istream& is, Query& q) {
	Query qt;
	string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS"){
		qt.type=QueryType::NewBus;
		is >> qt.bus;
		int stop_count;
		is >> stop_count;
		vector<string>& stops = qt.stops;
		stops.resize(stop_count);
		for (auto& tmp : qt.stops){
			string tmpstr;
			is >> tmpstr;
			tmp=tmpstr;
		}
	}else if (operation_code == "BUSES_FOR_STOP"){
		qt.type=QueryType::BusesForStop;
		is >> qt.stop;
	}else if (operation_code == "STOPS_FOR_BUS"){
		qt.type=QueryType::StopsForBus;
		is >> qt.bus;
	}else if (operation_code == "ALL_BUSES"){
		qt.type=QueryType::AllBuses;
	}
	q=qt;
	return is;
}
