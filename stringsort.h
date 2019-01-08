
#ifndef PROJETO_STRINGSORT_H
#define PROJETO_STRINGSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/**
 *  Structure used for LSD, MSD and other
 */
typedef struct {
    char **str; // array of strings
    int *len; // array of string lengths
    int N; // number of strings (size of array of strings)
} StringElementsArray;


#define CUTOFF 5
#define R 256
#define BUFFER 1000
// terminate symbol for strings
#define STRING_END_CHAR -1

void createStringElementsArray(StringElementsArray *si, int N);
void createStringElementsArrayAndFill(StringElementsArray *si, int N, char **strings);
void freeStringElementsArray(StringElementsArray *si);
void printStringElementsArray(StringElementsArray *a);
void msdSortClient(StringElementsArray * a, StringElementsArray * aux);
int charAt(StringElementsArray *a, int i, int d);
void msdSort(StringElementsArray *a, StringElementsArray *aux, int lo, int hi, int d);
void insertionSort(StringElementsArray *a);
#endif //PROJETO_STRINGSORT_H
