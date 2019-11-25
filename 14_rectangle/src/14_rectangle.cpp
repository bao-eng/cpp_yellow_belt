#include <iostream>
#include "rectangle.h"

using namespace std;

int main() {
	Rectangle r(10,5);
	cout << "Area: " << r.GetArea() << endl;
	cout << "Perimeter: " << r.GetPerimeter() << endl;
	cout << "Width: " << r.GetWidth() << endl;
	cout << "height: " << r.GetHeight() << endl;

	return 0;
}
