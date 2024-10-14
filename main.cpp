#include <iostream>
#include <locale>
#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "AdminStaff.h"
#include "exceptions.h"

using namespace std;

void showMenu() {
    cout << "1. Добавить студента\n";
    cout << "2. Добавить преподавателя\n";
    cout << "3. Добавить администратора\n";
    cout << "4. Вывести всех\n";
    cout << "5. Удалить объект\n";
    cout << "6. Сохранить в файл\n";
    cout << "7. Восстановить из файла\n";
    cout << "8. Выход\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    Keeper keeper;
    int choice;

    while (true) {
        showMenu();
        cout << "Выберите действие: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный выбор, попробуйте снова.\n";
            continue;
        }

        cin.ignore();

        if (choice == 1) {
            string name, group, specialty;
            int course;
            double GPA;

            cout << "Введите ФИО: ";
            getline(cin, name);
            cout << "Введите группу: ";
            getline(cin, group);
            cout << "Введите специальность: ";
            getline(cin, specialty);
            cout << "Введите курс: ";
            cin >> course;
            cout << "Введите средний балл (с точкой, например 4.5): ";
            cin >> GPA;

            keeper.addObj(new Student(name, group, specialty, course, GPA));
            cout << "Студент добавлен успешно.\n";
        }
        else if (choice == 2) {
            string name, subjects, groups;

            cout << "Введите ФИО: ";
            getline(cin, name);
            cout << "Введите предметы: ";
            getline(cin, subjects);
            cout << "Введите группы: ";
            getline(cin, groups);

            keeper.addObj(new Teacher(name, subjects, groups));
            cout << "Преподаватель добавлен успешно.\n";
        }
        else if (choice == 3) {
            string name, position, phone, responsibility;

            cout << "Введите ФИО: ";
            getline(cin, name);
            cout << "Введите должность: ";
            getline(cin, position);
            cout << "Введите телефон: ";
            getline(cin, phone);
            cout << "Введите область ответственности: ";
            getline(cin, responsibility);

            keeper.addObj(new AdminStaff(name, position, phone, responsibility));
            cout << "Администратор добавлен успешно.\n";
        }
        else if (choice == 4) {
            keeper.printAll();
        }
        else if (choice == 5) {
            int index;
            cout << "Введите индекс объекта, который хотите удалить: ";
            cin >> index;
            try {
                keeper.removeObject(index);
                cout << "Объект успешно удалён.\n";
            }
            catch (const IndexOutOfRangeException& ex) {
                cout << ex.what() << endl;
            }
        }
        else if (choice == 6) {
            keeper.saveToFile("data_s.txt");
            cout << "Объекты успешно сохранены в файл.\n"; // Сообщение об успешном сохранении
        }
        else if (choice == 7) {
            keeper.loadFromFile("data_s.txt");
            cout << "Объекты успешно восстановлены.\n";
        }
        else if (choice == 8) {
            break;
        }
    }

    return 0;
}
