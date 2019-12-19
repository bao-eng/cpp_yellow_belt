#pragma once

#include <iostream>
#include <vector>
#include "date.h"
#include "node.h"

using namespace std;

class Database{
public:
	void Add(const Date date, string event);
	void Print(ostream& stream);
	int RemoveIf(shared_ptr<Node>);
	vector<string> FindIf(shared_ptr<Node>);
	string Last(shared_ptr<Date>);

private:
};
