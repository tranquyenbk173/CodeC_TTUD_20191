#include<stdio.h>
#include<string.h>
#include<conio.h>

typedef struct avl
{
	char key[30];
	char m[30];
	int bal;
	// bal = 0 can bang, -1 lech trai, 1 lech phai
	struct avl *pLeft;
	struct avl *pRight;
} AVLNODE;

char ans[5][50];
int ll = 0;


AVLNODE* CreateNode(char* Data)
{
	AVLNODE* pNode;
	pNode = new AVLNODE; //Xin cap phát bo nho dong de tao mot phan tu (node) moi

	if (pNode == NULL)
	{
		return NULL;
	}
	
	int n = strlen(Data), k = 0;
	char tu[30], nghia[30];
	int i;
	for(i = 0; i<n; i++)
	{
		if (Data[i] != ' ')
			tu[i] = Data[i];
	}
	tu[i] = '\0';
	
	for (; i<n; i++)
		nghia[k++] = Data[i];
	nghia[k] = '\0';
	
	strcpy(pNode->key, tu);
	strcpy(pNode->m, nghia);
	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->bal = 0;
	return pNode;
}

void LeftRotate(AVLNODE* &P) // Xoay don trai tai P
{
	AVLNODE *Q;
	Q = P->pRight;
	P->pRight = Q->pLeft;
	Q->pLeft = P;
	P = Q;
}

void RightRotate(AVLNODE* &P) // Xoay don phai tai P
{
	AVLNODE *Q;
	Q = P->pLeft;
	P->pLeft = Q->pRight;
	Q->pRight = P;
	P = Q;
}

void LeftBalance(AVLNODE* &P) // xu li cay con trai mat can bang
{
	switch(P->pLeft->bal)
	{
		case -1: //mat can bang trai- trai
			RightRotate(P);
			P->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1: // mat can bang trai - phai
			LeftRotate(P->pLeft);
			RightRotate(P);

			switch(P->bal)
			{
				case 0:
					P->pLeft->bal= 0;
					P->pRight->bal= 0;
					break;
				case -1:
					P->pLeft->bal= 0;
					P->pRight->bal= 1;
					break;
				case 1:
					P->pLeft->bal= -1;
					P->pRight->bal= 0;
					break;
			}
			P->bal = 0;
			break;
	}
}

void RightBalance (AVLNODE* &P) // xu li cay con phai mat can bang
{
	switch(P->pRight->bal)
	{
		case 1: // lech phai phai
			LeftRotate(P);
			P->bal = 0;
			P->pLeft->bal = 0;
			break;
		case -1: // lech phai - trai
			RightRotate(P->pRight);
			LeftRotate(P);

			switch(P->bal)
			{
				case 0:
					P->pLeft->bal = 0;
					P->pRight->bal = 0;
					break;
				case -1:
					P->pRight->bal = 1;
					P->pLeft ->bal = 0;
					break;
				case 1:
					P->pRight->bal = 0;
					P->pLeft->bal = 1;
					break;
			}
			P->bal =  0;
			break;
	}
}

int InsertNode(AVLNODE* &root, char* s)
{
	int res;// ghi nhan ket qua khi them vao cay con cua root
	// res = -1 them that bai do thieu bo nho
	// res = 0 them that bai do trung
	// res = 1 them thang cong nhung khong lam thay doi chieu cao cay
	// res = 2 them thanh cong lam tang chieu cao cua cay

	if (root == NULL)
	{
		root = CreateNode(s);
		if (root == NULL)
			return -1; // het bo nho

		return 2; // them thanh cong, lam tang chieu cao cay
	}

	else
	{
		int t = strcmp(root->key, s);
		if(t == 0)
			return 0; // khoa da co tren cay
		else if (t < 0)
		{
			res = InsertNode(root->pRight, s);
			if (res < 2)
				return res; // them khong thanh cong

			switch(root->bal)
			{
				case 0: root->bal = 1; return 2;
				case -1: root->bal = 0; return 1;
				case 1: RightBalance(root); return 1;
			}
		}
		else
		{
			res = InsertNode(root->pLeft, s);
			if (res < 2)
				return res;

			switch(root->bal)
			{
				case 0: root->bal = -1; return 2;
				case -1: LeftBalance(root); return 1;
				case 1: root->bal = 0; return 1;
			}
		}
	}
}

void Traverse(AVLNODE* root) // Duyet Theo thu tu LNR
{
	if (root != NULL)
	{
		Traverse(root->pLeft);
		printf("\n Khoa %s, can bang: %d ", root->key, root->bal);
		Traverse(root->pRight);
	}
}

void Suggest(AVLNODE* root, char *s, int &count) // Suggest tu doan ki tu chua hoan chinh
{
	if (root != NULL)
	{
		Suggest(root->pLeft, s, count);
		int i = 0;

		while (s[i] == root->key[i])
		{
			i++;
			if (i == strlen(s))
			{
				if (count == 5) return;
				printf("\n %d %s: %s", ll+1, root->key, root->m);
				
				char s[50];
				strcat(s, root->key); 
				strcat(s, ": ");
				strcat(s, root->m); 
				strcpy(ans[ll++], s);
				
				count ++;
				break;
			}
		}

		Suggest(root->pRight, s, count);
	}
}

void RemoveAll(AVLNODE* root)
{
	if (root!= NULL)
	{
		RemoveAll(root->pLeft);
		RemoveAll(root->pRight);
		delete root;
	}
}

int main()
{
	AVLNODE* root = NULL;
	char Data[30];
	int count = 0; // dem so tu suggest duoc!

	// Nhap tu dien vao cay AVL:
	FILE* fp = fopen("tudien.txt", "rb");
	while (fscanf(fp, "%s", Data) > 0)
	{
		InsertNode(root, Data);
	}

//	printf("\n Cay AVL vua tao la: ");
//	Traverse(root);

	// Nhap tu de suggest =]]
	printf("\n Nhap vao mot tu: "); scanf("%s", Data);

	Suggest(root, Data, count);
	if (count == 0)
		printf("\n Khong tim duoc ket qua!");
	
	int kk;
	printf("\n Tu thu may? "); scanf("%d", &kk);
	printf("\n %d, %s", kk, ans[kk]);
		
	RemoveAll(root);
	getch();

	return 0;
}

