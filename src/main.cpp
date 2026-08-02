#include <iostream>
#include <limits>
#include "../include/Student.h"
#include "../include/StudentManager.h"

using namespace std;

void displayStudent(const Student &student)
{
    cout << "\nStudent Found!\n";
    cout << "Name       : " << student.getName() << endl;
    cout << "Age        : " << student.getAge() << endl;
    cout << "ID         : " << student.getId() << endl;
    cout << "Department : " << student.getDepartment() << endl;
}

int getValidInt(const string &message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            return value;
        }

        cout << "\nInvalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    StudentManager manager;
    manager.loadFromFile();

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

        int choice = getValidInt("\nEnter your choice: ");

        if (choice == 1)
        {
            string name, department;

            cout << "\nEnter Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            if (name.empty())
            {
                cout << "\nName cannot be empty!\n";
                continue;
            }

            int age = getValidInt("Enter Age: ");

            if (age <= 0)
            {
                cout << "\nAge must be greater than 0.\n";
                continue;
            }

            int id = getValidInt("Enter ID: ");

            if (id <= 0)
            {
                cout << "\nID must be greater than 0.\n";
                continue;
            }

            if (manager.idExists(id))
            {
                cout << "\nA student with this ID already exists!\n";
                continue;
            }

            cout << "Enter Department: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, department);

            if (department.empty())
            {
                cout << "\nDepartment cannot be empty!\n";
                continue;
            }

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
            int id = getValidInt("\nEnter Student ID: ");

            if (id <= 0)
            {
                cout << "\nID must be greater than 0.\n";
                continue;
            }

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            if (name.empty())
            {
                cout << "\nName cannot be empty!\n";
                continue;
            }

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
            int id = getValidInt("\nEnter Student ID: ");

            if (id <= 0)
            {
                cout << "\nID must be greater than 0.\n";
                continue;
            }

            string name, department;

            cout << "Enter New Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            if (name.empty())
            {
                cout << "\nName cannot be empty!\n";
                continue;
            }

            int age = getValidInt("Enter New Age: ");

            if (age <= 0)
            {
                cout << "\nAge must be greater than 0.\n";
                continue;
            }

            cout << "Enter New Department: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, department);

            if (department.empty())
            {
                cout << "\nDepartment cannot be empty!\n";
                continue;
            }

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
            int id = getValidInt("\nEnter Student ID: ");

            if (id <= 0)
            {
                cout << "\nID must be greater than 0.\n";
                continue;
            }

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
            cout << "\nInvalid Choice! Please choose between 1 and 7.\n";
        }
    }

    return 0;
}