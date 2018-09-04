#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if(argc <= 1){
   	return -1;
  }  
  int n = atoi(argv[1]); 

/*
//Let's increase n until it reaches the value 10
  while(n < 10){
    printf("n = %d\n", n);
    n = n + 1;
  }


printf("end of the loop n = %d\n", n);
*/


//Let's increase n 10 times
  int i;
  for (i = 0; i < 10; i = i + 1){
    printf("n = %d. number of times increased = %d\n", n, i + 1);
    n = n + 1;
  }


}