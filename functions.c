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

void printBagOfWords(char **matrix, int col) {
    for (int i = 0; i < col; i++) {
        printf("[%s]", matrix[i]);
        printf("\n");
    }
}

char **generateWordSearch(int col, int row) {
    char **wordsearch = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++) {
        wordsearch[i] = (char *) malloc((size_t) row++);
        for (int j = 0; j < row; j++) {
            wordsearch[i][j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26];
        }
    }
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

    for (int i = 0; i < col; i++) {
        fgets(wordsearch[i], BUFFER, f);
    }

    fclose(f);
    return wordsearch;
}

char **readFromFileBagOfWords(int col, int row) {
    char *aux = (char *) malloc(100);
    char **bagOfWords = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++)
        bagOfWords[i] = (char *) malloc((size_t) row++);

    FILE *f;
    if ((f = fopen("/home/latourrette/Documents/lp1/projetolp1/data/bagOfWords.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < col; i++) {
        fgets(aux, BUFFER, f);
        strcpy(&aux[strlen(aux) - 1], "\0");
        strcpy(bagOfWords[i], aux);
    }
    fclose(f);
    return bagOfWords;
}


void createStringElementsArray(StringElementsArray *si, int N) {
    si->N = N;
    si->str = (char **) malloc(sizeof(char *) * N);
    si->len = (int *) malloc(sizeof(int) * N);
}

void createStringElementsArrayAndFill(StringElementsArray *si, int N, char **strings) {
    int i;
    createStringElementsArray(si, N);
    for (i = 0; i < N; i++) {
        si->str[i] = (char*) malloc(strlen(strings[i]) + 1);
        strcpy(si->str[i],strings[i]);
        si->len[i] = (int) strlen(strings[i]);
    }
}

void freeStringElementsArray(StringElementsArray *si) {
    free(si->str);
    free(si->len);
    free(si);
}

void printStringElementsArray(StringElementsArray *a) {
    int i;
    printf("\n-------------\nStringElementsArray (N=%d):\n", a->N);
    for (i = 0; i < a->N; i++)
        printf("\t%s\t(%d)\n", a->str[i], a->len[i]);
    printf("-------------\n");
}