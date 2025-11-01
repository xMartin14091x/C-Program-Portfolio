#include <stdio.h>
#include <stdlib.h>

char ConvertableTempUnit[] = {'C', 'c', 'F', 'f', 'K', 'k', 'R', 'r'};

double ToCelcius(char FromUnit, double Val) {
    if(FromUnit == 'C' || FromUnit == 'c') return Val;

    if(FromUnit == 'F' || FromUnit == 'f') return (Val - 32) * 5 / 9;
    else if(FromUnit == 'K' || FromUnit == 'k') return (Val - 273);
    else if(FromUnit == 'R' || FromUnit == 'r') return (Val * 5) / 4;
    else return 0;
}

double FromCelcius(char ToUnit, double Val) {
    if(ToUnit == 'C' || ToUnit == 'c') return Val;

    if(ToUnit == 'F' || ToUnit == 'f') return (Val / 5) * 9 + 32;
    else if(ToUnit == 'K' || ToUnit == 'k') return (Val + 273);
    else if(ToUnit == 'R' || ToUnit == 'r') return (Val / 5) * 4;
    else return 0;
}

int main(int argc, char *argv[]) {
    int isCTU1 = -1, isCTU2 = -1;
    double InputVal;

    if(argc != 4) {
        printf("Invalid Input! (From Unit, To Unit, Temp)");
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        if(argv[1][0] == ConvertableTempUnit[i] && isCTU1 == -1) isCTU1 = i;
        if(argv[2][0] == ConvertableTempUnit[i] && isCTU2 == -1) isCTU2 = i;
    
        if(isCTU1 != -1 && isCTU2 != -1) break;
    }

    if(isCTU1 == -1 || isCTU2 == -1) {
        printf("Invalid Temp! (C, F, K, R)");
        return 1;
    }

    InputVal = atof(argv[3]);
    if(InputVal == 0) {
        printf("Invalid Temp input!");
        return 1;
    }

    printf("Answer: %.2lf", FromCelcius(argv[2][0] ,ToCelcius(argv[1][0], InputVal)));

    return 0;
}