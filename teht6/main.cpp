#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

#include "student.h"

using namespace std;

void printStudents(vector<Student> students)
{
    for (Student& student : students) {
        student.printStudentInfo();
    }
}

int main ()
{
    vector<Student> studentList;
    int selection = 0;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;

        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            string name;
            int age;

            cout << "Student name ?" << endl;
            cin >> name;


            cout << "Student age ?" << endl;
            while(!(cin >> age)) {
                cout << "Invalid input. Please enter a whole number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            studentList.push_back(Student(name, age));

            break;
        }
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.

            printStudents(studentList);
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
                return a.getName()<b.getName();
            });

            printStudents(studentList);
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
                return a.getAge()<b.getAge();
            });

            printStudents(studentList);
            break;
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            string name;

            cout << "Student to be found name ?" << endl;
            cin >> name;

            vector<Student> studentsWithName;
            copy_if(studentList.begin(), studentList.end(), back_inserter(studentsWithName), [=](Student& s) {
                return s.getName() == name;
            });

            if(studentsWithName.size() != 0)
            {
                cout << "Student found:" << endl;
                printStudents(studentsWithName);
            }
            else
                cout << "No students found:" << endl;

            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    } while(selection < 5);

    return 0;
}
