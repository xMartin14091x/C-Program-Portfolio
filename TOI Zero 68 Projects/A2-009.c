#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int LoopCountOfTeams, CountOfTeams, SpecialPass, **Score, *WinnerCount1, *WinnerCount2;

    if(scanf("%d %d", &CountOfTeams, &SpecialPass) != 2) return 1;

    Score = (int**)calloc(CountOfTeams, sizeof(int*));
    WinnerCount1 = (int*)calloc(CountOfTeams / 2, sizeof(int));
    WinnerCount2 = (int*)calloc(CountOfTeams / 4, sizeof(int));

    if(Score == NULL || WinnerCount1 == NULL || WinnerCount2 == NULL) {
        free(Score);
        free(WinnerCount1);
        free(WinnerCount2);
        return 2;
    }

    for (int i = 0; i < CountOfTeams; i++) {
        Score[i] = (int*)calloc(CountOfTeams, sizeof(int));

        if(Score[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(Score[j]);
            }
            
            free(Score);
            return 3;
        }
    }

    for (int i = 0; i < CountOfTeams; i++) {
        for (int j = 0; j < CountOfTeams; j++) {
            scanf("%d", &Score[i][j]);
        }
    }  

    for (int i = 0; i < CountOfTeams; i += 2) {
        if(((i + 1 == SpecialPass || i + 2 == SpecialPass) && SpecialPass > 0) && Score[i][i + 1] != SpecialPass) {
            WinnerCount1[i / 2] = SpecialPass;

            SpecialPass = 0;
        } else WinnerCount1[i / 2] = Score[i][i + 1];
    }

    int *Next = WinnerCount2, *Current = WinnerCount1, WhileLoopCountOfTeam = CountOfTeams / 2, WhileLoopCounter = 2;    
    while(WhileLoopCountOfTeam > 1) {
        for (int i = 0; i < WhileLoopCountOfTeam / 2; i++) {

            if(((Current[i * 2] == SpecialPass || Current[i * 2 + 1] == SpecialPass) && SpecialPass > 0) && Score[Current[i * 2] - 1][Current[i * 2 + 1] - 1] != SpecialPass) {
                Next[i] = SpecialPass;
                
                SpecialPass = 0;
            } else Next[i] = Score[Current[i * 2] - 1][Current[i * 2 + 1] - 1];
        }
        
        
        WhileLoopCountOfTeam /= 2;
        WhileLoopCounter++;

        int *temp = Next;
        Next = Current;
        Current = temp;
    }
    
    printf("%d", Current[0]);

    for (int i = 0; i < CountOfTeams; i++) {
        free(Score[i]);
    }

    free(Score);
    free(WinnerCount1);
    free(WinnerCount2);

    return 0;
}