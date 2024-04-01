#include <string.h>
#include <stdio.h>
#include "headers.h"
#include "random.c"

char taproot() {
    char result[63]; // Allocate space for 62 characters + null terminator 
    char charset[] = "qpzry9x8gf2tvdw5gs984hup5znkjw5hyxe6vh596g2n5mj4z7vfw4v9et247tmu37r";
    
    for (int i = 0; i < 62; i++) { 
        if (i < 4) {  // Corrected comparison 
            result[i] = "bc1p"[i]; 
        } else {
            result[i] = charset[getRandom(67)];
        }
    }
    result[62] = '\0'; // Add null terminator


    return result;
}