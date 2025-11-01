#include <stdio.h>
#include <stdlib.h>

int main() {
    int Choice;
    double Answer, Arg1, Arg2;

    printf("1 = Addition\n2 = Subtraction\n3 = Multiplication\n4 = Division\n\nSelect: ");
    
    if(scanf(" %d", &Choice) != 1 || Choice > 4 || Choice < 1) {
        printf("Invalid Input!");

        return 1;
    }

    printf("Enter first and second number: ");
    if(scanf(" %lf %lf", &Arg1, &Arg2) != 2) {
        printf("Invalid Input!");
        
        return 1;
    }

    switch (Choice) {
        case 1: {
            Answer = Arg1 + Arg2;
            break;
        }

        case 2: {
            Answer = Arg1 - Arg2;
            break;
        }

        case 3: {
            Answer = Arg1 * Arg2;
            break;
        }

        case 4: {
            Answer = Arg1 / Arg2;
            break;
        }

        default:{
            printf("Unexpected Behaviour!");
            return 1;
        }    
    }

    printf("Answer: %.2lf", Answer);

    return 0;
}