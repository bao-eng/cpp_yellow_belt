#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool f(int val){
	if(val>3){
		return true;
	}
	return false;
}

int main() {
	set<int> s = {1,2,3,4,5,6};
	vector<int> v;

	////NOT OK
//		vector<int> garbage;
//		partition_copy(
//	    begin(s), end(s),
//	    back_inserter(garbage), back_inserter(v), f);

	////OK
//	v.assign(begin(s), end(s));
//	auto it = partition(begin(v), end(v), f);
//	v.erase(begin(v), it);

	////NOT OK
//	vector<int> garbage;
//	partition_copy(
//	begin(s), end(s),
//	back_inserter(v), back_inserter(garbage), f);

	////NOT OK
//	v.assign(begin(s), end(s));
//	auto it = remove_if(begin(v), end(v),
//	                    [](int x) { return !f(x); });
//	v.erase(it, end(v));

	////NOT OK
//	v.assign(begin(s), end(s));
//	auto it = partition(begin(v), end(v), f);
//	v.erase(it, end(v));

	////NOT OK
//	copy_if(begin(s), end(s), back_inserter(v), f);

	////OK
//	copy_if(begin(s), end(s), back_inserter(v),
//	        [](int x) { return !f(x); });

	////OK
//	v.assign(begin(s), end(s));
//	auto it = remove_if(begin(v), end(v), f);
//	v.erase(it, end(v));

	////NOT OK
//	remove_copy_if(begin(s), end(s), back_inserter(v),
//	               [](int x) { return !f(x); });

	////NOT OK
//	auto it = remove_if(begin(s), end(s),
//	                    [](int x) { return !f(x); });
//	copy(it, end(s), back_inserter(v));

	////OK
//	v.assign(begin(s), end(s));
//	sort(begin(v), end(v),
//	     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
//	auto it = partition_point(begin(v), end(v), f);
//	v.erase(begin(v), it);

	////NOT OK
//	v.assign(begin(s), end(s));
//	sort(begin(v), end(v),
//	     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
//	auto it = partition_point(begin(v), end(v), f);
//	v.erase(it, end(v));

	////OK
//	remove_copy_if(begin(s), end(s), back_inserter(v), f);

	////NOT OK
//	auto it = partition(begin(s), end(s), f);
//	copy(it, end(s), back_inserter(v));




























//	auto it = remove_if(begin(s), end(s), //error
//	                    [](int x) { return !f(x); });
//	copy(it, end(s), back_inserter(v));

//	v.assign(begin(s), end(s)); ok
//	sort(begin(v), end(v),
//	     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
//	auto it = partition_point(begin(v), end(v), f);
//	v.erase(begin(v), it);

//	copy_if(begin(s), end(s), back_inserter(v), f); notok

//	vector<int> garbage; notok
//	partition_copy(
//	    begin(s), end(s),
//	    back_inserter(v), back_inserter(garbage), f);

//	auto it = partition(begin(s), end(s), f); error
//	copy(it, end(s), back_inserter(v));

//	remove_copy_if(begin(s), end(s), back_inserter(v), notok
//	               [](int x) { return !f(x); });

//	remove_copy_if(begin(s), end(s), back_inserter(v), f); ok

//	v.assign(begin(s), end(s)); ok
//	auto it = partition(begin(v), end(v), f);
//	v.erase(begin(v), it);

//	vector<int> garbage; ok
//	partition_copy(
//	    begin(s), end(s),
//	    back_inserter(garbage), back_inserter(v), f);

//	copy_if(begin(s), end(s), back_inserter(v), ok
//	        [](int x) { return !f(x); });

//	v.assign(begin(s), end(s)); ok
//	auto it = remove_if(begin(v), end(v), f);
//	v.erase(it, end(v));

//	v.assign(begin(s), end(s)); notok
//	auto it = remove_if(begin(v), end(v),
//	                    [](int x) { return !f(x); });
//	v.erase(it, end(v));

//	v.assign(begin(s), end(s)); notok
//	sort(begin(v), end(v),
//	     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
//	auto it = partition_point(begin(v), end(v), f);
//	v.erase(it, end(v));

//	v.assign(begin(s), end(s)); notok
//	auto it = partition(begin(v), end(v), f);
//	v.erase(it, end(v));



	for(auto i: v){
		cout << i << " ";
	}

//	vector<int> vec;
//	auto vector_begin = begin(vec);
//	auto vector_end = end(vec);
//
//	string str;
//	auto string_begin = begin(str);
//	auto string_end = end(str);
//
//	set<int> s;
//	auto set_begin = begin(s);
//	auto set_end = end(s);

	//partial_sum(set_begin, set_end, back_inserter(vec)); //OK
	//auto res = is_heap(string_begin, string_end); //OK
	//auto res = is_permutation(vector_begin, vector_end, vector_begin); //OK
	//auto res = accumulate(set_begin, set_end, 0); //OK
	//partial_sum(vector_begin, vector_end, set_begin); //NOT OK
	//auto res = is_permutation(set_begin, set_end, vector_begin); //OK
	//partial_sum(set_begin, set_end, vector_begin); //OK
	//auto res = is_heap(set_begin, set_end); //NOT OK
	//auto res = next_permutation(string_begin, string_end); //OK
	//auto res = is_permutation(set_begin, set_end, back_inserter(vec)); //NOT OK
	//auto res = accumulate(vector_begin, vector_end, 0); //OK
	//auto res = next_permutation(set_begin, set_end); //NOT OK

	return 0;
}
