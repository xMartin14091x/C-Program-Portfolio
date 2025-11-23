#include <stdio.h>
int main() {
int Input;
if(scanf("%d", &Input) == 1) {
    if(Input % 4 == 0 && Input % 100 != 0 || Input == 1500) printf("yes");
    else if(Input % 400 == 0) printf("yes");
    else printf("no");
} else return 1;
return 0;
}