#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "AdminStaff.h"
#include "exceptions.h" // Подключаем для работы с исключениями
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

Keeper::Keeper() : count(0), capacity(10) {
    objects = new University * [capacity]; // Выделяем память для массива
}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i) {
        delete objects[i]; // Освобождаем память для каждого объекта
    }
    delete[] objects; // Освобождаем память для массива указателей
}

void Keeper::resize() {
    capacity *= 2; // Увеличиваем объем в два раза
    University** newObj = new University * [capacity];
    for (int i = 0; i < count; i++) {
        newObj[i] = objects[i]; // Переписываем старые объекты
    }
    delete[] objects;
    objects = newObj; // Устанавливаем новый массив объектов
}

void Keeper::addObj(University* obj) {
    if (count >= capacity) {
        resize();
    }
    objects[count++] = obj; // Добавление объекта
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= count) {
        throw IndexOutOfRangeException(); // Генерируем исключение, если индекс некорректен
    }
    delete objects[index]; // Удаляем объект из памяти
    for (int i = index; i < count - 1; ++i) {
        objects[i] = objects[i + 1]; // Сдвигаем оставшиеся элементы
    }
    --count; // Уменьшаем счетчик объектов
}

void Keeper::printAll() const {
    for (int i = 0; i < count; i++) {
        cout << i << ". ";
        objects[i]->print(); // Вызываем функцию печати для каждого объекта
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Ошибка открытия файла для записи.");
    }

    // Сохраняем каждый объект без индексов, но с указанием типа
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
        // Сохраняем сам объект
        objects[i]->saveToFile(outFile);
    }

    outFile.close();
    
}

void Keeper::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw runtime_error("Ошибка открытия файла для чтения.");
    }

    string type;
    while (getline(inFile, type)) {
        University* obj = nullptr;

        // Определяем тип объекта и загружаем его
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
            cerr << "Ошибка: нераспознанный тип объекта \"" << type << "\"" << endl;
            continue; // Пропускаем некорректные строки
        }

        if (obj) {
            addObj(obj);  // Добавляем объект в контейнер
        }
    }

    inFile.close();
    
}
