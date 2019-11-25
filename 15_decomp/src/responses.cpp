#include "responses.h"

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


