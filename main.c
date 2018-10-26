
#include"functions.h"

int main() {

    char **wordsearch = createManually(MAXSEARCH,MAXSEARCH);
    /*char words[MAXWORDS][MAXSEARCH] = {{'P', 'O', 'R', 'T', 'O'},
                                       {'A', 'V', 'E', 'I', 'R', 'O'},
                                       {'C', 'O', 'I', 'M', 'B', 'R', 'A'},
                                       {'F', 'A', 'R', 'O'},
                                       {'L', 'I', 'S', 'B', 'O', 'A'}
    };*/

    char **test = readFromFile(MAXSEARCH,MAXSEARCH);

    //printMatrix(wordsearch);
    printMatrix(test, MAXSEARCH, MAXSEARCH);
    return 0;
}