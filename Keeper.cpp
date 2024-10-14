#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "AdminStaff.h"
#include "exceptions.h" // ���������� ��� ������ � ������������
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

Keeper::Keeper() : count(0), capacity(10) {
    objects = new University * [capacity]; // �������� ������ ��� �������
}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i) {
        delete objects[i]; // ����������� ������ ��� ������� �������
    }
    delete[] objects; // ����������� ������ ��� ������� ����������
}

void Keeper::resize() {
    capacity *= 2; // ����������� ����� � ��� ����
    University** newObj = new University * [capacity];
    for (int i = 0; i < count; i++) {
        newObj[i] = objects[i]; // ������������ ������ �������
    }
    delete[] objects;
    objects = newObj; // ������������� ����� ������ ��������
}

void Keeper::addObj(University* obj) {
    if (count >= capacity) {
        resize();
    }
    objects[count++] = obj; // ���������� �������
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= count) {
        throw IndexOutOfRangeException(); // ���������� ����������, ���� ������ �����������
    }
    delete objects[index]; // ������� ������ �� ������
    for (int i = index; i < count - 1; ++i) {
        objects[i] = objects[i + 1]; // �������� ���������� ��������
    }
    --count; // ��������� ������� ��������
}

void Keeper::printAll() const {
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        objects[i]->print(); // �������� ������� ������ ��� ������� �������
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("������ �������� ����� ��� ������.");
    }

    // ��������� ������ ������ ��� ��������, �� � ��������� ����
    for (int i = 0; i < count; ++i) {
        if (dynamic_cast<Student*>(objects[i])) {
            outFile << "Student" << endl;
        }
        else if (dynamic_cast<Teacher*>(objects[i])) {
            outFile << "Teacher" << endl;
        }
        else if (dynamic_cast<AdminStaff*>(objects[i])) {
            outFile << "AdminStaff" << endl;
        }
        // ��������� ��� ������
        objects[i]->saveToFile(outFile);
    }

    outFile.close();
    
}

void Keeper::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw runtime_error("������ �������� ����� ��� ������.");
    }

    string type;
    while (getline(inFile, type)) {
        University* obj = nullptr;

        // ���������� ��� ������� � ��������� ���
        if (type == "Student") {
            obj = Student::loadFromFile(inFile);
        }
        else if (type == "Teacher") {
            obj = Teacher::loadFromFile(inFile);
        }
        else if (type == "AdminStaff") {
            obj = AdminStaff::loadFromFile(inFile);
        }
        else {
            cerr << "������: �������������� ��� ������� \"" << type << "\"" << endl;
            continue; // ���������� ������������ ������
        }

        if (obj) {
            addObj(obj);  // ��������� ������ � ���������
        }
    }

    inFile.close();
    
}
