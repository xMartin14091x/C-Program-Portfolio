#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const int SizeSmallU = 83, SizeMediumU = 77, SizeLargeU = 76, TypeOriginalU = 82, TypeTomyumU = 84, AddPorkU = 80, AddEggU = 69, NoTopingU = 78;
    int PriceToPay = 0, CountOfToping;
    char NoodleSize, NoodleType, NoodleToping;

    if(scanf("%c %c %c", &NoodleSize, &NoodleType, &NoodleToping) != 3) return 1;
    if(NoodleToping != NoTopingU) if(scanf("%d", &CountOfToping) != 1) { return 2; }    
    
    PriceToPay = (NoodleSize == SizeSmallU) && (NoodleType == TypeOriginalU) ? PriceToPay += 60 : 
    (NoodleSize == SizeSmallU) && (NoodleType == TypeTomyumU) ? PriceToPay += 80 :

    (NoodleSize == SizeMediumU) && (NoodleType == TypeOriginalU) ? PriceToPay += 80 :
    (NoodleSize == SizeMediumU) && (NoodleType == TypeTomyumU) ? PriceToPay += 100 :

    (NoodleSize == SizeLargeU) && (NoodleType == TypeOriginalU) ? PriceToPay += 100 :
    (NoodleSize == SizeLargeU) && (NoodleType == TypeTomyumU) ? PriceToPay += 120 : 
    printf("Error Teritary Operation PriceToPay 1");

    PriceToPay = NoodleToping == NoTopingU ? PriceToPay : 
    NoodleToping == AddPorkU ? PriceToPay += 15 * CountOfToping : 
    NoodleToping == AddEggU ? PriceToPay += 10 * CountOfToping :
    printf("Error Teritary Operation PriceToPay 2");

    printf("%d", PriceToPay);

    return 0;
}