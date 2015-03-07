#include <stdio.h>
#include <string.h>
#define LIMIT 13

void enqueue(int);
void printQueue(void);
unsigned long long int g13Product(void);

int main(int argc, char *argv[]){
    int n; 
    unsigned long long int val = 1;

    if (argc < 2){
        fprintf(stderr, "%s: no input file found\n", argv[0]);
        return 1; 
    }
    FILE *fp;
    if ((fp = fopen(*++argv, "r")) == NULL){
        printf("error: cannot open %s\n", *argv);
        return 1;
    }

    while ((n = getc(fp)) != EOF){
        if (n != '\n')
            enqueue(n - '0');
        if (g13Product() > val)
            val = g13Product();
    }  
    printf("%llu\n", val);
    
    fclose(fp);

    return 0;
}

int buf[LIMIT];
int start = 0;


void enqueue(int n){
    if (n < 0)
        printf("error: %d %c\n", n, n + '0');
    buf[start] = n;
    start = (start + 1) % LIMIT;
}

unsigned long long int g13Product(void){
    int i;
    unsigned long long int val;
    i = 0;
    val = 1;
    for (i = 0; i < LIMIT; i++)
        val *= (unsigned long long int) buf[i];
}

void printQueue(){
    int i;
    for (i = 0; i < LIMIT; i++)
        printf("%d ", buf[i]);
    putchar('\n');
}
