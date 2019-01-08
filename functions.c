
#include"functions.h"

void printMatrix(char **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%c]", matrix[i][j]);
        }
        printf("\n");
    }
}

void printBagOfWords(char **matrix, int row) {
    for (int i = 0; i < row; i++) {
        printf("[%s]", matrix[i]);
        printf("\n");
    }
}

char **generateWordSearch(int row, int col) {
    char **wordsearch = (char **) malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++) {
        wordsearch[i] = (char *) malloc((size_t) col++);
        for (int j = 0; j < col; j++) {
            wordsearch[i][j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26];
        }
        if (wordsearch[i][strlen(wordsearch[i])] == '\n') {
            wordsearch[i][strlen(wordsearch[i])] = '\0';

        }
    }
    return wordsearch;
}

char **createManuallyBagOfWords(int row, int col) {
    char **bagOfWords = (char **) malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
        bagOfWords[i] = (char *) malloc((size_t) col++);

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

char **readFromFile(int row, int col) {
    char *aux = (char *) malloc(100);

    char **wordsearch = (char **) malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
        wordsearch[i] = (char *) malloc((size_t) col++);

    FILE *f;
    if ((f = fopen("/home/latourrette/Documents/lp1/projetolp1/data/wordSearch.txt", "r")) == NULL) {
        printf("Error! openingfile:///run/media/latourrette/g/gba file");
        exit(1);
    }

    for (int i = 0; i < row; i++) {
        fgets(aux, BUFFER, f);
        strcpy(&aux[strlen(aux)], "\0");
        strcpy(wordsearch[i], aux);
    }
    free(aux);
    fclose(f);
    return wordsearch;
}

char **readFromFileBagOfWords(int row, int col) {
    char *aux = (char *) malloc(100);
    char **bagOfWords = (char **) malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
        bagOfWords[i] = (char *) malloc((size_t) col);

    FILE *f;
    if ((f = fopen("/home/latourrette/Documents/lp1/projetolp1/data/bagOfWords.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < row; i++) {
        fgets(aux, BUFFER, f);
        strcpy(&aux[strlen(aux) - 1], "\0");
        strcpy(bagOfWords[i], aux);
    }
    fclose(f);
    return bagOfWords;
}

bool isvalid(int row, int col) {
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

void findWords(char **wordSearch, char *word) {

    int **pos = (int **) malloc(sizeof(int *) * BUFFER);
    for (int k = 0; k < BUFFER; ++k) {
        pos[k] = (int *) malloc(sizeof(int) * strlen(word) * 2 + 1);
    }


    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (wordSearch[i][j] == word[0]) {
                recursiveSearch(wordSearch, i, j, word, 0, strlen(word) - 1, pos, 0);
            }
        }
    }
    free(pos);
}

void recursiveSearch(char **wordSearch,
                     int currentRow, int currentCol, char *word, int index, int n, int **pos,
                     int d) {

    int directions[8][3] = {{-1, -1}, // NW
                            {-1, 0},  // N
                            {-1, 1},  // NE
                            {0,  -1},  // W
                            {0,  1},  // E
                            {1,  -1}, // SW
                            {1,  0},  // S
                            {1,  1},  // SE
    };
    char dir[8][3] = {
            {"NW"},
            {"N"},
            {"NE"},
            {"W"},
            {"E"},
            {"SW"},
            {"S"},
            {"SE"},
    };

    if (index > n || wordSearch[currentRow][currentCol] != word[index]) {
        return;
    }

    pos[index][0] = currentRow;
    pos[index][1] = currentCol;
    pos[index][2] = d;

    // current character matches with the last character
    // in the word
    if (index == n) {
        printf("%s ", word);
        for (int i = 0; i <= n; ++i) {
            printf("->[%d, %d]", pos[i][0], pos[i][1]);
        }
        printf(" Directions");
        for (int i = 1; i <= n; ++i) {
            printf("-> [%s]", dir[pos[i][2]]);
        }
        printf("\n");
        return;
    }


    for (int i = 0; i < 8; ++i) {
        if (isvalid(currentRow + directions[i][0], currentCol + directions[i][1])) {
            recursiveSearch(wordSearch, currentRow + directions[i][0], currentCol + directions[i][1],
                            word, index + 1, n, pos, i);
        }
    }
}

