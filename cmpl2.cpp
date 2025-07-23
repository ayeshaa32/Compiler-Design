#include<iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter expression : ";
    cin >> input;

    for (int i =0; i<input.length(); i++) {
        if (input[i] == '+' || input[i] == '_' || input[i] == '*' || input[i] == '/' || input[i] =='%' || input[i] == '='){
            cout << "operator found: " << input[i] << endl;
        }
    }
    return 0;
}
