#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ExchangeRateUSDTHB 32

struct WholeCost {
    double THB;
    double USD1;
    double USD2;
};

struct Investment {
    char Name[51];
    
    double Percentage;
    double THBPrice;
    double USD1Price;
    double USD2Price;

    int DCATimeframe;
    int PrimaryAccount;
    int SecondaryAccount;
    int TeritaryAccount;
};

char 
MainBanner[] = 
    " **                                     **                                  **  \n"
    "/**                                    /**                                 /**  \n"
    "/** *******  **    **  *****   ****** ****** **********   *****  *******  ******\n"
    "/**//**///**/**   /** **///** **//// ///**/ //**//**//** **///**//**///**///**/ \n"
    "/** /**  /**//** /** /*******//*****   /**   /** /** /**/******* /**  /**  /**  \n"
    "/** /**  /** //****  /**////  /////**  /**   /** /** /**/**////  /**  /**  /**  \n"
    "/** ***  /**  //**   //****** ******   //**  *** /** /**//****** ***  /**  //** \n"
    "// ///   //    //     ////// //////     //  ///  //  //  ////// ///   //    //  \n\n"
    "   ******             **                  **             **                     \n"
    "  **////**           /**                 /**            /**                     \n"
    " **    //   ******   /**  *****  **   ** /**  ******   ******  ******  ******   \n"
    "/**        //////**  /** **///**/**  /** /** //////** ///**/  **////**//**//*   \n"
    "/**         *******  /**/**  // /**  /** /**  *******   /**  /**   /** /** /    \n"
    "//**    ** **////**  /**/**   **/**  /** /** **////**   /**  /**   /** /**      \n"
    " //****** //******** ***//***** //****** ***//********  //** //****** /***      \n"
    "  //////   //////// ///  /////   ////// ///  ////////    //   //////  ///       ",

AddInvBanner[] = 
    "     **          **      ** **                                                          \n" 
    "    ****        /**     /**//            *****                                          \n"
    "   **//**       /**     /** ** *******  **///**                                         \n"
    "  **  //**   ******  ******/**//**///**/**  /**                                         \n"
    " ********** **///** **///**/** /**  /**//******                                         \n"
    "/**//////**/**  /**/**  /**/** /**  /** /////**                                         \n"
    "/**     /**//******//******/** ***  /**  *****                                          \n"
    "//      //  //////  ////// // ///   //  /////                                           \n\n"
    " **                                     **                                  **          \n"
    "/**                                    /**                                 /**          \n"
    "/** *******  **    **  *****   ****** ****** **********   *****  *******  ******  ******\n"
    "/**//**///**/**   /** **///** **//// ///**/ //**//**//** **///**//**///**///**/  **//// \n"
    "/** /**  /**//** /** /*******//*****   /**   /** /** /**/******* /**  /**  /**  //***** \n"
    "/** /**  /** //****  /**////  /////**  /**   /** /** /**/**////  /**  /**  /**   /////**\n"
    "/** ***  /**  //**   //****** ******   //**  *** /** /**//****** ***  /**  //**  ****** \n"
    "// ///   //    //     ////// //////     //  ///  //  //  ////// ///   //    //  //////  ",

EditInvBanner[] =
    " ********      ** **   **                                                       \n"
    "/**/////      /**//   /**                                                       \n"
    "/**           /** ** ******                                                     \n"
    "/*******   ******/**///**/                                                      \n"
    "/**////   **///**/**  /**                                                       \n"
    "/**      /**  /**/**  /**                                                       \n"
    "/********//******/**  //**                                                      \n"
    "////////  ////// //    //                                                       \n\n"
    " **                                     **                                  **  \n"
    "/**                                    /**                                 /**  \n"
    "/** *******  **    **  *****   ****** ****** **********   *****  *******  ******\n"
    "/**//**///**/**   /** **///** **//// ///**/ //**//**//** **///**//**///**///**/ \n"
    "/** /**  /**//** /** /*******//*****   /**   /** /** /**/******* /**  /**  /**  \n"
    "/** /**  /** //****  /**////  /////**  /**   /** /** /**/**////  /**  /**  /**  \n"
    "/** ***  /**  //**   //****** ******   //**  *** /** /**//****** ***  /**  //** \n"
    "// ///   //    //     ////// //////     //  ///  //  //  ////// ///   //    //  \n";

