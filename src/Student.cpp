#include "../include/Student.h"

Student ::Student()
{
     name = "";
    age = 0;
    id = 0;
    department = "";
}
Student ::Student(string name, int age, int id, string department)
{
    this->name = name;
    this->age = age;
    this->id = id;
    this->department = department;
}
int Student::getAge() const
{
    return age;
}
int Student::getId() const
{
    return id;
}
string Student::getName() const
{
    return name;
}
string Student::getDepartment() const
{
    return department;
}
void Student :: setName (string name)
{
    this-> name=name;
}
void Student :: setAge (int age)
{
    this-> age=age;
}
void Student :: setDepartment(string department)
{
    this-> department =department;
}