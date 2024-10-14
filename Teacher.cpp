#include "Teacher.h"
using namespace std;

Teacher::Teacher(const string& name, const string& groups, const string& subjects)
    : name(name), groups(groups), subjects(subjects) {}

void Teacher::print() const {
    cout << "Преподаватель: " << name;
    if (!groups.empty()) {
        cout << ", Группы: " << groups;
    }
    if (!subjects.empty()) {
        cout << ", Предметы: " << subjects;
    }
    cout << endl;
}

void Teacher::saveToFile(ofstream& outFile) const {
    outFile  << name << ";" << groups << ";" << subjects << endl;
}

University* Teacher::loadFromFile(ifstream& inFile) {
    string name, groups, subjects;

    getline(inFile, name, ';');
    getline(inFile, groups, ';');
    getline(inFile, subjects);

    return new Teacher(name, groups, subjects);
}
