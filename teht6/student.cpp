#include <iostream>
#include "student.h"

Student::Student(std::string n, int a): Name(n), Age(a) {}

void Student::setAge(int newAge)
{
    Student::Age = newAge;
}

void Student::setName(std::string newName)
{
    Student::Name = newName;
}

std::string Student::getName()
{
    return Student::Name;
}

int Student::getAge()
{
    return Student::Age;
}

void Student::printStudentInfo()
{
    std::cout << "Student " << Student::getName() << " Age " << Student::getAge() << std::endl;
}
