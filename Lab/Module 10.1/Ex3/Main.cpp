/*
3. Complete the program below that creates a structure to store two fields/members (i.e.
name of planet and distance from the sun (in million km)). Then use the structure variables
to enter the related information and display the list of planets and its distances A sample
output for the program is given below:
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    string turn[3] = {"1st","2nd","3rd"};
    struct planet{
        string name;
        double distance;
    };
    planet Planets[3];
    cout << "This program provides distances of planets from the Sun\n\n";
    for(int i = 0 ; i < 3 ; i++){
        cout << "\nEnter the " << turn[i] << " planet's name: ";
        getline(cin >> ws , Planets[i].name);
        cout << "Enter the " << turn[i] <<  " planet's distance (in million km):";
        cin >> ws >> Planets[i].distance;
    }
    cout << endl;
    cout << left;
    cout << setw(10) << "Name" << setw(20) << "Distances (in million km)\n";
    for(const auto &s : Planets){
        cout << setw(10) << s.name << setw(20) << s.distance << endl;
    }
    return 0;
}
