#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define N 1000000

typedef struct element
{
	int key;
	struct element *next;
} NODE;

FILE *f, *f1[10];

char name[10][10] = {"f1.dat", "f2.dat", "f3.dat", "f4.dat", "f5.dat", \
					"f6.dat", "f7.dat", "f8.dat", "f9.dat", "f10.dat"};
void TaoFile(int n) // Tao file ban dau co n phan tu:
{
	int x;
	
	f = fopen("goc.dat", "wb");
	
	srand(time(NULL));
	
	{
		for (int i = 0; i<n; i++)
		{
			x = rand();
			fwrite(&x, 2, 1, f); 
		}
		fclose(f);
	}
}

void InFile(char *filename) // In file goc:
{
	int x;
	
	f = fopen(filename, "rb");
	
	if (f != NULL)
	{
		while (fread(&x, 2, 1, f) > 0)
		{
			printf("%d ", x);
		}
	}	
	
	fclose(f);
}

void qSort_arr(int A[], int start, int end) // Quick sort voi mang
{
	//chon phan tu dau lam chot
	if(start<end) //co nhieu hon 1 phan tu
	{
		int p,q,tmp;
		p=start; q=end;
		while(p<q)
		{
			while(A[p]<=A[start]) 
				p++;
			while(A[q]>A[start]) 
				q--;
			if(p<q)
			{
				tmp=A[p];
				A[p]=A[q];
				A[q]=tmp;
			}
		}
		tmp=A[start];
		A[start]=A[q];
		A[q]=tmp;
		//goi de quy
		qSort_arr(A,start,q-1);
		qSort_arr(A,q+1,end);
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Max_Heapify(int a[], int i, int n)
{
	int largest;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if (left > n-1) return;
	
	if (left < n && a[left] > a[i])
		largest = left; 
	else
		largest = i;
	if (right < n && a[right]>a[largest])
		largest = right;
		
	if (i != largest) 
	{
		swap(a[i], a[largest]);
		Max_Heapify(a, largest, n);
	}
	
}

void Build_Max_Heap(int a[], int n)
{
	for (int i = n/2; i >=0; i--)
	{
		Max_Heapify(a, i, n); 
	}
}

void HeapSort_arr(int a[], int n) // Heap sort voi mang:
{
	Build_Max_Heap(a, n); 
	for (int i = n-1; i>0; i--)
	{
		swap(a[i], a[0]);
		Max_Heapify(a, 0, i-1);
	}
}


void SplitFile(int n, int &c) // Chia du lieu tu file goc ra 10 file trung gian
{	// c la so file trung gian sd
	f = fopen("goc.dat", "rb");
	if (f != NULL)
	{
		// Doc dan k phan tu vao bo nho de sap xep roi dua ra cac file con
			
		int k = 30000, i, x; // k phai toi thieu bang 10
		int *a = new int [k];
		c = 0;
		
		while(fread(&x, 2, 1, f) > 0)
		{
			for (i = 0; i<k; i++) // doc k phan tu tu file f vao bo nho de sap xep
			{
				a[i] = x;
				fread(&x, 2, 1, f);
			}
		
			qSort_arr(a, 0, k - 1);
			//SelectionSort_Arr(a, n);
			//HeapSort_arr(a, n);
				
			f1[c] = fopen(name[c], "wb"); // mo file de ghi

			for (i = 0; i<k; i++)
			{
				x = a[i];
				fwrite(&x, 2, 1, f1[c]);
			}
			c++;
		}
	
		// dong cac file trung gian va file goc:
		for (int j = 0; j<c; j++)
			fclose(f1[j]);
		fclose(f);
	}
	delete[] a;
}

/// Tron du lieu tu cac file 
void MergeFiles(int n, int c)
{ // c la so file trung gian sd

	f = fopen("goc.dat", "wb");
	int i;
	
	// Mo file trung gian:
	for (i = 0; i<c; i++)
	{
		f1[i] = fopen(name[i], "rb");
		
		if (f1[i] == NULL)
		{
			return;
		}
	}
	
	// Doc du lieu tu cac file trung gian:
	
	int min, count = 0; // min = chi so cua x[i] nho nhat, count = so phan tu da duoc luu vao file goc!
	int *x = new int [c], a; // mang luu tam cac gia tri doc duoc tu dau cac file ve cuoi
	
	for (i = 0; i<c; i++)
	{
		fread(&(a), 2, 1, f1[i]);
		x[i] = a;
	}	
 	
 	min = 0;
 	
 	while (count < n)
 	{
 		count ++;
 		for (int i = 0; i<c; i++)
 			if (x[min] > x[i]) 
 				{
 					min = i;
				}
		a = x[min];
 		fwrite(&a, 2, 1, f);
 		
 		int test = fread(&a, 2, 1, f1[min]);
 		
 		if (test==0) 
 			x[min] = INT_MAX;
 		else 
 			x[min] = a;
 	}
	
	fclose(f);
	for (int i = 0; i<c; i++)
		fclose(f1[i]);
}

int main()
{
	
	char a[30] = "goc.dat";
	// Khoi tao file ban dau:
	int n = 1000000; // Neu thuong so n/k qua lon, c tr gap loi! max (n/k) = 10;
	printf("\n FILE ban dau co cac phan tu la: ");
	TaoFile(n); 
	// InFile(a);
	
	// Chia du lieu ra cac file + Sap xep tren do:
	int c, i;
	SplitFile(n, c);
//	printf("\n Cac ket qua chia cac file trung gian:");
//	for (i = 0; i<c; i++)
//	{
//		printf("\n - File %d: ", i+1); InFile(name[i]);
//	}		
			
	// Tron lai tu cac file, luu vao file goc:
	MergeFiles(n, c);
	printf("\n File sau sap xep: \t \t ");
	InFile(a);
	
	f = fopen(a, "rb"); i = 0;
	while (fread(&c, 2, 1, f) > 0)
	{
		i++;
	}
	printf("\n Tap dich hien dang co %d phan tu!", i);
	
	return 0;
}
