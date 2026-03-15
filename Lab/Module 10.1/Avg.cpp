#include <iostream>
using namespace std;
extern float d1 , d2 , d3;
void Average(){
    double average = (d1+d2+d3)/3;
    cout << "The average walking/running steps for 3 days: " << average << endl;
}