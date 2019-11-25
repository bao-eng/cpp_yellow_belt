#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational(){
	  num=0;
	  den=1;
  }
  Rational(int numerator, int denominator) {
		int t=gcd(abs(numerator), abs(denominator));
		if(((numerator < 0) && (denominator < 0)) ||
				(numerator > 0) && (denominator > 0)) {
			num = abs(numerator) / t;
			den = abs(denominator) / t;
		} else {
			num = -abs(numerator) / t;
			den = abs(denominator) / t;
		}
  }

  int Numerator() const {
	  return num;
  }

  int Denominator() const {
	  return den;
  }
private:
  int num;
  int den;

	int gcd(const int& ai, const int& bi) {
		int a=ai;
		int b=bi;
		while((a>0)&&(b>0)) {
			if(a>b){
				a=a%b;
			}
			else{
				b=b%a;
			}
		}
		return a+b;
	}

};

void TestDefault() {
	Rational rat;
    AssertEqual(rat.Numerator(), 0);
    AssertEqual(rat.Denominator(), 1);
}

void TestGCD() {
	{
		Rational rat(2,4);
		AssertEqual(rat.Numerator(), 1);
		AssertEqual(rat.Denominator(), 2);
	}
	{
		Rational rat(4,2);
		AssertEqual(rat.Numerator(), 2);
		AssertEqual(rat.Denominator(), 1);
	}
}

void TestNegative() {
	{
		Rational rat(-1,2);
		AssertEqual(rat.Numerator(), -1);
		AssertEqual(rat.Denominator(), 2);
	}
	{
		Rational rat(1,-2);
		AssertEqual(rat.Numerator(), -1);
		AssertEqual(rat.Denominator(), 2);
	}
	{
		Rational rat(-1,-2);
		AssertEqual(rat.Numerator(), 1);
		AssertEqual(rat.Denominator(), 2);
	}
}

void TestPositive() {
	{
		Rational rat(-1,-2);
		AssertEqual(rat.Numerator(), 1);
		AssertEqual(rat.Denominator(), 2);
	}
}

void TestZeroNum() {
	{
		Rational rat(0,4);
		AssertEqual(rat.Numerator(), 0);
		AssertEqual(rat.Denominator(), 1);
	}
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestDefault,"TestDefault");
  runner.RunTest(TestGCD,"TestGCD");
  runner.RunTest(TestNegative,"TestNegative");
  runner.RunTest(TestNegative,"TestPositive");
  runner.RunTest(TestZeroNum,"TestZeroNum");
  return 0;
}
