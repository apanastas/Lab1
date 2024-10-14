#include "University.h"
#include "Student.h"
#include "Teacher.h"
#include "AdminStaff.h"
#include <stdexcept>

University* University::loadFromFile(ifstream& inFile) {
    // Здесь вы должны определить, какой именно тип объекта (Student, Teacher, AdminStaff) вы загружаете.
    // Например, вы можете начать файл с идентификатора типа объекта:

    char type;
    inFile.read(&type, sizeof(type)); // Считываем тип объекта из файла

    switch (type) {
    case 'S':
        return Student::loadFromFile(inFile);
    case 'T':
        return Teacher::loadFromFile(inFile);
    case 'A':
        return AdminStaff::loadFromFile(inFile);
    default:
        throw runtime_error("Неизвестный тип объекта при загрузке из файла.");
    }
}
