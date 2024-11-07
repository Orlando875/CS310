#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Adding integers: " << add<int>(5, "10") << endl; 
    cout << "Adding doubles: " << add<double>(5.5, 2.2) << endl;

    cout << "Adding unsupported types: " << add<char>('A', 'B') << endl; 

    return 0;
}