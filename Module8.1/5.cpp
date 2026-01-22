/*5.Write a program to find a maximum value among all values in an Array. Users can input values in Array as many as they want. */
#include <iostream>
using namespace std;
bool Answer()
{
    char ans;
    cout << "Do you want to add more (y/n)?: ";
    cin >> ans;

    if (ans == 'y')
        return true;
    else if (ans == 'n')
        return false;
    else
    {
        cout << "Please enter 'y' or 'n'\n";
        return Answer();
    }
}

int main()
{
    int i = 0;
    double *index = nullptr;
    string checker;
    bool invalidinput;
    while (true)
    {
        invalidinput= false;
        double *temp = new double[i + 1];
        for (int j = 0; j < i; j++)
            temp[j] = index[j];
        cout << "Input value in Array at index " << i << ":\n";
        cin >> checker;
        for (char c : checker)
        {
            if (isdigit(c))
            {
                continue;
            }
            else
            {
                invalidinput = true;
                break;
            }
        }
        if (!invalidinput)
        {
            temp[i] = stod(checker);
            delete[] index;
            index = temp;
            i++;
            if (!Answer())
                break;
        }else{
            cout << "Please enter only numbers\n";
        }
    }
    double maxValue = index[0];
    for (int j = 1; j < i; j++)
    {
        if (index[j] > maxValue)
            maxValue = index[j];
    }
    cout << "Maximum value is: " << maxValue << endl;
    delete[] index;
    return 0;
}
