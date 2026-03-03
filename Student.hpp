#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"
using namespace std;

class Student {
public:
    int id;
    string name;
    float gpa;
    Course* courseHead;
    Student* next;

    Student(int i = 0, string n = "", float g = 0.0);
    void addCourse(string cname, string location);
    void displayCourses() const;
};

#endif// TO DO:  Student class definition  here.
