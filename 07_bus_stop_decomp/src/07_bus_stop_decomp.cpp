#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

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

struct BusesForStopResponse { //OK
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) { //OK
	if (r.buses.size() == 0) {
		cout << "No stop" << endl;
	} else {
	  for (const string& bus : r.buses) {
		cout << bus << " ";
	  }
	  cout << endl;
	}
  return os;
}

struct stop_buses {
  string stop;
  vector<string> buses;
};

struct StopsForBusResponse {
	vector<stop_buses> stop_buses_arr;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stop_buses_arr.size() == 0) {
		cout << "No bus" << endl;
	} else {
		for (const auto& stop : r.stop_buses_arr) {
			cout << "Stop " << stop.stop << ": ";
			if (stop.buses.size()==0) {
				cout << "no interchange";
			} else {
				for (const auto& bus : stop.buses) {
					cout << bus << " ";
				}
			}
			cout << endl;
		}
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> allbuses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.allbuses.empty()) {
	        cout << "No buses" << endl;
	      } else {
	        for (const auto& bus_item : r.allbuses) {
	          cout << "Bus " << bus_item.first << ": ";
	          for (const string& stop : bus_item.second) {
	            cout << stop << " ";
	          }
	          cout << endl;
	        }
	      }
	return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) { //OK
	buses_to_stops[bus]=stops;
	vector<string>& tmp = buses_to_stops[bus];
	for (string& stop : tmp) {
		stops_to_buses[stop].push_back(bus);
	}
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const { //OK
		BusesForStopResponse resp;
		if (stops_to_buses.count(stop) != 0) {
		  for (const string& tmp : stops_to_buses.at(stop)) {
			resp.buses.push_back(tmp);
		  }
		}
		return resp;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
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

  AllBusesResponse GetAllBuses() const {
	  AllBusesResponse resp;
	  resp.allbuses=buses_to_stops;

	  return resp;
  }
private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
