#include "../include/StudentManager.h"
#include <bits/stdc++.h>

using namespace std;

void StudentManager::addStudent(const Student& newStudent)
{
    studentList.push_back(newStudent);
}

void StudentManager::displayStudents() const
{
    if (studentList.empty())
    {
        cout << "No students found.\n";
        return;
    }

    for (const Student& currentStudent : studentList)
    {
        cout << "------------------------" << endl;
        cout << "ID         : " << currentStudent.getId() << endl;
        cout << "Name       : " << currentStudent.getName() << endl;
        cout << "Age        : " << currentStudent.getAge() << endl;
        cout << "Department : " << currentStudent.getDepartment() << endl;
    }
}

Student* StudentManager::searchStudentById(int id)
{
    for (Student& currentStudent : studentList)
    {
        if (currentStudent.getId() == id)
        {
            return &currentStudent;
        }
    }

    return nullptr;
}

Student* StudentManager::searchStudentByName(const string& name)
{
    for (Student& student : studentList)
    {
        if (student.getName() == name)
        {
            return &student;
        }
    }

    return nullptr;
}