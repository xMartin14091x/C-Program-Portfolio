#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int PriceToPay = 0, AmountOfCarrot, AmountOfCaf, AmountOfTomato;

    scanf("%d %d %d", &AmountOfCarrot, &AmountOfCaf, &AmountOfTomato);

    PriceToPay = (AmountOfCarrot * 10) + (AmountOfCaf * 25) + (AmountOfTomato * 3);

    printf("%d", PriceToPay);  

    return 0;
}