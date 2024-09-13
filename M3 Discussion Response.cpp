// M3 Discussion Response

#include <iostream>
using namespace std;

int main() {
    string name;
    string favoriteNumber;

    cout << "What is your name?" << endl;
    cin >> name;  // Corrected to >> for input
    cout << "What is your favorite number?" << endl;
    cin >> favoriteNumber;

    int favNumber = stoi(favoriteNumber);  // Convert string to int

    if (favNumber <= 10) {
        cout << "Wow, that's a low number!" << endl;
    } else {
        cout << "Wow, that's a high number!" << endl;
    }

    return 0;
}