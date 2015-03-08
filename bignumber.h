/* @author k.k
 *
 * bignumber header
 *
 */
typedef struct{
    int d; /* value indicates the number of digits*/
    char *val; /* array to represent number (will be reversed to make operation 
                implementations easier)
              */
} num;
/* nfree: will free the memory of the string representation of the value as well as the num struct */
void nfree(num *);

/* init_num: @param buffer conting string representation of a number and number of digits
 *           @return num type
 *           note: do not have to input char number buffer in reversed order. 
 *                 function will reverse automatically */
    
num *init_num(char *);

/* add: return sum */
num *add(num *, num *);

/* multiply: return product of two numbers */
num *multiply(num * ,num *);

/* numcmp: compares two nums. returns either -1, 0, 1 */
int numcmp(num *, num*);

/* print: will print the number value as intended to be displayed
 * (i.e unreversed) */
void printnum(num *);
