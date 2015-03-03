/* @author k.k 03.02.2015
 *
 * Problem 13
 * Write out the first ten digits of the sum of the following one-hundred
 * 50 digit numbers (located in the file p13.txt)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"

#define MAXDIGITS 1000
#define BYTES 51


int main(int argc, char *argv[]){
    char *prog = *argv; //Store program name
    FILE *fp;
    if (argc < 2){
        fprintf(stderr, "%s: no input file found\n", prog);
        exit(1); 
    }
    if ((fp = fopen(*++argv, "r")) == NULL){
        fprintf(stderr, "%s: error opening %s\n", prog, *argv);
        exit(1);
    }
    num *x, *y, *z;
    size_t bytes = BYTES;
    char *numbuffer = (char *) malloc(BYTES * sizeof(size_t)); //Allocate memory for character buffer for storing line
    x = init_num("0", 1);
    while (getline(&numbuffer, &bytes, fp) > 0){ //first parameter must be char** (i.e pointer to a pointer to a char)
        y = init_num(numbuffer, BYTES - 1);
        z = x;
        x = add(z, y);
        free(y);
        free(z);
    }
                                     //so the getline function is able to update value of the char that it points to

    printf("%s\n", x->val); 
    
    

    return 0;
}
