#include <stdio.h>

int main() {
    int Number, AmountOf10, AmountOf5, AmountOf2, AmountOf1;
    if (scanf("%d", &Number) == 1) {
        AmountOf10 = Number >= 10 ? Number / 10 : 0;
        Number = AmountOf10 > 0 ? Number - (AmountOf10 * 10) : Number;

        AmountOf5 = Number >= 5 ? Number / 5 : 0;
        Number = AmountOf5 > 0 ? Number - (AmountOf5 * 5) : Number;

        AmountOf2 = Number >= 2 ? Number / 2 : 0;
        Number = AmountOf2 > 0 ? Number - (AmountOf2 * 2) : Number;

        AmountOf1 = Number >= 1 ? Number : 0;

        printf("10 = %d\n5 = %d\n2 = %d\n1 = %d", AmountOf10, AmountOf5,AmountOf2,AmountOf1);
    }
    


    return 0;
}