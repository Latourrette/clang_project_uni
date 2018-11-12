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
        if (wordsearch[i][strlen(wordsearch[i])] == '\n') {
            wordsearch[i][strlen(wordsearch[i])] = '\0';

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

    for (int i = 0; i < col; ++i) {
        if (bagOfWords[i][strlen(bagOfWords[i])] == '\n') {
            bagOfWords[i][strlen(bagOfWords[i])] = '\0';
        }
    }
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
        if (wordsearch[i][strlen(wordsearch[i])] == '\n') {
            wordsearch[i][strlen(wordsearch[i])] = '\0';
        }
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
        si->str[i] = (char *) malloc(strlen(strings[i]) + 1);
        strcpy(si->str[i], strings[i]);
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


// Program to find all occurrences of the word in
// a matrix

// check whether given cell (row, col) is a valid
// cell or not.
bool isvalid(int row, int col, int prevRow, int prevCol) {
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && !(row == prevRow && col == prevCol);
}

void findWords(char **wordSearch, char *word) {

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (wordSearch[i][j] == word[0]) {
                recursiveSearch(wordSearch, i, j, -1, -1, word, 0, strlen(word) - 1);
            }
        }
    }
}

int aux[10][10];
void recursiveSearch(char **wordSearch,
                     int currentRow, int currentCol, int prevRow, int prevCol, char *word, int index, int n) {

    int directions[8][2] = {{-1, -1}, // NW
                            {-1, 0},  // N
                            {-1, 1},  // NE
                            {0,  -1},  // W
                            {0,  1},  // E
                            {1,  -1}, // SW
                            {1,  0},  // S
                            {1,  1},  // SE
    };

    if (index > n || wordSearch[currentRow][currentCol] != word[index]) {
        return;
    }

    //append current character position to path
    //path += string(1, word[index]) + "(" + to_string(row)+ ", " + to_string(col) + ") ";
    aux[index][0] = currentRow;
    aux[index][1] = currentCol;
    // current character matches with the last character
    // in the word
    if (index == n)
    {
        printf("%s ", word);
        for (int i = 0; i <= n; ++i)
        {
           printf("->[%d, %d]",aux[i][0],aux[i][1]);
        }
        printf("\n");
        return;
    }


    for (int i = 0; i < 8; ++i) {
        if (isvalid(currentRow + directions[i][0], currentCol + directions[i][1], prevRow, prevCol)) {
            recursiveSearch(wordSearch, currentRow + directions[i][0], currentCol + directions[i][1],
                            currentRow, currentCol, word, index + 1, n);
        }
    }
}

