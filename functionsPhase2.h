
#ifndef PROJETO_FUNCTIONSPHASE2_H
#define PROJETO_FUNCTIONSPHASE2_H

#include"functions.h"
#include "mergeSortLinkedList.h"


struct WordList {
    char *word;
    struct WordList *nextWord;
} wordList;

struct Queue {
    struct WordList *front;
    struct WordList *last;
    int queueSize;
} queue;

struct WordSearch {
    char *c;
    int pos[2];
    struct WordSearch *N;
    struct WordSearch *NE;
    struct WordSearch *E;
    struct WordSearch *SE;
    struct WordSearch *S;
    struct WordSearch *SW;
    struct WordSearch *W;
    struct WordSearch *NW;
} wordSearch;

struct WordFind {
    char *c;
    int pos[2];
    char *dir;
    struct WordFind *next;
} wordFind;


struct Position{
    int x;
    int y;
    char** movements;
    int n;
}position ;

struct Cache{
    char*word;
    struct WordSearch ws;
}cache;

/**
 * Funcao para imprimir uma string dada uma posiçao inicial e um array de movimentos
 * @param ws Strutura da sopa de letras
 * @param p Strutura com a informaçao necessaria para a funçao
 * @return Conjunto de letras formadas de acordo com as posicoes
 */
char *path(struct WordSearch *ws, struct Position *p);

/**
 * Inicializaçao da estrutura queue
 * @param q Estrutura da queue
 */
void initQueue(struct Queue *q);

/**
 * Inicializacao da estrutura da ajuda para fazer o output
 * @param wf Estrutura do output
 */
void initWordFind(struct WordFind *wf);

/**
 * Para remover a palavra que tiver em primeiro na queue
 * @param q Estrutura da queue
 */
void pop(struct Queue *q);

/**
 * Para inserir uma palavra na queue
 * @param q Estrutura da queue
 * @param word Palavra a inserir
 */
void push(struct Queue *q, char *word);

/**
 * Para inserir um conjunto de palavras
 * @param q Estrutura da queue
 * @param bagOfWords Matrix do dicionario
 * @param row Nº de palavras
 */
void pushWords(struct Queue *q, char **bagOfWords, int row);

/**
 * Imprime o conteudo de uma lista ligada
 * @param head Inicio da lista
 */
void printList(struct WordList *head);

/**
 * Imprime conteudo da estrutura da sopa de letras
 * @param ws Estrutura da sopa de letras
 */
void printWordSearch(struct WordSearch *ws);

/**
 * Inicializacao da estrutura da sopa de letras
 * @param w Estrutura da sopa de letras
 */
void initWordSearch(struct WordSearch *w);

/**
 * Insere conteudo na estrutura da sopa de letras
 * @param ws Estrutura da sopa de letras
 * @param wordSearch Matrix da sopa de letras
 */
void insertIntoWS(struct WordSearch *ws, char **wordSearch);

/**
 * CLiente para começar a procura da palavra na sopa de letras
 * @param ws Estrutura da sopa de letras
 * @param word Palavra a procurar
 */
void findWordsStructs(struct WordSearch *ws, char *word);

/**
 * Funcao recursiva para continuar a procura da palavra na sopa de letras
 * @param ws Estrutura da sopa de letras
 * @param word Palavra a procurar
 * @param aux Estrutra para ajudar no output
 * @param wf Estrutura para ajudar no output
 * @param index indice da posiçao do caracter da palavra
 * @param n Tamanho da palavra
 */
void
recursiveSearchStructs(struct WordSearch *ws, char *word, struct WordFind *aux, struct WordFind *wf, int index, int n);

/**
 * Cliente para chamar as funcoes necessarias para o merge sort
 * @param q Estrutura da queue
 * @param n Estrutura do No que tem as informacoes necessarias para o merge
 */
void clientMergeSort(struct Queue *q, struct Node *n);

/**
 * Cliente que chama a funcao path()
 * @param p Estrutura com as informacoes necessarias
 * @param n numero de movimentos
 * @param x coordenada x, onde a procura começa
 * @param y coordenada y, onde a procura comeca
 * @param movements
 */
void clientPathFind(struct Position *p, int n, int x, int y, char**movements);

#endif //PROJETO_FUNCTIONSPHASE2_H
