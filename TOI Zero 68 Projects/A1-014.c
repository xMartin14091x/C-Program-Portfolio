#include <stdio.h>

int main() {
    int Number[3] = { }, LowestNumber;

    for (int i = 0; i < 3;) {
        if(scanf("%d", &Number[i]) == 1) {
            i++;
        } else break;
    }
    
    LowestNumber = Number[0];

    for (int i = 0; i < 3; i++) {
        LowestNumber = LowestNumber > Number[i] ? Number[i] : LowestNumber;
    }
    
    printf("%d", LowestNumber);

    return 0;
}