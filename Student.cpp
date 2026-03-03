#include "Student.hpp"
#include <iostream>
using namespace std;

Student::Student(int i, string n, float g) {
    id = i;
    name = n;
    gpa = g;
    courseHead = nullptr;
    next = nullptr;
}

void Student::addCourse(string cname, string location) {
    Course* newCourse = new Course(cname, location);

    if (courseHead == nullptr) {
        courseHead = newCourse;
    } else {
        Course* temp = courseHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newCourse;
    }
}

void Student::displayCourses() const {
    if (courseHead == nullptr) {
        cout << "None";
        return;
    }

    Course* temp = courseHead;
    while (temp != nullptr) {
        cout << temp->courseName << " " << temp->location << endl;
        temp = temp->next;
    }
}// TODO:  Student class methods implementation here.
