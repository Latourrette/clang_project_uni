

#include "functionsPhase2.h"


void initQueue(struct Queue *q) {
    q->front = NULL;
    q->last = NULL;
    q->queueSize = 0;
}

void initWordFind(struct WordFind *wf) {

    wf->c = (char *) malloc(2);
    wf->c = "";
    wf->pos[0] = 0;
    wf->pos[1] = 0;
    wf->dir = (char *) malloc(3);
    wf->dir = "";
    wf->next = NULL;
}

void initWordSearch(struct WordSearch *w) {
    struct WordSearch *aux;
    for (int i = 0; i < ROW; ++i) {
        aux = w;
        for (int j = 0; j < COL; ++j) {
            if (i == 0 && j == 0) {
                w->N = NULL;
                w->NE = NULL;
                w->E = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->S = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SW = NULL;
                w->W = NULL;
                w->NW = NULL;

            } else if (i == 0 && j == COL - 1) {
                w->N = NULL;
                w->NE = NULL;
                w->E = NULL;
                w->SE = NULL;
                w->S = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SW = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->W = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NW = NULL;

            } else if (i == ROW - 1 && j == 0) {
                w->N = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->E = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SE = NULL;
                w->S = NULL;
                w->SW = NULL;
                w->W = NULL;
                w->NW = NULL;

            } else if (i == ROW - 1 && j == COL - 1) {
                w->N = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NE = NULL;
                w->E = NULL;
                w->SE = NULL;
                w->S = NULL;
                w->SW = NULL;
                w->W = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NW = (struct WordSearch *) malloc(sizeof(struct WordSearch));

            } else if (i == 0) {
                w->N = NULL;
                w->NE = NULL;
                w->E = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->S = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SW = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->W = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NW = NULL;

            } else if (j == 0) {
                w->N = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->E = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->S = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SW = NULL;
                w->W = NULL;
                w->NW = NULL;

            } else if (j == COL - 1) {
                w->N = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NE = NULL;
                w->E = NULL;
                w->SE = NULL;
                w->S = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SW = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->W = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NW = (struct WordSearch *) malloc(sizeof(struct WordSearch));

            } else if (i == ROW - 1) {
                w->N = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->E = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SE = NULL;
                w->S = NULL;
                w->SW = NULL;
                w->W = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NW = (struct WordSearch *) malloc(sizeof(struct WordSearch));

            } else {
                w->N = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->E = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SE = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->S = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->SW = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->W = (struct WordSearch *) malloc(sizeof(struct WordSearch));
                w->NW = (struct WordSearch *) malloc(sizeof(struct WordSearch));
            }
            w->c = NULL;
            w->pos[0] = i;
            w->pos[1] = j;
            //printf("%d, %d, %s\n", w->pos[0], w->pos[1], w->c);
            w = w->E;
        }
        w = aux; // reset na coluna
        w = w->S;
    }
}


void pop(struct Queue *q) {
    q->queueSize--;

    struct WordList *tmp = q->front;
    q->front = q->front->nextWord;
    free(tmp);
}

void push(struct Queue *q, char *word) {
    q->queueSize++;

    if (q->front == NULL) {
        q->front = (struct WordList *) malloc(sizeof(struct WordList));
        q->front->word = word;
        q->front->nextWord = NULL;
        q->last = q->front;
    } else {
        q->last->nextWord = (struct WordList *) malloc(sizeof(struct WordList));
        q->last->nextWord->word = word;
        q->last->nextWord->nextWord = NULL;
        q->last = q->last->nextWord;
    }
}

void pushWords(struct Queue *q, char **bagOfWords, int row) {
    for (int i = 0; i < row; ++i) {
        push(q, bagOfWords[i]);
    }
}

void printList(struct WordList *head) {
    while (head != NULL) {
        printf("%s\n", head->word);
        head = head->nextWord;
    }
}


void printWordSearch(struct WordSearch *ws) {
    struct WordSearch *aux;
    while (ws != NULL) {
        aux = ws;
        while (ws != NULL) {
            printf("%s", ws->c);
            ws = ws->E;

        }
        //printf("%c", ws->c);
        printf("\n");
        ws = aux;
        ws = ws->S;
    }
}


