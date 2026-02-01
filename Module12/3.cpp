#include <iostream>
using namespace std;
class Number
{
private:
    int x, y;

public:
    Number(int num1, int num2)
    {
        this->x = num1;
        this->y = num2;
    }
    void CheckNum()
    {
        if (x % 2 == 0)
        {
            cout << x << " is an even number!" << endl;
        }
        else
        {
            cout << x << " is an odd number!" << endl;
        }
    }
    void CompareNum()
    {
        if (x > y)
        {
            cout << x << " is larger than " << y << endl;
        }
        else if (x < y)
        {
            cout << y << " is larger than " << x << endl;
        }
        else
        {
            cout << "Both numbers entered are the same!" << endl;
        }
    }
};
int main()
{
    int choice;
    cout << "Please Choose An Option:" << endl;
    cout << "1. Check Number" << endl;
    cout << "2. Compare Numbers" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int num1;
        cout << "Please enter a number: ";
        cin >> num1;
        Number ComAndCheck(num1 , 0);
        ComAndCheck.CheckNum();
        break;
    }
    case 2:
    {
        int num1, num2;
        cout << "Please enter the 1st number: ";
        cin >> num1;
        cout << "Please enter the 2nd number: ";
        cin >> num2;
        Number ComAndCheck(num1 , num2);
        ComAndCheck.CompareNum();
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