#include <stdio.h>
int main() {
int Input[3];
if(scanf("%d", &Input[0]) == 1 && scanf("%d", &Input[1]) == 1 && scanf("%d", &Input[2]) == 1) {
    (Input[0] == Input[1]) && (Input[0] == Input[2]) ? printf("all the same") : (Input[0] != Input[1]) && (Input[0] != Input[2]) && (Input[1] != Input[2]) ? printf("all different") : printf("neither");
} else return 1;
return 0;
}