#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int **a, **b, **c, m, n, p, q, cc;
void free_p()
{
	int i;
	for (i = 0; i<m; i++) delete[] a[i]; delete[] a;
	for (i = 0; i<p; i++) delete[] b[i]; delete[] b;
	for (i = 0; i<cc; i++) delete[] c[i]; delete[] c;
}
void in_size()
{
	system("cls");
	printf("\n Nhap kich thuoc hai ma tran A va B!");
	printf("\n Ma tran A:  ");
	printf("\n \t - So hang: "); scanf("%d", &m);
	printf("\n \t - So cot: "); scanf("%d", &n);
	printf("\n Ma tran B:  ");
	printf("\n \t - So hang: "); scanf("%d", &p);
	printf("\n \t - So cot: "); scanf("%d", &q);
}
void nhap2()
{
	int i, j;
	a = new int *[m];
	printf("\n Nhap cac phan thu cua A: ");
	for (i = 0; i<m; i++)
	{
		a[i] = new int [n];
		for (j = 0; j<n; j++)
		{
			printf("\n a[%d][%d] = ", i, j); scanf("%d", &a[i][j]);
		}
	}
	b = new int *[p];
	printf("\n Nhap cac phan thu cua B: ");
	for (i = 0; i<p; i++)
	{
		b[i] = new int [q];
		for (j = 0; j<q; j++)
		{
			printf("\n b[%d][%d] = ", i, j); scanf("%d", &b[i][j]);
		}
	}
}
void inmat(int **a, int m, int n)
{
	int i, j;
	for (i = 0; i<m; i++)
	{
		printf("\n");
		for (j = 0; j<n; j++)
		printf("\t%d", a[i][j]);
	}
}
void cong()
{
	int i, j;
	size: in_size();
	if (m!=p || n!=q)
	{
		printf("\n Kich thuoc hai ma tran phai bang nhau!"); getch();
		goto size;
	}
	nhap2();
	c = new int *[m];
	for (i = 0; i<m; i++)
	{
		c[i] = new int [n];
		for (j = 0; j<n; j++)
			c[i][j] = a[i][j] + b[i][j];
	}
	printf("\n Ket qua cua phep toan la: ");
	inmat(a, m, n); printf("\n +"); inmat(b, p, q); 
	printf("\n ____________________________________________"); inmat(c, m, n);
	getch(); 
	cc = m; free_p();
}
void nhan()
{
	int i, j, k;
	size: in_size();
	if (n!=p)
	{
		printf("\n Kich thuoc khong phu hop (So cot cua A = So hang cua B)!"); getch();
		goto size;
	}
	nhap2();
	c = new int *[m];
	for (i = 0; i<m; i++)
	{
		c[i] = new int [q];
		for (j = 0; j<q; j++)
			c[i][j] = 0;
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<q; j++)
			{
				k = 0;
				while (k<n)
				{c[i][j] += a[i][k] * b[k][j]; k++;
					}	
			}
	printf("\n Ket qua cua phep toan la: ");
	inmat(a, m, n); printf("\n *"); inmat(b, p, q); 
	printf("\n ____________________________________________"); inmat(c, m, q);
	getch();
	cc = m; free_p(); 
}
void nhap()
{
	int i, j;
	printf("\n Nhap vao ma tran A vuong: ");
	printf("\n So hang: "); scanf("%d", &m); n = m;
	a = new int *[m];
	printf("\n Nhap cac phan thu cua A: ");
	for (i = 0; i<m; i++)
	{
		a[i] = new int [n];
		for (j = 0; j<n; j++)
		{
			printf("\n a[%d][%d] = ", i, j); scanf("%d", &a[i][j]);
		}
	}
}
int** child(int **a, int m, int j)
{
	int **cd, k, t;
	cd = new int *[m-1];
	for (k = 0; k<m-1; k++)
	{
		cd[k] = new int [m-1];
		for (t = 0; t<m-1; t++)
			if (t<j) cd[k][t] = a[k+1][t];
			else if (t>=j) cd [k][t] = a[k+1][t+1];
	}
	return cd;
}
int det(int **a, int m)
{
	int j, s = 0;
	if (m == 2) return (a[0][0]* a[1][1] - a[1][0]*a[0][1]);
	for (j = 0; j<m; j++)
		if (j%2!=0) s -=a[0][j]*det(child(a, m, j), m-1);
		else s += a[0][j]*det(child (a, m, j), m-1);
	return s;
}
void dinhthuc()
{
	int i, j;
	free_p();
	nhap();
	printf("\n Ket qua cua phep toan la: ");
	for (i = 0; i<m; i++)
	{
		printf("\n|");
		for (j = 0; j<n; j++)
		printf("\t%d", a[i][j]);
		printf("\t|");
		if (i==0) printf("\t = %d", det(a, m));
	}
	getch();
}
int main()
{
	char ch;
	while (1)
	{
		system("cls");
		printf("\n Chuong trinh tinh toan voi ma tran so nguyen!");
		printf("\n =============================================");
		printf("\n 1. Cong hai ma tran. ");
		printf("\n 2. Nhan hai ma tran. ");
		printf("\n 3. Tinh dinh thuc cua ma tran. ");
		printf("\n =============================================");
		printf("\n Chon 1 - 3 de tinh toan. Phim khac de thoat!");
		fflush(stdin); ch = getch();
		if (ch == '1') cong();
		else if (ch == '2') nhan();
		else if (ch == '3') dinhthuc();
		else 
		{
			printf("\n Chan roi a? Y/...");
			fflush(stdin); ch = getch(); 
			if (ch == 'y' || ch == 'Y') break;
		}
	}
	printf("\n See again!");
	getch();
	return 0;
}
