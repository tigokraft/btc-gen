#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "components/gen.c" // include for generation of wallets
#include "components/random.c" // include for randomization
#include "components/text.h" // include for font related elements
#include "components/menus.c" // include for menus
#include "components/misc.c" // include for miscelanious functions



int main() {
    bool valid = true;
    bool sec = false;

    int option = 0;
    int secOption = 0;
    
    do
    {   
        option = mainMenu();
    
        switch (option)
        {
        case 1:
            sec = true;
            do
            {
                secOption = walletMenu();
                if (secOption != 6) {
                    generation(secOption);
                }
                else {
                    sec = false;
                }
            } while (sec);        
            break;
        case 2:
            valid = false;
            break;
        default:
            puts("INVALID OPTION");
            break;
        }
    } while (valid);
    
}