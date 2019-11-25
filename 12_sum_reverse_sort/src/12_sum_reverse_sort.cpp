#include "sum_reverse_sort.h"
#include <iostream>
using namespace std;


int main() {
	cout << Sum(2,3) << endl;
	cout << Reverse("numbers") << endl; // prints

	vector<int> v= {9,4,3,6};
	Sort(v);
	for(auto i: v){
		cout << i << ", ";
	}
	return 0;
}
