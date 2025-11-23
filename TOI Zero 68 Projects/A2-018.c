#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char Input;
    int InputInt;

    scanf("%c %d", &Input, &InputInt);

    for (int i = 0; i < InputInt; i++) {
        if(Input == 'R') {
            if(i == 0 || i % 3 == 0) printf("Red ");
            else if(i == 1 || (i - 1) % 3 == 0) printf("Green ");
            else if(i == 2 || (i - 2) % 3 == 0) printf("Blue ");
        }

        else if(Input == 'G') {
            if(i == 0 || i % 3 == 0) printf("Green ");
            else if(i == 1 || (i - 1) % 3 == 0) printf("Blue ");
            else if(i == 2 || (i - 2) % 3 == 0) printf("Red ");
        }

        else if(Input == 'B') {
            if(i == 0 || i % 3 == 0) printf("Blue ");
            else if(i == 1 || (i - 1) % 3 == 0) printf("Red ");
            else if(i == 2 || (i - 2) % 3 == 0) printf("Green ");
        }

        else printf("Error");
    }
    
    return 0;
}