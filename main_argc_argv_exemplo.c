#include <stdio.h>
int main(int argc, char **argv)
{
    printf("argc: %d\n", argc);
    printf("int main(\"");
    for(int i=0;i<argc;i++)
        printf("%s\", ", argv[i]);
    printf(")\n");
	return 0;
}
