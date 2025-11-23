#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define UserPasswordPath "Database.txt"

int Login(const char* Username, const char* Password) {
    FILE *fp;
    if((fp = fopen(UserPasswordPath, "r")) == NULL) return -1;

    char Buffer[1025] = { 0 };
    while(fgets(Buffer, 1025, fp) != NULL) {
     SHA256()
    }

    return 0;
}

int Signup(const char* Username, const char* Password) {

}

int Transfer(const int Amount) {

}

int Deposit(const int Amount) {

}

char 
    WelcomeBanner[] = 
    "****     ****                    **   **                ******                      **     **                  \n"
    "/**/**   **/**                   /**  //                /*////**                    /**    //            ***** \n"
    "/**//** ** /**  ******   ****** ****** ** *******       /*   /**   ******   ******* /**  ** ** *******  **///**\n"
    "/** //***  /** //////** //**//*///**/ /**//**///**      /******   //////** //**///**/** ** /**//**///**/**  /**\n"
    "/**  //*   /**  *******  /** /   /**  /** /**  /**      /*//// **  *******  /**  /**/****  /** /**  /**//******\n"
    "/**   /    /** **////**  /**     /**  /** /**  /**      /*    /** **////**  /**  /**/**/** /** /**  /** /////**\n"
    "/**        /**//********/***     //** /** ***  /**      /******* //******** ***  /**/**//**/** ***  /**  ***** \n"
    "//         //  //////// ///       //  // ///   //       ///////   //////// ///   // //  // // ///   //  /////  \n";

int main() {
    int Choice = 1;
    
    while(Choice) {
        system("cls");
        printf("%s\n\n\n\t[1.] Log in\n\t[2.] Sign up\n\n\t[0.] Exit\n\nPlease Select: ", WelcomeBanner);
        if(scanf(" %d", &Choice) != 1 || Choice < 0 || Choice > 3) {
            while(1) {
                system("cls");
                printf("Invalid Input! Please try again.\n\nPress ENTER to continue. ");
                getchar(); getchar();
            
                printf("%s\n\n\n\t[1.] Log in\n\t[2.] Sign up\n\n\t[0.] Exit\n\nPlease Select: ", WelcomeBanner);
                if(scanf(" %d", &Choice) == 1) break;
            }
        }

        switch(Choice) {
            case 1: {
                break;
            }

            case 2: {
                break;
            }

            default: {
                break;
            }
        }
    }

    return 0;
}