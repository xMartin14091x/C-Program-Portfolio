#include <stdio.h>
#include <stdlib.h>

int main() {
    int CountOfRabbit, CountOfOverWeightRabbit = 0, HighestWeightRabbit = 0, HighestWeightRabbitAddress = 0, *WeightOfRabbits;      
    char** RabbitNames;

    if(scanf("%d", &CountOfRabbit) != 1) return 1;

    WeightOfRabbits = (int*)calloc(CountOfRabbit, sizeof(int));
    if(WeightOfRabbits == NULL) return 1;

    RabbitNames = (char**)malloc(CountOfRabbit * sizeof(char*));
    for (int i = 0; i < CountOfRabbit; i++) {
        RabbitNames[i] = (char*)malloc(21 * sizeof(char));

        if(RabbitNames[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(RabbitNames[j]);
            }
            
            free(RabbitNames);
            free(WeightOfRabbits);
            return 2;
        }

        if(scanf("%s %d", RabbitNames[i], &WeightOfRabbits[i]) != 2) return 3;

        if(WeightOfRabbits[i] > 15) CountOfOverWeightRabbit++;
        if(HighestWeightRabbit < WeightOfRabbits[i]) {
            HighestWeightRabbit = WeightOfRabbits[i];

            HighestWeightRabbitAddress = i;
        }
    }

    printf("%d\n%s %d", CountOfOverWeightRabbit, RabbitNames[HighestWeightRabbitAddress], HighestWeightRabbit);
    
    for (int i = 0; i < CountOfRabbit; i++) {
        free(RabbitNames[i]);
    }
    
    free(RabbitNames);
    free(WeightOfRabbits); 

    return 0;
}