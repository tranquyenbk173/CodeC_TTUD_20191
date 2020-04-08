#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

FILE *fp, *f, *f1[10];
char name[10][10] = {"file0.dat", "file1.dat", "file2.dat", "file3.dat", \
		"file4.dat", "file5.dat", "file6.dat", "file7.dat", "file8.dat", "file9.dat"};


void new_File(int n)
{
	fp = fopen("goc.dat", "wb");
	srand(time(NULL));
	int *a = new int[1000], count = 0;
	for (int i = 0; i<n; i++)
	{
		a[i%1000] = rand();
		count ++;
		if (count == 999)
		{
			fwrite(a, sizeof(int), 1000, fp);
			count = 0;
		}
	}
	fclose(fp);
	delete[] a;
}

void read_File(char *filename)
{
	
	f = fopen(filename, "rb");
	
	if (f != NULL)
	{
		int *x = new int [1000];
		while (fread(x, sizeof(int), 1000, f) > 0)
		{
			for (int i = 0; i<1000; i++)
				printf("%d ", x[i]);
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

void split_File(int n, int &cfile)// chia file ban dau thanh nhieu file da duoc sap xep
{
	fp = fopen("goc.dat", "rb");
	
	if (fp != NULL)
	{
		int *a = new int[10000];
		int c; 
		cfile = 0;
		while (c = fread(a, sizeof(int), 10000, fp))
		{
			qSort_arr(a, 0, c-1);
			f = fopen(name[cfile], "wb");
			fwrite(a, sizeof(int), c, f);
			fclose(f);
			cfile ++;					
		}
	}
}

void merge_File(int n, int cfile)
{
	f = fopen("goc.dat", "wb");
	
	int **a, *ptr[cfile]; // ptr[i] tro toi phan tu dang xet tren buffer a[i]
	int lim[cfile]; // lim[i] la vi tri cua phan tu cuoi tren buffer i
	int x[10000];
	a = new int* [cfile];

	for (int i = 0; i<cfile; i++) // khoi tao buffer
	{
		a[i] = new int [1000];
		ptr[i] = &(a[i][0]);
	}
	
	FILE *fp[cfile]; // doc file vao cac buffer
	for (int i = 0; i<cfile; i++)
	{
		fp[i] = fopen(name[i], "rb");
		if (fp[i] == NULL) 
			return;
		lim[i]  = fread(a[i], sizeof(int), 1000, fp[i]); printf("\n %d", lim[i]); getch();
	}
	
	int count = 0, d = 0; // count = so luong ban ghi xu li duoc, d = chi so dang dien tren buffer tong
	while (count < n)
	{
		int min = 0;
		for (int i = 0; i<cfile; i++)
		{
			if (*(ptr[min]) > *(ptr[i]) )	
				min = i;
		}
		x[d++] = *ptr[min]; // ghi nhan phan tu min tren buffer tong
		count ++;
		 
		ptr[min] ++; // dich con tro tren buffer i 
		if (ptr[min] == a[min] + lim[min]) // neu ptr[i] tro den het buffer thi nap moi
		{
			lim[min]  = fread(a[min], sizeof(int), 1000, fp[min]);
		}
		
		if (d == 9999)
			{
				fwrite(x, sizeof(int), 10000, f);
				d = 0;
			}
	}
	fclose(f);
	for (int i = 0; i<cfile; i++)
		{
			fclose(fp[i]);
			delete[] a[i];
		}
	
	delete a;
}

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
	int x[c], a; // mang luu tam cac gia tri doc duoc tu dau cac file ve cuoi
	
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
	int n  = 100000, cfile;
	
	new_File(n); // tao file ngau nhien gom n phan tu
	//read_File("goc.dat"); // doc file vua tao
	
	split_File(n, cfile); // chia file thanh nhieu phan da duoc sap xep;
	
	MergeFiles(n, cfile); // tron cac file con laij thanh file dich
	
	read_File("goc.dat"); // doc file da xu li:
	
	return 0;
}
