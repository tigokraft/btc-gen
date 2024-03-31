#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <wincrypt.h>
#include "headers.h"

unsigned int getRandom(int value) {
    HCRYPTPROV hProv;
    unsigned int random_number;

    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0)) {
        // Handle error: Could not acquire cryptographic context
        return 0;  // Placeholder for error handling
    }

    if (!CryptGenRandom(hProv, sizeof(random_number), (BYTE*)&random_number)) {
        // Handle error: Could not generate random number
        CryptReleaseContext(hProv, 0);
        return 0; // Placeholder for error handling
    }

    CryptReleaseContext(hProv, 0);
    return random_number % value + 1;
}