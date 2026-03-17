/*1.Prime number is positive number greater than 2 and divisible only to its own and 1. Implement an application that let user input a number then determine if it is a prime number. Use While/For loop construct to do following exercise*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int number;
    bool isPrime = true;
    int divisor = 0;
    cout << "Input a number to check whether it is a prime number: ";
    cin >> number;
    if (number <= 1) {
        cout << number << " is not a prime number." << endl;
        return 0;
    }
    for (int i = 2; pow(i,2) <= number / 2; i++) {
        if (number % i == 0) {
            isPrime = false;
            divisor = i;
            break;
        }
    }
    if (isPrime) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number, because it is divisible by "
             << divisor << "." << endl;
    }
    return 0;
}
