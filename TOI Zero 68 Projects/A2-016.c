#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int CompareNumberString(char* Number1, char* Number2, int iLoop) {
    int CountOfSameCharacter = 0;
    for (int i = iLoop; i < strlen(Number1); i++) {
        if(Number1[i] == Number2[i]) CountOfSameCharacter++;
        // printf("%d %d %d\n", Number1[i], Number2[i], CountOfSameCharacter);
    }

    return CountOfSameCharacter;
}

int main() {
    char FirstChar1 = '\0', Numbers1[6] = { }, FirstChar2 = '\0', Numbers2[6] = { };

    if(scanf("%c %s %c %s", &FirstChar1, Numbers1, &FirstChar2, Numbers2) != 4) return 1;

    
    FirstChar1 == FirstChar2 && (CompareNumberString(Numbers1, Numbers2, 0) == 5) ? printf("1000000") : 
    FirstChar1 != FirstChar2 && (CompareNumberString(Numbers1, Numbers2, 0) == 5) ? printf("100000") : 

    FirstChar1 == FirstChar2 && (CompareNumberString(Numbers1, Numbers2, 2) == 3) ? printf("2000") :
    FirstChar1 == FirstChar2 && (CompareNumberString(Numbers1, Numbers2, 3) == 2) ? printf("1000") : 
     
    FirstChar1 != FirstChar2 && (CompareNumberString(Numbers1, Numbers2, 2) == 3) ? printf("200") : 
    FirstChar1 != FirstChar2 && (CompareNumberString(Numbers1, Numbers2, 3) == 2) ? printf("100") :
    
    FirstChar1 == FirstChar2 && strcmp(Numbers1, Numbers2) ? printf("20") : printf("0");

    return 0;
}