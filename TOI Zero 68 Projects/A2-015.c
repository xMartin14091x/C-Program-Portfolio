#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int Lenght, Widht, NumberOfLine, PricePerMeter, LenghtOfCable = 0, PriceOfCable = 0;

    scanf("%d %d %d %d", &Lenght, &Widht, &NumberOfLine, &PricePerMeter);

    LenghtOfCable = ((Lenght * 2) + (Widht * 2)) * NumberOfLine;
    PriceOfCable = LenghtOfCable * PricePerMeter;

    printf("%d\n%d", LenghtOfCable, PriceOfCable);

    return 0;
}