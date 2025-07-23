#include <iostream>
using namespace std;

bool isComment(const string& input)
{
    if (input.length() >= 2 && input[0] == '/' && input[1] == '/')
        return true;

    if (input.length() >= 4 && input[0] == '/' && input[1] == '*' &&
        input[input.length() - 2] == '*' && input[input.length() - 1] == '/')
        return true;

    return false;
}

int main()
{
    string input;
    cout << "Enter a line: ";
    cin >> input;

    if (isComment(input)){
        cout << "This is a comment line." << endl;}
    else
       { cout << "This is a multiple line Comment." << endl;}

    return 0;
}
