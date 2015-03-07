/* Problem 25
 *
 * Get the first 1000th digit Fibonacci number
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"

int main(){
    num *first_term = init_num("1", 1);
    num *second_term = init_num("1", 1);
    num *a, *b;
    int i = 2;
    while (second_term->d < 1000){
        a = first_term;
        b = second_term;
        second_term = add(second_term, first_term);
        first_term = b;
        free(a);
        i++;
    }
    printf("%d\n", i);
}
