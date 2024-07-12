#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string id;
    string firstName;
    string lastName;
};

struct Course {
    string code;
    string title;
};

vector<Student> students;
vector<Course> courses;

void addStudent() {
    Student student;
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter first name: ";
    cin >> student.firstName;
    cout << "Enter last name: ";
    cin >> student.lastName;
    students.push_back(student);
    cout << "Student added successfully.\n";
}

void viewStudents() {
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Name: " << student.firstName << " " << student.lastName << endl;
    }
}

void addCourse() {
    Course course;
    cout << "Enter course code: ";
    cin >> course.code;
    cout << "Enter course title: ";
    cin >> course.title;
    courses.push_back(course);
    cout << "Course added successfully.\n";
}

void viewCourses() {
    for (const auto& course : courses) {
        cout << "Code: " << course.code << ", Title: " << course.title << endl;
    }
}

void mainMenu() {
    int choice;
    do {
        cout << "GroupName School\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Add Course\n";
        cout << "4. View Courses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                addCourse();
                break;
            case 4:
                viewCourses();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    mainMenu();
    return 0;
}