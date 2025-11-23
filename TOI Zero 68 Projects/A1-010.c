#include <stdio.h>

// s 115, S 83
int main() {
char Student;
int Age;
scanf("%d %c", &Age, &Student);
(Age < 18) || (Student == 115 || Student == 83) ? printf("20") : printf("50");
return 0;
}