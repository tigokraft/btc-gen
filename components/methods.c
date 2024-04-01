#include <string.h>
#include <stdio.h>
#include "headers.h"

char* allMethods() {
    int value = getRandom(4);
    char *result = NULL; // Initialize to NULL

    switch (value) {
    case 1:
        result = taproot(); // No need for malloc, taproot allocates memory 
        break;
    case 2: 
        result = segWit();
        break;
    case 3:
        result = scriptAdd(); 
        break; 
    case 4: 
        result = legacy(); 
        break; 
    default:
        break;
    }

    return result;
}

char* taproot() {
    char *result = malloc(63 * sizeof(char)); 
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

char* segWit() {
    char *result = malloc(43 * sizeof(char)); 
    char charset[] = "qpzry9x8gf2tvdw5gs984hup5znkjw5hyxe6vh596g2n5mj4z7vfw4v9et247tmu37r";
      
    for (int i = 0; i < 42; i++) { 
        if (i < 4) {  // Corrected comparison 
            result[i] = "bc1q"[i]; 
        } else {
            result[i] = charset[getRandom(67)];
        }
    }
    result[42] = '\0'; // Add null terminator

    return result;
}

char* scriptAdd() {
    char* result = malloc(35 * sizeof(char));
    char charset[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

    for (int i = 0; i < 35; i++) { 
        if (i < 1) {  // Corrected comparison 
            result[i] = '3'; 
        } else {
            result[i] = charset[getRandom(58)];
        }
    }
    result[34] = '\0'; // Add null terminator

    return result;
}

char* legacy() {
    char* result = malloc(35 * sizeof(char));
    char charset[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

    for (int i = 0; i < 35; i++) { 
        if (i < 1) {  // Corrected comparison 
            result[i] = '1'; 
        } else {
            result[i] = charset[getRandom(58)];
        }
    }
    result[34] = '\0'; // Add null terminator

    return result;
}