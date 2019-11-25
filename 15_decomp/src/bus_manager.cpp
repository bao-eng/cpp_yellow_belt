#include "bus_manager.h"


	void BusManager::AddBus(const string& bus, const vector<string>& stops) { //OK
	buses_to_stops[bus]=stops;
	vector<string>& tmp = buses_to_stops[bus];
	for (string& stop : tmp) {
		stops_to_buses[stop].push_back(bus);
	}
	}

	BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const { //OK
		BusesForStopResponse resp;
		if (stops_to_buses.count(stop) != 0) {
		  for (const string& tmp : stops_to_buses.at(stop)) {
			resp.buses.push_back(tmp);
		  }
		}
		return resp;
	}

	StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
		StopsForBusResponse resp;
		if (buses_to_stops.count(bus) != 0) {
			for (const string& stop : buses_to_stops.at(bus)) {
				stop_buses tmp;
				tmp.stop=stop;
				if (stops_to_buses.at(stop).size() != 1) {
					for (const string& other_bus : stops_to_buses.at(stop)) {
						if (bus != other_bus) {
							tmp.buses.push_back(other_bus);
						}
					}
				}
				resp.stop_buses_arr.push_back(tmp);
			}
		}
		return resp;
	 }

	AllBusesResponse BusManager::GetAllBuses() const {
	  AllBusesResponse resp;
	  resp.allbuses=buses_to_stops;

	  return resp;
	}
