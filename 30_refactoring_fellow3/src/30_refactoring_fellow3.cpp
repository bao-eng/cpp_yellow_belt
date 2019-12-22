//автор: Калмыков Алексей Вадимович
//30 ноября 2019 г.

//Ошибка в объявлении const string& name_;. Вместо строки объявляется указатель. Вывод некорректный.
//Такая же ошибка при объявлении const string& subject_;
//Не ясно зачем метод GetProfession(); сделан приватным в классах потомках если в базовом он публичный.
//На мой взгляд, логичнее было бы сделать профессию полем класса Person и присваивать ему значение через список инициализации. Тогда метод GetProfession()
//не пришлось бы переопределять.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
	Person(const string& name) : name_(name) {}

	virtual void Walk(const string& destination) const {
		cout << ": " << name_ << " walks to: " << destination << endl;
	};

	string GetName() const {
		return name_;
	}

	virtual string GetProfession() const = 0;

private:
	const string name_;
};

class Student : public Person{
public:

    Student(const string& name, const string& favouriteSong)
		: Person(name)
		, favourite_song_(favouriteSong)
	{}

    void Learn() const {
        cout << GetProfession() << ": " << GetName() << " learns" << endl;
    }

    void SingSong() const {
        cout << GetProfession() << ": " << GetName() << " sings a song: " << favourite_song_ << endl;
    }

    void Walk(const string& destination) const override {
        cout << GetProfession();
        Person::Walk(destination);
        SingSong();
    }

private:
    const string favourite_song_;

    string GetProfession() const override {
    	return "Student";
    }
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject)
		: Person(name)
		, subject_(subject)
	{}

    void Teach() const {
        cout << GetProfession() << ": " << GetName() << " teaches: " << subject_ << endl;
    }

    void Walk(const string& destination) const override {
        cout << GetProfession();
        Person::Walk(destination);
    }

private:
    const string subject_;

    string GetProfession() const override {
        return "Teacher";
    }
};


class Policeman : public Person {
public:
    Policeman(const string& name)
		: Person(name)
	{}

    void Check(const Person& p) const {
    	cout << GetProfession() << ": " << GetName() << " checks " << p.GetProfession() << ". " <<
    			p.GetProfession() << "'s name is: " << p.GetName() << endl;
    }
    void Walk(const string& destination) const override {
        cout << GetProfession();
        Person::Walk(destination);
    }
private:
    string GetProfession() const override {
    	return "Policeman";
    }
};


void VisitPlaces(const Person& pers, vector<string> places) {
    for (auto p : places) {
        pers.Walk(p);
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
