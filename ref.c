#include <stdio.h>

void sum(int number){
  number = number + 1;
}

void _sum(int* number){
  *number = *number + 1;
}

int main(){
  int n = 2;
  //sum(n);
  //printf("Is n equals 3 now? n = %d\n", n);
  _sum(&n);
  printf("Is n equals 3 now? n = %d\n", n);
}
