#include <iostream>
using namespace std;


bool isEven(int number) {
    return number % 2 == 0;
}

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

void analyzeNumber(int number) {
    cout << "\nAnalysis of number " << number << ":\n";

    if (number > 0)
        cout << "- It is positive.\n";
    else if (number < 0)
        cout << "- It is negative.\n";
    else
        cout << "- It is zero.\n";

    if (isEven(number))
        cout << "- It is even.\n";
    else
        cout << "- It is odd.\n";

    if (isPrime(number))
        cout << "- It is a prime number.\n";
    else
        cout << "- It is not a prime number.\n";
}

int main() {
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    analyzeNumber(num);

    return 0;
}
