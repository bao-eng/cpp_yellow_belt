#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Profession {

private:
    const string Name;
    const string Occupation;

public:
    Profession(const string& name, const string& occupation) : Name(name), Occupation(occupation) {}

    string GetName() const {
        return Name;
    }
    string GetOccupation() const {
        return Occupation;
    }
    virtual void Walk(const string& destination) const = 0;
};


class Student : public Profession {

private:
    const string FavouriteSong;

public:

    Student(const string& name, const string& favouriteSong) : Profession(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }
};

class Teacher : public Profession {

private:
    const string Subject;

public:
    Teacher(const string& name, const string& subject) : Profession(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }
};

class Policeman : public Profession {

public:
    Policeman(const string& name) : Profession(name, "Policeman") {}

    void Check(Profession& person) const {
        cout << "Policeman: " << GetName() << " checks " << person.GetOccupation() << ". "
             << person.GetOccupation() << "'s name is: " << person.GetName() << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }
};

void VisitPlaces(Profession& person, vector<string> places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
}
