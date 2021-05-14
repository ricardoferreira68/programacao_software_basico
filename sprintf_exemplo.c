#include<stdio.h>
int main() 
{
   int j=32;
   char cha='m';
   float a=123.2;
   char str[20];
   sprintf(str, "%d %c %3.1f\n", j, cha, a);
   printf("%s", str);
}
