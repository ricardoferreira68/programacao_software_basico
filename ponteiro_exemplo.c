#include <stdio.h>
int main (void) 
{
	int var; 
	int *ptr; 
	var = 10;
	ptr = &var;
	printf("                      var: %d\n", var);
	printf("          endereço de var: %p\n", &var);
	printf("                      ptr: %p\n", ptr);
	printf("conteúdo apontado por ptr: %d\n", *ptr);
	return 0;
}
