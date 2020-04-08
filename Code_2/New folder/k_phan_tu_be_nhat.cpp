#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>

void init(int *a, int n)
{
	srand(time(NULL));
	for (int i = 0; i<n; i++)
		a[i] = rand();	
}

//void ghi_file(int a[],int n)
//{
//    FILE *f;
//    
//    f = fopen("input")
//    remove("input.txt");
//    f=fopen("input.txt","wt");
//    for(int i=0;i<n;i++)
//        fprintf(f,"%6d",a[i]);
//    fclose(f);
//}

void printarray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int a[], int left, int right,int k) {
      int i, j, x;
	  x = a[(left+right)/2];
      i = left; j = right;   
	  do  { 
	         while(a[i] < x) i++;
	         while(a[j] > x) j--; 
	         if(i <= j)   {   
			     swap(a[i],a[j]);  
		        i++ ; j--;    } 
		  } 
		while(i <= j); 
      if(left<j&&j>k) 
       QuickSort(a, left, j,k); 
	  else if(i<right&&j<k)
       QuickSort(a, i, right,k); 
}



int main()
{  
    int n, k; // n = max_num, k = so phan tu nho nhat muon in ra
    double t1; // thoi gian thuc hien thuat toan
    
   	system("cls");
    printf("So phan tu mang de khoi tao ngau nhien: ");scanf("%d",&n);
	int a[n];
	init(a,n);
	
    printf("So phan tu nho nhat muon in: ");scanf("%d",&k);
    
    printf("\n\n===========================================================");

    printf("\n\nDay vua tao ngau nhien la:\n\n");
    printarray(a, n);
    
    int start_t = clock();
	QuickSort(a,0,n-1,k);
	int end_t = clock();
	
	t1=(double)(end_t - start_t) / CLOCKS_PER_SEC; 
    printf("\n\n\nthoi gian thuc hien thuat toan: %lf (s)\n\n\n",t1);
    
    printf("\nK phan tu nho nhat la:\n\n");
    printarray(a, k);    
    
    return 0;
}


