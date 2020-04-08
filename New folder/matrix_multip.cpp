// Tran Thi Quyen _ 20173333 _ KHMT 01
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct matrix
{
	int r;
	int c;
	int **data;
};
void freee(struct matrix a)
{
	int i;
	for (i = 0; i<a.r; i++)
	delete[] a.data[i];
	delete a.data;
}
void newmatrix(struct matrix &a, int r, int c)
{
	int i, j, **temp;
	a.r = r; a.c = c;
	temp = new int* [r];
	for (i = 0; i<r; i++)
	{
		temp[i] = new int[c];
		for (j = 0; j<c; j++) 
		{
			printf("\n Nhap vao phan tu [%d][%d] = ", i, j); scanf("%d", &temp[i][j]);
		}
	}
	a.data = temp;
}
void print(struct matrix a)
{
	int i, j, r, c;
	r = a.r;
	c = a.c;
	for (i = 0; i<r; i++)
	{
		printf("\n \t ");
		for (j = 0; j<c; j++)
			printf("%d\t", a.data[i][j]);
	}
}
struct matrix  operator + (struct matrix a, struct matrix b)
{
	static struct matrix result1;
	int i, j, r, c;
	r = a.r; c = a.c;
	result1.r = r; result1.c = c;
	result1.data = new int *[r];
	for (i = 0; i<r; i++)
		{
			result1.data[i] = new int [c];
			for (j = 0; j<c; j++)
				result1.data[i][j] =  a.data[i][j] + b.data[i][j];
		}
	return result1;
}
struct matrix  operator * (struct matrix a, struct matrix b)
{
	static struct matrix result2;
	int ra, cb, ca, i, j, k;
	ra = a.r; cb = b.c; ca = a.c;
	result2.r = a.r; result2.c = b.c;
	result2.data = new int *[ra];
	for (i = 0; i<ra; i++)
	{
		result2.data[i] = new int [cb];
		for (j = 0; j<cb; j++)
		{
			result2.data[i][j] = 0;
			for (k = 0; k<ca; k++)
				result2.data[i][j] += a.data[i][k] * b.data[k][j];
		}
	}
	return result2;
}
void add()
{
	struct matrix a, b, result;
	int r, c;
	printf("\n Nhap vao kich thuoc cua hai ma tran: ");
	printf("\n So hang: "); scanf("%d", &r);
	printf("\n So cot: "); scanf("%d", &c);
	printf("\n Nhap ma tran A: "); newmatrix(a, r, c);
	printf("\n Nhap ma tran B: "); newmatrix(b, r, c);
	result = a+b;
	printf("\n Ket qua la: "); 
	print(a); printf("\n + "); print(b); printf("\n __________________________"); print(result);
	getch();
	freee(a); freee(b); freee(result);
}
void multi()
{
	struct matrix a, b, result;
	int ra, ca, rb, cb;
	printf("\n Nhap vao kich thuoc cua hai ma tran: ");
	do
	{
		printf("\n So hang cua A: "); scanf("%d", &ra);
		printf("\n So cot cua A: "); scanf("%d", &ca);
		printf("\n So hang cua B: "); scanf("%d", &rb);
		printf("\n So cot cua B: "); scanf("%d", &cb);
		if (ca != rb) printf("\n Kich thuoc khong phu hop! (So cot cua A = So hang cua B)");
	}while (ca != rb);
	printf("\n Nhap ma tran A: "); newmatrix(a, ra, ca);
	printf("\n Nhap ma tran B: "); newmatrix(b, rb, cb);
	result = a*b;
	printf("\n Ket qua la: "); 
	print(a); printf("\n * "); print(b); printf("\n __________________________"); print(result);
	getch();
	freee(a); freee(b); freee(result);
}
void test()
{
	struct matrix a, b, c, d, result;
	printf("\n De don gian, ta kiem tra phep toan voi ma tran cap 2!");
	printf("\n Nhap vao ma tran A: "); newmatrix(a, 2, 2);
	printf("\n Nhap vao ma tran B: "); newmatrix(b, 2, 2);
	printf("\n Nhap vao ma tran C: "); newmatrix(c, 2, 2);
	printf("\n Nhap vao ma tran D: "); newmatrix(d, 2, 2);
	result = a + b * c + d;
	printf("\n Ket qua A + B * C + D: ");
	print(result); getch();
	result = (a+b)*(c+d);
	printf("\n Ket qua (A + B) * (C + D): ");
	print(result); getch();
	result = (a*b+c)*d;
	printf("\n Ket qua (A * B + C) * D: ");
	print(result); getch();
	freee(a); freee(b); freee(c); freee(d); freee(result);
}
int main()
{
	char ch;
	while (1)
	{
		printf("\n Chon thao tac theo stt duoi day: ");
		printf("\n ----------------------------------");
		printf("\n 1. Cong ma tran!");
		printf("\n 2. Nhan ma tran!");
		printf("\n 3. Test mot so bieu thuc: A + B * C + D");
		// 
		fflush(stdin); ch = getch();
		if (ch == '1') add();
		else if (ch == '2') multi();
		else if (ch == '3') test();
		else
		{
			printf("\n Chan roi a? Y/ ..");
			fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break;
		}
	}
	return 0;
}
