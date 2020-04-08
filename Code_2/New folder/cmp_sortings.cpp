/// So sanh thoi gian thuc hien cua cac thuat toan sap xep

#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define N 1000
#define M 10000
#define P 1000000

typedef struct a
{
	int key;
	struct a *next;
}NODE;

typedef struct tagLIST
{
    NODE *phead ;
    NODE *ptail ;
}LIST;


int* init_arr(int n)  // Khoi tao mang 1 chieu:
{
	int x, *s;
	
	s = new int[n];
	
	srand(time(NULL));
	for (int i = 0; i<n; i++)
	{
		x = rand()% 100;
		s[i] = x;
	}
	return s;
}

NODE* init_llist(int n) // Khoi tao danh sach moc noi don
{
	int x, count = 0;
	NODE *head = NULL, *p;
	
	srand(time(NULL));
	
	while (count <= N)
	{
		count ++;
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
		x = rand() %100;
		p->key = x;
		p->next = NULL;
	}
	return head;
}


NODE* copy_ll(NODE *a)
{
	NODE *head = NULL, *pa, *pt;
	
	if (a == NULL) return NULL;
	
	pa = a;
	while (pa != NULL)
	{
		if (head == NULL)
		{
			head = new NODE;
			pt  = head;
		}
		else
		{
			pt->next = new NODE;
			pt = pt->next;
		}
		pt->key = pa->key;
		pt->next = NULL;
		pa = pa->next;
	}
	return head;
}

void free_ll(NODE *head)
{
	if (head == NULL)
		return;
	NODE *p = head;
	while (head!= NULL)
	{
		p = head;
		head = head->next; 
		delete p;
	}
}

/* TK Code trong slide*/

void insert (int A[], int &end, int value) // Them phan tu vao mang:
{
	if(end==-1)
	{
		end++;
		A[end]=value;
	}
	else
	{
		int pos=0, i;
		while(A[pos]<value) 
			pos++;
		for(i=end; i>=pos; i--) 
			A[i+1]=A[i];
		A[pos]=value;
		end=end+1;
	}
}

