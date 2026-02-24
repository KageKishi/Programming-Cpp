#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
int getValidatedInteger(const std::string &prompt);
double getValidatedDouble(const std::string &prompt);
class Library
{
private:
    json arr;
    json currentuser;
    string Title;
    int ISBN;
    double Price;
    string Author;
    int SearchedISBN;

public:
    Library()
    {
        arr = json::array();
        ifstream READ("Books.json");
        READ >> arr;
        READ.close();
    }
    void SavaData()
    {
        ofstream nerd("Books.json");
        currentuser["Title"] = Title;
        currentuser["ISBN"] = ISBN;
        currentuser["Price"] = Price;
        currentuser["Author"] = Author;
        arr.push_back(currentuser);
        nerd << arr.dump(6);
        nerd.close();
    }
    void AddaNewBook()
    {
        cout << "====Add a Book====\n";
        ISBN = getValidatedInteger("Input ISBN: ");
        cout << "Title: ";
        getline(cin, Title);
        Price = getValidatedDouble("Price: ");
        cout << "Author: ";
        getline(cin, Author);
        SavaData();
    }

    void UpdateABook()
    {
        cout << "====Update A Book====\n";
        SearchedISBN = getValidatedInteger("Input ISBN: ");
        for (auto &New : arr)
        {
            if (New["ISBN"] == SearchedISBN)
            {
                cout << "Please update the following:\n";
                ISBN = getValidatedInteger("ISBN: ");
                cout << "Title: ";
                getline(cin, Title);
                Price = getValidatedDouble("Price: ");
                cout << "Author: ";
                getline(cin, Author);
                ofstream nerd("Books.json");
                New["Title"] = Title;
                New["ISBN"] = ISBN;
                New["Price"] = Price;
                New["Author"] = Author;
                nerd << arr.dump(6);
                nerd.close();
            }
        }
    }
    void PrintAllBooks()
    {
        for (auto &Puthi : arr)
        {
            cout << string(20, '=') << endl;
            cout << "Author: " << Puthi["Author"] << endl;
            cout << "Title: " << Puthi["Title"] << endl;
            cout << "ISBN: " << Puthi["ISBN"] << endl;
            cout << "Price: " << Puthi["Price"] << endl;
            cout << string(20, '=') << endl;
        }
    }
};
int main()
{
    Library Everything;
    int choice;
    while (true)
    {
        system("cls");
        cout << "====Menu====";
        cout << "\n1.View all books\n";
        cout << "2.Add a new Book\n";
        cout << "3.Update a Book\n";
        cout << "4.Quit\n";
        choice = getValidatedInteger("Choose an Option: ");
        switch (choice)
        {
        case 1:
        {
            system("cls");
            Everything.PrintAllBooks();
            break;
        }
        case 2:
        {
            system("cls");
            Everything.AddaNewBook();
            break;
        }
        case 3:
        {
            system("cls");
            Everything.UpdateABook();
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid Choice\n";
            break;
        }
        }
        system("pause");
    }
    return 0;
}
int getValidatedInteger(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, temp);
        try
        {
            for (char c : temp)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Invalid character");
                }
            }
            int value = std::stoi(temp);
            if (value > 0)
            {
                return value;
            }
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid integer.\n";
        }
    }
}
double getValidatedDouble(const std::string &prompt)
{
    std::string temp;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, temp);
        try
        {
            bool dotSeen = false;
            for (char c : temp)
            {
                if (isdigit(c))
                    continue;
                if (c == '.' && !dotSeen)
                {
                    dotSeen = true;
                    continue;
                }
                throw std::invalid_argument("Invalid character");
            }
            double value = std::stod(temp);
            if (value > 0)
                return value;
            std::cout << "Error: Value must be greater than 0.\n";
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid number.\n";
        }
    }
}
