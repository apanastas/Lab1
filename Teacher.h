#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "University.h"
#include <string>
using namespace std;

class Teacher : public University {
private:
    string name;
    string groups;
    string subjects;

public:
    Teacher(const string& name, const string& groups, const string& subjects);
    void print() const override;
    void saveToFile(ofstream& outFile) const override;
    static University* loadFromFile(ifstream& inFile);
};
#endif
