#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using namespace std;

class Course {
public:
    string courseName;
    string location;
    Course* next;

    Course(string name = "", string loc = "");
};

#endif// TODO:  Course class definitins go here.
