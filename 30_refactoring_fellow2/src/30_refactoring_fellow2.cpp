//автор: Kofman Philipp
//30 ноября 2019 г.

//В методе Learn() осталось дублирование кода(вывод строки "Student: ").
//Также, для устранения дублирования следовало вызывть метод SingSong() в переопределённом методе Walk();

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& type) : name(name), type(type) {}

    virtual void Walk(const string& destination) const {
        cout << type << ": " << name << " walks to: " << destination << endl;
    }

    string Type() const {
        return type;
    }

    string Name() const {
        return name;
    }

protected:
    const string name;
    const string type;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) : Person(name, "Student"), favouriteSong(favouriteSong) {}

    void Learn() {
        cout << "Student: " << name << " learns" << endl;
    }

    void Walk(const string& destinantion) const override {
        Person::Walk(destinantion);
        cout << Type() << ": " << name << " sings a song: " << favouriteSong << endl;
    }

    void SingSong() {
        cout << Type() << ": " << name << " sings a song: " << favouriteSong << endl;
    }
private:
    const string favouriteSong;
};

class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), subject(subject) {}

    void Teach() {
        cout << Type() << ": " << name << " teaches: " << subject << endl;
    }
private:
    const string subject;
};

class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}
    void Check(Person& person) {
        cout << Type() << ": " << name << " checks " << person.Type() << ". " ;
        cout << person.Type() << "'s name is: " << person.Name() << endl;
    }
};

void VisitPlaces(Person& h, const vector<string>& places) {
    for (const auto& p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
