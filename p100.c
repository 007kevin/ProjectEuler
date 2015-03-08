/* if a box contains twenty-one coloured discs, composed of fifteen
 * blue discs and six red discs, and two discs are taken at random, 
 * it can be seen the probability of taking two blue discs,
 * P(BB) = (15/21)*(14/20) = 1/2
 *
 * The next such arrangement, for which there is exactly 50% chance
 * of taking two blue discs at random is a box contains 85 blue 
 * discs and 35 red discs
 * P(BB) = (85/120) * (84/119) = 1/2
 *
 * By finding the arrangement to contain over 
 * 10^12 = 1,000,000,000,000 discs in total, determine the number
 * of blue discs that the box would contain.
 */
#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"

int main(void){
    num *n1, *n2, *n3; 
    n1 = init_num("1000000000000");
    n2 = init_num("2");

    n3 = multiply(n2,n1); //multiply algorithm is faster if param1 > param2
    printnum(n3);

    nfree(n1);
    nfree(n2);
    nfree(n3);
    return 0;
}
