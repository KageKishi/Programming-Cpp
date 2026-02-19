/*8. Refer to the startup code provided below. Copy the code into your program and save the
code as Input.cpp. Create/Add two others .cpp file to the project to complete the given
code below by calling Total() function (from Sum.cpp file) and Average() function (from
Avg.cpp file). The values will be keyed inside Q08.cpp code and then shared across the
Avg.cpp and Sum.cpp using extern data storage type. Sample output of the program is
show below.*/
// File Input.cpp
//use this command to run ./Input.exe

#include <iostream>
#include "Sum.cpp"
#include "Avg.cpp"
using namespace std;
extern void Average();
extern void Total();
float d1, d2, d3;
int main()
{
    cout << "Please enter the values below:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    cout << "Total walking/running steps for Day1: "   ;
    cout << "\t ";
    cin >> d1;
    cout << "Total walking/running steps for Day2: ";
    cout << "\t ";
    cin >> d2;
    cout << "Total walking/running steps for Day3: ";
    cout << "\t ";
    cin >> d3;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    Total();
    Average();
    return 0;
}
