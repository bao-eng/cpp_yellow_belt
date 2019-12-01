#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:
	Human(const string& name, const string& occupation) : name_(name), occupation_(occupation){}

	virtual void Walk(const string& destination) const {
		cout << occupation_ <<  ": " << name_ << " walks to: " << destination << endl;
	}

	string GetName() const {
		 return name_;
	}

	string GetOccupation() const {
		 return occupation_;
	}

protected:
    const string name_;
    const string occupation_;
};

class Student : public Human {
public:
	Student(const string& name, const string& favouriteSong) : Human(name, "Student"), favouriteSong_(favouriteSong) {}

    void Learn() const {
        cout << occupation_ <<  ": " << name_ << " learns" << endl;
    }

    void SingSong() const {
        cout << occupation_ <<  ": " << name_ << " sings a song: " << favouriteSong_ << endl;
    }

    void Walk(const string& destination) const override{
    	Human::Walk(destination);
    	SingSong();
    }

private:
    const string favouriteSong_;
};

class Teacher : public Human {
public:
	Teacher(const string& name, const string& subject) : Human(name, "Teacher"), subject_(subject) {}

	void Teach() const {
        cout << occupation_ <<  ": " << name_ << " teaches: " << subject_ << endl;
    }

private:
    const string subject_;
};

class Policeman : public Human {
public:
	Policeman(const string& name) : Human(name, "Policeman") {}

	void Check(const Human& h) const {
        cout << occupation_ << ": " << name_ << " checks " << h.GetOccupation() << ". " << h.GetOccupation() << "'s name is: " << h.GetName() << endl;

    }
};

template <typename Iterator>
void VisitPlaces(Human& h, const Iterator range_begin, const Iterator range_end) {
    for (auto p = range_begin; p!=range_end; p++) {
    	h.Walk(*p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    vector<string> places= {"Moscow", "London"};

    VisitPlaces(t, places.begin(), places.end());
    p.Check(s);
    VisitPlaces(s, places.begin(), places.end());

    t.Teach();
    s.Learn();

    return 0;
}
