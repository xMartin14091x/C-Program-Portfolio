#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define ERR_NULL_POINTER -1
#define ERR_INVALID_DIRECTORY -2
#define ERR_UNDERSIZED_ARRAY -3
#define ERR_INVALID_INPUT -4

size_t sCWD = 5001, lDIRn = 257;

char BrowseDIRBanner[] = 
    " ******                                                    *******   ** *******  \n"
    "/*////**                                                  /**////** /**/**////** \n"
    "/*   /**  ******  ******  ***     **  ******  *****       /**    /**/**/**   /** \n"
    "/******  //**//* **////**//**  * /** **////  **///**      /**    /**/**/*******  \n"
    "/*//// ** /** / /**   /** /** ***/**//***** /*******      /**    /**/**/**///**  \n"
    "/*    /** /**   /**   /** /****/**** /////**/**////       /**    ** /**/**  //** \n"
    "/******* /***   //******  ***/ ///** ****** //******      /*******  /**/**   //**\n"
    "///////  ///     //////  ///    /// //////   //////       ///////   // //     // \n";

int CountOfDIR(const char* SRC_DIR) {
    int CDIR = 0;
    if(SRC_DIR == NULL) return ERR_NULL_POINTER;
    
    DIR *dp = opendir(SRC_DIR);
    if(dp == NULL) return ERR_INVALID_DIRECTORY;
    
    struct dirent *dpi = { 0 };
    while((dpi = readdir(dp)) != NULL) CDIR++;

    return CDIR;
}

int GetDIR2d(char **fDIRL, const char *SRC_DIR, int sEle) {
    int fCDIR = CountOfDIR(SRC_DIR);
    
    if(fCDIR > sEle) return ERR_UNDERSIZED_ARRAY;
    if(fDIRL == NULL || SRC_DIR == NULL) return ERR_NULL_POINTER;
    for (int i = 0; i < fCDIR; i++) if(fDIRL[i] == NULL) return ERR_NULL_POINTER;
    
    DIR *dp = opendir(SRC_DIR);
    if(dp == NULL) return ERR_INVALID_DIRECTORY;

    int IterationC = 0;
    struct dirent *dpi;
    while ((dpi = readdir(dp)) != NULL) {
        if(strcmp(strncpy(fDIRL[IterationC], dpi->d_name, lDIRn), dpi->d_name)) return ERR_UNDERSIZED_ARRAY;
        IterationC++;
    }
    
    return 0;
}

int CWDManager(char **fDIRL, char *fCWD, char *fPWD, int fDIRc) {
    if((fDIRc < 0) || (fDIRc > (CountOfDIR(fCWD) - 1))) return ERR_INVALID_INPUT;
    if(fDIRL == NULL || fCWD == NULL) return ERR_NULL_POINTER;
    for (int i = 0; i < CountOfDIR(fCWD); i++) if(fDIRL[i] == NULL) return ERR_NULL_POINTER;

    if(fCWD[strlen(fCWD) - 1] != '\\') strcat(fCWD, "\\");

    if(fDIRc == 0) {
        strcpy(fCWD, fPWD);
        return 0;
    }

    if(fDIRc == 1) {
        int CSlash = 0, CCSlash = 0;
        for (int i = 0; i < strlen(fCWD); i++) {
            if(fCWD[i] == '\\') CSlash++;
        }

        for (int i = 0; i < strlen(fCWD); i++) {
            if(fCWD[i] == '\\') CCSlash++;
            if(CCSlash >= CSlash - 1) fCWD[i + 1] = '\0';
        } return 0;        
    }

    strcat(fCWD, fDIRL[fDIRc]);
    return 0;
}

int main() {
    // debug
    int *errorr = (int*)calloc(1, sizeof(int));

    system("clear");

    char *CWD = (char*)calloc(sCWD, sizeof(char)), *PWD = (char*)calloc(sCWD, sizeof(char));
    if(CWD == NULL || PWD == NULL) goto FailedFree;

    if(getcwd(CWD, sCWD) == NULL || getcwd(PWD, sCWD) == NULL) goto FailedFree;

    int CDIR = CountOfDIR(CWD), oCDIR = 0, DIRChoice = 1, IterationC = 0;
    char **DIRL = (char**)calloc(CountOfDIR(CWD), sizeof(char*));
    if(DIRL == NULL) goto FailedFree;
    
    for (int i = 0; i < CDIR; i++) {
        DIRL[i] = (char*)calloc(lDIRn, sizeof(char));
        if(DIRL[i] == NULL) goto FailedFree;
    }
    
    while (DIRChoice != -1) {
        system("clear");

        if(IterationC == 0) {
            if(GetDIR2d(DIRL, CWD, CDIR) != 0) goto FailedFree;

            printf("%s\nCurrent Working Directory: %s\nPlease select which directory to go to:\n\n", BrowseDIRBanner, CWD);
            for (int i = 1; i < CDIR; i++) {
                if(i == 1) {
                    printf("\t[1] Back\n");
                    continue;
                }

                printf("\n\t[%d] %s", i, DIRL[i]);
            } printf("\n\nPlease enter the number: ");

            if(scanf(" %d", &DIRChoice) != 1) goto FailedFree;
            if((errorr[0] = CWDManager(DIRL, CWD, PWD, DIRChoice)) != 0) goto FailedFree;

            IterationC++; continue;
        }

        oCDIR = CDIR;
        CDIR = CountOfDIR(CWD);
        if(CDIR < 0) goto FailedFree;
        if(CDIR > oCDIR) {
            char **Temp = realloc(DIRL, CDIR * lDIRn);
            DIRL = Temp;

            if(DIRL == NULL) goto FailedFree;
            for (int i = oCDIR; i < CDIR; i++) {
                DIRL[i] = (char*)calloc(lDIRn, sizeof(char));
                if(DIRL[i] == NULL) goto FailedFree;
            }
        } if(GetDIR2d(DIRL, CWD, CDIR) != 0) goto FailedFree;
        
        printf("%s\nCurrent Working Directory: %s\nPlease select which directory to go to:\n\n\t[1] Program Working Directory: %s\n\t[2] Back", BrowseDIRBanner, CWD, PWD);
        for (int i = 2; i < CDIR; i++) {
            printf("\n\t[%d] %s", i + 1, DIRL[i]);
        } printf("\n\nPlease enter the number: ");

        if(scanf(" %d", &DIRChoice) != 1) goto FailedFree;
        DIRChoice -= 1;

        if(CWDManager(DIRL, CWD, PWD, DIRChoice) != 0) goto FailedFree;

        IterationC++;
    }
    
    return 0;

    FailedFree:
        system("cls");
        printf("FailedFree called! Please try again.\nErrno Information: ");
        strerror(errno);

        getchar(); getchar();

        if(CWD != NULL) free(CWD);
        if(PWD != NULL) free(PWD);
        if(DIRL != NULL && CWD != NULL) {
            for (int i = 0; i < CountOfDIR(CWD); i++) free(DIRL[i]);
            free(DIRL);
        } else if(DIRL != NULL) free(DIRL);
        
        return 1;
}