#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int LenghtOfRace, CountOfCheckpoint, RabbitJumpLenght, MonkeyJumpLenght, FrogJumpLenght, *Checkpoint, *CheckpointScore;
    int RabbitScore = 0, MonkeyScore = 0, FrogScore = 0, WholeScore = 0;

    if(scanf("%d %d %d %d %d", &LenghtOfRace, &CountOfCheckpoint, &RabbitJumpLenght, &MonkeyJumpLenght, &FrogJumpLenght) != 5) return 1;

    Checkpoint = (int*)calloc(CountOfCheckpoint, sizeof(int));
    CheckpointScore = (int*)calloc(CountOfCheckpoint, sizeof(int));

    for (int i = 0; i < CountOfCheckpoint; i++) {
        if(scanf("%d %d", &Checkpoint[i], &CheckpointScore[i]) != 2) {
            free(Checkpoint);
            free(CheckpointScore);

            return 1;
        }

        WholeScore += CheckpointScore[i];
        if(RabbitJumpLenght != 1 && Checkpoint[i] % RabbitJumpLenght == 0) RabbitScore += CheckpointScore[i];
        if(MonkeyJumpLenght != 1 && Checkpoint[i] % MonkeyJumpLenght == 0) MonkeyScore += CheckpointScore[i];
        if(FrogJumpLenght != 1 && Checkpoint[i] % FrogJumpLenght == 0) FrogScore += CheckpointScore[i];
    }
    
    if(RabbitJumpLenght == 1) RabbitScore = WholeScore;
    if(MonkeyJumpLenght == 1) MonkeyScore = WholeScore;
    if(FrogJumpLenght == 1) FrogScore = WholeScore;

    if(RabbitScore == MonkeyScore && MonkeyScore == FrogScore) printf("Rabbit %d\nMonkey %d\nFrog %d", RabbitScore, MonkeyScore, FrogScore);
    else if(RabbitScore == MonkeyScore && MonkeyScore > FrogScore) printf("Rabbit %d\nMonkey %d", RabbitScore, MonkeyScore);
    else if(RabbitScore == FrogScore && FrogScore > MonkeyScore) printf("Rabbit %d\nFrog %d", RabbitScore, FrogScore);
    else if(MonkeyScore == FrogScore && FrogScore > RabbitScore) printf("Monkey %d\nFrog %d", MonkeyScore, FrogScore);
    else if(RabbitScore > MonkeyScore && RabbitScore > FrogScore) printf("Rabbit %d", RabbitScore);
    else if(MonkeyScore > RabbitScore && MonkeyScore > FrogScore) printf("Monkey %d", MonkeyScore);
    else if(FrogScore > RabbitScore && FrogScore > MonkeyScore) printf("Frog %d", FrogScore);

    free(Checkpoint);
    free(CheckpointScore);
    return 0;
}