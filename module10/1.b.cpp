//1.b
#include <iostream>
using namespace std;
void CompareAndCheckNum(int num)
{
    if (num % 2 == 0)
    {
        cout << num << " is an Even Number." << endl
             << endl;
    }
    else
    {
        cout << num << " is an Odd Number." << endl
             << endl;
    }
}
void CompareAndCheckNum(int num1, int num2)
{
    if (num1 > num2)
    {
        cout << num1 << " is larger than " << num2 << "." << endl
             << endl;
    }
    else if (num1 < num2)
    {
        cout << num2 << " is larger than " << num1 << "." << endl
             << endl;
    }
    else
    {
        cout << "Both numbers are the same." << endl
             << endl;
    }
}
int main()
{
    int choice;
    cout << "Please Choose An Option:" << endl;
    cout << "1. Check Number" << endl;
    cout << "2. Compare Numbers" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
    {
        int num1;
        cout << "Please enter a number: ";
        cin >> num1;
        cout << endl;
        CompareAndCheckNum(num1); // function calling
        break;
    }
    case 2:
    {
        int num1, num2;
        cout << "Please enter the 1st number: ";
        cin >> num1;
        cout << "Please enter the 2nd number: ";
        cin >> num2;
        cout << endl;
        CompareAndCheckNum(num1, num2); // function calling
        break;
    }
    default:
    {
        cout << "Pls enter option 1 or 2 only" << endl
             << endl;
        break;
    }
    }
    return 0;
}