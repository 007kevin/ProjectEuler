/* @author k.k 03.02.2015
 * 
 * bignumber file that can add big numbers. 
 * todo: add other operations - * / %
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"


/* init_num: will initialize num by taking in the character string and number of digits */
num *init_num(char *p, int n){
    num *np = (num *) malloc(sizeof(num));
    if (np == NULL)
        fprintf(stderr, "error: could not initialize struct num *np\n");
    char *num = (char *) malloc(sizeof(char) * n + 1);
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

num *multiply(num *, num *){
    
}
<<<<<<< HEAD

int numcmp(num *num1, num *num2){
    /*if num1 has less digits than num2, then num1 < num2 */
    if (num1->d < num2->d)
        return -1;
    
    /*if num1 has greater digits than num2, then num1 > num2 */
    else if (num1->d > num->d)
        return 1;

    /*if string representation of digits are equal, the values are equal */
    else if (strcmp(num1->val, num2->val) == 0)
        return 0

    /*num1 and num2 have the same number of digits, but are not equal */
    else{
        int i;
        /* invariant: i is the i'th digit to compared, indexed [0 num1->d) */
        for (i = num1->d - 1; i >= 0; i--)
            if ((num1->val)[i] > ((num2->va)[i]))
                return 1;
            if ((num1->val)[i] < ((num2->val)[i]))
                return -1;
        }
        /* found to be equal */
        return 0
    }
}




























=======
>>>>>>> 4cce84b548066c06fd40327a483b6aeb1b7d94da
