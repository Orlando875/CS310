#include <iostream>

using namespace std;

int Addition(int x, int y)
{
	return x + y;
}

int main()
{
	int x;
	int y;

	cout << "\nEnter a positive or negative number: " << endl;
	cin >> x;

	cout << "\nEnter another positive or negative number: " << endl;
	cin >> y;

	int answer = Addition(x, y);

	if (answer < 0)
		cout << "\nThe answer is " << answer << ", which is a negative number." << endl;
	else
		cout << "\nThe answer is " << answer << ", which is a positive number." << endl;

	cout << "\nPress any key to continue..." << endl;

	return 0;
}