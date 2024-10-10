#include <iostream>
using namespace std;

int main() {
    const int rows = 3;
    const int cols = 4;
    
    int arr[rows][cols];

    arr[3][4] = 10;

    void displayArray() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    displayArray();
    return 0;
}