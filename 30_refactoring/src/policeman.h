#pragma once

#include "human.h"

class Policeman : public Human {
public:
    Policeman(const string& name);
    void Check(const Human& h) const;
};
