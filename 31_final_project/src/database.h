#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <functional>
#include "date.h"
#include "node.h"


using namespace std;

struct events{
	set<string> ev_set;
	vector<string> ev_vect;
};

struct event{
	Date date;
	string str;
};

class Database{
public:
	void Add(const Date date, string event);
	void Print(ostream& stream) const;
	int RemoveIf(const function<bool(const Date&, const string&)> lambda);
	vector<event> FindIf(const function<bool(const Date&, const string&)> lambda) const;
	event Last(const Date date) const;

private:
	map<Date,events> db;

};

ostream& operator << (ostream& stream, const event& event);

bool operator != (const event& lhs, const event& rhs);
