#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){    
  if(argc <= 1){
    return -1;
  }
  //max 10000000;
  int n = atoi(argv[1]);  
  
  //printf("Allocating memory for vector s_vec.\n");
  //int s_vec[n];
  //printf("Done allocating memory for s_vec!\n");

  //return 0;  

  printf("Dynamically allocating memory for vector h_vec.\n");
  int* h_vec = (int*) malloc(n * sizeof(int));
  //free(h_vec);

  int i, j;  
  printf("Done allocating memory for h_vec!\n");
  //printf("Memory address of h_vec = %p\n", h_vec);

  
  for(i = 0; i < n; i++){    
      h_vec[i] = i / 4;   
  } 
   
  printf("Printing the whole h_vec.\n");
  for(i = 0; i < n; i++){    
    printf("%d ", h_vec[i]); 
	//printf("%d ", *(h_vec + i));
  }
  printf("\n");

  //return 0;
  
  //printf("%d %d %d\n", *h_vec, *(h_vec+1), *(h_vec+2));
  
  printf("Printing only a part of h_vec.\n");
  //int* start_point = &h_vec[4];
  int* start_point = h_vec + 4;  
   
  for(i = 0; i < n - 4; i++){   
    printf("%d ", start_point[i]); 
  }
  printf("\n");
  
  free(h_vec);

  return 0;  
}

