#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CompareNumber(const int InputNumberLoop, const int OutputNumberLoop[], const int SizeOfOutputNumberLoop) {
    for (int i = 0; i < SizeOfOutputNumberLoop; i++) {
        if(InputNumberLoop == OutputNumberLoop[i]) return 0;      
    }

    return 1;
}

int main() {
    int InputNumber[10] = { 0 }, OutputNumber[10] = { 0 }, SizeOfOutputNumber = 0;

    for (int i = 0; i < 10; i++) {
        if(scanf("%d", &InputNumber[i]) != 1) return 1;
    }
    
    for (int i = 0; i < 10; i++) {
        if (CompareNumber(InputNumber[i], OutputNumber, i)) {
            OutputNumber[SizeOfOutputNumber] = InputNumber[i];
            SizeOfOutputNumber++;
        }        
    }
    
    for (int i = 0; i < SizeOfOutputNumber; i++) {
        printf("%d ", OutputNumber[i]);
    } 
    
    return 0;
}