#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>
// This file provides console color helpers; do not include other .cpp files here.
#ifndef COLOR_LIGHT_GRAY
#define COLOR_LIGHT_GRAY 7
#define COLOR_DARK_GRAY 8
#define COLOR_GREEN 10
#define COLOR_CYAN 11
#define COLOR_RED 12
#define COLOR_MAGENTA 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15
#endif
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void resetColor()
{
    setColor(7);
}