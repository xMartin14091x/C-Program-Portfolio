#include <stdio.h>
int main() {
int Numbers[2] = { };
if (scanf("%d", &Numbers[0]) == 1 && scanf("%d", &Numbers[1]) == 1) {
    Numbers[0] % Numbers[1] == 0 ? printf("yes") : printf("no");
} else return 1;
return 0;
}