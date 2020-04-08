#include<stdio.h>
#include<conio.h>
int tong(int a, int b)
{
	return a+b;
}
int main()
{
	int a, b, c;
	printf("\n Nhap vao hai so a, b: ");
	printf("\n \t a = "); scanf("%d", &a);
	printf("\n \t b = "); scanf("%d", &b);
	c = tong(a, b);
	printf("\n a + b = %d", c);
	getch();
	return 0;
}
