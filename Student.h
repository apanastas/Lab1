#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "University.h"
#include <string>
using namespace std;

class Student : public University{
private:
	string name;
	string group;
	string specialty;
	int course;
	double GPA;

public:
	Student(const string& name, const string& group, const string& specialty, int course, double GPA);
	void print() const override; // Реализация чисто виртуальной функции

	void saveToFile(ofstream& outFile) const override;
	static University* loadFromFile(ifstream& inFile);
};
#endif