//
// Created by latourrette on 26-10-2018.
//

#include"functions.h"

void printMatrix(char **matrix, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("[%c]", matrix[i][j]);
        }
        printf("\n");
    }
}

char **createManually(int col, int row) {
    char **wordsearch = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++)
        wordsearch[i] = (char *) malloc((size_t) row++);

    stpcpy(wordsearch[0], "JDCPCPXOAA");
    stpcpy(wordsearch[1], "ZXVOVXFRVV");
    stpcpy(wordsearch[2], "NDLEIRBIEA");
    stpcpy(wordsearch[3], "YTRQOMOIIO");
    stpcpy(wordsearch[4], "FZZAPAERTQ");
    stpcpy(wordsearch[5], "XAUEOEOOTO");
    stpcpy(wordsearch[6], "PORTUOAZLZ");
    stpcpy(wordsearch[7], "CZNOQUPUOP");
    stpcpy(wordsearch[8], "LXSBVXLNVQ");
    stpcpy(wordsearch[9], "ZIVOOAFRAV");

    return wordsearch;
}

char **createManuallyBagOfWords(int col, int row) {
    char **bagOfWords = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++)
        bagOfWords[i] = (char *) malloc((size_t) row++);

    stpcpy(bagOfWords[0], "PORTO");
    stpcpy(bagOfWords[1], "AVEIRO");
    stpcpy(bagOfWords[2], "COIMBRA");
    stpcpy(bagOfWords[3], "FARO");
    stpcpy(bagOfWords[4], "LISBOA");
    return bagOfWords;
}

char **readFromFile(int col, int row) {
    char **wordsearch = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++)
        wordsearch[i] = (char *) malloc((size_t) row++);

    FILE *f;
    if ((f = fopen("/home/latourrette/Documents/lp1/projetolp1/data/wordsearch.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < col; i++)
        fgets(wordsearch[i], BUFFER, f);

    fclose(f);
    return wordsearch;
}

char **readFromFileBagOfWords(int col, int row) {
    char **bagOfWords = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++)
        bagOfWords[i] = (char *) malloc((size_t) row++);

    FILE *f;
    if ((f = fopen("/home/latourrette/Documents/lp1/projetolp1/data/bagOfWords.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < col; i++)
        fgets(bagOfWords[i], BUFFER, f);

    fclose(f);
    return bagOfWords;
}

