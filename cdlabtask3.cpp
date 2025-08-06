#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <regex>

using namespace std;

bool isDelimiter(char ch) {
    string delimiters = ";:,(){}[]";
    return delimiters.find(ch) != string::npos;
}

bool isInteger(const string &str) {
    return regex_match(str, regex("^[0-9]+$"));
}

bool isRealNumber(const string &str) {
    return regex_match(str, regex("^[0-9]*\\.[0-9]+$"));
}

int main() {
    ifstream file("program.txt"); // Make sure this file exists in the same folder
    string line;

    cout << "Detected Tokens:\n";

    while (getline(file, line)) {
        string token;
        for (size_t i = 0; i < line.length(); ++i) {
            char ch = line[i];

            if (isspace(ch) || isDelimiter(ch)) {
                if (!token.empty()) {
                    if (isInteger(token)) {
                        cout << "Integer: " << token << endl;
                    } else if (isRealNumber(token)) {
                        cout << "Real Number: " << token << endl;
                    }
                    token.clear();
                }
                if (isDelimiter(ch)) {
                    cout << "Delimiter: " << ch << endl;
                }
            } else if (ch == '.') {
                if (!token.empty() && isdigit(token.back())) {
                    token += ch;
                } else {
                    if (!token.empty()) {
                        cout << "Unknown token: " << token << endl;
                        token.clear();
                    }
                    token = ch;
                }
            } else {
                token += ch;
            }
        }

        if (!token.empty()) {
            if (isInteger(token)) {
                cout << "Integer: " << token << endl;
            } else if (isRealNumber(token)) {
                cout << "Real Number: " << token << endl;
            } else {
                cout << "Unknown token: " << token << endl;
            }
        }
    }

    file.close();
    return 0;
}
