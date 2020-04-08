#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char key[30];
	int BalFactor;
	struct node *left;
	struct node *right;
};

typedef node* NODE;

NODE root;


void LeftLeft(NODE &T) // Xoay phai trong TH trai - trai
{
	NODE *T1 = T->pLeft;
	T->pLeft = T1->pRight;
	T1->pRight = T;
	switch(T1->BalFactor)
	{
		case -1: T->BalFactor = 0;
				T1->BalFactor = 0; break;
		case 0: T->BalFactor = -1;
				T1->BalFactor = 1; break;
	}
	T = T1;
}

void RightRight(NODE &T) // Xoay trai trong truong hop phai
{
	NODE* T1 = T->pRight;
	T->pRight = T1->pLeft;
	T1->pLeft = T;
	switch(T1->BalFactor)
	{
		case 1: T->BalFactor = 0;
				T1->BalFactor = 0; break;
		case 0: T->BalFactor = 1;
				T1->BalFactor = -1; break;
	}
	T = T1;
}

void LeftRight(NODE) &T) // Xoay kep trong TH trai - phai
{
	NODE* T1 = T->pLeft;
	NODE* T2 = T1->pRight;
	T->pLeft = T2->pRight;
	T2->pRight = T;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	switch(T2->BalFactor)
	{
		case -1: T->BalFactor = 1;
		T1->BalFactor = 0; break;
		case 0: T->BalFactor = 0;
		T1->BalFactor = 0; break;
		case 1: T->BalFactor = 0;
		T1->BalFactor = -1; break;
	}
	T2->BalFactor = 0;
	T = T2;
}


void RightLeft(NODE &T) // Xoay kep trong truong hop lechj phai - trai
{
	NODE* T1 = T->pRight;
	NODE* T2 = T1->pLeft;
	T->pRight = T2->pLeft;
	T2->pLeft = T;
	T1->pLeft = T2->pRight;
	T2->pRight = T1;
	
	switch(T2->BalFactor)
	{
		case -1: T->BalFactor = 0;
				T1->BalFactor = 1; break;
		case 0: T->BalFactor = 0;
				T1->BalFactor = 0; break;
		case 1: T->BalFactor = -1;
				T1->BalFactor = 0; break;
	}
	
	T2->BalFactor = 0;
	T = T2;
}

int BalanceLeft(AVLTree &T)
{
	AVLNode* T1 = T->pLeft;
	switch(T1->BalFactor)
	{
		case -1: LeftLeft(T); return 2;
		case 0: LeftLeft(T); return 1;
		case 1: LeftRight(T); return 2;
	}
	return 0;
}

int BalanceRight(AVLTree &T)
{
	AVLNode* T1 = T->pRight;
	switch(T1->BalFactor)
	{
		case -1: RightLeft(T); return 2;
		case 0: RightRight(T); return 1;
		case 1: RightRight(T); return 2;
	}
	return 0;
}

void InsertNode(NODE &T, char *s)
{
	int n = strlen(s);
	for (i = 0; i<strlen(s); i++)
	{
		NODE temp = T;
		while ()
	}
}
