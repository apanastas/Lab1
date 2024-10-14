#include "University.h"
#include "Student.h"
#include "Teacher.h"
#include "AdminStaff.h"
#include <stdexcept>

University* University::loadFromFile(ifstream& inFile) {
    // ����� �� ������ ����������, ����� ������ ��� ������� (Student, Teacher, AdminStaff) �� ����������.
    // ��������, �� ������ ������ ���� � �������������� ���� �������:

    char type;
    inFile.read(&type, sizeof(type)); // ��������� ��� ������� �� �����

    switch (type) {
    case 'S':
        return Student::loadFromFile(inFile);
    case 'T':
        return Teacher::loadFromFile(inFile);
    case 'A':
        return AdminStaff::loadFromFile(inFile);
    default:
        throw runtime_error("����������� ��� ������� ��� �������� �� �����.");
    }
}
