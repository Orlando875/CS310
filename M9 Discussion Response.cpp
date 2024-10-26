#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {} // Corrected initialization

    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Child class Student
class Student : public Person {
private:
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void displayStudentInfo() {
        displayPersonInfo();
        cout << "Major: " << major << endl;
    }
};

// Child class Teacher
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}

    void displayTeacherInfo() {
        displayPersonInfo();
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    // Creating a Student
    Student student1("Alice", 20, "Computer Science"); // Added missing age argument
    cout << "Student Information:" << endl;
    student1.displayStudentInfo();

    cout << endl;

    // Creating a Teacher
    Teacher teacher1("Mr. Smith", 45, "Mathematics");
    cout << "Teacher Information:" << endl;
    teacher1.displayTeacherInfo();

    return 0;
}