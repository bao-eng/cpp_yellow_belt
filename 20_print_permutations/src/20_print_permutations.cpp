#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);

	int count=N;
	for(auto& i: v){
		i=count;
		count--;
	}

	do {
		for(auto i: v){
			cout << i << " ";
		}
		cout << endl;
	} while(prev_permutation(v.begin(),v.end()));

	return 0;
}
