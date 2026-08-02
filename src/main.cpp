#include <iostream>
#include "../include/Student.h"
#include "../include/StudentManager.h"

using namespace std;

void displayStudent(const Student &student)
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
    manager.loadFromFile();
    int choice;

    while (true)
    {
        cout << "\n========== Student Management System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Search Student by Name\n";
        cout << "5. Update Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, department;
            int age, id;

            cout << "\nEnter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;
            if (age <= 0)
            {
                cout << "\nInvalid age!\n";
                continue;
            }

            cout << "Enter ID: ";
            cin >> id;
            if (manager.idExists(id))
            {
                cout << "\nA student with this ID already exists!\n";
                continue;
            }

            cout << "Enter Department: ";
            cin.ignore();
            getline(cin, department);

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
            Student *foundStudentPtr = manager.searchStudentById(id);

            if (foundStudentPtr != nullptr)
            {
                displayStudent(*foundStudentPtr);
            }
            else
            {
                cout << "\nStudent not found.\n";
            }
        }
        else if (choice == 4)
        {
            string name;

            cout << "\nEnter Name: ";
            cin.ignore();
            getline(cin, name);

            Student *foundStudentPtr = manager.searchStudentByName(name);

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
            int id, age;
            string name, department;

            cout << "\nEnter Student ID: ";
            cin >> id;

            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter New Age: ";
            cin >> age;
            if (age <= 0)
            {
                cout << "\nInvalid age!\n";
                continue;
            }

            cout << "Enter New Department: ";
            cin.ignore();
            getline(cin, department);

            bool isUpdated = manager.updateStudent(id, name, age, department);

            if (isUpdated)
            {
                cout << "\nStudent Updated Successfully!\n";
            }
            else
            {
                cout << "\nStudent Not Found!\n";
            }
        }
        else if (choice == 6)
        {
            int id;

            cout << "\nEnter Student ID: ";
            cin >> id;

            bool isDeleted = manager.deleteStudent(id);

            if (isDeleted)
            {
                cout << "\nStudent Deleted Successfully!\n";
            }
            else
            {
                cout << "\nStudent Not Found!\n";
            }
        }

        else if (choice == 7)
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