#include<stdio.h>
#include<math.h>
int main()
{
    char a, b = 'b', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g';
    printf("\n Ket qua cua bieu thuc dieu kien la: ");
    a = 0?b:(e?f:g);
    printf(" %c", a);
}
