#include <stdio.h>

int main(void)
{	
  int a=5;	
  int *p;		

  p=&a;

  
  printf("El valor almacenado en a es: %i\n", a);
  printf("La dirección de memoria de la variable a es; %p\n", &a);
  printf("La dirección de memoria almacenada en el puntero p es: %p\n", p);
  printf("La dirección de memoria del puntero p es: %p\n", &p);

  return 0;
}
