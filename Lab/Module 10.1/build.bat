@echo off
REM Build script for Module 10.1 (Windows)
g++ -Wall -Wextra -g3 "Input.cpp" "Sum.cpp" "Avg.cpp" -o "output\Input.exe"
if %errorlevel% neq 0 (
    echo Build failed with exit code %errorlevel%
    exit /b %errorlevel%
)
echo Build succeeded: output\Input.exe
