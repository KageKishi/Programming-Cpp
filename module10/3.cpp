/*3. Modify the start-up code provided below to include functions with arguments using call by
reference. Please ensure that the output of the program remains unchanged (Hint: You will need
to remove the return keywords from the user-defined functions first.)*/
#include <iostream>
using namespace std;
void TenPercent(float &price)
{
    price = price * 0.9;
}
void FifteenPercent(float &price)
{
    price = price * 0.85;
}
int main()
{
    float price;
    cout << "Please enter the total price: ";
    cin >> price;
    if (price >= 0 && price < 200)
    {
        TenPercent(price);
    }
    else if (price >= 200)
    {
        FifteenPercent(price);
    }
    else
    {
        cout << "Please enter a valid value" << endl;
    }
    cout << "The total price after discount is: " << price << endl;
    return 0;
}
