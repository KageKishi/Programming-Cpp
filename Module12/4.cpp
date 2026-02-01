#include <iostream>
using namespace std;
class One
{
public:
    void DisplayOne()
    {
        cout << "We are covering OOP part 2 this week!" << endl
             << endl;
    }
    void DisplayTwo()
    {
        cout << "This is our 2nd last lab session!" << endl
             << endl;
    }
};
class Two : public One
{
};
int main()
{
    One Obj1;
    Two Obj2;
    cout << "Here are facts about this week!" << endl
         << endl;
    Obj1.DisplayOne();
    Obj2.DisplayTwo();
    return 0;
}