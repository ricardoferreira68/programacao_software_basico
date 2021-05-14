#include <stdio.h>
//#include <conio.h>
int main()
{
   char ch1,ch2,ch3;
   //ch1=getch();     // Não exibe o caractere na tela
   //ch2=getche();   // Exibe o caractere na tela
   ch3=getchar(); // Exibe o caractere na tela e aguarda
                             // Enter para armazenar na variável ch3
   printf("%c %c %c", ch1, ch2, ch3);
}
