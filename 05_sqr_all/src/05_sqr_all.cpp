#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <class first, class second> pair<first, second> sqri (const pair<first, second>& p);
template <typename key, typename value> map<key, value> sqri (const map<key, value>& m);
template<typename T> vector<T> sqri (const vector<T>& v);
template<typename T> T sqri (const T& n);

template <class first, class second>
pair<first, second> sqri (const pair<first, second>& p){
	return make_pair(sqri(p.first),sqri(p.second));
}

template <typename key, typename value>
map<key, value> sqri (const map<key, value>& m){
	map<key, value> tmp;
	for(auto i: m){
		tmp.insert(make_pair(i.first,sqri(i.second)));
	}
	return tmp;
}

template<typename T>
vector<T> sqri (const vector<T>& v){
	vector<T> tmp;
	for(auto i: v){
		tmp.push_back(sqri(i));
	}
	return tmp;
}

template<typename T>
T sqri (const T& n){
	return n*n;
}

template <class  T>
auto Sqr(const T& x){
	return sqri(x);
}

int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
