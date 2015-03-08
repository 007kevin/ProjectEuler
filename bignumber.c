/* @author k.k 03.02.2015
 * 
 * bignumber file that can add big numbers. 
 * 
 * todo: add other operations - * / %
 *       learn valgrind to check for memory leaks
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

/* will free all memory allocated to num */
void nfree(num *num){
    free(num->val);
    free(num);
}

/* init_num: will initialize num by taking in the character string and number of digits */
num *init_num(char *p){
    int n = strlen(p);
    num *np = (num *) malloc(sizeof(num));
    if (np == NULL)
        fprintf(stderr, "error: could not initialize struct num *np\n");
    char *num = (char *) malloc(sizeof(char) * n + 1);/* +1 for num terminator */
    if (num == NULL)
        fprintf(stderr, "error: could not initialize char *num\n");
    num[n] = '\0';
    np->d = n;
    /* reverse input of number string for easier application of operators */
    while (n)
        num[--n] = *p++;
    
    np->val = num;
    return np;
}


/* add: will take in two values of type num and return a num pointer with the summed value*/
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
    int value1, value2;
    while (--n){
        value1 = i < num1->d ? (num1->val)[i] - '0': 0 ;
        value2 = i < num2->d ?(num2->val)[i] - '0': 0;
        temp[i] = ((value1 + value2 + carryflag) % 10) + '0';
        if (value1 + value2 + carryflag > 9)
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
    np->d = i;
    return np;
}

num *multiply(num *num1, num *num2){
   /* multiply algorithm does less steps if num1 > num2.
    * For example, multiply(2, 1000000) is a low slower than multiply(1000000, 2) since the former
    * calls the add function 1000000, whereas the latter calls twice
    */
   if (numcmp(num1, num2) < 0){
        num *temp;

        temp = num1;
        num1 = num2;
        num2 = temp;
   }
   num *one = init_num("1"); //incrementor by one
   num *p = init_num("0"); //counter for number of times num1 is added to itself 
   num *value = init_num("0"); //value to be returned
   num *a; //pointer holders for freeing up memory 

   /* invariant: p is the number of times num1 has added to itself 
    * Before while loop, condition is true since num1 has been added to itself 0 times
    * After while loop, condition it true since num1 has been added to itself p times */
   while (numcmp(p, num2) != 0){
       a = value;
       value = add(value, num1);
       nfree(a); 
       a = p;
       p = add(p, one);
       nfree(a);
   }
   nfree(one);
   nfree(p);
   return value;
}

int numcmp(num *num1, num *num2){
    /*if num1 has less digits than num2, then num1 < num2 */
    if (num1->d < num2->d)
        return -1;
    
    /*if num1 has greater digits than num2, then num1 > num2 */
    else if (num1->d > num2->d)
        return 1;

    /*num1 and num2 have the same number of digits, but are not equal */
    else{
        int i;
        /* invariant: */
        for (i = num1->d - 1; i >= 0; i--){
            if ((num1->val)[i] > ((num2->val)[i]))
                return 1;
            if ((num1->val)[i] < ((num2->val)[i]))
                return -1;
        }
        /* found to be equal */
        return 0;
    }
}

void printnum(num *num1){
    int i = num1->d - 1;
    while (i >= 0)
        putchar((num1->val)[i--]);
    putchar('\n');
}





























