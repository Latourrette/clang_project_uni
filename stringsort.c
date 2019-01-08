

#include "stringsort.h"


void createStringElementsArray(StringElementsArray *si, int N) {
    si->N = N;
    si->str = (char **) malloc(sizeof(char *) * N);
    si->len = (int *) malloc(sizeof(int) * N);
}

void createStringElementsArrayAndFill(StringElementsArray *si, int N, char **strings) {
    int i;
    createStringElementsArray(si, N);
    for (i = 0; i < N; i++) {
        si->str[i] = (char *) malloc(strlen(strings[i]) + 1);
        strcpy(si->str[i], strings[i]);
        si->len[i] = (int) strlen(strings[i]);
    }
}

void freeStringElementsArray(StringElementsArray *si) {
    free(si->str);
    free(si->len);
    free(si);
}

void printStringElementsArray(StringElementsArray *a) {
    int i;
    printf("\n-------------\nStringElementsArray (N=%d):\n", a->N);
    for (i = 0; i < a->N; i++)
        printf("\t%s\t(%d)\n", a->str[i], a->len[i]);
    printf("-------------\n");
}

void msdSortClient(StringElementsArray *a, StringElementsArray *aux) {
    for (int i = 0; i < a->N; i++) {
        printf("Word[%d] = %s\n", i + 1, a->str[i]);
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

    if (hi <= lo + CUTOFF) {
        insertionSort(a);
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

void insertionSort(StringElementsArray *a) {
    int aux;
    char tmp[BUFFER];

    for (int i = 1; i < a->N; i++) {
        int j = i;

        while (j > 0 && strcmp(a->str[j - 1], a->str[j]) > 0) {
            strncpy(tmp, a->str[j - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(a->str[j - 1], a->str[j], sizeof(a->str[j - 1]) - 1);
            a->str[j - 1][sizeof(a->str[j - 1]) - 1] = '\0';

            strncpy(a->str[j], tmp, sizeof(a->str[j]) - 1);
            a->str[j][sizeof(a->str[j]) - 1] = '\0';

            aux = a->len[j - 1];
            a->len[j - 1] = a->len[j];
            a->len[j] = aux;
            --j;
        }
    }
}
