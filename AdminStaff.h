#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "University.h"
#include <string>
using namespace std;

class AdminStaff : public University {
private:
    string name;
    string position;
    string phone;
    string responsibility;

public:
    AdminStaff(const string& name, const string& position, const string& phone, const string& responsibility);
    void print() const override;
    void saveToFile(ofstream& outFile) const override;
    static University* loadFromFile(ifstream& inFile);
};
#endif
