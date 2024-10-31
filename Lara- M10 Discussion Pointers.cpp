#include <iostream>
using namespace std;

int main() {
    int *ptr;
    int num = 10;

    *ptr = num; 

    cout << "The value of num is: " << *ptr << endl;

    int *numPtr = &num;
    cout << "The address of num is: " << numPtr << endl

    return 0;
}