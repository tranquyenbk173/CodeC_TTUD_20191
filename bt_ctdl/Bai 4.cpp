#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct SLL 
{
	int val;
	struct SLL *next;
};
struct SLL *head = NULL;
int count;
void print()
{
	struct SLL *temp;
	printf("\n ---------------- \n --> List cac gia tri: ");
	temp = head;
	while (temp!=NULL)
	{
		printf("\n %d", temp->val);
		temp = temp->next;
	}
	getch();
}
void create()
{
	int n, a;
	struct SLL *temp; 
	printf("\n Nhap so luong phan tu can khoi tao: "); scanf("%d", &n);
	count = n;
	printf("\n Danh sach ban dau: ");
	while (n>0)
	{
		n--;
		a = rand()%50;
		if (head == NULL)
		{
			head = new struct SLL;
			temp = head;
		}
		else 
		{
			temp -> next = new struct SLL;
			temp = temp -> next;
		}
		temp->val = a;
		temp ->next = NULL;
	} 
	print();
}
void add(int val, int pos)
{
	struct SLL *temp, *add;
	int i = 0;
	if (pos > count)
	{
		printf("\n Vi tri khong phu hop!"); getch();
		return;
	}
	add = new struct SLL; add->val = val;
	temp = head;
	while (i!=pos-1)
	{
		temp = temp->next; i++;
	}
	add->next = temp->next;
	temp->next = add; count++;
}
void remove(int pos)
{
	struct SLL *del, *temp;
	int i = 0;
	if (pos > count-1)
	{
		printf("\n Vi tri khong phu hop!"); getch();
		return;
	}
	temp = head;
	while (i!=pos - 1)
	{
		temp = temp->next; i++;
	}
	del = temp ->next;
	temp->next = del->next;
	count --;
	delete del;
}
void copy (struct SLL * &target, struct SLL * &s)
{
	struct SLL *tt, *ts;
	int i = 1;
	target = new struct SLL; 
	target->val = s ->val;
	target->next = NULL;
	tt = target; 
	ts = s;
	while (i!=count)
	{
		tt->next = new struct SLL;
		tt = tt->next;
		ts = ts->next; 
		tt->val = ts->val;
		tt->next = NULL;
		i++;		
	}
}
void append(struct SLL* &target, struct SLL* &s)
{
	struct SLL *temp;
	temp = target;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = s;
	count*=2;
}

void freee()
{
	struct SLL *temp; 
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}
int main()
{
	struct SLL *s;
	char ch;
	int p, v;
	create();
	while (1)
	{
		printf("\n Chon thao tac theo thu tu duoi: ");
		printf("\n 1. Them mot phan tu!");
		printf("\n 2. Xoa mot phan tu!");
		printf("\n 3. Nhan ban!");
		fflush(stdin); ch = getch();
		if ( ch == '1')
		{
			printf("\n - Them vao gia tri: "); scanf("%d", &v);
			printf("\n - Tai vi tri: "); scanf("%d", &p);
			add(v, p); print();
		}
		else if (ch == '2')
		{
			printf("\n - Xoa phan tu tai vi tri: "); scanf("%d", &p);
			remove(p); print();
		}
		else if (ch == '3') 
		{
			copy(s, head); if (s== NULL) printf("\n NULL"); getch();
			append(head, s);
			print();
		}
		else
		{
			printf("\n Are you sure? Y/..");
			fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break;
		}
	}
	freee(); 
	return 0;
}
