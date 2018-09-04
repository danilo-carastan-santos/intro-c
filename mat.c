#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){    
  if(argc <= 1){
    return -1;
  }
  //max 10000;
  int n = atoi(argv[1]);  
  
  printf("Alocando memoria para matriz s_matriz.\n");
  int s_matriz[n][n];
  printf("Alocacao da s_matriz feita com sucesso!\n");  

  printf("Alocando ponteiro bidimensional h_matriz.\n");
  int** h_matriz = (int**) malloc(n * sizeof(int*));
  int i, j;
  for(i = 0; i < n; i++){
    h_matriz[i] = (int*) malloc(n * sizeof(int));
  }
  printf("Alocacao da h_matriz feita com sucesso!\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      h_matriz[i][j] = i / 4; 
    }
  } 
   
  printf("Imprimindo h_matriz inteira.\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", h_matriz[i][j]);
    }
  printf("\n");
  }
  
  printf("Imprimindo apenas um pedaco de h_matriz.\n");
  int** start_point = &h_matriz[0]; 
 
  for(i = 0; i < n/4; i++){
    for(j = 0; j < n; j++){
      printf("%d ", start_point[i][j]);
    }
  printf("\n");
  }
  
  printf("\"Achatando\" h_matriz em um ponteiro unidimensional f_matriz.\n");
  int* f_matriz = (int*) malloc(n * n * sizeof(int));

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      f_matriz[i * n + j] = i / 4; 
    }
  }

  printf("Imprimindo f_matriz.\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", f_matriz[i * n + j]);
    }
  printf("\n");
  }

  printf("Imprimindo apenas um pedaco de f_matriz.\n");
  int* _start_point = &f_matriz[0 * n]; 
 
  for(i = 0; i < n/4; i++){
    for(j = 0; j < n; j++){
      printf("%d ", _start_point[i * n + j]);
    }
  printf("\n");
  }

  for(i = 0; i < n; i++){
    free(h_matriz[i]);
  }
  free(h_matriz);

  free(f_matriz);

  return 0;  
}



