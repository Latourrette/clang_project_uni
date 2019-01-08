
#include"functionsPhase2.h"


void printMenu();

void printSubMenu();

int main() {

    //char **wordsearch = generateWordSearch(MAXSEARCH,MAXSEARCH);
    char **wordsearch1 = readFromFile(ROW,COL);
    //char **bagOfWords = createManuallyBagOfWords(MAXWORDS,BUFFER);
    char **bagOfWords2 = readFromFileBagOfWords(MAXWORDS,BUFFER);

    for (int i = 0; i < MAXWORDS; ++i) {
           findWords(wordsearch1,bagOfWords2[i]);
    }

    //printMatrix(wordsearch, MAXSEARCH,MAXSEARCH);
    //printf("\n\n");
    //printMatrix(wordsearch2, MAXSEARCH,MAXSEARCH);
    //printBagOfWords(bagOfWords,MAXWORDS);
    //printf("\n\n");
    //printBagOfWords(bagOfWords2,MAXWORDS);*/

    /* StringElementsArray* bag = (StringElementsArray*) malloc(sizeof(StringElementsArray));
     StringElementsArray* aux = (StringElementsArray*) malloc(sizeof(StringElementsArray));

     createStringElementsArrayAndFill(bag,MAXWORDS,bagOfWords);
     createStringElementsArray(aux,MAXWORDS);
     printStringElementsArray(bag);

     msdSortClient(bag,aux);
     printStringElementsArray(bag);
     freeStringElementsArray(bag);
     free(bagOfWords);*/

    /*for (int i = 0; i <  MAXWORDS; ++i) {
        findWords(wordsearch2,bagOfWords[i]);
    }*/


    /*char **bagOfWords;
    char **wordSearch;
    int menu;
    char c;
    bool exit = true;



    while (exit) {
        printMenu();
        fflush(stdin);
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                system("clear");
                bagOfWords = readFromFileBagOfWords(MAXWORDS, BUFFER);
                printBagOfWords(bagOfWords, MAXWORDS);
                printf("\n-------------------------------\n\n");
                printf("Aplicar MSD na lista de palavras?(y/n)\n");
                fflush(stdin);
                c = getchar();
                scanf("%c", &c);
                if (c == 'y') {
                    StringElementsArray *bag = (StringElementsArray *) malloc(sizeof(StringElementsArray));
                    StringElementsArray *aux = (StringElementsArray *) malloc(sizeof(StringElementsArray));

                    createStringElementsArrayAndFill(bag, MAXWORDS, bagOfWords);
                    createStringElementsArray(aux, MAXWORDS);
                    printStringElementsArray(bag);
                    freeStringElementsArray(bag);
                    freeStringElementsArray(aux);
                }
                break;
            case 2:
                system("clear");
                wordSearch = readFromFile(ROW, COL);
                printMatrix(wordSearch, ROW, COL);
                break;
            case 3:
                system("clear");
                int row, col;
                printf("\n\nIndique linhas e colunas:\n>");
                scanf("%d", &row);
                printf(">");
                scanf("%d", &col);
                wordSearch = generateWordSearch(row, col);
                printMatrix(wordSearch, row, col);
                break;
            case 4:
                system("clear");
                findWords(wordSearch,bagOfWords);
                break;
            case 5:
                system("clear");
                wordSearch = NULL;
                bagOfWords = NULL;
                break;
            case 0:
                system("clear");
                printf("Bye!");
                exit=false;
                break;
            default:
                printf("Opção inválida!\n Tente outra vez!");
                printMenu();
        }
    }*/

    char **bagOfWords = readFromFileBagOfWords(MAXWORDS, BUFFER);
    //printBagOfWords(bagOfWords,MAXWORDS);

    struct Queue q;
    initQueue(&q);
    pushWords(&q, bagOfWords, MAXWORDS);

    //printList(q.front);
    //mergeSort(q.front);

    char **wordSearch = readFromFile(ROW, COL);
    //printMatrix(wordSearch,ROW,COL);
    struct WordSearch ws;
    initWordSearch(&ws);
    insertIntoWS(&ws, wordSearch);
    /*while (q.front != NULL) {
        findWordsStructs(&ws, q.front->word);
        q.front = q.front->nextWord;
    }*/
    /*struct Position p;
    p.n=5;
    p.x=3;
    p.y=4;
    p.movements = (char**)malloc(sizeof(char*)*5);
    for (int i = 0; i < 5; ++i) {
        p.movements[i] =(char*) malloc(3);
    }
    p.movements[0]="E";
    p.movements[1]="E";
    p.movements[2]="N";
    p.movements[3]="NW";
    p.movements[4]="W";
    char *aaa = path(&ws,&p);*/
    //printWordSearch(&ws);

    return 0;
}

void printMenu() {
    printf("\n\n\nProjeto -- AED I e LP I -- Fase 1 --\n");
    printf("----------------------------------------------------\n");
    printf("1. Carregar lista de palavras de ficheiro e imprimir\n");
    printf("2. Carregar sopa de letras de ficheiro e imprimir\n");
    printf("3. Gerar sopa de letras aleatoriamente e imprimir\n");
    printf("4. Pesquisar as palavras na sopa de letras.\n");
    printf("5. Reset nas estruturas de dados");
    printf("\n0. Sair");
    puts("\n");
    printf("> ");
}

