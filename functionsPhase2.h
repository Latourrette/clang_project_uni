
#ifndef PROJETO_FUNCTIONSPHASE2_H
#define PROJETO_FUNCTIONSPHASE2_H

#include"functions.h"

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

char *path(struct WordSearch *ws, struct Position *p);

void initQueue(struct Queue *q);

void initWordFind(struct WordFind *wf);

void pop(struct Queue *q);

void push(struct Queue *q, char *word);

void pushWords(struct Queue *q, char **bagOfWords, int row);

void printList(struct WordList *head);

void printWordSearch(struct WordSearch *ws);

struct WordList *mergeSort(struct WordList *head);

static struct WordList *bisectList(struct WordList *head);

static struct WordList *mergeList(struct WordList *list1, struct WordList *list2);

void initWordSearch(struct WordSearch *w);

void insertIntoWS(struct WordSearch *ws, char **wordSearch);

void findWordsStructs(struct WordSearch *ws, char *word);

void
recursiveSearchStructs(struct WordSearch *ws, char *word, struct WordFind *aux, struct WordFind *wf, int index, int n);

#endif //PROJETO_FUNCTIONSPHASE2_H
