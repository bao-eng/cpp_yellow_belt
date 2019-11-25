#include "sum_reverse_sort.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Sum(int x, int y){
	return x+y;
}

string Reverse(string s){
	string tmp;
	int len=s.length();
	for(int i=0;i<len;i++){
		tmp.push_back(s[len-i-1]);
	}
	return tmp;
}

void Sort(vector<int>& nums){
	sort (nums.begin(), nums.end());
}
