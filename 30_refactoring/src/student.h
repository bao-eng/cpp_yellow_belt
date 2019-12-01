#pragma once

#include "human.h"

class Student : public Human {
public:
    Student(const string& name, const string& favouriteSong);
    void Learn() const;
    void SingSong() const;
    void Walk(const string& destination) const override;

    const string FavouriteSong;
};
