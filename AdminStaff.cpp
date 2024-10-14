#include "AdminStaff.h"
using namespace std;

AdminStaff::AdminStaff(const string& name, const string& position, const string& phone, const string& responsibility)
    : name(name), position(position), phone(phone), responsibility(responsibility) {}

void AdminStaff::print() const {
    cout << "���������������� ��������: " << name;
    if (!position.empty()) {
        cout << ", ���������: " << position;
    }
    if (!phone.empty()) {
        cout << ", �������: " << phone;
    }
    if (!responsibility.empty()) {
        cout << ", ������� ���������������: " << responsibility;
    }
    cout << endl;
}

void AdminStaff::saveToFile(ofstream& outFile) const {
    outFile << name << ";" << position << ";" << phone << ";" << responsibility << endl;
}

University* AdminStaff::loadFromFile(ifstream& inFile) {
    string name, position, phone, responsibility;

    getline(inFile, name, ';');
    getline(inFile, position, ';');
    getline(inFile, phone, ';');
    getline(inFile, responsibility);

    return new AdminStaff(name, position, phone, responsibility);
}
