#include <iostream>
using namespace std;

int main() {
    int a, b, t;
    cout << "Enter the time for the first dish (a): ";
    cin >> a;
    cout << "Enter the additional time for each subsequent dish (b): ";
    cin >> b;
    cout << "Enter the total available time (t): ";
    cin >> t;

    int time_spent = 0;
    int dish_count = 0;
    
    while (time_spent + a <= t) {
        time_spent += a;
        dish_count++;
        a += b;  
    }

    cout << "Bianca can prepare " << dish_count << " dishes." << endl;
    
    return 0;
}