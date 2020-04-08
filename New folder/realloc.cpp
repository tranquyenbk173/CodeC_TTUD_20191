#include <stdio.h>
#include <stdlib.h>
int main()
{
   int *a, *b;
   a = (int*) malloc(sizeof(int));
   *a = 123;
   printf("\n Gia tri cua a la: %d, tai dia chi %d", *a, a);
   b = (int*) realloc(a, sizeof(float));
   printf("\n Gia tri cua b la: %d, tai dia chi %d", *b, b);
   free(a); free(b);
   return(0);
}
