// Tran Thi Quyen _ 20173333 _ KHMT. 01 - K62
#include<stdio.h>
#include<conio.h>
struct TIME 
{
	int h;
	int m;
};
void print(struct TIME a)
{
	printf("%dh %dm", a.h, a.m);
}
void newtime(struct TIME & a)
{
	printf("\n Gio: "); scanf("%d", &(a.h)); printf("\t Phut: "); scanf("%d", &(a.m));
}
struct TIME operator + (struct TIME a, struct TIME b)
{
	static struct TIME c;
	c.h = a.h + b.h + (a.m + b.m)/60;
	c.m = (a.m + b.m) % 60;
	return c;
}
struct TIME operator - (struct TIME a, struct TIME b)
{
	static struct TIME c;
	if (a.h > b.h || (a.h==b.h && a.m>b.h))
	{
		c.h = (60*a.h + a.m - 60*b.h - b.m)/60;
		c.m = (60*a.h + a.m - 60*b.h - b.m)%60;
	}
	else 
	{
		c.h = (60*a.h + a.m - 60*b.h - b.m)/60;
		c.m = (60*a.h + a.m - 60*b.h - b.m)%60;
		while (c.m<0)
		{
			c.m +=60;
			while (c.h<0) c.h+=23;
		}
		while (c.h<0) c.h+=24;
	}
	return c;	
}
void add()
{
	struct TIME a, b, result;
	printf("\n Nhap vao thoi diem: "); newtime(a);
	printf("\n Khoang thoi gian cong them: "); newtime(b);
	result = a+b;
	printf("\n Ta duoc thoi diem ket qua: ");
	print(a); printf(" + "); print(b); printf(" = "); print(result);
	getch();
}
void gap()
{
	struct TIME a, b, result;
	in: printf("\n Nhap vao thoi diem 1: "); newtime(a);
	printf("\n Nhap vao thoi diem 2: "); newtime(b);
	if (a.h<b.h) 
	{
		printf("\n ------------------ \n Nhap sai!"); goto in;
	}
	result = a-b;
	printf("\n Ta duoc khoang thoi gian: ");
	print(a); printf(" - "); print(b); printf(" = "); print(result);
	getch();
}
void sub()
{
	struct TIME a, b, result;
	printf("\n Nhap vao thoi diem: "); newtime(a);
	printf("\n Khoang thoi gian tru bot: "); newtime(b);
	result = a-b;
	printf("\n Ta duoc thoi diem ket qua: ");
	print(a); printf(" - "); print(b); printf(" = "); print(result);
}
int main()
{
	char ch;
	while(1)
	{
		printf("\n Chon cac thao tac theo stt ben duoi!");
		printf("\n 1. Cong thoi gian!");
		printf("\n 2. Tru thoi gian!");
		printf("\n 3. Tinh khoang thoi gian!");
		fflush(stdin); ch = getch();
		if (ch == '1') add();
		else if (ch == '2') sub();
		else if (ch == '3') gap();

		else
		{
			printf("\n Chan roi a? Y/.. ");
			fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break;
		}
	}
}
