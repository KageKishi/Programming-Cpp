/*4.Write a program to find a minimum value among A, B, C, D and E*/
//doesnt need to be complicated , just testing features
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<char, int> value = {
        {'A', 0},
        {'B', 0},
        {'C', 0},
        {'D', 0},
        {'E', 0}};
    bool firstInput = true;
    int smallest;
    for (auto &p : value)
    {
        cout << "Input value of " << p.first << ": ";
        cin >> p.second;
        if (firstInput)
        {
            smallest = p.second; // initialize smallest
            firstInput = false;
        }
        else if (p.second < smallest)
        {
            smallest = p.second;
        }
    }
    cout << "\nThe smallest number among A, B, C, D, and E is: " << smallest << endl;
    return 0;
}
