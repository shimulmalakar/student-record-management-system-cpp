#include <iostream>
#include "../include/Student.h"
#include "../include/StudentManager.h"

using namespace std;

int main()
{
    StudentManager manager;

    Student shimul("Shimul", 21, 101, "CSE");
    Student rahim("Rahim", 20, 102, "ECE");

    manager.addStudent(shimul);
    manager.addStudent(rahim);

    manager.displayStudents();

    int searchId;

    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    Student* foundStudent = manager.searchStudentById(searchId);

    if (foundStudent != nullptr)
    {
        cout << "\nStudent Found\n";
        cout << "ID         : " << foundStudent->getId() << endl;
        cout << "Name       : " << foundStudent->getName() << endl;
        cout << "Age        : " << foundStudent->getAge() << endl;
        cout << "Department : " << foundStudent->getDepartment() << endl;
    }
    else
    {
        cout << "\nStudent not found.\n";
    }

    return 0;
}