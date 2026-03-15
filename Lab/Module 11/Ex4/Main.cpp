#include <iostream>
using namespace std;
class Max
{
private:
    int x, y, z;
public:
    void CheckMax(int x, int y, int z)
    {
        if (x > y && x > z)
        {
            cout << x << endl;
        }
        if (y > z && y > z)
        {
            cout << y << endl;
        }
        if (z > x && z > y)
        {
            cout << z << endl;
        }
    }
};
int main()
{
    Max Check;
    int a, b, c;
    cout << "Please enter 3 different integers: " << endl;
    cin >> a >> b >> c;
    cout << "The largest value is: ";
    Check.CheckMax(a, b, c);
    return 0;
}