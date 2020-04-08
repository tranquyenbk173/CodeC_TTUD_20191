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

void SplitFile(int n) // Chia du lieu tu file goc ra 10 file trung gian
{	
	f = fopen("goc.dat", "rb");
	if (f != NULL)
	{
		// Mo 10 file trung gian de ghi:
		for (int i = 0; i<10; i++)
			f1[i] = fopen(name[i], "wb");
			
		// bat dau ghi, moi khi ghi den phan tu thuoc diem chia tiep theo, chuyen sang ghi o file tiep theo	
		int j = 0, k = 0, x;	// k: so ptu doc tu file goc, j: stt file trung gian
		FILE *fp = f1[j];
		while(fread(&x, 2, 1, f) > 0)
		{
			k ++;
			fwrite(&x, 2, 1, fp);
			if (k == n/10)
			{
				j++;
				fp = f1[j%10];
				k = 0;	
			}
		}
		
		// dong cac file trung gian va file goc:
		for (int i = 0; i<10; i++)
			fclose(f1[i]);
		fclose(f);
	}
}

void Inds(NODE *head)
{
	if (head == NULL)
		return;
	
	NODE *p = head;
	while (p != NULL)
	{
		printf("\t %d", p->key);
		p = p->next;
	}
}

NODE* Vaofilecon(char *filename) // Dua du lieu tu file fp vao bo nho de xu li:
{
	NODE *p, *head = NULL;
	int x;
	
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
		return NULL;
	
	while (fread(&x, 2, 1, fp) > 0)
	{
		if (head == NULL)
		{
			head = new NODE; 
			p = head;
		}	
		else
		{ 
			p->next = new NODE;
			p = p->next;
		}
		
		p->key = x;
		p->next = NULL;
	} 
	
	fclose(fp);
	return head;
}

void Split_List(NODE *&first, NODE *&second)
{
	NODE *start=first;
	NODE *end=first->next;
	
	while(end->next!=NULL && end->next->next!=NULL)
	{
		start = start->next;
		end = end->next->next;
	}
	
	second = start->next;
	start->next=NULL;
}


void merge(NODE *first, NODE *second, NODE *&third)
{
	NODE *ptr;
	third=(NODE*)malloc(sizeof(NODE));
	third->next=NULL;
	ptr=third;
	
	NODE *p=first;
	NODE *q=second;
	
	while(p!=NULL && q!=NULL)
	{
		if(p->key <= q->key)
		{
			ptr->next=p;
			p=p->next;
			ptr=ptr->next;
			ptr->next=NULL;
		}
		else
		{
			ptr->next=q;
			q=q->next;
			ptr=ptr->next;
			ptr->next=NULL;
		}
	}
	
	if(p==NULL) 
		ptr->next=q;
	else 
		ptr->next=p;
	
	ptr=third;
	third=third->next;
	free(ptr);
}

void Rafilecon(char* filename, NODE *head)
{
	if (head == NULL)
		return;
	
	FILE *fp = fopen(filename, "wb");
	
	NODE* p = head; 
	int x;
	while (p!= NULL)
	{
		x = p->key;
		fwrite(&x, 2, 1, fp);
		p = p->next;	
	}
	getch();
	
	fclose(fp);
}

void Free(NODE *head)
{
	NODE *p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

void MergeSort(NODE * &head) //Merge Sort voi du lieu dua vao
{
	if(head!=NULL && head->next!=NULL) 
	{
		NODE *second=NULL;
		Split_List(head,second);
		
		MergeSort(head);
		MergeSort(second);
		
		NODE *third=NULL;
		merge(head,second,third);
		head=third;
	}
	
}

void Xuli_File_con(char* filename) // sap xep tron cac phan tu thuoc file fp: dua du lieu vao bo nho va luu ket qua sau sx
{
	NODE *head = Vaofilecon(filename); // Dua cac phan tu vao  
	
	MergeSort(head);
	
	Rafilecon(filename, head); // Dua ds da sap xep ra file ban dau
	
	Free(head); // Giai phong khoi bo nho
	
}

/// Tron du lieu tu cac file 
void MergeFiles(int n)
{
	f = fopen("goc.dat", "wb");
	
	// Mo file trung gian:
	for (int i = 0; i<10; i++)
	{
		f1[i] = fopen(name[i], "rb");
		
		if (f1[i] == NULL)
		{
			return;
		}
	}
	
	// Doc du lieu tu cac file trung gian:
	
	int min, count = 0; // min = chi so cua x[i] nho nhat, count = so phan tu da duoc luu vao file goc!
	int x[10], a; // mang luu tam cac gia tri doc duoc tu dau cac file ve cuoi
	
	for (int i = 0; i<10; i++)
	{
		fread(&(a), 2, 1, f1[i%10]);
		x[i] = a;
	}	
	getch();
 	
 	min = 0;
 	
 	while (count < n)
 	{
 		count ++;
 		for (int i = 0; i<10; i++)
 			if (x[min] > x[i]) 
 				{
 					min = i;
				}
				
 		fwrite(&(x[min]), 2, 1, f);
 		int test = fread(&(x[min]), 2, 1, f1[min]);
 		
 		if (test==0) 
 			x[min] = INT_MAX;
	}
	
	fclose(f);
	for (int i = 0; i<10; i++)
		fclose(f1[i]);
}

int main()
{
	int n = 10;
	
	char a[30] = "goc.dat";
	// Khoi tao file ban dau:
	//printf("\n FILE ban dau co cac phan tu la: ");
	
	TaoFile(n); 
	
	// InFile(a);
	
	// Chia du lieu ra cac file + Sap xep tren do:
	
	SplitFile(n);
	for (int i = 0; i<10; i++)
		{
			Xuli_File_con(name[i]);
		}
	for (int i = 0; i<10; i++)
		InFile(name[i]);
		
	// Tron lai tu cac file, luu vao file goc:
	
	MergeFiles(n);
//	e = clock();
//	printf("\n Thoi gian: %ld", (double)(e - s)/CLOCKS_PER_SEC); getch();
	printf("\n File sau sap xep: \t \t ");
	InFile(a);
	
	return 0;
}
