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

