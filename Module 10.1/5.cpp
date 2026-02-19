#include <iostream>
#include <cmath>
using namespace std;
struct student
{
    float weight;
    float height;
    float BMI;
};
int main()
{
    int stdnum;
    cout << "Enter number of students required: ";
    cin >> stdnum;
    student students[stdnum];
    for (int i = 1; i < stdnum + 1; i++)
    {
        cout << "\nEnter Student" << i << " Height (in m): ";
        cin >> students[i - 1].height;
        cout << "Enter Student" << i << " Weight (in kg): ";
        cin >> students[i - 1].weight;
        students[i - 1].BMI = students[i - 1].weight / pow(students[i - 1].height, 2);
    }
    cout << "\nCalculated BMI:\n";
    for (int i = 1; i < stdnum + 1; i++)
    {
        cout << "Student" << i << " - " << students[i - 1].BMI << endl;
    }
    return 0;
}
