#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int CountOfChar = 0, CountOfError = 0;
    char *StudentID1, *StudentID2;
    if(scanf("%d", &CountOfChar) != 1) return 1;

    StudentID1 = (char*)malloc((CountOfChar + 1) * sizeof(char));
    if(StudentID1 == NULL) return 2;
    StudentID2 = (char*)malloc((CountOfChar + 1) * sizeof(char));
    if(StudentID2 == NULL) {
        free(StudentID1); 
        return 2;
    }

    if(scanf(" %s %s", StudentID1, StudentID2) != 2) return 3;

    for (int i = 0; i < CountOfChar; i++) {
        int StudentID1Int = StudentID1[i] - '0', StudentID2Int = StudentID2[i] - '0';
        StudentID1Int + StudentID2Int != 9 ? CountOfError++ : CountOfError;
    }

    CountOfError == 0 ? printf("YES") : printf("NO %d", CountOfError);

    return 0;
}