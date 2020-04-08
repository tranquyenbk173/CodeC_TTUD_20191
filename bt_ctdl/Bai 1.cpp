#include<stdio.h>
#include<conio.h>
double *a;
int end = 0, max = 0;
void beg()
{
	int k;
	max = 10;
	a = new double [max];
	for (k = 0; k<8; k++) a[k] = k;
	end = 8;
}
void load()
{
	int i;
	double *tg;
	tg = a;
	a = new double [max*3];
	for (i=0; i<end; i++) a[i] = tg[i];
	delete[] tg;
	max *=3;
}
void add(int pos, double val)
{
	int i, p;
	if (end == max) load();
	if (pos == -2 || pos == end-1)
	{
		a[end] = val;
		end ++; return;
	}
	else if (pos == -1) p = 0;
	else p = pos;
	for (i = end; i>p; i--) 
		a[i] = a[i-1];
	a[p] = val;
	end++;
}
void deleteAt(int pos)
{
	int p, i;
	if (pos == end-1 || pos == -2) 
	{
		end--;
		return;
	}
	if (pos == -1) p = 0;
	else p = pos;
	for (i = p; i<end-1; i++) a[i] = a[i+1];
	end--; 
}
void print()
{
	int k;
	printf("\n --------------------- \n ==> ");
	for (k = 0; k<end; k++) printf("\t %.2lf", a[k]);
	getch();
}
int main()
{
	char ch;
	int p; 
	double v;
	printf("\n Mang ban dau: "); beg(); print();
	while (1)
	{
		printf("\n Chon cac thao tac theo thu tu sau: (phim khac de thoat!)");
		printf("\n 1. Them mot phan tu moi!");
		printf("\n 2. Xoa mot phan tu!");
		fflush(stdin); ch = getch(); 
		if (ch == '1')
		{
			printf("\n - Them vao vi tri: "); scanf("%d", &p); printf("\n -  Gia tri: "); scanf("%lf", &v); 
			add(p, v); 
			print();
		}
		else if (ch == '2')
		{
			printf("\n Xoa tai vi tri: "); scanf("%d", &p);
			deleteAt(p);
			print();
		}
		else 
		{
			printf("\n Are yo sure? Y/ .."); fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break; 
		}
	 } 
}
