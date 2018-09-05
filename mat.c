#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){    
  if(argc <= 1){
    return -1;
  }
  //max 10000;
  int n = atoi(argv[1]);  
  
  //printf("Statically allocating memory for vector s_matrix.\n");
  //int s_matrix[n][n];
  //printf("Done allocating memory for s_matrix!\n");  

  printf("Dynamically allocating memory for matrix h_matrix.\n");
  /*
  A matrix in C can be seen as a vector of vectors, that is, a pointer of pointers
  h_matrix is a vector which each positon will contain a memory address of a row
  of the matrix
  */
  int** h_matrix = (int**) malloc(n * sizeof(int*));
  //So far each row is empty (not allocated)
  //Now we need to allocate memory for each row
  int i, j;
  for(i = 0; i < n; i++){
    h_matrix[i] = (int*) malloc(n * sizeof(int));
  }
  printf("Done allocating memory for h_matrix!\n");

  //Here i am filling h_matrix with some data, nothing special
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      h_matrix[i][j] = i / 4; 
    }
  } 
   
  printf("Printing the whole matrix.\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", h_matrix[i][j]);
    }
  printf("\n");
  }
  
  /*
  Similar with vectors, we can play with memory addresses
  here i am getting the memory address of the row with position 5
  */
  printf("Printing only a part of h_matrix.\n");
  int** start_point = &h_matrix[5]; 
 
  for(i = 0; i < n/4; i++){
    for(j = 0; j < n; j++){
      printf("%d ", start_point[i][j]);
    }
  printf("\n");
  }
  

/*
//Here i am using a vector in the same way as a matrix.
//It is a little more complicated. Uncomment lines 60 and 92
//if you feel like understanding how it works
  printf("\"Flattening\" h_matrix into a single vector f_matrix.\n");
  int* f_matrix = (int*) malloc(n * n * sizeof(int));

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      f_matrix[i * n + j] = i / 4; 
    }
  }

  printf("Printing f_matrix.\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", f_matrix[i * n + j]);
    }
  printf("\n");
  }

  printf("Printing only a part of f_matrix.\n");
  int* _start_point = &f_matrix[0 * n]; 
 
  for(i = 0; i < n/4; i++){
    for(j = 0; j < n; j++){
      printf("%d ", _start_point[i * n + j]);
    }
  printf("\n");
  }

  free(f_matrix);
*/


//Freeing a matrix is more complicated. First we need to free each row
  for(i = 0; i < n; i++){
    free(h_matrix[i]);
  }
//And then finally the whole matrix
  free(h_matrix); 

  return 0;  
}