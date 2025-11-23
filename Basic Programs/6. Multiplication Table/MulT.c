#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc != 2 || atoi(argv[1]) == 0) {
        printf("Invalid.\nFormat: .\\a.exe 'Number'");
        return 1;
    }

    int argvi = atoi(argv[1]);

    for (int i = 1; i < 13; i++) {
        printf("%d x %d = %d\n", argvi, i, argvi * i);
    }
    
    return 0;
}