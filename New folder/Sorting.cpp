// 27.04.2019 - Sorting

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[50], n;

// Doc mang ban dau tu file:

//void newfile()
//{
//	FILE *fp = fopen("sorting.txt", "wb");
//	
//	int b[] = {40, 30, 65, 25, 35, 50, 76, 10, 28, 27, 33, 36, 34, 48, 60, 68, 80, 69};
//	
//	for (int i = 0; i<19; i++)
//		fwrite(&(b[i]), sizeof(int), 1, fp);
//	
//	printf("\n ghi file thanh cong!");
//	fclose(fp);
//} 

void init()
{
	FILE *fp = fopen("sorting.txt", "rb");
	int temp;
	n = 0;
	
	if (fp == NULL)
	{
		printf("\n File khong ton tai!");
		getch();
		return;
	}
	
	while (fread(&temp, sizeof(int), 1, fp) > 0)
	{
		a[n] = temp;
		n++;
 	}
 	fclose(fp);
}

// Dua ket qua da sap xep ra man hinh: 
void print()
{
	for (int i = 0; i<n; i++)
	printf("\t %d", a[i]);
	getch();
}

// Ham hoan doi gia tri cua hai phan tu:
void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// Chia mang thanh 2 phan tuong ung voi Pivot duoc chon truoc do, phan trai chua cac phan tu khong lon hon a[pivot]
// phan phai chua cac phan tu lon hon a[pivot]
int Partition(int *a, int left, int right, int pivot)
{
	int i, storeIndex, val;
	
	Swap(a[pivot], a[right]);
	storeIndex = left;
	val = a[right];
	
	for (i = left; i<right; i++)
	{
		if (a[i] <= val)
		{
			Swap(a[i], a[storeIndex]);
			storeIndex ++;
		}
	}
	
	Swap(a[storeIndex], a[right]);
	
	return storeIndex;
}

// ham sap xep Quick Sort: pivot = (left + right)/2
void QuickSort_M(int *a, int left, int right)
{
	if (left < right)
	{
		int pivot = (left + right)/2;
		pivot = Partition(a, left, right, pivot);
		
		if (left < pivot - 1)
			QuickSort_M(a, left, pivot-1);
		if (pivot < right)
			QuickSort_M(a, pivot + 1, right);
	}
}

// ham sap xep Quick Sort: pivot = left
void QuickSort_L(int *a, int left, int right)
{
	if (left < right)
	{
		int pivot = left;
		pivot = Partition(a, left, right, pivot);
		
		QuickSort_L(a, left, pivot-1);
		QuickSort_L(a, pivot, right);
	}
}

// ham sap xep Quick Sort: pivot = right
void QuickSort_R(int *a, int left, int right)
{
	if (left < right)
	{
		int pivot = right;
		pivot = Partition(a, left, right, pivot);
		
		QuickSort_R(a, left, pivot-1);
		QuickSort_R(a, pivot, right);
	}
}

int main()
{
	int k;
	
	while (1)
	{
		printf("\n --------------MENU--------------");
		printf("\n 1. Sap xep theo Quick Sort, pivot = (left + right)/2: ");
		printf("\n 2. Sap xep theo Quick Sort, pivot = left: ");
		printf("\n 3. Sap xep theo Quick Sort, pivot = right: ");
		printf("\n 4. Sap xep theo Merge Sort: ");
		printf("\n 5. Sap xep theo HeapSort: ");
		printf("\n 6. Sap xep thep Selection Sort: ");
		printf("\n 7. Sap xep theo Insertion Sort: ");
		printf("\n 8. Sap xep theo Buble Sort: ");
		printf("\n --------------------------------");
		printf("\n ====> ");
		
		scanf("%d", &k);
		if (k == 1)
		{
			init();
			printf("\n Day truoc khi sap xep la: "); print();
			printf("\n Ket qua sap xep nhanh - (left + right)/2 la: ");
			QuickSort_M(a, 0, n-1); printf("\n OK");
			print();
		}	
		else if(k == 2)
		{
			init();
			printf("\n Ket qua sap xep nhanh - left la: ");
			QuickSort_L(a, 0, n-1);
			print();
		}	
		else if(k == 3)
		{
			init();
			printf("\n Ket qua sap xep nhanh - right la: ");
			QuickSort_M(a, 0, n-1);
			print();
		}	
		else if(k == 4)
		{
			init();
			printf("\n Ket qua sap xeo theo Merge Sort: ");
			
			print();
		}
		else if(k == 5)
		{
			init();
			printf("\n Ket qua sap xeo theo Heap Sort: ");
			
			print();
		}
		else if(k == 6)
		{
			init();
			printf("\n Ket qua sap xeo theo Selection Sort: ");
			
			print();
		}
		else if(k == 7)
		{
			init();
			printf("\n Ket qua sap xeo theo Insertion Sort: ");
			
			print();
		}
		else if(k == 8)
		{
			init();
			printf("\n Ket qua sap xeo theo Buble Sort: ");
			
			print();
		}
		else 
		{
			printf("\n Chan roi a?  Y/...");
			char ch = getch();
			if (ch == 'y' || ch == 'Y')
				break;
		}
	}
}