void insertIntoWS(struct WordSearch *ws, char **wordSearch) {
    struct WordSearch *aux = ws;
    struct WordSearch *aux2[ROW][COL];
    int k = 0;

    for (int i = 0; i < ROW; ++i) {
        aux = ws;
        for (int j = 0; j < COL; ++j) {
            ws->c = (char *) malloc(2);
            ws->c[0] = wordSearch[i][j];
            aux2[i][j] = ws;
            k++;
            if (ws->N != NULL) {
                ws->N = aux2[i - 1][j];
            }
            if (ws->E != NULL)
                ws = ws->E;
        }
        ws = aux; // reset na coluna
        if (ws->S != NULL)
            ws = ws->S;
    }
    ws = aux; // reset na coluna
    while (ws->N != NULL)
        ws = ws->N; // ir para a posiçao inicial

    for (int i = 0; i < ROW; ++i) {
        aux = ws;
        for (int j = 0; j < COL; ++j) {

            //printf("Vizinhos de [%d,%d] : ", i, j);
            if (ws->N != NULL) {
                ws->N = aux2[i - 1][j];
                //printf("N = %s ", ws->N->c);
            }
            if (ws->NE != NULL) {
                ws->NE = aux2[i - 1][j + 1];
                //printf("NE = %s ", ws->NE->c);

            }
            if (ws->E != NULL) {
                ws->E = aux2[i][j + 1];
                //printf("E = %s ", ws->E->c);

            }
            if (ws->SE != NULL) {
                ws->SE = aux2[i + 1][j + 1];
                //printf("SE = %s ", ws->SE->c);

            }
            if (ws->S != NULL) {
                ws->S = aux2[i + 1][j];
                //printf("S = %s ", ws->S->c);

            }
            if (ws->SW != NULL) {
                ws->SW = aux2[i + 1][j - 1];
                //printf("SW = %s ", ws->SW->c);

            }
            if (ws->W != NULL) {
                ws->W = aux2[i][j - 1];
                //printf("W = %s ", ws->W->c);

            }
            if (ws->NW != NULL) {
                ws->NW = aux2[i - 1][j - 1];
                //printf("NW = %s ", ws->NW->c);
            }

            //printf("\n");
            ws = ws->E;
        }
        ws = aux; // reset na coluna
        ws = ws->S;
    }
}


void findWordsStructs(struct WordSearch *ws, char *word) {

    struct WordSearch *aux;
    struct WordFind *aux2;


    while (ws != NULL) {
        aux = ws;
        while (ws != NULL) {
            if (ws->c[0] == word[0]) {
                struct WordFind wf;
                initWordFind(&wf);
                aux2 = &wf;
                recursiveSearchStructs(ws, word, aux2, &wf, 0, strlen(word) - 1);
            }
            ws = ws->E;
        }
        ws = aux;
        ws = ws->S;
    }
}

