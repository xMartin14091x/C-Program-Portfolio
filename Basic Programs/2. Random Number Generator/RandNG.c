#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int RandNumber = 0, Range1, Range2;

    srand(time(NULL));
    printf("Enter the range for the number to be generated (Ex. 30 60): ");
    if(scanf(" %d %d", &Range1, &Range2) != 2 || Range2 <= Range1) {
        printf("Invalid Input!");
        return 1;
    }

    RandNumber = rand() % (Range2 + 1 - Range1) + Range1;
    printf("Answer: %d", RandNumber);

    return 0;
}