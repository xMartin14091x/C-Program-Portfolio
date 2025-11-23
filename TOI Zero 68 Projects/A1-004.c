#include <stdio.h>

int main() {
    int Score[3] = { }, SumOfScore;

    for (int i = 0; i < 3;) {
        if(scanf("%d", &Score[i]) == 1) {
            i++;
        } else return 1;
    }
    
    if(Score[0] < 5 || Score[1] < 20 || Score[2] < 25) {
        printf("fail");
    } else printf("pass");

    return 0;
}