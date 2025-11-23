#include <stdio.h>
#include <string.h>
// a 97, e 101, i 105, o 111, u 117
int main() {
char character;
if (scanf("%c", &character) == 1) {
    if (character == 97 || character == 101 || character == 105 || character == 111 || character == 117) printf("yes");
    else printf("no");
} else return 1;
return 0;
}