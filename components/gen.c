#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

#include "headers.h"
#include "methods.c"

FILE* fptr;

void generation(int value) {
    char* address;
    int keyPressed = 0;
    bool valid = true;

    time_t currentTime;
    struct tm *timeInfo;
    char formattedTime[20]; 
    FILE *fp;

    time(&currentTime);
    timeInfo = localtime(&currentTime);
    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d-%M-%S", timeInfo);

    // Construct the filename with ".txt" extension
    char filename[30]; // Make sure it's large enough to hold the name and extension
    strcpy(filename, formattedTime); 
    strcat(filename, ".txt"); 
    
    fptr = fopen(filename, "w"); 
    

    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }
 
    system("cls");
    name();

    do
    {
        if (value == 1) {
            address = allMethods();
        }
        if (value == 2) {
            address = taproot();
        }
        if (value == 3) {
            address = segWit();
        }
        if (value == 4) {
            address = scriptAdd();
        }
        if (value == 5) {
            address = legacy();
        }

        printf("generated: %s\n", address);
        fprintf(fptr, "generated: %s | method: %d\n", address, value);
        free(address);  

        if (kbhit()) {  // Check if a key has been pressed
            keyPressed = getch(); // Get the key if it has
            valid = false;
        } 
    } while (valid);

    fclose(fptr);
}