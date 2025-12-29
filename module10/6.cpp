/*6. Modify the countdown program below that requests for a value from the user before the
countdown can begin. The program must include a gap of 1 second for every time the program
displays the countdown value from the value entered to zero followed by a Beep sound. Use a
loop, Beep() and Sleep() function to solve this problem. (Hint: You will need to include the
windows.h header file for your program to work with Sleep() and Beep() function)*/
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    int x;
    cout << "Please enter the countdown starting value: ";
    cin >> x;
    cout << "Countdown begins..." << endl;
    while (x >= 0)
    {
        cout << x << endl;
        Beep(500,500);
        Sleep(500);
        x--;
    }
    cout << "Happy New Year!" << endl;
    return 0;
}

