#include <iostream>
#include "../include/Student.h"
#include "../include/StudentManager.h"

using namespace std;

void displayStudent(const Student& student)
{
    cout << "\nStudent Found!\n";
    cout << "Name: " << student.getName() << endl;
    cout << "Age: " << student.getAge() << endl;
    cout << "ID: " << student.getId() << endl;
    cout << "Department: " << student.getDepartment() << endl;
}

int main()
{
    StudentManager manager;
    int choice;

    while (true)
    {
        cout << "\n========== Student Management System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Search Student by Name\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, department;
            int age, id;

            cout << "\nEnter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Department: ";
            cin >> department;

            Student newStudent(name, age, id, department);

            manager.addStudent(newStudent);

            cout << "\nStudent Added Successfully!\n";
        }
        else if (choice == 2)
        {
            manager.displayStudents();
        }
       else if (choice == 3)
{
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    Student* foundStudentPtr = manager.searchStudentById(id);

    if (foundStudentPtr != nullptr)
    {  displayStudent(*foundStudentPtr);
    }
    else
    {
        cout << "\nStudent not found.\n";
    }
}
        else if (choice == 4)
        {
            string name;

            cout << "Enter Student Name: ";
            cin >> name;

            Student* foundStudentPtr = manager.searchStudentByName(name);

            if (foundStudentPtr != nullptr)
            {
                displayStudent(*foundStudentPtr);
            }
            else
            {
                cout << "\nStudent not found.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "\nThank you for using the Student Management System!\n";
            break;
        }
        else
        {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}