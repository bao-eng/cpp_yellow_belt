#include "date.h"

Date::Date(const int& year, const int& month, const int& day) : year_(year), month_(month), day_(day){}

int Date::GetYear() const{
	return year_;
}

int Date::GetMonth() const{
	return month_;
}

int Date::GetDay() const{
	return day_;
}

Date ParseDate(istringstream& is){
	int year, month, day;
	char tmp;
	is >> year >> tmp >> month >> tmp >> day;
	return Date(year, month, day);
}

ostream& operator << (ostream& stream, const Date& date) {
	stream << setfill('0');
	stream << setw(4) << date.GetYear() << '-'
		   << setw(2) << date.GetMonth() << '-'
		   << setw(2) << date.GetDay();
	return stream;
}

bool operator < (const Date& lhs, const Date& rhs) {
	if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() == rhs.GetMonth()){
			return lhs.GetDay()<rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

bool operator <= (const Date& lhs, const Date& rhs) {
	if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() == rhs.GetMonth()){
			return lhs.GetDay()<=rhs.GetDay();
		}
		return lhs.GetMonth() <= rhs.GetMonth();
	}
	return lhs.GetYear() <= rhs.GetYear();
}

bool operator > (const Date& lhs, const Date& rhs) {
	if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() == rhs.GetMonth()){
			return lhs.GetDay()>rhs.GetDay();
		}
		return lhs.GetMonth() > rhs.GetMonth();
	}
	return lhs.GetYear() > rhs.GetYear();
}

bool operator >= (const Date& lhs, const Date& rhs) {
	if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() == rhs.GetMonth()){
			return lhs.GetDay()>=rhs.GetDay();
		}
		return lhs.GetMonth() >= rhs.GetMonth();
	}
	return lhs.GetYear() >= rhs.GetYear();
}

bool operator == (const Date& lhs, const Date& rhs) {
	return (lhs.GetYear() == rhs.GetYear()) &&
			(lhs.GetMonth() == rhs.GetMonth()) &&
			(lhs.GetDay() == rhs.GetDay());
}

bool operator != (const Date& lhs, const Date& rhs) {
	return (lhs.GetYear() != rhs.GetYear()) ||
			(lhs.GetMonth() != rhs.GetMonth()) ||
			(lhs.GetDay() != rhs.GetDay());
}
