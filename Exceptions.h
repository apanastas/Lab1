#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// ������� ����� ��� ����������
class KeeperException : public std::exception {
protected:
    std::string message;
public:
    KeeperException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// ����������: ������� �������� �� ������� ����������
class EmptyContainerException : public KeeperException {
public:
    EmptyContainerException() : KeeperException("������: ������� ������� ������� �� ������� ����������.") {}
};

// ����������: ������������ ������ ��� ���������� ������ ��������
class MemoryAllocationException : public KeeperException {
public:
    MemoryAllocationException() : KeeperException("������: ������������ ������ ��� ���������� ������ ��������.") {}
};

// ����������: ������� ������� � ��������������� ��������
class IndexOutOfRangeException : public KeeperException {
public:
    IndexOutOfRangeException() : KeeperException("������: ������� ������� � �������� ��� ������ ����������.") {}
};

#endif // EXCEPTIONS_H
