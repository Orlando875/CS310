#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Some generic animal sound!" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Woof!" << endl;
    }
    void fetch() {
        cout << "Fetching the ball!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Meow!" << endl;
    }
    void climbTree() {
        cout << "Climbing the tree!" << endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->speak();  
    myDog->fetch();  

    myCat->speak();  
    myCat->climbTree();  

    delete myDog;
    delete myCat;

    return 0;
}