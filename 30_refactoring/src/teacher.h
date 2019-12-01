#pragma once

#include "human.h"

class Teacher : public Human {
public:
    Teacher(const string& name, const string& subject);
    void Teach() const;

    const string Subject;
};
