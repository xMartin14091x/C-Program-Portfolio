#include <stdio.h>

int main() {
int InputNumberInt1, InputNumberInt2, Answer;
char InputNumberChar[3] = { }, ProcessedInputNumberChar[3] = { }, Operation;

if((scanf(" %s", InputNumberChar) == 1) && scanf(" %c", &Operation)) {
    ProcessedInputNumberChar[0] = InputNumberChar[1];
    ProcessedInputNumberChar[1] = InputNumberChar[0];

    sscanf(InputNumberChar, "%d", &InputNumberInt1);
    sscanf(ProcessedInputNumberChar, "%d", &InputNumberInt2);
    

    if(Operation == '+') Answer = InputNumberInt1 + InputNumberInt2;
    else if(Operation == '*') Answer = InputNumberInt2 * InputNumberInt1;
    
    printf("%d %c %d = %d", InputNumberInt1, Operation, InputNumberInt2, Answer);
} else return 1;

return 0;
}