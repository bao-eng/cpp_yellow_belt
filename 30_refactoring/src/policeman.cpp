#include "policeman.h"

Policeman::Policeman(const string& name) : Human(name, "Policeman") {}

void Policeman::Check(const Human& h) const {
    cout << Occupation << ": " << Name << " checks " << h.Occupation << ". " << h.Occupation << "'s name is: " << h.Name << endl;

}
