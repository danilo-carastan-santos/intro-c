#include <stdio.h>

int main(){
  int ducks = 12;
  int *quacks = &ducks;
  printf("ducks=%p, quacks=%d\n", &ducks, *quacks);

  //ducks = 45;
  //printf("ducks=%d, quacks=%p\n", ducks, quacks);
  //*quacks = 67;
  //printf("ducks=%p, quacks=%d\n", &ducks, *quacks);
}