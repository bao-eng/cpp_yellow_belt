#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border){
	auto it = lower_bound (numbers.begin(), numbers.end(), border);
	cout << "border=" << border << " *it=" << *it;
	if (it==numbers.begin()){
		cout << " F1"<< endl;
		return it;
	}
	if(it==numbers.end()){
		cout << " F2"<< endl;
		return prev(it);
	}else {
		if(abs(border-*prev(it)) <= abs(*it-border)){
			cout << " F3"<< endl;
			return prev(it);
		}else{
			cout << " F4"<< endl;
			return it;
		}
	}
}

// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

//1 4 4 6 6
//1

int main() {
  set<int> numbers = {-1};
  cout <<
      *FindNearestElement(numbers, 0) << " " << //1
      *FindNearestElement(numbers, 3) << " " << //4
      *FindNearestElement(numbers, 5) << " " << //4
      *FindNearestElement(numbers, 6) << " " << //6
      *FindNearestElement(numbers, 100) << endl; //6

  set<int> nnumbers = {-6, -4, -1};
  cout <<
      *FindNearestElement(nnumbers, 0) << " " << //1
      *FindNearestElement(nnumbers, -3) << " " << //4
      *FindNearestElement(nnumbers, -5) << " " << //4
      *FindNearestElement(nnumbers, -6) << " " << //6
      *FindNearestElement(nnumbers, -100) << endl; //6


  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
