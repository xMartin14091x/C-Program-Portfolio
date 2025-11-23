#include <stdio.h>
#include <string.h>

int main() {
char character[300] = { };
if (scanf("%s", character) == 1) {
    if (strlen(character) == 13) printf("yes");
    else printf("no");
} else return 1;
return 0;
}