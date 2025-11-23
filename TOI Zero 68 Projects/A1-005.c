#include <stdio.h>

int main() {
    int MonthDaySeason[3] = { };
    if(scanf("%d", &MonthDaySeason[0]) == 1 && scanf("%d", &MonthDaySeason[1]) == 1) {
        if (MonthDaySeason[0] % 3 == 0 && MonthDaySeason[1] >= 21) MonthDaySeason[0] == 3 ? printf("spring") : MonthDaySeason[0] == 6 ? printf("summer") : MonthDaySeason[0] == 9 ? printf("fall") : MonthDaySeason[0] == 12 ? printf("winter") : 0;
        else MonthDaySeason[0] <= 3 ? printf("winter") : MonthDaySeason[0] <= 6 ? printf("spring") : MonthDaySeason[0] <= 9 ? printf("summer") : MonthDaySeason[0] <= 12 ? printf("fall") : 0;
    } else return 1;
    return 0;
}