#include <stdio.h>
#include <stdlib.h>

int main() {
    int NumberOfTrees, TreesThatHaveNests = 0, *NumberOfHeights;

    if(scanf(" %d", &NumberOfTrees) == 1) {
        NumberOfHeights = (int*)malloc(NumberOfTrees * sizeof(int));
        if(NumberOfHeights == NULL) {
            return 1;
        }

        for (int i = 0; i < NumberOfTrees;) {
            if(scanf(" %d", &NumberOfHeights[i])) {
                i++;
            } else return 1;
        }

        for (int i = 0; i < NumberOfTrees; i++) {
            if(NumberOfTrees == 1) TreesThatHaveNests = 1;
            else if(NumberOfHeights[i] > NumberOfHeights[i - 1] && NumberOfHeights[i] > NumberOfHeights[i + 1] && i - 1 > 0 && i + 1 >= NumberOfTrees) TreesThatHaveNests++;
            else if(i - 1 < 0 && i + 1 <= NumberOfTrees) TreesThatHaveNests += NumberOfHeights[i] > NumberOfHeights[i + 1];
            else if(i - 1 >= 0 && i + 1 >= NumberOfTrees) TreesThatHaveNests += NumberOfHeights[i] > NumberOfHeights[i - 1];
            else TreesThatHaveNests += (NumberOfHeights[i] > NumberOfHeights[i - 1] ? 1 : 0) && (NumberOfHeights[i] > NumberOfHeights[i + 1] ? 1 : 0);
        }
    
        printf("%d", TreesThatHaveNests);
    } else return 1;

    return 0;
}