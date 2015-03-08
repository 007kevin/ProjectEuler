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

/* init_num: @param buffer conting string representation of a number and number of digits
 *           @return num type
 *           note: do not have to input char number buffer in reversed order. 
 *                 function will reverse automatically */
num *init_num(char *, int);

/* add: return sum */
num *add(num *, num *);

<<<<<<< HEAD
/* multiply: return product of two numbers */
num *multiply(num * ,num *);

/* numcmp: compares two nums. returns either -1, 0, 1 */
int numcmp(num *, num*);
=======
num *multiply(num *, num *);
>>>>>>> 4cce84b548066c06fd40327a483b6aeb1b7d94da
