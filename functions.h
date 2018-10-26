//
// Created by latourrette on 26-10-2018.
//

#ifndef PROJETO_FUNCTIONS_H
#define PROJETO_FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Maximum size for word search*/
#define MAXSEARCH 10
#define MAXWORDS  5
#define BUFFER 10000

/**
 * Leitura da matriz a partir de um ficheiro de texto
 * @return
 */
char **readFromFile(int col, int row);

/**
 * Leitura da matriz manualmente
 * @return
 */
char **createManually(int col, int row);

/**
 *
 * @param matrix
 */
void printMatrix(char **matrix, int col, int row);

#endif //PROJETO_FUNCTIONS_H
