/* @author k.k Winter 2015
 *
 * Project Euler
 * Problem 22
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
 * begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, 
 * is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMIT 10000
#define OPEN 1
#define CLOSE 0

/* inputName: input name from buffer into nameList*/
void inputName(char *);

/* printlist: print all values from nameList*/
void printlist(void);

/* q_sort: sort v[left]...v[right] into increaseing order, K&R p.99*/
void q_sort (char *v[], int left, int right);

/*buffer to store names*/
char *nameList[LIMIT];
/*index for nameList*/
int listIndex = 0;


int main(int argc, char *argv[]){
    FILE *fp;
    if ((fp = fopen(*++argv, "r")) == NULL){
        fprintf(stderr, "%s: cannot open file.\n", *(argv - 1));
        exit(1);
    }
     
    int c,i, scoreSum, score, flag = CLOSE;
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
    q_sort(nameList, 0, listIndex - 1);
    printf("The names: \n");
    printlist(); 
    scoreSum = 0;
        for (i = 0; i < listIndex; i++){
        scoreSum += nameScore(nameList[i]) * (i + 1);
    }

    printf("%d\n", scoreSum);
    return 0;

}


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


void q_sort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /*do nothing if array contains fewer than two elements*/
        return;
    swap(v, left, (left + right)/2); /*store pivot value*/
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);    /*restore pivot value to its correct position*/
    q_sort(v, left, last-1);
    q_sort(v, last + 1, right);
}

/*swap: interchange v[i] and v[j]*/
void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int nameScore(char *p){
    int i = 0;
    while(*p){
        i += (*p++ - 'A' + 1);
    }
    return i;
}






