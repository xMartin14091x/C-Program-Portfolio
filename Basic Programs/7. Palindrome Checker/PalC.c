#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Invalid.\nFormat: .\\a.exe 'String/Number'");

        return 1;
    } else if(strlen(argv[1]) == 1) {
        printf("Is a Palindrome.");

        return 0;
    }

    int lenargv = strlen(argv[1]);
    
    for (int i = 0; i < lenargv / 2; i++) {
        if (argv[1][i] == argv[1][lenargv  - i - 1]) {
            continue;
        } else {
            printf("Not a Palindrome.");
            return 0;
        }
    }
    
    printf("Is a Palindrome.");
    return 0;
}