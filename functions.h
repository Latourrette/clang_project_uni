
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
 * Cria manualmente matrix de dicionario
 * @param row linhas
 * @param col colunas
 * @return Matrix alocada com os dados
 */
char **createManuallyBagOfWords(int row, int col);

/**
 * Cria a matrix da sopa da letra
 * @param row linhas
 * @param col colunas
 * @return Matrix alocada com os dados
 */
char **readFromFileBagOfWords(int row, int col);

/**
 * Imprime a matrix da sopa de letras
 * @param matrix Matrix da sopa de letras
 * @param row linhas
 * @param col colunas
 */
void printMatrix(char **matrix, int row, int col);

/**
 * Imprime a matrix do dicionario
 * @param matrix Matrix da sopa de letras
 * @param col colunas, nº de palavras
 */
void printBagOfWords(char **matrix, int row);

/**
 * Cliente para começar a procura da palavra na matrix da sopa de letras
 * @param wordSearch matrix da sopa de letras
 * @param word palavra a procurar
 */
void findWords(char **wordSearch, char *word);

/**
 * Funcao recursiva para encontrar o resto da palavra
 * @param wordSearch matrix da sopa de letras
 * @param currentRow linha atual
 * @param currentCol coluna atual
 * @param word palavra a procurar
 * @param index indice da posiçao do caracter da palavra
 * @param n tamanho da palavra
 * @param pos matrix para o output
 * @param d indicie para a matrix das direçoes
 */
void recursiveSearch(
        char **wordSearch, int currentRow, int currentCol, char *word, int index, int n, int **pos, int d);

/**
 * Funcao de ajuda de validaçao para entrar na funçao recursiva
 * @param row linha atual
 * @param col coluna atual
 * @return V/F
 */
bool isvalid(int row, int col);

#endif //PROJETO_FUNCTIONS_H
