#include <stdio.h>
int main() {
int DateMonth[2];
if(scanf("%d", &DateMonth[0]) == 1 && scanf("%d", &DateMonth[1]) == 1) {
    (DateMonth[0] >= 22 && DateMonth[1] == 12) || (DateMonth[0] <= 19 && DateMonth[1] == 1) ? printf("capricorn") : 
    (DateMonth[0] >= 20 && DateMonth[1] == 1) || (DateMonth[0] <= 18 && DateMonth[1] == 2) ? printf("aquarius") :
    (DateMonth[0] >= 19 && DateMonth[1] == 2) || (DateMonth[0] <= 20 && DateMonth[1] == 3) ? printf("pisces") :
    (DateMonth[0] >= 21 && DateMonth[1] == 3) || (DateMonth[0] <= 19 && DateMonth[1] == 4) ? printf("aries") :
    (DateMonth[0] >= 20 && DateMonth[1] == 4) || (DateMonth[0] <= 20 && DateMonth[1] == 5) ? printf("taurus") :
    (DateMonth[0] >= 21 && DateMonth[1] == 5) || (DateMonth[0] <= 21 && DateMonth[1] == 6) ? printf("gemini") :
    (DateMonth[0] >= 22 && DateMonth[1] == 6) || (DateMonth[0] <= 22 && DateMonth[1] == 7) ? printf("cancer") :
    (DateMonth[0] >= 23 && DateMonth[1] == 7) || (DateMonth[0] <= 22 && DateMonth[1] == 8) ? printf("leo") :
    (DateMonth[0] >= 23 && DateMonth[1] == 8) || (DateMonth[0] <= 22 && DateMonth[1] == 9) ? printf("virgo") :
    (DateMonth[0] >= 23 && DateMonth[1] == 9) || (DateMonth[0] <= 23 && DateMonth[1] == 10) ? printf("libra") :
    (DateMonth[0] >= 24 && DateMonth[1] == 10) || (DateMonth[0] <= 21 && DateMonth[1] == 11) ? printf("scorpio") :
    (DateMonth[0] >= 22 && DateMonth[1] == 11) || (DateMonth[0] <= 21 && DateMonth[1] == 12) ? printf("sagittarius") : printf("none");
} else return 1;
return 0;
}