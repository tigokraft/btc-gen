#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

unsigned int getRandomNumberInRange(int value) {
    unsigned int seed = time(NULL) ^ GetTickCount64() ^ GetCurrentProcessId();
    srand(seed);
    return (rand() % 100) + 1;
}

float getRandomFloat(float min, float max) {
    unsigned int seed = time(NULL) ^ GetTickCount64() ^ GetCurrentProcessId();
    srand(seed);
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}
