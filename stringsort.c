//
// Created by latourrette on 29-10-2018.
//

#include <assert.h>
#include "stringsort.h"

void msdSortClient(StringElementsArray *a, StringElementsArray *aux) {
    for (int i = 0; i < a->N; i++) {
        printf("Word[%d] = %s\n", i+1, a->str[i]);
    }
    msdSort(a, aux, 0, a->N - 1, 0);
    printf("\n-----------------\nList MSD Sorted:\n");
    for (int i = 0; i < a->N; i++) {
        printf("\t%s\n", a->str[i]);
    }
}

int charAt(StringElementsArray *a, int i, int d) {
    return (d < a->len[i]) ? (a->str[i][d]) : STRING_END_CHAR;
}

void msdSort(StringElementsArray *a, StringElementsArray *aux, int lo, int hi, int d) {
    int i, r, j;
    int *count = malloc((R + 2) * sizeof(int));

    if (hi <= lo) {
        return;
    }

    for (i = 0; i < R + 2; i++) {
        count[i] = 0;
    }

    for (i = lo; i <= hi; i++) {
        count[charAt(a, i, d) + 2]++;
    }
    for (r = 0; r < R + 1; r++) {
        count[r + 1] += count[r];
    }

    for (i = lo; i <= hi; i++) {
        j = charAt(a, i, d) + 1;
        aux->str[count[j]] = a->str[i];
        aux->len[count[j]] = a->len[i];
        count[j]++;
    }

    for (i = lo; i <= hi; i++) {
        a->str[i] = aux->str[i - lo];
        a->len[i] = aux->len[i - lo];
    }

    for (r = 0; r < R; r++) {
        msdSort(a, aux, lo + count[r], lo + count[r + 1] - 1, d + 1);
    }
    free(count);
    freeStringElementsArray(aux);
}