//2.b
#include <iostream>
using namespace std;
void Accelerate(float dis, float time)
{
    cout << "velocity is " << dis / time << " m/s\n";
}
void Accelerate(float ini, float velo, float time)
{
    cout << "acceleration is " << (ini + velo * time) << " m/s^2";
}
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
        float d, t;
        cout << "Enter the distance travelled (in m) = ";
        cin >> d;
        cout << "Enter the time take (in s) = ";
        cin >> t;
        Accelerate(d, t);
    }
    else if (Option == 2)
    {
        float u, v, t;
        cout << "Enter the initial velocity (in m/s) = ";
        cin >> u;
        cout << "Enter the final velocity (in m/s) = ";
        cin >> v;
        cout << "Enter the time take (in s) = ";
        cin >> t;
        Accelerate(u, v, t);
    }
    else
    {
        cout << "Please enter option 1 or 2 only." << endl;
    }
    return 0;
}