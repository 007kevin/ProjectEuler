#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

//num *add(num *, num*);
int main(){
    num *x, *y, *z;
    x = init_num("123456", 6);
    y = init_num("354", 3);
    z = add(x, y);
    printf("%s\n", z->val);
    return 0;
}

num *init_num(char *p, int n){
    num *np = (num *) malloc(sizeof(num));
    if (np == NULL)
        fprintf(stderr, "error: could not initialize struct num *np\n");
    char *num = (char *) malloc(sizeof(char) * n + 1);
    if (num == NULL)
        fprintf(stderr, "error: could not initialize char *num\n");
    num[n] = '\0';
    np->d = n;
    while (n)
        num[--n] = *p++;
    
    np->val = num;
    return np;
}

num *add(num *num1, num *num2){
    int n, m;
    /* add one to n to always account for potential carry over */
    if (num1->d > num2->d){
        n = num1->d + 1;
        m = num2->d;
    }
    else{
        m = num1->d;
        n = num2->d + 1;
    }
    num *np = (num *) malloc(sizeof(num));
    char *temp = (char *) malloc(sizeof(char) * n + 1); /* add one for null terminator*/
    if (temp == NULL)
        fprintf(stderr, "error: could not initialize temp in add function\n");
    int i = 0, carryflag = 0;
    char *val1 = num1->val, *val2 = num2->val;
    while (m--){//check --m if fail
        temp[i] = (((val1[i] - '0') + (val2[i] - '0') + carryflag) % 10) + '0';
        if ((val1[i] - '0') + (val2[i] - '0') > 9)
            carryflag = 1;
        else
            carryflag = 0;
        i++;
    }
    if (carryflag){
        temp[i++] = '1';
    }
    temp[i] = '\0';
    np->val = temp;
    np->d = i - 1;
    return np;
}