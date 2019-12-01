#include "human.h"
#include <vector>

Human::Human(const string& nm, const string& oc) : Name(nm), Occupation(oc){}

void Human::Walk(const string& destination) const {
	cout << Occupation <<  ": " << Name << " walks to: " << destination << endl;
}

void Human::VisitPlaces(const vector<string>& places) const {
    for (const auto& p: places) {
    	this->Walk(p);
    }
}
