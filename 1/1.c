#include <stdio.h>
#include <stdlib.h>

int countNumberOfZeros(FILE *fp) {
    char* rotation;
    int currentRot = 50, timesZero = 0;

    while (fscanf(fp, "%s", rotation) == 1) {
    	char* substr = rotation + 1;
    	int r;
        if (rotation[0] == 'L')			r = -1 * atoi(substr);
        else if (rotation[0] == 'R')	r = atoi(substr);

        currentRot += r;
        currentRot = currentRot % 100;
        if (currentRot == 0) timesZero++;
    }
    return timesZero;
}

int main() {
    FILE *fp;
    char *mode = "r";
    char *inFile = "input";

    fp = fopen(inFile, mode);
    if (fp == NULL) {
        fprintf(stderr, "Can't open input file %s!\n", inFile);
        exit(1);
    }

    int timesZero = countNumberOfZeros(fp);
    printf("timesZero is %d\n", timesZero);

    fclose(fp);
}
