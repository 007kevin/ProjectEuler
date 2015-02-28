#include <stdio.h>
#include <stdlib.h>

#define MAXDIGITS 1000

typedef struct {
    int ndigits;
    char d[MAXDIGITS];
}num;

num *init_num(size_t, char *);

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

    size_t bytes = 51;
    char *numbuffer = (char *) malloc(bytes); //Allocate memory for character buffer for storing line
    getline(&numbuffer, &bytes, fp); //first parameter must be char** (i.e pointer to a pointer to a char)
                                     //so the getline function is able to update value of the char that it points to
    num *val = init_num(bytes, numbuffer);

    printf("%s\n", val->d); 
    
    

    return 0;
}

/* init_num for storing the value from buffer into a num structure */
num *init_num(size_t n, char *p){
    num *q = (num *) malloc(sizeof(num)); //allocate memory for num structure
    q->ndigits = n; //Set number of digits in the big number
    char *r = q->d;
    while ((*r++ = *p++) != '\n')
        ;
    return q;
}
