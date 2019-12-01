#include "student.h"

Student::Student(const string& name, const string& favouriteSong) : Human(name, "Student"), FavouriteSong(favouriteSong) {}

void Student::Learn() const {
    cout << Occupation <<  ": " << Name << " learns" << endl;
}

void Student::SingSong() const {
    cout << Occupation <<  ": " << Name << " sings a song: " << FavouriteSong << endl;
}

void Student::Walk(const string& destination) const {
    cout << Occupation <<  ": " << Name << " walks to: " << destination << endl;
    this->SingSong();
}
