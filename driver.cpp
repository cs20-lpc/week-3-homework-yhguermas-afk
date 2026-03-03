#include <iostream>
#include <string>
#include "Student.hpp"
using namespace std;

class LinkedList {
private:
    Student* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertStudent(int id, string name, float gpa) {
        Student* newStudent = new Student(id, name, gpa);

        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newStudent;
        }
    }

    void deleteStudent(int id) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->id == id) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted student with ID " << id << endl;
            return;
        }

        Student* curr = head;
        while (curr->next != nullptr && curr->next->id != id) {
            curr = curr->next;
        }

        if (curr->next == nullptr) {
            cout << "Student not found.\n";
        } else {
            Student* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Deleted student with ID " << id << endl;
        }
    }

    Student* searchStudent(int id) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Student* temp = head;
        while (temp != nullptr) {
            cout << temp->id << " " << temp->name << " " << temp->gpa << " ";
            if (temp->courseHead == nullptr)
                cout << "None";
            cout << endl;
            temp = temp->next;
        }
    }

    int countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void addCourseToStudent(int id, string cname, string location) {
        Student* s = searchStudent(id);
        if (s == nullptr) {
            cout << "Student not found.\n";
        } else {
            s->addCourse(cname, location);
            cout << "Course added successfully.\n";
        }
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\n1. Insert Student\n2. Delete Student\n3. Search Student\n4. Display All\n5. Count Students\n6. Add a course\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;

            list.insertStudent(id, name, gpa);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            list.deleteStudent(id);
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Student* s = list.searchStudent(id);
            if (s == nullptr) {
                cout << "Student not found.\n";
            } else {
                cout << "Found: " << s->id << " " << s->name << " " << s->gpa << endl;
                cout << "Courses:\n";
                s->displayCourses();
            }
        }

        else if (choice == 4) {
            cout << "Students in List:\n";
            list.displayAll();
        }

        else if (choice == 5) {
            cout << "Total students: " << list.countStudents() << endl;
        }

        else if (choice == 6) {
            int id;
            string cname, location;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Course Name: ";
            getline(cin, cname);
            cout << "Enter location: ";
            getline(cin, location);

            list.addCourseToStudent(id, cname, location);
        }

    } while (choice != 7);

    return 0;
}