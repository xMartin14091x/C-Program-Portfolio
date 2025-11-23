#include <stdio.h>

int main() {
int SafeNumber = 4567, SafeNumberInput;
char SafeCharacter = 'H', SafeCharacterInput;
scanf(" %c %d", &SafeCharacterInput, &SafeNumberInput);
(SafeNumber == SafeNumberInput) && (SafeCharacter == SafeCharacterInput) ? printf("safe unlocked") : (SafeNumber != SafeNumberInput) && (SafeCharacter == SafeCharacterInput) ? printf("safe locked - change digit") : (SafeNumber == SafeNumberInput) && (SafeCharacter != SafeCharacterInput) ? printf("safe locked - change char") : printf("safe locked");
return 0;
}