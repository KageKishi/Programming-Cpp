/*4. Complete the start-up code provided below to include a user-defined function called CheckMax
that receives four parameters from main function and determines which integer has the highest
value (max). Complete the program using function with arguments using call by reference.
Please ensure that the output of the program remains unchanged*/
#include <iostream>
using namespace std;
int CheckMax(int x, int y, int z, int &max)
{
    if (x > y && x > z)
    {
        max = x;
    }
    else if (y > x && y > z)
    {
        max = y;
    }
    else
    {
        max = z;
    }
    return max;
}
int main()
{
    int a, b, c, max;
    cout << "Please enter 3 different integers: " << endl;
    cin >> a >> b >> c;
    cout << "The largest value is: ";
    cout << CheckMax(a, b, c, max);
    return 0;
}
