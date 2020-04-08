#include<stdio.h>
#include<string.h>
#include<conio.h>
struct test
{
	int a;
	struct test *next;
};
struct test *pdau;
int sosanh(char *xau1, char *xau2)
{
	int i, j; 
	char s11[30], s22[30], s1[30], s2[30];
	strcpy(s1, xau1); strcpy(s2, xau2); 
	i = strlen(s1) - 1; j = strlen(s2) - 1;
	while (i>0) 
	{
		if (s1[i] != ' ' && s1[i-1] == ' ') break;
		i--;
	}
	while (j>0) 
	{
		if (s2[j] != ' ' && s2[j-1] == ' ') break;
		j--;
	}
	strcpy(s11, &s1[i]); strcpy(s22, &s2[j]); 
	if (i>0) s1[i - 1] = '\0'; 
	if (j>0) s2[j - 1] = '\0'; 
	strcat(s11, s1); strcat(s22, s2); 
	return strcmp(s11, s22);		
}
void swap(struct test *p1, struct test *p2)
{
	struct test *pre1, *pre2, *tg;
	if (p1 != pdau)
		{
			pre1 = pdau;
			while (pre1->next != p1) pre1 = pre1->next; 
			pre1->next = p2;
		}
	pre2 = pdau;
	while (pre2->next != p2) pre2 = pre2->next; 
	pre2->next = p1;  
	tg = p1->next; p1->next = p2->next; p2->next = tg; 
}
int main()
{
	struct test *p1, *p2;
	/*char s1[30], s2[30];
	printf("\n Nhap vao s1: "); fflush(stdin); gets(s1);
	printf("\n Nhap vao s2: "); fflush(stdin); gets(s2);
	printf("\n So sanh s1 va s2 theo ten: ");
	if (sosanh(s1, s2)>0) printf("\n s1 > s2");
	else printf("\n s1 < s2");
	printf("\n s1 = %s", s1);
	printf("\n s2 = %s", s2);
	getch(); */
	pdau = p1 = new struct test;
	p1->a = 3;
	p1->next = new struct test;
	p2 = p1->next;
	p2->a = 5;
	p2->next = NULL; 
	swap(p1, p2); p1 = p2;
	while (p1!= NULL) 
	{
		printf("%d --> ", p1->a); getch(); p1 = p1->next;
	}
}
