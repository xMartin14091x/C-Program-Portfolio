#include <stdio.h>
#include <string.h>

int main() {
char FirstName[50] = { }, LastName[50] = { }, Password[20] = { }, AgeChar[5] = { };
if(scanf("%s", FirstName) == 1 && scanf(" %s", LastName) == 1 && scanf(" %s", AgeChar) == 1) {
    if(strlen(FirstName) > 5 && strlen(LastName) > 5) {
        Password[0] = FirstName[0];
        Password[1] = FirstName[1];
        Password[2] = LastName[strlen(LastName) - 1];
        Password[3] = AgeChar[strlen(AgeChar) - 1];
    } else {
        Password[0] = FirstName[0];
        Password[1] = AgeChar[0];
        Password[2] = AgeChar[1];
        Password[3] = LastName[strlen(LastName) - 1];
    }    
} else return 1;

printf("%s", Password);

return 0;
}