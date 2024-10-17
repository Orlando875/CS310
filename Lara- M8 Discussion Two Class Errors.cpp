#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int studentID;

    Student(string n, int a, int id) : Person(name, age), studentID(id) {}

    void displayStudentInfo() {
        cout << "Student ID: " << studentID << ", Name: " << name << ", Age: " << age << endl
    }
};

int main() {
    Student s1("Alice", 20, 12345);

    s1.displayStudentInfo();

    return 0;
}