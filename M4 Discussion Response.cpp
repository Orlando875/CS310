#include <iostream>

using namespace std;

int main() {
    while (false) {
        cout << "Hello World!";
    }
    
    do {
        cout << "Goodbye World!";
    } while (false);  // Might want to change 'true' to 'false' to avoid an infinite loop.
    
    return 0;
}