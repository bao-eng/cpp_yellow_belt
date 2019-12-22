#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <sstream>
#include <iomanip>

#define PI 3.14

using namespace std;

class Figure{
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Triangle : public Figure{
public:
	Triangle(unsigned int da, unsigned int db, unsigned int dc){
		a=da;
		b=db;
		c=dc;
	}
	string Name() const override{
		return "TRIANGLE";
	}
	double Perimeter() const override{
		return a+b+c;
	}
	double Area() const override{
		double p=(double)((a+b+c))/2;
		return sqrt(p*(p-(double)a)*(p-(double)b)*(p-(double)c));
	}
private:
	unsigned int a,b,c;
};

class Rect : public Figure{
public:
	Rect(unsigned int da, unsigned int db){
		a=da;
		b=db;
	}
	string Name() const override{
		return "RECT";
	}
	double Perimeter() const override{
		return (a+b)*2;
	}
	double Area() const override{
		return a*b;
	}
private:
	unsigned int a,b;
};

class Circle : public Figure{
public:
	Circle(unsigned int dr){
		r=dr;
	}
	string Name() const override{
		return "CIRCLE";
	}
	double Perimeter() const override{
		return 2*PI*r;
	}
	double Area() const override{
		return PI*r*r;
	}
private:
	unsigned int r;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
	string type;
	is >> type;
	if(type == "RECT"){
		unsigned int a,b;
		is >> a >> b;
		return make_shared<Rect>(a,b);
	} else if(type == "TRIANGLE"){
		unsigned int a,b,c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a,b,c);
	} else if(type == "CIRCLE"){
		unsigned int r;
		is >> r;
		return make_shared<Circle>(r);
	}
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
