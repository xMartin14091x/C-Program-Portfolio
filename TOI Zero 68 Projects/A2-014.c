#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int CountOfW = 0, CountOfWInARow = 0, CountOfWInARowIndex = 0, HighestCountOfWInARow = 0;
    char Name1[201] = { }, Name2[201] = { }, Output[201] = { }, Buffer[201] = { };

    if(scanf(" %s %s", Name1, Name2) != 2) return 1;

    Name1[strlen(Name1)] = '\0';
    Name2[strlen(Name2)] = '\0';

    int SizeHolderName1 = strlen(Name1), SizeHolderName2 = strlen(Name2);

    if(SizeHolderName1 > SizeHolderName2) {
        for (int i = 0; i < SizeHolderName1 - SizeHolderName2; i++) {
            Buffer[i] = Name2[i];
        }

        strcat(Name2, Buffer);
        Name2[strlen(Name2)] = '\0'; 
    } else if(SizeHolderName1 < SizeHolderName2) {
        for (int i = 0; i < SizeHolderName2 - SizeHolderName1; i++) {
            Buffer[i] = Name1[i];
        }
        
        strcat(Name1, Buffer);
        Name1[strlen(Name2)] = '\0'; 
    }

    for (int i = 0; i < strlen(Name1); i++) {
        if(Name1[i] == 'L' || Name1[i] == 'O' || Name1[i] == 'V' || Name1[i] == 'E' || Name1[i] == 'l' || Name1[i] == 'o' || Name1[i] == 'v' || Name1[i] == 'e' || Name2[i] == 'L' || Name2[i] == 'O' || Name2[i] == 'V' || Name2[i] == 'E' || Name2[i] == 'l' || Name2[i] == 'o' || Name2[i] == 'v' || Name2[i] == 'e') {
            Output[i] = 'w';
            CountOfW++;
            CountOfWInARow++;
        } else {
            Output[i] = '$';
            
            CountOfWInARow = 0;
        }

        HighestCountOfWInARow = HighestCountOfWInARow < CountOfWInARow ? CountOfWInARow : HighestCountOfWInARow;
    }

    if(CountOfW % 2 != 0) {
        snprintf(Buffer, sizeof(Buffer), "%s%d", Output, HighestCountOfWInARow);
        snprintf(Output, sizeof(Output), "%s", Buffer);
    } else if(HighestCountOfWInARow <= 2) {
        char Hashtag = '#';
        snprintf(Buffer, sizeof(Buffer), "%s%c", Output, Hashtag);
        snprintf(Output, sizeof(Output), "%s", Buffer);
    }

    printf("%s", Output);

    // Debug ----------
    //printf("\n\nDEBUG:\nSizeName1: %d\nSizeName2: %d\nCurrentName1Size: %d\nCurrentName2Size: %d\nName1: %s\nName2: %s\nOutput: %s\nCountOfW: %d\nHighestCountOfW: %d", SizeHolderName1, SizeHolderName2, strlen(Name1), strlen(Name2), Name1, Name2, Output, CountOfW, HighestCountOfWInARow);
    

    return 0;
}