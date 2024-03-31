#include <stdio.h>
#include <windows.h>

#include "headers.h"

void name() {
    printf(YEL" __     __     ______     __         __         ______     ______      ______     ______     __   __    \n");
    printf("/\\ \\  _ \\ \\   /\\  __ \\   /\\ \\       /\\ \\       /\\  ___\\   /\\__  _\\    /\\  ___\\   /\\  ___\\   /\\ \"-.\\ \\   \n");
    printf("\\ \\ \\/ \".\\ \\  \\ \\  __ \\  \\ \\ \\____  \\ \\ \\____  \\ \\  __\\   \\/_/\\ \\/    \\ \\ \\__ \\  \\ \\  __\\   \\ \\ \\-.  \\  \n");
    printf(" \\ \\__/\".~\\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\    \\ \\_\\     \\ \\_____\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\ \n");
    printf("  \\/_/   \\/_/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/     \\/_/      \\/_____/   \\/_____/   \\/_/ \\/_/ \n\n\n\n"reset);
}

// =========================================
//              Arrow Printer
// =========================================
void arrowHere(int realPosition, int arrowPosition) {
    if (realPosition == arrowPosition) {
        printf(" -> ");
    }
    else {
        printf("    ");
    }
}

// =========================================
//            Main screen menu
// =========================================
int mainMenu() {
    system("cls");

    int position = 1;
    int keyPressed = 0;

    #define MIN 1 
    #define MAX 2

    do
    {
        system("cls");

        name();

        arrowHere(1,position); printf(" START GEN \n");
        arrowHere(2,position); printf(" EXIT \n");

        keyPressed = getch();
        fflush(stdin);

        if (keyPressed == 80 && position != MAX) {
            position++;
        }
        else if (keyPressed == 72 && position != MIN) {
            position--;
        }
        else if (position == MAX && keyPressed == 80) {
            position = MIN;
        }
        else if(position == MIN && keyPressed == 72) {
            position = MAX;
        }
        else {
            position = position;
        }

    } while (keyPressed != 13);

    return position;
}


// =========================================
//          Secondary screen menu
// =========================================
int walletMenu() {
    system("cls");

    int position = 1;
    int keyPressed = 0;

    #define MIN 1 
    #define MAX 6

    do
    {
        system("cls");

        name();

        printf("SELECT WHAT TYPE OF WALLET YOU WANT TO GENERATE\n\n");

        arrowHere(1,position); printf(" ALL TYPES \n");
        arrowHere(2,position); printf(" Taproot \n");
        arrowHere(3,position); printf(" SegWit \n");
        arrowHere(4,position); printf(" Script \n");
        arrowHere(5,position); printf(" Legacy \n");
        arrowHere(6,position); printf(" BACK \n");

        keyPressed = getch();
        fflush(stdin);

        if (keyPressed == 80 && position != MAX) {
            position++;
        }
        else if (keyPressed == 72 && position != MIN) {
            position--;
        }
        else if (position == MAX && keyPressed == 80) {
            position = MIN;
        }
        else if(position == MIN && keyPressed == 72) {
            position = MAX;
        }
        else {
            position = position;
        }

    } while (keyPressed != 13);

    return position;
}