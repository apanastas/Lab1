#ifndef KEEPER_H
#define KEEPER_H
#include <iostream>
#include "University.h"
using namespace std;

class Keeper {
private:
	University** objects; //Массив указателей на объекты базового класса
	int capacity; //Объем массива
	int count; //Текущее количество объектов
	
	void resize();

public:
	Keeper();
	~Keeper();

	
	void addObj(University* obj);
	void removeObject(int index);
	void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);
	void printAll() const;
};
#endif