#include <stdio.h>

int main() {
    unsigned int Number[3] = { }, HighestNumber = 0;

    for (int i = 0; i < 3;) {
        if(scanf("%u", &Number[i]) == 1) {
            i++;
        } else break;
    }
    
    for (int i = 0; i < 3; i++) {
        HighestNumber = HighestNumber < Number[i] ? Number[i] : HighestNumber;
    }
    
    printf("%d", HighestNumber);

    return 0;
}