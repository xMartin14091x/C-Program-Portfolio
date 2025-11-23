#include <stdio.h>

// C = 67, c = 99, F = 70, f = 102
int main() {
int Tempreature;
char UnitOfTemp;
if(scanf("%d", &Tempreature) == 1 && scanf(" %c", &UnitOfTemp) == 1) {
    (UnitOfTemp == 67 || UnitOfTemp == 99) && (Tempreature <= 0) ? printf("solid") :
    (UnitOfTemp == 67 || UnitOfTemp == 99) && (Tempreature > 0 && Tempreature < 100) ? printf("liquid") : 
    (UnitOfTemp == 67 || UnitOfTemp == 99) && (Tempreature > 100) ? printf("gas") :

    (UnitOfTemp == 70 || UnitOfTemp == 102) && (Tempreature <= 32) ? printf("solid") :
    (UnitOfTemp == 70 || UnitOfTemp == 102) && (Tempreature > 32 && Tempreature < 212) ? printf("liquid") :
    (UnitOfTemp == 70 || UnitOfTemp == 102) && (Tempreature >= 212) ? printf("gas") : printf("Error");
} else return 1;
return 0;
}