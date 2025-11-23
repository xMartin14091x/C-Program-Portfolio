#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const int CharRU = 82, CharTU = 84, CharMU = 77, CharHU = 72, CharOU = 79, CharJU = 74;
    int AmountOfCal = 0, AmountOfBoba, Sweetness, AmountOfTea;
    char TypeOfTea, TypeOfBoba;

    if(scanf(" %c %d %c %d %d", &TypeOfBoba, &AmountOfBoba, &TypeOfTea, &Sweetness, &AmountOfTea) != 5) return 1;

    AmountOfCal += (TypeOfBoba == CharHU) && (TypeOfTea == CharRU) && (Sweetness == 1) ? 12 + (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharRU) && (Sweetness == 2) ? (18 * AmountOfTea)+ (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharRU) && (Sweetness == 3) ? (25 * AmountOfTea)+ (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharTU) && (Sweetness == 1) ? (15 * AmountOfTea) + (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharTU) && (Sweetness == 2) ? (20 * AmountOfTea) + (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharTU) && (Sweetness == 3) ? (30 * AmountOfTea) + (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharMU) && (Sweetness == 1) ? (10 * AmountOfTea) + (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharMU) && (Sweetness == 2) ? (15 * AmountOfTea) + (AmountOfBoba * 5) :
    (TypeOfBoba == CharHU) && (TypeOfTea == CharMU) && (Sweetness == 3) ? (20 * AmountOfTea) + (AmountOfBoba * 5) : 

    (TypeOfBoba == CharOU) && (TypeOfTea == CharRU) && (Sweetness == 1) ? (12 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharRU) && (Sweetness == 2) ? (18 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharRU) && (Sweetness == 3) ? (25 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharTU) && (Sweetness == 1) ? (15 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharTU) && (Sweetness == 2) ? (20 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharTU) && (Sweetness == 3) ? (30 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharMU) && (Sweetness == 1) ? (10 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharMU) && (Sweetness == 2) ? (15 * AmountOfTea) + (AmountOfBoba * 3) :
    (TypeOfBoba == CharOU) && (TypeOfTea == CharMU) && (Sweetness == 3) ? (20 * AmountOfTea) + (AmountOfBoba * 3) :

    (TypeOfBoba == CharJU) && (TypeOfTea == CharRU) && (Sweetness == 1) ? (12 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharRU) && (Sweetness == 2) ? (18 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharRU) && (Sweetness == 3) ? (25 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharTU) && (Sweetness == 1) ? (15 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharTU) && (Sweetness == 2) ? (20 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharTU) && (Sweetness == 3) ? (30 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharMU) && (Sweetness == 1) ? (10 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharMU) && (Sweetness == 2) ? (15 * AmountOfTea) + (AmountOfBoba * 2) :
    (TypeOfBoba == CharJU) && (TypeOfTea == CharMU) && (Sweetness == 3) ? (20 * AmountOfTea) + (AmountOfBoba * 2) : printf("0");

    printf("%d", AmountOfCal);

    return 0;
}