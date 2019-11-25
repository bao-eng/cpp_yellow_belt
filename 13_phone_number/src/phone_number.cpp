#include "phone_number.h"
#include <sstream>
#include <stdexcept>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number){
	stringstream ss(international_number);
	char tmpc;
	ss >> tmpc;
	if(tmpc!='+'||ss.fail()||ss.eof()){
		throw invalid_argument("");
	}
	getline(ss, country_code_, '-');
	if(ss.fail()||ss.eof()){
		throw invalid_argument("");
	}
	getline(ss, city_code_, '-');
	if(ss.fail()||ss.eof()){
		throw invalid_argument("");
	}
	getline(ss, local_number_);
	if(ss.fail()){
		throw invalid_argument("");
	}
}

string PhoneNumber::GetCountryCode() const{
  return country_code_;
}
string PhoneNumber::GetCityCode() const{
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const{
  return "+"+country_code_+"-"+city_code_+"-"+local_number_;
}
