#include <stdio.h>

// s 115, S 83
int main() {
char Characters[5] = { };
int CharacterCount[5] = { 0 };
scanf("%s", Characters);

for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
        if(Characters[i] == Characters[j]) CharacterCount[i]++;
    }   
}

for (int i = 0; i < 5; i++) {
    CharacterCount[i]++;
}

for (int i = 0; i < 5; i++) {

    if(CharacterCount[i] == 5 - i) { 
        printf("%d%c", CharacterCount[i], Characters[i]); 
        break;
    }

    printf("%d%c", CharacterCount[i], Characters[i]);
    i += CharacterCount[i] - 1;
}

return 0;
}