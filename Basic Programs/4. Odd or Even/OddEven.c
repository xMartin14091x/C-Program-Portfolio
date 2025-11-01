#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int OE = 0, argvc = 0;

    for (int i = 1; i < argc; i++) {
        printf("\nInput Value %d: %s\n", i, argv[i]);
        argvc = atoi(argv[i]);
        if(argvc == 0) {
            printf("Number is Even. Or a Character is inputted.\n");
            continue;
        }

        OE = argvc % 2;

        switch (OE) {
        case 0:
            printf("Number is Even\n");
            break;
        
        default:
            printf("Number is Odd\n");
            break;
        }
    }

    return 0;
}