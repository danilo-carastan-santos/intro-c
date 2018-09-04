#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if(argc <= 1){
   	return -1;
  }  
  int n = atoi(argv[1]); 

  if(n > 10){
  	printf("n is greater than 10\n");
   }
  else if(n == 10){
  	printf("n is actually 10\n");
  }
  else{
  	printf("n is lower and it's not 10\n");
  }

}