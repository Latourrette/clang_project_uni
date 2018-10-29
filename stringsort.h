//
// Created by latourrette on 29-10-2018.
//

#ifndef PROJETO_STRINGSORT_H
#define PROJETO_STRINGSORT_H

#include "functions.h"

#define CUTOFF 5
#define R 256
// terminate symbol for strings
#define STRING_END_CHAR -1

void msdSortClient(StringElementsArray * a, StringElementsArray * aux);
int charAt(StringElementsArray *a, int i, int d);
void msdSort(StringElementsArray *a, StringElementsArray *aux, int lo, int hi, int d);
void insertionSort(StringElementsArray *a);
#endif //PROJETO_STRINGSORT_H