int main() {
    struct WholeCost wc;
    struct Investment *sIp = (struct Investment*)calloc(1, sizeof(struct Investment)), *BsIp;
    if(sIp == NULL) {
        printf("sIp memory allocation failed.\n");
        strerror(errno);

        return 1;
    }

    char InvestmentBuffer[50001] = { }, AppendBuffer[10001] = { };

    system("cls");

    printf("%s\n\nCalculator for calculating the value of the followings:\n", MainBanner);
    printf("\n\t[1] Amount of Money needed for an Investment at a specific Percentage of the Cost");
    printf("\n\t[2] To Calculate the amount of time needed to DCA the Investment");
    printf("\n\t[3] To gives out a .txt file that contains a formated Investment Calculator's Output");
    printf("\n\nNote: The calculator supports 3 accounts for Cost. 1 THB Account, and 2 USD Account");
    printf("\n\nPress ENTER to continue: ");
    getchar();

    THBSelection:
        system("cls");
        printf("%s\n\nPlease select the amount of money in THB Account (None / Not-Usable = 0): ", MainBanner);
        if(scanf(" %lf", &wc.THB) != 1 || wc.THB < 0) {
            printf("Invalid Input! Please try again.\nPress ENTER to try again.");
            while(getchar() != '\n');
            while(getchar() != '\n');

            goto THBSelection;
        }

    USD1Selection:
        system("cls");
        printf("%s\n\nPlease select the amount of money in USD1 Account: (None / Not-Usable = 0): ", MainBanner);
        if(scanf(" %lf", &wc.USD1) != 1 || wc.USD1 < 0) {
            printf("Invalid Input! Please try again.\nPress ENTER to try again.");
            while(getchar() != '\n');
            while(getchar() != '\n');

            goto USD1Selection;
        }

    USD2Selection:
        system("cls");
        printf("%s\n\nPlease select the amount of money in USD2 Account: (None / Not-Usable = 0): ", MainBanner);
        if(scanf(" %lf", &wc.USD2) != 1 || wc.USD2 < 0) {
            printf("Invalid Input! Please try again.\nPress ENTER to try again.");
            while(getchar() != '\n');
            while(getchar() != '\n');

            goto USD2Selection;
        }

    if(wc.THB == 0 && wc.USD1 == 0 && wc.USD2 == 0) {
        printf("Invalid Input for Cost! Please try again.\nPress ENTER to try again.");
        while(getchar() != '\n');
        while(getchar() != '\n');
        
        goto THBSelection;
    }

    static int IterationC = 1;

    AddInvestment:
        system("cls");

        if(IterationC > 1) {
            BsIp = realloc(sIp, IterationC * sizeof(struct Investment));
            sIp = BsIp;

            sIp[IterationC - 1].DCATimeframe = 0;
            sIp[IterationC - 1].Name[0] = '\0';
            sIp[IterationC - 1].Percentage = 0.00;
            sIp[IterationC - 1].THBPrice = 0.00;
            sIp[IterationC - 1].USD1Price = 0.00;
            sIp[IterationC - 1].USD2Price = 0.00;
            sIp[IterationC - 1].PrimaryAccount = 0;

            printf("%s\n\nPlease enter what is the name for the investment (Enter 0 to stop adding): ", AddInvBanner);
        } else printf("%s\n\nPlease enter what is the name for the investment: ", AddInvBanner);

        if(scanf(" %50s", sIp[IterationC - 1].Name) <= 0 || sIp[IterationC - 1].Name == NULL) {
            printf("Error! Failed to assign value to sIp element %d.\n", IterationC - 1);
            
            goto FailedFree;
        }
 
        if(sIp[IterationC - 1].Name[0] == '0') goto PercentCheck;

        AddInvestmentPercentage:
            printf("\nEnter how much percent of the overall cost would you like to use for this Investment: ");
            if(scanf(" %lf", &sIp[IterationC - 1].Percentage) != 1 || sIp[IterationC - 1].Percentage > 100 || sIp[IterationC - 1].Percentage < 0) {
                printf("Invalid Input! Please try again.\nPress ENTER to try again.");
                while(getchar() != '\n');
                while(getchar() != '\n');

                goto AddInvestmentPercentage;
            }

        AddInvestmentAccAssign:
            printf("\nEnter which account can this investment use (Ex. 3 1 2 for the program to use primary USD2, secondary THB, teritary USD1): ");
            if(scanf(" %d %d %d", &sIp[IterationC - 1].PrimaryAccount, &sIp[IterationC - 1].SecondaryAccount, &sIp[IterationC - 1].TeritaryAccount) != 3 || sIp[IterationC - 1].PrimaryAccount < 1 || sIp[IterationC - 1].PrimaryAccount > 3 || sIp[IterationC - 1].SecondaryAccount < 1 || sIp[IterationC - 1].SecondaryAccount > 3 || sIp[IterationC - 1].TeritaryAccount < 1 || sIp[IterationC - 1].TeritaryAccount > 3) {
                printf("Invalid Input! Please try again.\nPress ENTER to try again.");
                while(getchar() != '\n');
                while(getchar() != '\n');

                goto AddInvestmentAccAssign;
            }
        
        AddInvestmentDCATimeframeAssign:
            printf("\nEnter how long would you like to DCA the Investment (In week): ");
            if(scanf(" %d", &sIp[IterationC - 1].DCATimeframe) != 1 || sIp[IterationC - 1].DCATimeframe <= 0) {
                printf("Invalid Input! Please try again.\nPress ENTER to try again.");
                while(getchar() != '\n');
                while(getchar() != '\n');

                goto AddInvestmentDCATimeframeAssign;
            }
        
        IterationC++;

        goto AddInvestment;

    PercentCheck:
        double Sum = 0;
        for (int i = 0; i < IterationC; i++) {
            Sum += sIp[i].Percentage;
        }

        if(Sum > 100.00) {
            printf("Invalid Input for Percentage (More than 100%)! Please try again.\nPress ENTER to try again.");
            while(getchar() != '\n');
            while(getchar() != '\n');

            IterationC = 1;


            goto AddInvestment;
        } else goto Calculation;

    Calculation:
        double WholeAmountTHB = (wc.USD1 + wc.USD2) * ExchangeRateUSDTHB + wc.THB, WholeAmountUSD = (wc.USD1 + wc.USD2) + wc.THB / ExchangeRateUSDTHB;
        double AvailUSD1 = wc.USD1, AvailUSD2 = wc.USD2, AvailUSD = (wc.USD1 + wc.USD2), AvailTHB = wc.THB;
        
        system("cls");
        printf("%s\n\nWhole USD: %.2lf Whole THB: %.2lf\nWhole Amount THB: %.2lf\nWhole Amount USD: %.2lf\n", MainBanner, (wc.USD1 + wc.USD2), wc.THB, WholeAmountTHB, WholeAmountUSD);

        sprintf(InvestmentBuffer, "Whole USD: %.2lf Whole THB: %.2lf\nWhole Amount THB: %.2lf\nWhole Amount USD: %.2lf\n", (wc.USD1 + wc.USD2), wc.THB, WholeAmountTHB, WholeAmountUSD);

        for (int i = 0; i < IterationC; i++) {
            switch (sIp[i].PrimaryAccount) {
            case 1:
                if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailTHB / ExchangeRateUSDTHB) {
                    sIp[i].THBPrice = sIp[i].Percentage / 100 * WholeAmountUSD * ExchangeRateUSDTHB;

                    AvailTHB -= sIp[i].THBPrice;
                } else {
                    switch (sIp[i].SecondaryAccount) {
                    case 2:
                        if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD1 + AvailTHB / ExchangeRateUSDTHB) {
                            sIp[i].THBPrice = AvailTHB;
                            sIp[i].USD1Price = (sIp[i].Percentage / 100 * WholeAmountUSD) - (AvailTHB / ExchangeRateUSDTHB);
                        
                            AvailTHB = 0;
                            AvailUSD1 -= sIp[i].USD1Price;
                        } else {
                            sIp[i].THBPrice = AvailTHB;
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].USD2Price = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD1 - (AvailTHB / ExchangeRateUSDTHB));
                            
                            AvailUSD1 = 0;
                            AvailTHB = 0;
                            AvailUSD2 -= sIp[i].USD2Price;
                        }
                    
                        break;

                    case 3:
                        if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD2 + AvailTHB * ExchangeRateUSDTHB) {
                            sIp[i].THBPrice = AvailTHB;
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].USD2Price = (sIp[i].Percentage / 100 * WholeAmountUSD) - (AvailTHB / ExchangeRateUSDTHB);
                            
                            AvailTHB = 0;
                            AvailUSD1 = 0;
                            AvailUSD2 -= sIp[i].USD2Price;
                        } else {
                            sIp[i].THBPrice = AvailTHB;
                            sIp[i].USD2Price = AvailUSD2;
                            sIp[i].USD1Price = (sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD2 - (AvailTHB / ExchangeRateUSDTHB);

                            AvailTHB = 0;
                            AvailUSD2 = 0;
                            AvailUSD1 -= sIp[i].USD1Price;
                        }

                        break;
                    
                    default:
                        printf("Invalid Secondaru Account Inputted! Please try again.");
                        goto FailedFree;

                        break;
                    }
                }

                printf("\nName: %s (%.2lf %%)\nAmount Invested: %.2lfTHB %.2lf$ %.2lf$\nDCA Amount: %.2lfTHB %.2lf$ %.2lf$ (For %d Week(s))\n", sIp[i].Name, sIp[i].Percentage, sIp[i].THBPrice, sIp[i].USD1Price, sIp[i].USD2Price, sIp[i].THBPrice / sIp[i].DCATimeframe, sIp[i].USD1Price / sIp[i].DCATimeframe, sIp[i].USD2Price / sIp[i].DCATimeframe, sIp[i].DCATimeframe);
                sprintf(AppendBuffer, "\nName: %s (%.2lf Percent)\nAmount Invested: %.2lfTHB %.2lf$ %.2lf$\nDCA Amount: %.2lfTHB %.2lf$ %.2lf$ (For %d Week(s))\n", sIp[i].Name, sIp[i].Percentage, sIp[i].THBPrice, sIp[i].USD1Price, sIp[i].USD2Price, sIp[i].THBPrice / sIp[i].DCATimeframe, sIp[i].USD1Price / sIp[i].DCATimeframe, sIp[i].USD2Price / sIp[i].DCATimeframe, sIp[i].DCATimeframe);

                strcat(InvestmentBuffer, AppendBuffer);

                break;
            
            case 2:
                if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD1) {
                    sIp[i].USD1Price = sIp[i].Percentage / 100 * WholeAmountUSD;

                    AvailUSD1 -= sIp[i].USD1Price;
                } else {
                    switch (sIp[i].SecondaryAccount) {
                    case 1:
                        if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD1 + (AvailTHB / ExchangeRateUSDTHB)) {
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].THBPrice = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD1) * ExchangeRateUSDTHB;

                            AvailUSD1 = 0;
                            AvailTHB -= sIp[i].THBPrice;
                        } else {
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].THBPrice = AvailTHB;
                            sIp[i].USD2Price = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD1 - (AvailTHB / ExchangeRateUSDTHB));
                            
                            AvailUSD1 = 0;
                            AvailTHB = 0;
                            AvailUSD2 -= sIp[i].USD2Price;
                        }

                        break;
                    
                    case 3:
                        if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD1 + AvailUSD2) {
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].USD2Price = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD1);

                            AvailUSD1 = 0;
                            AvailUSD2 -= sIp[i].USD2Price;
                        } else {
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].USD2Price = AvailUSD2;
                            sIp[i].THBPrice = ExchangeRateUSDTHB * ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD1 - AvailUSD2);

                            AvailUSD1 = 0;
                            AvailUSD2 = 0;
                            AvailTHB -= sIp[i].THBPrice;
                        }

                        break;

                    default:
                        printf("Invalid Secondaru Account Inputted! Please try again.");
                        goto FailedFree;

                        break;
                    }
                }

                printf("\nName: %s (%.2lf %%)\nAmount Invested: %.2lfTHB %.2lf$ %.2lf$\nDCA Amount: %.2lfTHB %.2lf$ %.2lf$ (For %d Week(s))\n", sIp[i].Name, sIp[i].Percentage, sIp[i].THBPrice, sIp[i].USD1Price, sIp[i].USD2Price, sIp[i].THBPrice / sIp[i].DCATimeframe, sIp[i].USD1Price / sIp[i].DCATimeframe, sIp[i].USD2Price / sIp[i].DCATimeframe, sIp[i].DCATimeframe);
                sprintf(AppendBuffer, "\nName: %s (%.2lf Percent)\nAmount Invested: %.2lfTHB %.2lf$ %.2lf$\nDCA Amount: %.2lfTHB %.2lf$ %.2lf$ (For %d Week(s))\n", sIp[i].Name, sIp[i].Percentage, sIp[i].THBPrice, sIp[i].USD1Price, sIp[i].USD2Price, sIp[i].THBPrice / sIp[i].DCATimeframe, sIp[i].USD1Price / sIp[i].DCATimeframe, sIp[i].USD2Price / sIp[i].DCATimeframe, sIp[i].DCATimeframe);

                strcat(InvestmentBuffer, AppendBuffer);

                break;

            case 3:
                if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD2) {
                    sIp[i].USD2Price = sIp[i].Percentage / 100 * WholeAmountUSD;

                    AvailUSD2 -= sIp[i].USD1Price;
                } else {
                    switch (sIp[i].SecondaryAccount) {
                    case 1:
                        if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD2 + (AvailTHB / ExchangeRateUSDTHB)) {
                            sIp[i].USD2Price = AvailUSD2;
                            sIp[i].THBPrice = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD2) * ExchangeRateUSDTHB;

                            AvailUSD2 = 0;
                            AvailTHB -= sIp[i].THBPrice;
                        } else {
                            sIp[i].USD2Price = AvailUSD2;
                            sIp[i].THBPrice = AvailTHB;
                            sIp[i].USD1Price = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD2 - (AvailTHB / ExchangeRateUSDTHB));
                            
                            AvailTHB = 0;
                            AvailUSD2 = 0;
                            AvailUSD1 -= sIp[i].USD1Price;
                            
                        }

                        break;
                    
                    case 2:
                        if(sIp[i].Percentage / 100 * WholeAmountUSD <= AvailUSD1 + AvailUSD2) {
                            sIp[i].USD2Price = AvailUSD2;
                            sIp[i].USD1Price = ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD2);

                            AvailUSD2 = 0;
                            AvailUSD1 -= sIp[i].USD1Price;
                        } else {
                            sIp[i].USD1Price = AvailUSD1;
                            sIp[i].USD2Price = AvailUSD2;
                            sIp[i].THBPrice = ExchangeRateUSDTHB * ((sIp[i].Percentage / 100 * WholeAmountUSD) - AvailUSD1 - AvailUSD2);

                            AvailUSD1 = 0;
                            AvailUSD2 = 0;
                            AvailTHB -= sIp[i].THBPrice;
                        }

                        break;

                    default:
                        printf("Invalid Secondary Account Inputted! Please try again.");
                        goto FailedFree;

                        break;

                    }

                printf("\nName: %s (%.2lf %%)\nAmount Invested: %.2lfTHB %.2lf$ %.2lf$\nDCA Amount: %.2lfTHB %.2lf$ %.2lf$ (For %d Week(s))\n", sIp[i].Name, sIp[i].Percentage, sIp[i].THBPrice, sIp[i].USD1Price, sIp[i].USD2Price, sIp[i].THBPrice / sIp[i].DCATimeframe, sIp[i].USD1Price / sIp[i].DCATimeframe, sIp[i].USD2Price / sIp[i].DCATimeframe, sIp[i].DCATimeframe);
                sprintf(AppendBuffer, "\nName: %s (%.2lf Percent)\nAmount Invested: %.2lfTHB %.2lf$ %.2lf$\nDCA Amount: %.2lfTHB %.2lf$ %.2lf$ (For %d Week(s))\n", sIp[i].Name, sIp[i].Percentage, sIp[i].THBPrice, sIp[i].USD1Price, sIp[i].USD2Price, sIp[i].THBPrice / sIp[i].DCATimeframe, sIp[i].USD1Price / sIp[i].DCATimeframe, sIp[i].USD2Price / sIp[i].DCATimeframe, sIp[i].DCATimeframe);
                
                strcat(InvestmentBuffer, AppendBuffer);
                    
                break;
            }

            default:
                
                break;
        }
    }

    EditConfirmation: 
        char placeholder1 = '\0';
        printf("\n\nWould you like to edit anything? (y/n): ");
        scanf(" %c", &placeholder1);

        if(placeholder1 != 'y' && placeholder1 != 'Y' && placeholder1 != 'n' && placeholder1 != 'N') goto EditConfirmation;
        else if(placeholder1 == 'y' || placeholder1 == 'Y') {
            int EditInvNumber, EditElememtNumber;

            SelectElement: 
                system("cls");
                printf("%s\n\nSelections:\n", EditInvBanner);
                for (int i = 0; i < IterationC - 1; i++) {
                    printf("\n\t[%d] %s", i + 1, sIp[i].Name);
                }

                printf("\n\nPlease select one to edit: ");
                if(scanf(" %d", &EditInvNumber) != 1) {
                    printf("Invalid Input! Please try again.\nPress ENTER to try again.");
                    while(getchar() != '\n');
                    while(getchar() != '\n');

                    goto EditConfirmation;
                } EditInvNumber -= 1;

                // WIP!
                SelectEditElement:
                    system("cls");
                    printf("%s\n\nWhat would you like to edit?\n\n\t[1] Name: %s\n\t[2] Percentage: %.2lf\n\t[3] Account choice: %d %d %d\n\t[4] DCA Timeframe: \n\n\t[0] Back\n\nPlease Select your choice: ", EditInvBanner, sIp[EditInvNumber].Name, sIp[EditInvNumber].Percentage, sIp[EditInvNumber].DCATimeframe, sIp[EditInvNumber].PrimaryAccount, sIp[EditInvNumber].SecondaryAccount, sIp[EditInvNumber].TeritaryAccount);
                    if(scanf(" %d", &EditElememtNumber) != 1 || EditElememtNumber < 0 || EditElememtNumber > 3) {
                        printf("Invliad Choice!\nPress ENTER to try again. ");
                        while(getchar() != '\n');
                        while(getchar() != '\n');

                        goto SelectEditElement;
                    } else if(EditElememtNumber == 0) goto SelectElement;
                    
                    switch (EditElememtNumber) {
                    case 1:
                        char CBuffer[51] = { };
                        
                        system("cls");
                        printf("%s\n\nPlease enter the new name for %s: ", EditInvBanner, sIp[EditInvNumber].Name);
                        if(scanf(" %50s", CBuffer) != 1) {
                            printf("Invalid Input! Press ENTER to try again. ");
                            
                            while(getchar() != '\n');
                            while(getchar() != '\n');

                            goto SelectEditElement;
                        }

                        if(strcmp(strcpy(sIp[EditInvNumber].Name, CBuffer), CBuffer)) {
                            printf("Error with strcpy command! Please try again!");
                            goto FailedFree;
                        }
                        
                        goto Calculation;

                        break;
                    
                    case 2:
                        double DBuffer;

                        system("cls");
                        printf("%s\n\nPlease enter the new Percentage value: ", EditInvBanner);
                        if(scanf(" %lf", &DBuffer) != 1 || DBuffer <= 0 || DBuffer > 100) {
                            printf("Invalid Input! Press ENTER to try again. ");
                            
                            while(getchar() != '\n');
                            while(getchar() != '\n');

                            goto SelectEditElement;
                        }

                        sIp[EditInvNumber].Percentage = DBuffer;
                        
                        double Sum = 0;
                        for (int i = 0; i < IterationC; i++) {
                            Sum += sIp[i].Percentage;
                        }
                    
                        if(Sum > 100.00) {
                            printf("Invalid Input for Percentage (More than 100%)! Please try again.\nPress ENTER to try again.");
                            while(getchar() != '\n');
                            while(getchar() != '\n');
                        
                            IterationC = 1;
                        
                        
                            goto AddInvestment;
                        } else goto Calculation;
                        
                        break;
                    
                    case 3:
                        int Pri, Sec, Ter;

                        printf("Please enter the new value for Primary, Secondary, and Teritary bank account (1 THB Account, 2 USD1 Account, 3 USD2 Account): ");
                        if(scanf(" %d %d %d", &Pri, &Sec, &Ter) != 3 || Pri == Sec || Pri == Ter || Sec == Ter || Pri <= 0 || Pri > 3 || Sec <= 0 || Sec > 3 || Ter <= 0 || Ter > 3) {
                            printf("Invalid Input! Press ENTER to try again. ");
                            
                            while(getchar() != '\n');
                            while(getchar() != '\n');

                            goto SelectEditElement;
                        }

                        sIp[EditInvNumber].PrimaryAccount = Pri;
                        sIp[EditInvNumber].SecondaryAccount = Sec;
                        sIp[EditInvNumber].TeritaryAccount = Ter;

                        goto Calculation;
                        break;

                    case 4:
                        int DCATimeframe;

                        printf("Please enter the new DCA timeframe value: ");
                        if(scanf(" %d", DCATimeframe) != 1 || DCATimeframe <= 0) {
                            printf("Invalid Input! Press ENTER to try again. ");
                            
                            while(getchar() != '\n');
                            while(getchar() != '\n');

                            goto SelectEditElement;
                        }

                        sIp[EditInvNumber].DCATimeframe = DCATimeframe;

                        goto Calculation;

                    default:
                        break;
                    }
        }
        
    FILE *fp = fopen("InvestmentPlan.txt", "w");
    if(fp == NULL) {
        printf("Error opening file for write (Investment Plan.txt) please try again.");
        goto FailedFree;
    }
    
    fprintf(fp, InvestmentBuffer);

    fclose(fp);

    free(sIp);

    return 0;
    
    FailedFree:
        strerror(errno);

        free(sIp);
        
        return 1;
}