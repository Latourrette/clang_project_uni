
#ifndef PROJETO_FUNCTIONS_H
#define PROJETO_FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"stringsort.h"

/*Maximum size for word search*/
#define ROW 10
#define COL 10
#define MAXWORDS  5
#define BUFFER 1000


/**
 * Leitura da matriz a partir de um ficheiro de texto
 * @return
 */
char **readFromFile(int row, int col);

/**
 * Leitura da matriz manualmente
 * @return
 */
char **generateWordSearch(int row, int col);

/**
 *
 * @param col
 * @param row
 * @return
 */
char **createManuallyBagOfWords(int row, int col);

/**
 *
 * @param col
 * @param row
 * @return
 */
char **readFromFileBagOfWords(int row, int col);

/**
 *
 * @param matrix
 */
void printMatrix(char **matrix, int row, int col);

/**
 *
 * @param matrix
 * @param col
 */
void printBagOfWords(char **matrix, int row);


void wordSearchFunc(char **wordSearch, char *word, int col, int row);

void wordSearchRecursive(char **wordSearch, char *word, int x, int y, int z);

void findWords(char **wordSearch, char *word);

void recursiveSearch(
        char **wordSearch, int currentRow, int currentCol, char *word, int index, int n, int **pos, int d);

bool isvalid(int row, int col);

#endif //PROJETO_FUNCTIONS_H
