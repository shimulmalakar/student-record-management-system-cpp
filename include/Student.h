#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;
    int id;
    string department;

public:
    Student();
    Student(string name, int age, int id, string department);
    int getAge() const;
    int getId() const;
    string getName() const;
    string getDepartment() const;

    void setName(string name);
    void setAge(int age);
    void setDepartment(string department);
};


#endif