void recursiveSearchStructs(struct WordSearch *ws, char *word, struct WordFind *aux,
                            struct WordFind *wf, int index, int n) {


    if (index > n || ws->c[0] != word[index]) {
        return;
    }

    if (index == 0) {
        wf->c = ws->c;
        wf->pos[0] = ws->pos[0];
        wf->pos[1] = ws->pos[1];
        wf->dir = "I";
    }

    if (index == n) {
        wf = aux;
        printf("%s", word);
        while (wf != NULL) {
            printf("->[%d, %d]", wf->pos[0], wf->pos[1]);
            wf = wf->next;
        }
        printf(" Directions : ");
        wf = aux;
        while (wf != NULL) {
            printf("-> %s ", wf->dir);
            wf = wf->next;
        }
        printf("\n");
        return;
    }

    index++;
    struct WordFind *aux2 = wf;

    if (ws->N != NULL && ws->N->c[0] == word[index]) {
        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->N->c;
        wf->pos[0] = ws->N->pos[0];
        wf->pos[1] = ws->N->pos[1];
        wf->dir = "N";
        wf->next = NULL;
        recursiveSearchStructs(ws->N, word, aux, wf, index, n);
        wf = aux2;
    }
    if (ws->NE != NULL && ws->NE->c[0] == word[index]) {
        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->NE->c;
        wf->pos[0] = ws->NE->pos[0];
        wf->pos[1] = ws->NE->pos[1];
        wf->dir = "NE";
        wf->next = NULL;
        recursiveSearchStructs(ws->NE, word, aux, wf, index, n);
        wf = aux2;
    }

    if (ws->E != NULL && ws->E->c[0] == word[index]) {
        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->E->c;
        wf->pos[0] = ws->E->pos[0];
        wf->pos[1] = ws->E->pos[1];
        wf->dir = "E";
        wf->next = NULL;
        recursiveSearchStructs(ws->E, word, aux, wf, index, n);
        wf = aux2;
    }
    if (ws->SE != NULL && ws->SE->c[0] == word[index]) {
        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->SE->c;
        wf->pos[0] = ws->SE->pos[0];
        wf->pos[1] = ws->SE->pos[1];
        wf->dir = "SE";
        wf->next = NULL;
        recursiveSearchStructs(ws->SE, word, aux, wf, index, n);
        wf = aux2;
    }

    if (ws->S != NULL && ws->S->c[0] == word[index]) {

        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->S->c;
        wf->pos[0] = ws->S->pos[0];
        wf->pos[1] = ws->S->pos[1];
        wf->dir = "S";
        wf->next = NULL;
        recursiveSearchStructs(ws->S, word, aux, wf, index, n);
        wf = aux2;
    }

    if (ws->SW != NULL && ws->SW->c[0] == word[index]) {

        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->SW->c;
        wf->pos[0] = ws->SW->pos[0];
        wf->pos[1] = ws->SW->pos[1];
        wf->dir = "SW";
        wf->next = NULL;
        recursiveSearchStructs(ws->SW, word, aux, wf, index, n);
        wf = aux2;
    }


    if (ws->W != NULL && ws->W->c[0] == word[index]) {

        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->W->c;
        wf->pos[0] = ws->W->pos[0];
        wf->pos[1] = ws->W->pos[1];
        wf->dir = "W";
        wf->next = NULL;
        recursiveSearchStructs(ws->W, word, aux, wf, index, n);
        wf = aux2;
    }
    if (ws->NW != NULL && ws->NW->c[0] == word[index]) {

        wf->next = (struct WordFind *) malloc(sizeof(struct WordFind));
        wf = wf->next;
        wf->c = ws->NW->c;
        wf->pos[0] = ws->NW->pos[0];
        wf->pos[1] = ws->NW->pos[1];
        wf->dir = "NW";
        wf->next = NULL;
        recursiveSearchStructs(ws->NW, word, aux, wf, index, n);
    }
}

char *path(struct WordSearch *ws, struct Position *p) {
    char *pathString = (char *) malloc(p->n + 1);
    int j = 0;

    for (int i = 0; i < p->x; ++i) {
        if (ws->S != NULL) {
            ws = ws->S;
        } else
            printf("Coordenada invalida");

    }
    for (int i = 0; i < p->y; ++i) {
        if (ws->E != NULL) {
            ws = ws->E;
        } else
            printf("Coordenada invalida");
    }
    for (int i = 0; i < p->n; ++i) {

        if (strcmp(p->movements[i], "N") == 0 && ws->N != NULL) {
            ws = ws->N;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "NE") == 0 && ws->NE != NULL) {
            ws = ws->NE;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "E") == 0 && ws->E != NULL) {
            ws = ws->E;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "SE") == 0 && ws->SE != NULL) {
            ws = ws->SE;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "S") == 0 && ws->S != NULL) {
            ws = ws->S;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "SW") == 0 && ws->SW != NULL) {
            ws = ws->SW;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "W") == 0 && ws->W != NULL) {
            ws = ws->W;
            pathString[j] = ws->c[0];
        } else if (strcmp(p->movements[i], "NW") == 0 && ws->NW != NULL) {
            ws = ws->NW;
            pathString[j] = ws->c[0];
        }
        j++;

    }
    printf("%s", pathString);
    return pathString;
}

void  clientPathFind(struct Position *p, int n, int x, int y, char**movements){
    p->n=n;
    p->x=x;
    p->y=y;
    p->movements = (char**)malloc(sizeof(char*)*n);
    for (int i = 0; i < n; ++i) {
        p->movements[i] =(char*) malloc(n);
        strcpy(p->movements[i],movements[i]);
    }

}

void clientMergeSort(struct Queue *q,struct Node *n){
    int i = 0;
    while(q->front!=NULL){
        addElement(&n,q->front->word,i++);;
        q->front = q->front->nextWord;
    }
    MergeSort(&n,1);
    printListNode(n);
}