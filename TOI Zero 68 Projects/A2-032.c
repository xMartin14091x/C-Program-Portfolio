#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int HighestCountOfPokemon = 0, CountOfPokemon, PosX, PosY, WidthY, LenghtX, **PokemonTile, **CountOfPokemonTile;

    if(scanf("%d %d", &WidthY, &LenghtX) != 2) return 1;

    PokemonTile = (int**)calloc(WidthY, sizeof(int*));
    if(PokemonTile == NULL) return 1;

    CountOfPokemonTile = (int**)calloc(WidthY, sizeof(int*));
    if(CountOfPokemonTile == NULL) return 2;

    for (int i = 0; i < WidthY; i++) {
        PokemonTile[i] = (int*)calloc(LenghtX, sizeof(int));
        CountOfPokemonTile[i] = (int*)calloc(LenghtX, sizeof(int)); 

        if(PokemonTile[i] == NULL || CountOfPokemonTile[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(CountOfPokemonTile[j]);
                free(PokemonTile[j]);
            } 
            
            free(CountOfPokemonTile);
            free(PokemonTile);

            return 1;
        }
    }
    
    scanf("%d", &CountOfPokemon);

    for (int i = 0; i < CountOfPokemon; i++) {
        if(scanf("%d %d", &PosY, &PosX) != 2) return 1;

        PokemonTile[PosY][PosX]++;
    }
    
    for (int Y = 0; Y < WidthY; Y++) {
        for (int X = 0; X < LenghtX; X++) {
                if(PokemonTile[Y][X] == 0) {
                    if(Y > 0 && X > 0 && X < LenghtX - 1 && Y < WidthY - 1) {
                        // Inner portion of the rectangle / square
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y][X - 1];               
                        CountOfPokemonTile[Y][X] += PokemonTile[Y][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X + 1];
                    }
    
                    if(X == 0 && Y == 0) {
                        // Left Upper Coner
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X + 1];
                    } else if (X == 0 && Y == WidthY - 1) {
                        // Left Lower Coner
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X + 1];
                    } else if(X == LenghtX - 1 && Y == 0) {
                        // Right Upper Coner
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X - 1];
                    } else if(X == LenghtX - 1 && Y == WidthY - 1) {
                        // Right Lower Coner
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X - 1];
                    } else if(Y == 0 && (X > 0 && X <= LenghtX - 1)) {
                        // Upside while Y is 0 and X is between 0 < X < LenghtX - 1
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X + 1];
                    } else if(Y == WidthY - 1 && (X > 0 && X < LenghtX - 1)) {
                        // Lowerside while Y is WidthY - 1 and X is between 0 < X < LenghtX - 1
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X + 1];
                    } else if(X == 0 && (Y > 0 && Y < WidthY - 1)) {
                        // Leftside while X is 0 and Y is between 0 < Y < WidthY - 1
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X + 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][  X  ];
                    } else if(X == LenghtX - 1 && (Y > 0 && Y < WidthY - 1)) {
                        // Leftside while X is 0 and Y is between 0 < Y < WidthY - 1
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][  X  ];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y - 1][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[  Y  ][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][X - 1];
                        CountOfPokemonTile[Y][X] += PokemonTile[Y + 1][  X  ];
                    }
                }
        }
    }
    
    /*printf("\n\n");
    for (int i = 0; i < WidthY; i++) {
        for (int j = 0; j < LenghtX; j++) {
            printf("%d ", CountOfPokemonTile[i][j]);
        }
        
        printf("\n");
    }*/
    

    for (int i = 0; i < WidthY; i++) {
        for (int j = 0; j < LenghtX; j++) {
            if(HighestCountOfPokemon < CountOfPokemonTile[i][j] && PokemonTile[i][j] == 0) {
                HighestCountOfPokemon = CountOfPokemonTile[i][j];
            }            
        }
    }

    printf("%d", HighestCountOfPokemon);

    for (int i = 0; i < WidthY; i++) {
        free(CountOfPokemonTile[i]);
        free(PokemonTile[i]);
    } 
    
    free(CountOfPokemonTile);
    free(PokemonTile);

    return 0;
}