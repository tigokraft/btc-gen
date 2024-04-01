#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#include "headers.h"
#include "methods.c"

FILE* fptr;

void generation(int value) {
    char* address;
    int keyPressed = 0;
    bool valid = true;

    system("cls");
    name();

    fptr = fopen("hits.txt", "a+");

    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }
 

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
        fprintf("generated: %s | method: %d", address, value);
        free(address);  

        if (kbhit()) {  // Check if a key has been pressed
            keyPressed = getch(); // Get the key if it has
            valid = false;
        } 
    } while (valid);

    fclose(fptr);
}