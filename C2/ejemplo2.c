#include <stdio.h> 

int main()
{
	int a=1;
	int *p;
	printf("El valor almacenado en a es: %i\n", a);

	p= &a;
	*p=3;
	printf("El valor almacenado en a es: %i\n", *p);
	//printf("El valor almacenado en a es: %i\n", a);
}
