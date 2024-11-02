#include <iostream>
using namespace std;

int main() {
    int num1, num2;  // Declare integers, not references
    int* ptr1 = &num1;  // Initialize pointers with the addresses of num1 and num2
    int* ptr2 = &num2;

    // Get numbers from the user
    cout << "Enter two numbers:" << endl;
    cout << "Number 1: ";
    cin >> *ptr1;  
    cout << "Number 2: ";
    cin >> *ptr2;  

    cout << "\nBefore swapping:" << endl;
    cout << "Number 1 = " << *ptr1 << ", Number 2 = " << *ptr2 << endl;

    // Swapping values using pointers
    int temp = *ptr1;  // Corrected syntax
    *ptr1 = *ptr2;
    *ptr2 = temp;

    cout << "\nAfter swapping:" << endl;
    cout << "Number 1 = " << *ptr1 << ", Number 2 = " << *ptr2 << endl;

    return 0;
}