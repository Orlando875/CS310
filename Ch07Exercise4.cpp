#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);  
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

string removeVowels(const string& str) {
    string result = "";  
    for (int i = 0; i < str.length(); ++i) {
        if (!isVowel(str[i])) {
            result += str.substr(i, 1);  
        }
    }
    return result;
}

int main() {
    string inputStr;

    cout << "Enter a string: ";
    getline(cin, inputStr);

    string result = removeVowels(inputStr);

    cout << "String after removing vowels: " << result << endl;

    return 0;
}