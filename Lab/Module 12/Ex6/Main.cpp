#include <iostream>
using namespace std;
// global variable shared by CalculateDiscount and CalculateTax
class Discount
{
public:
    float dprice;
    float CalculateDiscount(float price)
    {
        if (price > 0 && price < 100)
        {
            dprice = price; // no discount :(
        }
        if (price >= 100 && price < 200)
        {
            dprice = price * 0.9; // 10 percent discount
        }
        if (price >= 200)
        {
            dprice = price * 0.85; // 15 percent discount :)
        }
        return dprice;
    }
};
class Tax : public Discount
{
public:
    float CalculateTax()
    {
        return dprice + dprice * 0.06;
    }
};
int main()
{
    float price;
    int check = 1;
    Tax discount;
    do
    {
        cout << "Please enter the total purchase price: RM";
        cin >> price;
        if (price > 0)
        {
            cout << "The total purchase price entered is: RM" << price << endl;
            check = 2;
        }
        if (price <= 0)
        {
            cout << "Please enter a valid value!" << endl
                 << endl;
            check = 1;
        }
    } while (check == 1);
    cout << "The total price after discount is: RM" << discount.CalculateDiscount(price) << endl;
    cout << "The total price with tax is: RM" << discount.CalculateTax() << endl;
}