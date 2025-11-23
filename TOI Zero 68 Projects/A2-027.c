#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int CountOfScore, *Score, HighestScore = 0, CountOfHighestScore = 0;
    
    if(scanf("%d", &CountOfScore) != 1) return 1;

    Score = (int*)calloc(CountOfScore, sizeof(int));

    if(Score == NULL) return 1;

    for (int i = 0; i < CountOfScore; i++) {
        if(scanf("%d", &Score[i]) != 1) return 1;
        HighestScore = HighestScore < Score[i] ? Score[i] : HighestScore;
    }

    for (int i = 0; i < CountOfScore; i++) {
        if(Score[i] == HighestScore) CountOfHighestScore++;
    }

    printf("%d\n%d", HighestScore, CountOfHighestScore);        

    return 0;
}