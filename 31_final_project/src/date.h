#pragma once

#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

class Date{
public:
	Date(const int& year, const int& month, const int& day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
private:
	const int year_;
	const int month_;
	const int day_;
};

Date ParseDate(istringstream& is);

//void operator<<(ostream& stream, const Date& date);

ostream& operator << (ostream& stream, const Date& date);

bool operator < (const Date& lhs, const Date& rhs);

bool operator <= (const Date& lhs, const Date& rhs);

bool operator > (const Date& lhs, const Date& rhs);

bool operator >= (const Date& lhs, const Date& rhs);

bool operator == (const Date& lhs, const Date& rhs);

bool operator != (const Date& lhs, const Date& rhs);
