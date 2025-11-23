#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int UnknownDueToOnlyInT = 1, HighestCountOfAs = 0, CountOfAs = 0, IsR = 0, IsB = -1;
    char Input[501] = { };

    if(scanf(" %s", Input) != 1) return 1;

    int LenghtOfInput = strlen(Input);
    for (int i = 0; i < LenghtOfInput; i++) {
        if(UnknownDueToOnlyInT == 1 && (Input[i] != 'T' && Input[i] != 't' && Input[i] != 'I' && Input[i] != 'i')) UnknownDueToOnlyInT = 0;

        if(Input[i] == 'R' || Input[i] == 'r') {
            if(i + 1 < LenghtOfInput && (Input[i + 1] != 'A' && Input[i + 1] != 'a')) {
                printf("no %d", i + 1);
                return 0;
            } else if(i + 1 >= LenghtOfInput && (Input[i] == 'R' || Input[i] == 'r')) {
                printf("no %d", i + 1);
            }

            IsR = 1;
        } else if(Input[i] == 'B' || Input[i] == 'b') {
            if(i + 1 < LenghtOfInput && (Input[i + 1] != 'T' && Input[i + 1] != 't' && Input[i + 1] != 'I' && Input[i + 1] != 'i')) {
                printf("no %d", i + 1);
                return 0;                
            } else if(i + 1 >= LenghtOfInput && (Input[i] == 'B' || Input[i] == 'b')) {
                printf("no %d", i + 1);
            }
        }

        if(IsR == 1) {
            if(Input[i + 1] == 'A' || Input[i + 1] == 'a') CountOfAs++;
            else {IsR = 0; CountOfAs = 0;}
        } else if(IsR == 0 && (Input[i] == 'A' || Input[i] == 'a')) {
            printf("no %d", i);
            return 0;
        }

        HighestCountOfAs = HighestCountOfAs < CountOfAs ? CountOfAs : HighestCountOfAs;
    }
    
    if(UnknownDueToOnlyInT == 1) printf("unknown %d", strlen(Input));
    else printf("yes %d", HighestCountOfAs);

    return 0;
}