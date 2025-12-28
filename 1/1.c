#include <stdio.h>
#include <stdlib.h>

int countNumberOfZeros(FILE *fp) {
    char *rotation;
    int currentRot = 50, timesZero = 0;

    while (fscanf(fp, "%s", rotation) == 1) {
        char *substr = rotation + 1;
        int r = atoi(substr);
        if (rotation[0] == 'L')         r = -r;

        currentRot += r;
        currentRot = currentRot % 100;
        if (currentRot == 0) timesZero++;
    }
    return timesZero;
}

int main() {
    FILE *fp;
    char *inFile = "input";

    fp = fopen(inFile, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open input file %s!\n", inFile);
        exit(1);
    }

    printf("timesZero is %d\n", countNumberOfZeros(fp));

    fclose(fp);
    return 0;
}
