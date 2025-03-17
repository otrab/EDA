#include <stdio.h>

void operacion(int *x, int y, int *z);

int main(void)
{	
int x=3;	int y=5;	int z=8;		
printf("x:%i,y:%i, z:%i antes de operacion\n", x,y,z);	
operacion(&x,y,&z);
printf("x:%i,y:%i, z:%i después de operación\n", x,y,z);	
}

void operacion(int *x, int y, int *z)
{	
*x=*x*2;	
 y=y**x;	
 *z=*x+y;
}
