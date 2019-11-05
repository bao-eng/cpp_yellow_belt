#include <iostream>
#include <vector>


using namespace std;

int main() {
	int N;
	cin >> N;
	int64_t avg=0;
	int h_count=0;
	vector<int64_t> temp(N);
	vector<int> hot;
	for(auto& i: temp){
		cin >> i;
		avg+=i;
	}
	avg/=static_cast<int64_t>(N);

	for(int j=0;j<=temp.size()-1;j++){
		if(temp[j]>avg){
			hot.push_back(j);
			h_count++;
		}
	}

	cout << h_count << endl;
	for(auto& i: hot){
		cout << i << " ";
	}
	return 0;
}
