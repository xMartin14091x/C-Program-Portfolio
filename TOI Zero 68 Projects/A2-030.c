#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int **ArrayInput, SumOfRow = 0, SumOfColumn = 0, RowAddress = -1, ColumnAddress = -1;    

    ArrayInput = (int**)calloc(5, sizeof(int*));

    if(ArrayInput == NULL) return 1;

    for (int i = 0; i < 5; i++) {
        ArrayInput[i] = (int*)calloc(5, sizeof(int));
    
        if(ArrayInput[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(ArrayInput[j]);
            }
            
            free(ArrayInput);
            return 1;
        }
    
        for (int j = 0; j < 5; j++) {
            if(scanf("%d", &ArrayInput[i][j]) != 1) return 1;
        }       
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            SumOfRow += ArrayInput[i][j];
        }
        
        if(SumOfRow % 2 != 0) {
            RowAddress = i;

            break;
        }

        SumOfRow = 0;
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            SumOfColumn += ArrayInput[j][i];
        }
        
        if(SumOfColumn % 2 != 0) {
            ColumnAddress = i;

            break;
        }

        SumOfColumn = 0;
    }

    printf("%d %d", RowAddress, ColumnAddress);

    for (int i = 0; i < 5; i++) {
        free(ArrayInput[i]);
    } free(ArrayInput);
    

    return 0;
}