#include <iostream>
using namespace std;
class Velocity
{
private:
    float d, v, t , u , a;

public:
    void CalculateV()
    {
        cout << "Please enter the following values: " << endl;
        cout << "Enter the time taken (in s) = ";
        cin >> t;
        cout << "Enter the distance travelled (in m) = ";
        cin >> d;
        v = d / t;
        cout << "Velocity = " << v << " m/s" << endl;
    }
    void CalculateA()
    {
        cout << "Please enter the following values: " << endl;
        cout << "Enter the time taken (in s) = ";
        cin >> t;
        cout << "Enter the initial velocity (in m/s) = ";
        cin >> u;
        cout << "Enter the final velocity (in m/s) = ";
        cin >> v;
        a = (v - u) / t;
        cout << "Acceleration = " << a << " m/s^2" << endl;
    }
};
class Acceleration : public Velocity
{
};
int main()
{
    int Option;
    cout << "1 - Calculate Velocity " << endl;
    cout << "2 - Calculate Acceleration " << endl;
    cout << "Your option: ";
    cin >> Option;
    cout << endl;
    if (Option == 1)
    {
        Velocity Vel;
        Vel.CalculateV();
    }
    else if (Option == 2)
    {
        Acceleration Acc;
        Acc.CalculateA();
    }
    else
    {
        cout << "Please enter option 1 or 2 only." << endl;
    }
    return 0;
}