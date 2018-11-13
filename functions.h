//
// Created by latourrette on 26-10-2018.
//

#ifndef PROJETO_FUNCTIONS_H
#define PROJETO_FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

/*Maximum size for word search*/
#define ROW 10
#define COL 10
#define MAXWORDS  5
#define BUFFER 1000


/**
 *  Structure used for LSD, MSD and other
 */
typedef struct {
    char **str; // array of strings
    int *len; // array of string lengths
    int N; // number of strings (size of array of strings)
} StringElementsArray;

/**
 * Leitura da matriz a partir de um ficheiro de texto
 * @return
 */
char **readFromFile(int col, int row);

/**
 * Leitura da matriz manualmente
 * @return
 */
char **generateWordSearch(int col, int row);

/**
 *
 * @param col
 * @param row
 * @return
 */
char **createManuallyBagOfWords(int col, int row);

/**
 *
 * @param col
 * @param row
 * @return
 */
char **readFromFileBagOfWords(int col, int row);

/**
 *
 * @param matrix
 */
void printMatrix(char **matrix, int col, int row);

/**
 *
 * @param matrix
 * @param col
 */
void printBagOfWords(char **matrix, int col);

/**
 *
 * @param si
 * @param N
 */
void createStringElementsArray(StringElementsArray *si, int N);

/**
 *
 * @param si
 * @param N
 * @param strings
 */
void createStringElementsArrayAndFill(StringElementsArray *si, int N, char **strings);

/**
 *
 * @param a
 */
void printStringElementsArray(StringElementsArray *a);

/**
 *
 * @param si
 */
void freeStringElementsArray(StringElementsArray *si);

void wordSearchFunc(char **wordSearch, char *word, int col, int row);

void wordSearchRecursive(char **wordSearch, char *word, int x, int y, int z);

void findWords(char **wordSearch, char *word);

void recursiveSearch(
        char **wordSearch, int currentRow, int currentCol, char *word, int index, int n, int **pos, int d);

bool isvalid(int row, int col);

#endif //PROJETO_FUNCTIONS_H
