#include <stdio.h> 

void intercambia (int *a, int *b);

int main(void)
{	
  int a=1;	
  int b=3;		
  
  printf("Valor de a: %i. Valor de b: %i\n", a,b);	
  intercambia(&a,&b);	
  printf("Valor de a: %i. Valor de b: %i\n", a,b);
}

void intercambia(int *a,int *b)
{	
  int aux;	
  
  aux=*b;	
  *b=*a;	
  *a=aux;	
  printf("Dentro de función, a: %i, b:%i\n", *a,*b);
}
