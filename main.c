
#include"functionsPhase2.h"


void printMenu();

void printSubMenu();

int main() {

    char **wordsearch = readFromFile(ROW,COL);
    char **bagOfWords = readFromFileBagOfWords(MAXWORDS,BUFFER);


//     StringElementsArray* bag = (StringElementsArray*) malloc(sizeof(StringElementsArray));
//     StringElementsArray* aux = (StringElementsArray*) malloc(sizeof(StringElementsArray));
//
//     createStringElementsArrayAndFill(bag,MAXWORDS,bagOfWords);
//     createStringElementsArray(aux,MAXWORDS);
//     printStringElementsArray(bag);
//
//     msdSortClient(bag,aux);
//     printStringElementsArray(bag);
//     freeStringElementsArray(bag);
//     free(bagOfWords);

//    for (int i = 0; i <  MAXWORDS; ++i) {
//        findWords(wordsearch,bagOfWords[i]);
//    }


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

    //char **bagOfWords = readFromFileBagOfWords(MAXWORDS, BUFFER);
    //printBagOfWords(bagOfWords,MAXWORDS);

//    struct Queue q;
//    initQueue(&q);
//    pushWords(&q, bagOfWords, MAXWORDS);
//
//    struct Node *n = NULL;
//    clientMergeSort(&q,n);


    char **wordSearch = readFromFile(ROW, COL);
    //printMatrix(wordSearch,ROW,COL);
    struct WordSearch ws;
    initWordSearch(&ws);
    insertIntoWS(&ws, wordSearch);
    /*while (q.front != NULL) {
        findWordsStructs(&ws, q.front->word);
        q.front = q.front->nextWord;
    }*/
    struct Position p;
    char ** movements;

    movements = (char**)malloc(sizeof(char*)*5);
    for (int i = 0; i < 5; ++i) {
        movements[i] =(char*) malloc(3);
    }

    movements[0]="E";
    movements[1]="E";
    movements[2]="N";
    movements[3]="NW";
    movements[4]="W";
    clientPathFind(&p,5,3,4,movements);
    char *aaa = path(&ws,&p);
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

