#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int val;
   char str[20];

   gets(str);
   val = atoi(str);
   printf("Gia tri duoi dang chuoi = %s, \nGia tri duoi dang so nguyen = %d\n", str, val);

   strcpy(str, "vietjack.com");
   val = atoi(str);
   printf("\nGia tri duoi dang chuoi = %s, \nGia tri duoi dang so nguyen = %d\n", str, val);

   return(0);
}
