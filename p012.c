#include <stdio.h>

int numOfDivisors(int n);

int main(int argc, char** argv){
  int factor = 1;
  int value = 0;
  while (numOfDivisors(value) < 502){
    value = value + factor++;
  }
  printf("%d\n", value);
  return 0;
}

int numOfDivisors(int n){
  int i;
  int num = 0;
  for (i = 1; i <=n; ++i){
    if (n % i == 0)
      num++;
  }
  return num;
}
