#include <string>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "policeman.h"

using namespace std;

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    t.VisitPlaces({"Moscow", "London"});
    p.Check(s);
    s.VisitPlaces({"Moscow", "London"});

    return 0;
}
