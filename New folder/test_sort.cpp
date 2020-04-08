//// Test Sort

#include<stdio.h>
#include<conio.h>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *a, int L, int R, int index)
{
	int storeIndex;
	swap(a[index], a[R]);
	
	storeIndex = L;
	for (int i = L; i<R; i++)
	{
		if (a[i] <= a[R])
		{
			swap(a[i], a[storeIndex]);
			storeIndex ++;
		}
	}
	swap(a[storeIndex], a[R]);
	
	return storeIndex;
}

int Partition(int A[], int L, int R, int indexPivot) {
  int pivot = A[indexPivot];
  swap(A[indexPivot], A[R]);
  int storeIndex = L;
  for(int i = L; i <= R-1; i++){
    if(A[i] < pivot){
      swap(A[storeIndex], A[i]);
      storeIndex++;
    }
  }
  swap(A[storeIndex], A[R]);
  return storeIndex;
}

void QuickSort_M(int *a, int left, int right)
{
	if (left < right)
	{
		int pivot = (left + right)/2;
		pivot = Partition(a, left, right, pivot);
		
		if (left < pivot)
			QuickSort_M(a, left, pivot - 1);
		if (pivot < right)
			QuickSort_M(a, pivot + 1, right);
	}
}


void quickSort(int A[], int L, int R) {
  if(L < R){
    int index = (L + R)/2;
    index = partition(A, L, R, index);
    if(L < index)
      quickSort(A, L, index-1);
    if(index < R)
      quickSort(A, index+1, R);
  }
}


void quicksort(int *a, int L, int R)
{
	int index = (L + R)/2;
	
	index = partition(a, L, R, index);
	
	if (L < index - 1)
		quicksort(a, L, index - 1);
	if (R > index)
		quicksort(a, index, R);
}

int main()
{
	static int a[] = {30, 40, 65, 25, 35, 50, 76, 10, 28, 27, 33, 36, 34, 48, 60, 68, 80, 69};
	
	printf("\n Day truoc khi sap xep la: \n ");
	for (int i = 0; i<19; i++)
		printf("\t %d", a[i]);
		
	QuickSort_M(a, 0, 18);
		
	printf("\n Day sau khi sap xep la: \n ");
	for (int i = 0; i<19; i++)
		printf("\t %d", a[i]);
		
	getch();	
}
