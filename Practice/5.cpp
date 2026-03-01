/*5. Shape management (apply inheritance concept to create classes of shape)
Write a program to allow user mange different shapes of geometry.
You can suggest Attributes according to the shapes Line, Rectangles and
Triangle*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
int getValidatedInteger(const std::string &prompt);
class shape 
{
public:
    json arr;
    json current;
    shape()
    {
        arr = json::array();
        ifstream READ("shapes.json");
        if (READ && READ.peek() != EOF)
        {
            try
            {
                READ >> arr;
            }
            catch (...)
            {
                arr = json::array();
            }
        }
        if (READ.is_open())
            READ.close();
    }
    void saveShape()
    {
        ofstream WRITE("shapes.json");
        WRITE << arr.dump(5);
        WRITE.close();
    }
};
class triangle : public shape
{
private:
    int base, height;

public:
    void MakeTriangle()
    {
        for (int i = 1; i <= height; i++)
        {
            cout << setw(height - i + 1) << "";
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                if (j == 1 || j == 2 * i - 1 || i == height)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    void InputTriangle()
    {
        height = getValidatedInteger("Enter height: ");
        MakeTriangle();
        json newShape;
        newShape["type"] = "triangle";
        newShape["height"] = height;
        arr.push_back(newShape);
        saveShape();
    }
    void viewAlltriangle()
    {
        for (auto &shape : arr)
        {
            if (shape["type"] == "triangle")
            {
                height = shape["height"];
                cout << "Triangle - " << "Height: " << height << endl;
                MakeTriangle();
            }
        }
    }
};
class rectangle : public shape
{
private:
    int width, height;

public:
    void InputRectangle()
    {
        width = getValidatedInteger("Enter width: ");
        height = getValidatedInteger("Enter height: ");
        MakeRectangle();
        json newShape;
        newShape["type"] = "rectangle";
        newShape["width"] = width;
        newShape["height"] = height;
        arr.push_back(newShape);
        saveShape();
    }
    void MakeRectangle()
    {
        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= width; j++)
            {
                if (i == 1 || i == height || j == 1 || j == width)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    void ViewAllRectangles()
    {
        for (auto &shape : arr)
        {
            if (shape["type"] == "rectangle")
            {
                int width = shape["width"];
                int height = shape["height"];
                cout << "Rectangle - Width: " << width << ", Height: " << height << endl;
                MakeRectangle();
            }
        }
    }
};
class line : public shape
{
private:
    int length;

public:
    void InputLine()
    {
        length = getValidatedInteger("Enter length: ");
        MakeLine();
        json newShape;
        newShape["type"] = "line";
        newShape["length"] = length;
        arr.push_back(newShape);
        saveShape();
    }
    void MakeLine()
    {
        cout << string(length, '-') << endl;
        cout << endl;
    }
    void ViewAllLines()
    {
        for (auto &shape : arr)
        {
            if (shape["type"] == "line")
            {
                length = shape["length"];
                cout << "Line - Length: " << length << endl;
                MakeLine();
            }
        }
    }
};
int main()
{
    triangle tri;
    rectangle rec;
    line lin;
    int choice;
    do
    {
        cout << "==== Menu ====\n";
        cout << "1. View all lines\n";
        cout << "2. View all rectangles\n";
        cout << "3. View all triangles\n";
        cout << "4. Add a new shape\n";
        cout << "5. Quit\n";
        do
        {
            choice = getValidatedInteger("Choose an option: ");
        } while (choice < 1 || choice > 5);
        switch (choice)
        {
        case 1:
        {
            lin.ViewAllLines();
            break;
        }
        case 2:
        {
            rec.ViewAllRectangles();
            break;
        }
        case 3:
        {
            tri.viewAlltriangle();
            break;
        }
        case 4:
        {
            int shapeChoice;
            cout << "Choose a shape to add:\n";
            cout << "1. Line\n";
            cout << "2. Rectangle\n";
            cout << "3. Triangle\n";
            do
            {
                shapeChoice = getValidatedInteger("Choose an option: ");
            } while (shapeChoice < 1 || shapeChoice > 3);
            switch (shapeChoice)
            {
            case 1:
            {
                lin.InputLine();
                break;
            }
            case 2:
            {
                rec.InputRectangle();
                break;
            }
            case 3:
            {
                tri.InputTriangle();
                break;
            }
            default:
            {
                cout << "Invalid choice\n";
                break;
            }
            }
            break;
        }
        case 5:
        {
            cout << "Goodbye!\n";
            break;
        }
        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }
    } while (choice != 5);
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
