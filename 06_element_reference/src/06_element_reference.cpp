#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <stdexcept>

using namespace std;

template<typename key, typename value>
value& GetRefStrict(map<key, value>& m,key k){
	if(m.count(k)==1){
		return m[k];
	}
	throw runtime_error("");
}

int main() {
	map<int, string> m = {{0, "value"}};
	//cout << GetRefStrict(m, 0) << endl;
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	cout << "" << endl; // prints 
	return 0;
}
