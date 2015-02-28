#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMIT 10000
#define OPEN 1
#define CLOSE 0

void inputName(char *);
void printlist(void);
int listIndex = 0;


int main(int argc, char *argv[]){
    FILE *fp;
    if ((fp = fopen(*++argv, "r")) == NULL){
        fprintf(stderr, "%s: cannot open file.\n", *(argv - 1));
        exit(1);
    }
     
    int c, flag = CLOSE;
    char name[100];
    int nameIndex = 0;
    while ((c = fgetc(fp)) != EOF){
        if (c == ',')
            flag = CLOSE;
        if (c == '\"')
            flag = OPEN;
        while (flag == OPEN && (c = fgetc(fp))){
            if (c == '\"')
              flag = CLOSE;
            else{
              name[nameIndex++] = c; 
            }
        }
        if (nameIndex){
            name[nameIndex] = '\0';
            nameIndex = 0;
            inputName(name);
        }
    }

    printf("The names: \n");
    printlist(); 
    return 0;
}

char *nameList[LIMIT];

void inputName(char *n){
    char *p = malloc(strlen(n + 1));//n + 1 for null terminator
    strcpy(p, n);
    nameList[listIndex++] = p;
}

void printlist(){
    int i;
    for (i = 0; i < listIndex; i++)
         printf("%s\n", nameList[i]);
}
