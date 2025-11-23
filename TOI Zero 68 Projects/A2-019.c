#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int IsBA = 0, IsBB = 0, Counter1 = 0, Counter2 = 0;
    char Input[9];

    scanf("%s", Input);

    for (int i = 0; i < strlen(Input); i++) {
        if((Input[i - 1] == 'B' || Input[i - 1] == 'b') && Counter1 == 0 || IsBA == 1) {
            IsBA = 1;
            if(Input[i] == 'U' || Input[i] == 'u') {
                Counter1++;
            } else IsBA = 0;
        }

        else if((Input[i - 1] == 'B' || Input[i - 1] == 'b') && Counter2 == 0 || IsBB == 1) {
            IsBB = 1;
            if(Input[i] == 'U' || Input[i] == 'u') {
                Counter2++;
            } else IsBB = 0;
        }
    }

    IsBA = 0;
    IsBB = 0;

    if(Counter1 >= Counter2 && Counter1 != 0) printf("Yes %d", Counter1);
    else if(Counter2 != 0) printf("Yes %d", Counter2);
    else {
        for (int i = 0; i < strlen(Input); i++) {
            if((Input[i - 1] == 'B' || Input[i - 1] == 'b') && Counter1 == 0 || IsBA == 1) {
                IsBA = 1;
                Input[i] = 'U';
            }
        }

        if(IsBA == 0) {
            for (int i = 0; i < strlen(Input); i++) {
                if(i % 3 == 0 || i == 0) Input[i] = 'B';
                else Input[i] = 'U';
            }
        }
    
        printf("%s", Input);
    }
    
    return 0;
}