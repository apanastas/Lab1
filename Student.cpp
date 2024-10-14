#include "Student.h"
using namespace std;

Student::Student(const string& name, const string& group, const string& specialty, int course, double GPA)
    : name(name), group(group), specialty(specialty), course(course), GPA(GPA) {}

void Student::print() const {
    cout << "�������: " << name;
    if (!group.empty()) {
        cout << ", ������: " << group;
    }
    if (!specialty.empty()) {
        cout << ", �������������: " << specialty;
    }
    cout << ", ����: " << course << ", ������� ����: " << GPA << endl;
}

void Student::saveToFile(ofstream& outFile) const {
    outFile << name << ";" << group << ";" << specialty << ";" << course << ";" << GPA << endl;
}

University* Student::loadFromFile(ifstream& inFile) {
    string name, group, specialty;
    int course;
    double GPA;

    getline(inFile, name, ';');
    getline(inFile, group, ';');
    getline(inFile, specialty, ';');
    inFile >> course;
    inFile.ignore(); // ���������� �����������
    inFile >> GPA;
    inFile.ignore(); // ���������� ����� ������

    return new Student(name, group, specialty, course, GPA);
}
