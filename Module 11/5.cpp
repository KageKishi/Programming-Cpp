#include <iostream>
using namespace std;
class Discount
{
private:
    double price;

public:
    float TenPercent(float price)
    {
        price = price * 0.9;
        return price;
    }
    float FifteenPercent(float price)
    {
        price = price * 0.85;
        return price;
    }
};
int main()
{
    float price;
    Discount discount;
    cout << "Please enter the total price: ";
    cin >> price;
    if (price > 0 && price < 200)
    {
        price = discount.TenPercent(price);
    }
    else if (price >= 200)
    {
        price = discount.FifteenPercent(price);
    }
    else
    {
        cout << "Invalid price entered.";
        cout << "Please restart the program!" << endl
             << endl;
    }
    cout << "The total price after discount is: " << price << endl;
    return 0;
}