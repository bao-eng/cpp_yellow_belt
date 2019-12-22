#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <deque>

using namespace std;

class Expression{
public:
	Expression(int num){
		string tmp = to_string(num);
		expr.insert(expr.end(),tmp.begin(),tmp.end());

	}
	void AddOp(const char& op, const int& num){
		if((prev_op=='+' || prev_op=='-') && (op=='*' || op=='/')){
			expr.push_front('(');
			expr.push_back(')');
		}
		expr.push_back(' ');
		expr.push_back(op);
		expr.push_back(' ');
		string tmp = to_string(num);
		expr.insert(expr.end(),tmp.begin(),tmp.end());
		prev_op=op;
	}
	string GetExpString(){
		string tmp;
		tmp.insert(tmp.begin(), expr.begin(),expr.end());
		return tmp;
	}
private:
	deque<char> expr;
	char prev_op;
};

int main() {
	char op;
	int num, N;
	cin >> num >> N;
	Expression exp(num);
	for(int i=0;i<N;i++){
		cin >> op >> num;
		exp.AddOp(op,num);
	}
	cout << exp.GetExpString() << endl;
	return 0;
}
