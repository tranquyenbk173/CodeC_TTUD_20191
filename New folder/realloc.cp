#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char *str;

   /* lan cap phat bo nho ban bau */
   str = (char *) malloc(15);
   strcpy(str, "VietJackTeam");
   printf("Chuoi = %s,  tai Dia chi = %u\n", str, str);

   /* tai cap phat lai bo nho */
   str = (char *) realloc(str, 25);
   strcat(str, "@gmail.com");
   printf("Chuoi = %s,  tai Dia chi = %u\n", str, str);

   free(str);

   return(0);
}
