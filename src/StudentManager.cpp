#include "../include/StudentManager.h"
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;

void StudentManager::addStudent(const Student &newStudent)
{
    studentList.push_back(newStudent);
    saveToFile();
}

void StudentManager::displayStudents() const
{
    if (studentList.empty())
    {
        cout << "No students found.\n";
        return;
    }

    for (const Student &currentStudent : studentList)
    {
        cout << "------------------------" << endl;
        cout << "ID         : " << currentStudent.getId() << endl;
        cout << "Name       : " << currentStudent.getName() << endl;
        cout << "Age        : " << currentStudent.getAge() << endl;
        cout << "Department : " << currentStudent.getDepartment() << endl;
    }
}

Student *StudentManager::searchStudentById(int id)
{
    for (Student &currentStudent : studentList)
    {
        if (currentStudent.getId() == id)
        {
            return &currentStudent;
        }
    }

    return nullptr;
}

Student *StudentManager::searchStudentByName(const string &name)
{
    for (Student &student : studentList)
    {
        if (student.getName() == name)
        {
            return &student;
        }
    }

    return nullptr;
}

bool StudentManager::updateStudent(int id, const string &newName, int newAge, const string &newDepartment)
{
    for (Student &student : studentList)
    {
        if (student.getId() == id)
        {
            student.setName(newName);
            student.setAge(newAge);
            student.setDepartment(newDepartment);
            saveToFile();
            return true;
        }
    }

    return false;
}

bool StudentManager::deleteStudent(int id)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].getId() == id)
        {
            studentList.erase(studentList.begin() + i);
            saveToFile();
            return true;
        }
    }

    return false;
}
void StudentManager::saveToFile()
{
    ofstream outFile("data/students.txt");

    for (const Student &student : studentList)
    {
        outFile << student.getId() << ","
                << student.getName() << ","
                << student.getAge() << ","
                << student.getDepartment() << "\n";
    }

    outFile.close();
}

void StudentManager::loadFromFile()
{
    ifstream inFile("data/students.txt");

    string line;

    while (getline(inFile, line))
    {
        stringstream ss(line);

        string name, department;
        string idStr, ageStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, department);
        int id = stoi(idStr);
        int age = stoi(ageStr);
        Student newStudent(name, age, id, department);

        studentList.push_back(newStudent);
    }
    inFile.close();
}