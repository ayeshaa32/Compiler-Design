#include <iostream>
#include <string>
using namespace std;

bool isAlphabet(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isUnderscore(char ch) {
    return ch == '_';
}

bool isValidIdentifier(const string& input) {
    if (input.empty())
        return false;


    if (!(isAlphabet(input[0]) || isUnderscore(input[0])))
        return false;


    for (int i = 1; i < input.length(); i++) {
        char ch = input[i];
        if (!(isAlphabet(ch) || isDigit(ch) || isUnderscore(ch)))
            return false;
    }

    return true;
}

int main() {
    string userInput;
    cout << "Enter an identifier: ";
    cin >> userInput;

    if (isValidIdentifier(userInput))
        cout << "Valid identifier." << endl;
    else
        cout << "Invalid identifier." << endl;

    return 0;
}
