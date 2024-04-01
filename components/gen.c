#include <stdio.h>
#include <string.h>
#include "headers.h"
#include "random.c"
#include "menus.c"
#include "methods.c"

int generation(int value) {
    switch (value)
    {
    case 1:
        genAll();
        break;
    default:
        break;
    }
}

void genAll() {
    // system("cls");
    
    printf("generated: %s\n", taproot());
    
    // int keyPressed = 0;
    
    // int method = 0;

    

    // keyPressed = getch();
    //     fflush(stdin);
    
    
}