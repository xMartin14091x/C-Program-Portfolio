#include <stdio.h>

int main() {
    char Input1[32], Input2[32];

    if(scanf("%s", Input1) == 1 && scanf("%s", Input2) == 1) {
        printf("Hello %s %s\n", Input1, Input2);
        printf("%c%c%c%c", Input1[0], Input1[1], Input2[0], Input2[1]);
    }

    return 0;
}