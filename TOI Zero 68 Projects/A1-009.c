#include <stdio.h>
#include <string.h>

int main() {
int Number[2];
if(scanf("%d", &Number[0]) == 1 && scanf("%d", &Number[1]) == 1) {
    Number[0] + Number[1] >= 50 ? printf("%d\npass", Number[0] + Number[1]) : printf("%d\nfail", Number[0] + Number[1]);
} else return 1;
return 0;
}