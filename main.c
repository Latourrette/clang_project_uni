#include<stdio.h>
#include<string.h>

/*Maximum size for word search*/
#define MAXSEARCH 10
#define MAXWORDS  20

int main() {

    char wordsearch[MAXSEARCH][MAXSEARCH] = {{'J', 'D', 'C', 'P', 'C', 'P', 'X', 'O', 'A', 'A'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
                                             {'N', 'D', 'L', 'E', 'I', 'R', 'B', 'I', 'E', 'A'},
                                             {'Y', 'T', 'R', 'Q', 'O', 'M', 'O', 'I', 'I', 'O'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
                                             {'Z', 'X', 'V', 'O', 'V', 'X', 'F', 'R', 'V', 'V'},
    };

    char words[MAXWORDS][MAXSEARCH] = {{'T', 'H', 'E', 'O', 'R', 'Y'},
                                       {'S', 'T', 'R', 'I', 'N', 'G'},
                                       {'A', 'R', 'R', 'A', 'Y'},
                                       {'A', 'P', 'P', 'L', 'E'},
                                       {'E', 'N', 'G', 'I', 'N', 'E', 'E', 'R'},
                                       {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'},
                                       {'P', 'H', 'Y', 'S', 'I', 'C', 'S'},
                                       {'C', 'A', 'L', 'C', 'U', 'L', 'U', 'S'},
                                       {'A', 'L', 'G', 'E', 'B', 'R', 'A'},
                                       {'T', 'I', 'G', 'E', 'R'},
                                       {'B', 'R', 'I', 'D', 'G', 'E'},
                                       {'N', 'E', 'T', 'W', 'O', 'R', 'K'},
                                       {'P', 'R', 'O', 'G', 'R', 'A', 'M'},
                                       {'H', 'O', 'U', 'S', 'E'},
                                       {'E', 'Q', 'U', 'A', 'T', 'I', 'O', 'N'},
                                       {'M', 'E', 'M', 'O', 'R', 'Y'},
                                       {'S', 'L', 'E', 'E', 'P'},
                                       {'L', 'O', 'G', 'I', 'C'},
                                       {'S', 'Y', 'S', 'T', 'E', 'M'},
                                       {'P', 'I', 'A', 'N', 'O'}};

    int i = 0;
    int j = 0;

    for (i = 0; i < MAXSEARCH; i++) {
        for (j = 0; j < MAXSEARCH; j++) {
        }
    }

    for (i = 0; i < MAXSEARCH; i++) {
        for (j = 0; j < MAXSEARCH; j++) {
        }
    }
    return 0;
}