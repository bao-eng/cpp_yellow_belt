#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s){
	vector<string> tmp;
	auto itf=s.begin();
	for(auto i=s.begin(); i!=s.end()-1;i++){
		if(*i==' '){
			string tmps(itf,i);
			tmp.push_back(tmps);
			itf=i+1;
		}
	}
	string tmps(itf,s.end());
	tmp.push_back(tmps);
	return tmp;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
