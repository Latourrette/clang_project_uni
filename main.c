
#include"functions.h"
#include "stringsort.h"

int main() {

    //char **wordsearch = generateWordSearch(MAXSEARCH,MAXSEARCH);
    char **wordsearch2 = readFromFile(MAXSEARCH,MAXSEARCH);
    char **bagOfWords = createManuallyBagOfWords(MAXWORDS,MAXSEARCH);
    //char **bagOfWords2 = readFromFileBagOfWords(MAXWORDS,MAXSEARCH);

    //printMatrix(wordsearch, MAXSEARCH,MAXSEARCH);
    //printf("\n\n");
    //printMatrix(wordsearch2, MAXSEARCH,MAXSEARCH);
    //printBagOfWords(bagOfWords,MAXWORDS);
    //printf("\n\n");
    //printBagOfWords(bagOfWords2,MAXWORDS);*/

    StringElementsArray* bag = (StringElementsArray*) malloc(sizeof(StringElementsArray));
    StringElementsArray* aux = (StringElementsArray*) malloc(sizeof(StringElementsArray));

    createStringElementsArrayAndFill(bag,MAXWORDS,bagOfWords);
    createStringElementsArray(aux,MAXWORDS);
    printStringElementsArray(bag);

    msdSortClient(bag,aux);
    printStringElementsArray(bag);
    freeStringElementsArray(bag);
    free(bagOfWords);

    return 0;
}