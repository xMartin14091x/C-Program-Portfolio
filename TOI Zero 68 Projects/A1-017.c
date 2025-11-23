#include <stdio.h>
int main() {
int Year[2], Month[2], Date[2];
if(scanf("%d", &Year[0]) == 1 && scanf("%d", &Month[0]) == 1 && scanf("%d", &Date[0]) == 1 && scanf("%d", &Year[1]) == 1 && scanf("%d", &Month[1]) == 1 && scanf("%d", &Date[1]) == 1) {
    Year[0] == Year[1] ? Month[0] == Month[1] ? Date[0] == Date[1] ? printf("0") : Date[0] < Date[1] ? printf("1") : printf("2") : Month[0] < Month[1] ? printf("1") : printf("2") : Year[0] < Year[1] ? printf("1") : printf("2");    
}
return 0;
}