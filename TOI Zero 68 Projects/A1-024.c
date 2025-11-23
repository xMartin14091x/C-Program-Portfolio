#include <stdio.h>

// C = 67, c = 99, F = 70, f = 102
int main() {
int YearCC[2];
char UnitOfTemp;
if(scanf("%d", &YearCC[0]) == 1 && scanf("%d", &YearCC[1]) == 1) {
    YearCC[0] <= 1990 ? YearCC[1] <= 1500 ? printf("1250") : YearCC[1] <= 2000 ? printf("1400") : printf("2000") :
    YearCC[0] < 2000 ? YearCC[1] <= 1500 ? printf("1100") : YearCC[1] <= 2000 ? printf("1300") : printf("1700") :
    YearCC[0] >= 2000 ? YearCC[1] <= 1500 ? printf("1000") : YearCC[1] <= 2000 ? printf("1200") : printf("1500") : printf("error");
} else return 1;
return 0;
}