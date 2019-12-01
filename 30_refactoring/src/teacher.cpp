#include "teacher.h"

Teacher::Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {}

void Teacher::Teach() const {
    cout << Occupation <<  ": " << Name << " teaches: " << Subject << endl;
}
