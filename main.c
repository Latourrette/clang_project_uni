
#include"functions.h"
#include "stringsort.h"

int main() {

    //char **wordsearch = generateWordSearch(MAXSEARCH,MAXSEARCH);
    char **wordsearch2 = readFromFile(ROW,COL);
    char **bagOfWords = createManuallyBagOfWords(MAXWORDS,BUFFER);
    //char **bagOfWords2 = readFromFileBagOfWords(MAXWORDS,MAXSEARCH);

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

    for (int i = 0; i <  MAXWORDS; ++i) {
        findWords(wordsearch2,bagOfWords[i]);
    }
    return 0;
}