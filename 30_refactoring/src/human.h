#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:
	Human(const string& nm, const string& oc);
	virtual void Walk(const string& destination) const;

	void VisitPlaces(const vector<string>& places) const;

    const string Name;
    const string Occupation;
};
