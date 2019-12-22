#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};


// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

template <typename InputIt>
void PrintPersVect(InputIt range_begin, InputIt range_end){
	for(auto i=range_begin; i!=range_end; i++){
		cout << i->age << " ";
		if(i->gender==Gender::MALE){
			cout << "MALE" << " ";
		}else{
			cout << "FEMALE" << " ";
		}
		cout << i->is_employed << endl;
	}
}

void PrintStats(vector<Person> persons){
	//female_employed / female_unemployed / male_employed / male_unemployed
	auto fm = partition (persons.begin(), persons.end(), [](Person p){return p.gender==Gender::FEMALE;});
	auto f_empl = partition (persons.begin(), fm, [](Person p){return p.is_employed==true;});
	auto m_empl = partition (fm, persons.end(), [](Person p){return p.is_employed==true;});

	//	Median age = 40
	PrintPersVect(persons.begin(),persons.end());
	cout << endl;
	//	Median age for females = 40
	cout << "females:" << endl;
	PrintPersVect(persons.begin(),fm);
	cout << endl;
	//	Median age for males = 55
	cout << "males:" << endl;
	PrintPersVect(fm,persons.end());
	cout << endl;
	//	Median age for employed females = 40
	cout << "employed females:" << endl;
	PrintPersVect(persons.begin(),f_empl);
	cout << endl;
	//	Median age for unemployed females = 80
	cout << "unemployed females:" << endl;
	PrintPersVect(f_empl,fm);
	cout << endl;
	//	Median age for employed males = 55
	cout << "employed males:" << endl;
	PrintPersVect(fm,m_empl);
	cout << endl;
	//	Median age for unemployed males = 78
	cout << "unemployed males:" << endl;
	PrintPersVect(m_empl,persons.end());
	cout << endl;


	cout << "Median age = "                        << ComputeMedianAge(persons.begin(),persons.end()) << endl;
	cout << "Median age for females = " 		   << ComputeMedianAge(persons.begin(),fm) << endl;
	cout << "Median age for males = " 			   << ComputeMedianAge(fm,persons.end()) << endl;
	cout << "Median age for employed females = "   << ComputeMedianAge(persons.begin(),f_empl) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(f_empl,fm) << endl;
	cout << "Median age for employed males = "     << ComputeMedianAge(fm,m_empl) << endl;
	cout << "Median age for unemployed males = "   << ComputeMedianAge(m_empl,persons.end()) << endl;

}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
