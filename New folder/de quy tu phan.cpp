/// Tran Quyen -  28.04.2019

/// Hai bai de quy tu phan trong Slide
/// Va bai toan con tho cua thay Vuong

#include<stdio.h>
#include<conio.h>


/// Bài 1a: Ham de quy - tinh cac phan tu cua day so: 1, 2, 3, 4, 4, 5, 8, 11, 12, 14, 21, 30, 35, 40, 56, ...
int a(int n)
{
	if (n < 1)
	{
		printf("\n error!");
		getch(); return 0;
	}
	if (n < 5) 
		return n;
	else 
		return a(n-1) - a(n-2) + a(n-3) + a(n-4);
}


/// Bai 1b: Khong dung de quy, tinh tong day so tren: 
int sum(int n)
{
	int a[5] = {0, 1, 2, 3, 4}; // 
	int sum = 0;
	
	if (n <= 0)
	{
		printf("\n Loi!");
		getch(); return 0;
	}
	else if (n<5)
	{
		if (n == 1)
			return a[1];
		else if (n == 2)
			return a[1] + a[2];
		else if (n == 3)
			return a[1] + a[2] + a[3];
		else if (n == 4)
			return a[1] + a[2] + a[3] + a[4];
	}
	else 
	{
		sum += a[1] + a[2] + a[3] + a[4]; // tong day so tu a[1] den a[4]
		
		for (int i = 5; i<=n; i++)
		{
			a[i%5] = a[(i+1)%5] + a[(i+2)%5] - a[(i+3)%5] + a[(i+4)%5]; // --> Dong nay co 18 phep toan!!!
			sum += a[i%5]; // tong day so tu a[1] den a[i]
		}
	}
	return sum;
}


// Bai 2a: Dung de quy - Tinh cac phan tu cua day: 1,2,3,4,6,9,14,21,32,48,73,110,167,252,...
int b(int n)
{
	if (n < 1) 
	{
		printf("\n error!");
		getch(); 
		return 0;
	}
	else if (n < 5)
		return n;
	else
	{
		return b(n-4) - b(n-3) + b(n-2) + b(n-1);
	}
}

// Bai 2b: Khong dung de quy, tinh tong n phan tu dau day:
// Cach khong dung mang "xoay vong": ton it phep toan hon!
int sum_2(int n)
{ 
	int a1, a2, a3, a4, a5; // Khong dung mang se tiet kiem cac phep toan hon moi lan goi toi bien
	int sum = 0;
	a1 = 1; a2 = 2; a3 = 3; a4 = 4;
	
	if (n <= 0)
	{
		printf("\n ERROR!");
		getch(); return 0;
	}
	
	else if (n<5)
	{
		if (n == 1)
			return a1;
		else if (n == 2)
			return a1 + a2;
		else if (n == 3)
			return a1 + a2 + a3;
		else if (n == 4)
			return a1 + a2 + a3 + a4;
	}
	
	else 
	{
		sum += a1 + a2 + a3 + a4; // tong day so tu a[1] den a[4]
		
		for (int i = 5; i<=n; i++)
		{
			a5 = a1 - a2 + a3 + a4; // trong moi vong for chi co 9 phep toan
			sum += a5; // tong day so tu a1 toi ai
			a1 = a2;
			a2 = a3;
			a3 = a4;
			a4 = a5;
		}
	}
	return sum;
}

// Ham tinh so Fibonaxi:
int f(int n)
{
	if (n < 2) 
		return 1;
	else 
	{
		int f0, f1, f2;
		f0 = f1 = 1;
		
		for (int i = 2; i < n + 1; i++)
		{
			f2 = f0 + f1;
			f0 = f1; f1 = f2;
		}
		
		return f2;
	}
}

int p(int m, int n)
{
	if (n < 12)
	{
		return 0;
	}
	else
	{
		return (15 * m * f(n - 12));
	}
}

int main() /// Ham nay de kiem tra hoat dong cua cac ham o tren:
{
	char ch;
	int n;
	
	while (1)
	{
		printf("\n Chon thao tac theo stt:");
		printf("\n 1. Dung de quy, tinh cac phan tu cua day so: 1, 2, 3, 4, 4, 5, 8, 11, 12, 14, 21, 30, 35, 40, 56, ...");
		printf("\n 2. Tinh tong day so tren (gom n so) ma khong dung de quy:\n");
		printf("\n 3. Dung de quy, tinh cac phan tu cua day so: 1,2,3,4,6,9,14,21,32,48,73,110,167,252,...");
		printf("\n 4. Tinh tong day so tren (gom n so) ma khong dung de quy: \n");
		printf("\n 5. Bai toan con tho cua thay Vuong :");
		
		printf("\n ");
		ch = getch();
		if (ch == '1')
		{
			printf("\n Nhap so phan tu can tinh: ");
			scanf("%d", &n);
			
			for (int i = 1; i < n+1; i++)
			{
				printf("\n --> Phan tu thu %d: %d", i, a(i));
			}
			getch();
		} 
		else if (ch == '2')
		{
			printf("\n Nhap so phan tu can tinh tong: ");
			scanf("%d", &n);
			
			printf("\n --> Tong cua %d phan tu dau tien la: %d \n ", n, sum(n));
			getch();
		}
		else if (ch == '3')
		{
			printf("\n Nhap so phan tu can tinh: ");
			scanf("%d", &n);
			
			for (int i = 1; i < n+1; i++)
			{
				printf("\n --> Phan tu thu %d: %d", i, b(i));
			}
			getch();
		}
		else if (ch == '4')
		{
			printf("\n Nhap so phan tu can tinh tong: ");
			scanf("%d", &n);
			
			printf("\n --> Tong cua %d phan tu dau tien la: %d \n ", n, sum_2(n));
			getch();
		}
		else if (ch == '5')
		{
			int m, n;
			printf("\n a. Bai toan don gian: m cap tho sau n thang thu duoc bao nhieu tien ban tho? \
			\n    Biet moi cap tho gia ban ra duoc 15$");
			printf("\n - So cap tho ban dau: m = "); scanf("%d", &m);
			printf("\n - Sau bao nhieuu thang: n = "); scanf("%d", &n);
			printf("\n ==> So tien thu duoc la: %d $\n \n ", p(m, n));
			getch();
		}
		else 
		{
			printf("\n Chan roi a? Y/ ..");
			fflush(stdin);
			ch = getch();
			if (ch == 'y' || ch == 'Y') 
				break; 
		}
	}
}
