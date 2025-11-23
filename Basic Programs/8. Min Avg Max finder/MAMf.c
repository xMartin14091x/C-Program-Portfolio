#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Invalid.\nFormat: .\\a.exe 'Numbers'");

        return 1;
    }

    long long int Min = 9223372036854775807, Max = 0, SumOfAll = 0;
    
    for (int i = 1; i < argc; i++) {
        int Buffer = atoi(argv[i]);
        if(Buffer < Min) Min = Buffer;
        if(Buffer > Max) Max = Buffer;

        SumOfAll += Buffer;
    }
    
    printf("Min: %lld\nMax: %lld\nAvg: %lld", Min, Max, SumOfAll / (argc - 1));

    return 0;
}