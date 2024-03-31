#include <windows.h>
#include <stdio.h>
#include <string.h>

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // Get a handle to the console output
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    // Retrieve console screen buffer information
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &csbi)) {
        // Handle the error 
        fprintf(stderr, "Error getting console width"); 
        return -1; // Or another suitable error indicator
    }

    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}