void insertionSort_arr(const int B[], int n, int A[]) // sap xep chen ra 1 mang moi:
{
	int end=-1;
	for(int i=0; i<n; i++) // chen lan luot tung phan tu cua B sang vi tri thich hop tren A
		insert(A, end, B[i]);
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void SelectionSort_Arr(int A[], int n) // Sap xep chon voi mang
{
	int i,j;
	int pos;
	for(i=0; i<n; i++)
	{
		pos=i;
		for(j=i+1; j<n; j++)
		{
			if(A[pos] > A[j]) pos=j;
		}
			if (pos != i)	
				swap(A[pos], A[i]);
	}
}

void BubbleSort_Arr(int A[], int n) // Sap xep noi bot voi mang
{
	int i,j;
	for(i=n-1;i>0;i--)
		for(j=1;j<=i;j++)
		{
			if(A[j]<A[j-1])
			{
				int k=A[j];
				A[j]=A[j-1];
				A[j-1]=k;
			}
		}
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* T?o các m?ng t?m */
    int L[n1], R[n2];
 
    /* Copy d? li?u sang các m?ng t?m */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* G?p hai m?ng t?m v?a r?i vào m?ng arr*/
    i = 0; // Kh?i t?o ch? s? b?t d?u c?a m?ng con d?u tiên
    j = 0; // Kh?i t?o ch? s? b?t d?u c?a m?ng con th? hai
    k = l; // IKh?i t?o ch? s? b?t d?u c?a m?ng luu k?t qu?
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các ph?n t? còn l?i c?a m?ng L vào arr n?u có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy các ph?n t? còn l?i c?a m?ng R vào arr n?u có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort_arr(int a[], int first, int last) // sap xep tron tren mang:
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		
		MergeSort_arr(a, first, mid);
		MergeSort_arr(a, mid+1, last);
		
		merge(a, first, mid, last);
	}
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

void insert_ll(NODE *&pHead, int x)
{
	NODE* ptr = new NODE;
	ptr->key = x;

	if(pHead==NULL)
	{
		ptr->next=NULL;
		pHead=ptr;
	}
	else
	{
		if(pHead->key >= x)
		{
			ptr->next=pHead;
			pHead=ptr;
		}
		else
		{
			NODE *preQ=pHead;
			NODE *q=pHead->next;
			while(q!=NULL && q->key < x)
			{
				preQ=q;
				q=q->next;
			}
			ptr->next=q;
			preQ->next=ptr;
		}
	}
}

void InsertionS_ll(NODE* b, NODE* &c) // sap xep chen voi ds moc noi
{
	NODE *p;
	if (b == NULL) return;
	
	p = b;
	while (p != NULL)
	{
		insert_ll(c, p->key);
		
		p = p->next;
	}
}

void SelectionSort_ll(NODE* &head) // sap xep chon voi ds moc noi:
{
	if (head == NULL)
		return;
		
	NODE *i = head;
	NODE *pos, *j;
	int temp;
	
	while (i!= NULL)
	{
		pos = i;
		j = i->next;
		while (j != NULL)
		{
			if (pos->key > j->key) pos =  j;
			j = j->next;
		}
		if (pos != i)
		{
			temp = pos->key;
			pos->key = i->key;
			i->key = temp;
		}
		
		i = i->next;
	}
	
}

//void BubbleSort_ll(NODE *head, int n) // Sap xep noi bot voi ds moc noi
//{
//	if (head == NULL) return;
//	
//	NODE *p;
//	
//	for(i=n-1;i>0;i--)
//	{
//		p = head;
//		if (p->key > p->next->key)
//			if(A[j]<A[j-1])
//			{
//				int k=A[j];
//				A[j]=A[j-1];
//				A[j-1]=k;
//			}
//	}
//}

void split(NODE *&first, NODE *&second)
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

void MergeSort_ll(NODE *&pHead)
{
	if(pHead!=NULL && pHead->next!=NULL)
	{
		NODE *second=NULL;
		split(pHead,second);
		MergeSort_ll(pHead);
		MergeSort_ll(second);
		NODE *third=NULL;
		merge(pHead,second,third);
		pHead=third;
	}
}

void AddTail(LIST &L,NODE *p)
{
    if(L.phead==NULL)
    {
        L.phead=p;
        L.ptail=L.phead;
    }
    else
    {
        L.ptail->next=p;
        L.ptail=p;
    }
}
void QuickSort(LIST &L) // Quick sort voi danh sach moc noi:
{
    NODE *x,*p;
    LIST l1,l2;
    
    if(L.phead==NULL) return;
    
    else
    {	 
        if(L.phead==L.ptail) return;
        
        l1.phead=l1.ptail=NULL;
        l2.phead=l2.ptail=NULL;
        
        x=L.phead;L.phead=x->next;
        while(L.phead!=NULL)
        {
            p=L.phead; 
            L.phead=p->next;
            p->next=NULL;
            if(p->key<=x->key)
               AddTail(l1,p);
            else
               AddTail(l2,p);
        }
        
        QuickSort(l1); 
        QuickSort(l2);
        
        if(l1.phead!=NULL)
        {
            L.phead=l1.phead;
            l1.ptail->next=x;
        }
        else
        L.phead=x;
        
        if(l2.phead!=NULL)
        {
            x->next=l2.phead;
            L.ptail=l2.ptail;
        }
        else
        L.ptail=x;
    } 
    
}


int main()
{
	int n = M, i; // n la so luong phan tu trong danh sach:

	int start_t, end_t;
	
	printf("\n n = %d", n);
	
	printf("\n *** Lam viec voi mang mot chieu: ");
	int *arr = init_arr(n);
	int a[n];
	
	start_t = clock();
	insertionSort_arr(arr, n, a);
	end_t = clock();
	printf("\n - Insertion_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	for (i = 0; i<n; i++)
	{
		a[i] = arr[i];
	}
	start_t = clock();
	SelectionSort_Arr(a, n);
	end_t = clock();
	printf("\n - Selection_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	for (i = 0; i<n; i++)
	{
		a[i] = arr[i];
	}
	start_t = clock();
	BubbleSort_Arr(a, n);
	end_t = clock();
	printf("\n - Bubble_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	for (i = 0; i<n; i++)
	{
		a[i] = arr[i];
	}
	start_t = clock();
	MergeSort_arr(a, 0, n-1); 
	end_t = clock();
	printf("\n - Merge_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	for (i = 0; i<n; i++)
	{
		a[i] = arr[i];
	}
	start_t = clock();
	qSort_arr(a, 0, n-1);
	end_t = clock();
	printf("\n - Quick_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	

	for (i = 0; i<n; i++)
	{
		a[i] = arr[i];
	}
	start_t = clock();
	HeapSort_arr(a, n); 
	end_t = clock();
	printf("\n - Heap_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	delete[] arr;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n *** Lam viec voi danh sach lien ket: ");
	NODE *b = init_llist(n);
	NODE *c;
	
	start_t = clock();
	InsertionS_ll(b, c);
	end_t = clock();
	printf("\n - Insertion_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
//	c = copy_ll(b);
//	start_t = clock();
//	SelectionSort_ll(c);
//	end_t = clock();
//	free_ll(c);
//	printf("\n - Selection_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
//	for (i = 0; i<n; i++)
//	{
//		a[i] = arr[i];
//	}
//	start_t = clock();
//	BubbleSort_ll(a, n);
//	end_t = clock();
//	free_ll(c);
//	printf("\n - Bubble_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	c = copy_ll(b);
	start_t = clock();
	MergeSort_ll(c); 
	end_t = clock();
	free_ll(c);
	printf("\n - Merge_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
//	c = copy_ll(b);
//	NODE *p = c;
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//	LIST L;
//	L.phead = c;
//	L.ptail = p;
//	
//	start_t = clock();
//	QuickSort(L);
//	end_t = clock();
//	free_ll(c);
//	printf("\n - Quick_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	

//	for (i = 0; i<n; i++)
//	{
//		a[i] = arr[i];
//	}
//	start_t = clock();
//	HeapSort_arr(a, n); 
//	end_t = clock();
//	free_ll(c);
//	printf("\n - Heap_Sort = %lf", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	free_ll(b);
}
