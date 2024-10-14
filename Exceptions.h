#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// Базовый класс для исключений
class KeeperException : public std::exception {
protected:
    std::string message;
public:
    KeeperException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// Исключение: Попытка удаления из пустого контейнера
class EmptyContainerException : public KeeperException {
public:
    EmptyContainerException() : KeeperException("Ошибка: попытка удалить элемент из пустого контейнера.") {}
};

// Исключение: Недостаточно памяти для добавления нового элемента
class MemoryAllocationException : public KeeperException {
public:
    MemoryAllocationException() : KeeperException("Ошибка: недостаточно памяти для добавления нового элемента.") {}
};

// Исключение: Попытка доступа к несуществующему элементу
class IndexOutOfRangeException : public KeeperException {
public:
    IndexOutOfRangeException() : KeeperException("Ошибка: попытка доступа к элементу вне границ контейнера.") {}
};

#endif // EXCEPTIONS_H
