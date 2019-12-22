//автор: Firelord
//1 декабря 2019 г.

//В методах классов потомков осталось дублирование кода, возможно стоило выводить значение полей type_ вместо фиксированных строк.
//Также, для устранения дублирования следовало вызывть метод SingSong() в переопределённом методе Walk();
//Не все методы объявленны константными.
//Сейчас весь код представлен одним файлом, для дальнейшего развития следует разделить код на отельный файлы.


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Walker {
public:
    Walker(const string &name, const string &type) : name_(name), type_(type) {}

    virtual void Walk(const string &destination) const {
        cout << GetType() << ": " << name_ << " walks to: " << destination << endl;
    }

    void VisitPlaces(const vector<string> &places) const {
        for (auto p : places) {
            Walk(p);
        }
    }

    string GetName() const {
        return name_;
    }

    string GetType() const {
        return type_;
    }

protected:
    const string name_;
    const string type_;
};

class Student : public Walker {
public:
    Student(const string &name, const string &favourite_song) : Walker(name, "Student"),
                                                                favourite_song_(favourite_song) {}

    void Learn() {
        cout << "Student: " << name_ << " learns" << endl;
    }

    void Walk(const string &destination) const override {
        cout << "Student: " << name_ << " walks to: " << destination << endl;
        cout << "Student: " << name_ << " sings a song: " << favourite_song_ << endl;
    }

    void SingSong() {
        cout << "Student: " << name_ << " sings a song: " << favourite_song_ << endl;
    }

private:
    const string favourite_song_;
};


class Teacher : public Walker {
public:
    Teacher(const string &name, const string &subject) : Walker(name, "Teacher"), subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << name_ << " teaches: " << subject << endl;
    }

private:
    const string subject;
};


class Policeman : public Walker {
public:
    Policeman(const string &name) : Walker(name, "Policeman") {}

    void Check(Walker s) {
        cout << "Policeman: " << name_ << " checks " << s.GetType() << ". "
             << s.GetType() << "'s name is: " << s.GetName() << endl;
    }
};

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    t.VisitPlaces({"Moscow", "London"});
    p.Check(s);
    s.VisitPlaces({"Moscow", "London"});
    return 0;
}
