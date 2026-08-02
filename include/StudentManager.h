#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "Student.h"
#include <vector>
using namespace std;
class StudentManager
{
private:
    vector<Student> studentList;

public:
    void addStudent(const Student& newStudent);
    void displayStudents() const;
    Student* searchStudentById(int id);
    Student* searchStudentByName(const string& name);
    bool updateStudent(int id, const string& newName, int newAge, const string& newDepartment);
    bool deleteStudent(int id);
};
#endif 