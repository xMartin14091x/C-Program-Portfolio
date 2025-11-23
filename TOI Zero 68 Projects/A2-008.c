#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int CountOfCarCannotBeSold = 0, HighestPerformance = 0, CountOfCar, **CarPriceNPerformance;

    if(scanf("%d", &CountOfCar) != 1) return 1;

    CarPriceNPerformance = (int**)calloc(CountOfCar, sizeof(int*));

    if(CarPriceNPerformance == NULL) return 1;

    for (int i = 0; i < CountOfCar; i++) {
        CarPriceNPerformance[i] = (int*)calloc(2, sizeof(int));

        if(CarPriceNPerformance[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(CarPriceNPerformance[j]);
                free(CarPriceNPerformance);

                return 2;
            }            
        }
    }

    for (int i = 0; i < CountOfCar; i++) {
        for (int j = 0; j < 2; j++) {
            if(scanf("%d", &CarPriceNPerformance[i][j]) != 1) return 3;            
        }
    }

    for (int i = CountOfCar - 1; i >= 0; i--) {
        if(HighestPerformance > CarPriceNPerformance[i][1]) CountOfCarCannotBeSold++;
        else HighestPerformance = CarPriceNPerformance[i][1];
    }
    

    printf("%d", CountOfCarCannotBeSold);
    
    for (int i = 0; i < CountOfCar; i++) {
        free(CarPriceNPerformance[i]);          
    }
    
    free(CarPriceNPerformance);

    return 0;
}