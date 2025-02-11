#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    Student(std::string, int);

    void setAge(int);
    void setName(std::string);
    std::string getName();
    int getAge();
    void printStudentInfo();

private:
    std::string Name;
    int Age;
};

#endif // STUDENT_H
