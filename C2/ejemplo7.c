#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void llena_arreglo(int arreglo[]);
void imprime_arreglo(int arreglo[]);

int main(void)
{	
  int A1[10], A2[10];
  srand(time(NULL));	
  llena_arreglo(A1);	
  llena_arreglo(A2);	
  imprime_arreglo(A1);	
  imprime_arreglo(A2);
}

void llena_arreglo(int arreglo[]){	
  for(int i=0; i<10; i++)    arreglo[i]=rand()%10;}

void imprime_arreglo(int arreglo[]){	
   for(int i=0; i<10; i++)  printf("%i\t", arreglo[i]);	
   printf("\n");}
