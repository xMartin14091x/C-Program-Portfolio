#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int HeightOfTriangle;
    if(scanf("%d", &HeightOfTriangle) != 1) return 1;

    for (int i = 0; i < HeightOfTriangle; i++) {
        for (int j = 0; j < i + 1; j++) {
            if(j == 0 || j == i || i == HeightOfTriangle - 1) {
                printf("0 ");
            } else printf("1 ");
        }
        
        printf("\n");
    }
    

    return 0;
}