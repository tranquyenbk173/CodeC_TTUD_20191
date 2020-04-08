/// Code cay nhi phan

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Btree 
{
	int data;
	struct Btree *left;
	struct Btree *right;
};

struct Btree *root;

void TaoFile();

// Them mot Node moi vao cay:
void ThemNodeVaoCay(struct Btree* &root, int data)
{
	if (root == NULL)
	{
		root = new struct Btree;
		root->data = data;
		root->right = NULL;
		root->left = NULL;
		return;
	}
	else
	{
		// Neu phan tu nho hon node goc: 
		if (root->data > data)
			ThemNodeVaoCay(root->left, data); // them vao ben trai	
		else if (root->data < data) // Neu phan tu lon hon node goc:
			ThemNodeVaoCay(root->right, data); // them vao ben phai
	}
}

	
// Xay dung cay nhi phan theo du lieu cho trong FILE:
void Build_B_Tree_fromFILE()
{
	int data;
	FILE *fp = fopen("Btree.txt", "rb");
	if (fp == NULL) // kiem tra file rong 
	{
		printf("\n Khong tim thay du lieu!");
		getch(); 
		return;
	}
	
	while (fread(&data, sizeof(int), 1, fp) > 0)
	{
		ThemNodeVaoCay(root, data);
	}
	
	fclose(fp);
	printf("\n Xay dung cay nhi phan hoan thanh!"); getch();
	return;
}

// Xuat du lieu:
void Xuat_NLR(struct Btree *root)
{
	if (root == NULL) return;
	printf("\t %d", root->data);
	Xuat_NLR(root->left);
	Xuat_NLR(root->right);
}

// Dem so la chan:
int EvenLeaf(struct Btree *root)
{
	if(root == NULL) // TH nut rong: 
		return 0;
	
	if(root->right == NULL && root->left == NULL) // TH nut la chan: 
		return 1;
	
	return EvenLeaf(root->left) + EvenLeaf(root->right);
}

//Dem so nut co data > k:
int countNodes(struct Btree *root, int k)
{
	if (root == NULL) // TH nut rong:
		return 0;
	
	if (root->data > k) // TH node co data > k
		return countNodes(root->right, k) + countNodes(root->left, k) + 1;
	else  // TH node co data <= k
		return countNodes(root->right, k) + countNodes(root->left, k);
}

// Dem so la cua cay:
int countLeaft(struct Btree *root)
{
	if (root == NULL) return 0; // TH nut rong:
	
	if (root->left == NULL && root->right == NULL) 
		return 1;
	else
		return countLeaft(root->left) + countLeaft(root->right); 
}

// Tong trong nut le cua cay:
int OddSum(struct Btree *root)
{
	if (root == NULL) 
		return 0;
	
	if (root->data % 2 != 0) 
		return root->data + OddSum(root->left) + OddSum (root->right);
	else 
		return OddSum(root->left) + OddSum (root->right);
}

//Tim Node trai nhat o cay con phai hoan doi cho Root;
void MostLeftOnRight(struct Btree* &X, struct Btree* &Y)
{
	if (Y->left != NULL)
		MostLeftOnRight(X, Y->left);
		
	X->data = Y->data;
	X = Y;
	Y = Y->right;
}

// Xoa mot root co gia tri bat ki trong cay:
void XoaNode(struct Btree* &root, int k)
{
	if (root == NULL) // Neu cay rong thi thoat	
		return;
	
	if (root->data > k)
		XoaNode(root->left, k);
	else if (root->data < k)
		XoaNode(root->right, k);
	else // Khi root->data == k, da tim duoc node can xoa:
	{
		struct Btree *X = root; // X la Node the mang cho root, se bi xoa, con root se duoc gan boi mot Node khac phu hop
		
		if (root->left != NULL) // Co the Ton tai cay con phai
		{
			root = root->right;
		}
		else if (root->right != NULL) // Co the ton tai cay con trai
		{
			root = root->left;
		}
		else // Khi root co ca cay con trai va cay con phai;
		{
			struct Btree *Y = root->right;
			MostLeftOnRight(X, Y);
		}
		
		delete(X);
	}
}

//Lay phan xa guong cua cay:
struct Btree* mirror(struct Btree *root)
{
	struct Btree *temp = new struct Btree;
	
	if (root == NULL)
		return NULL;
	
	temp->data = root->data;
	temp->left = mirror(root->right);
	temp->right = mirror(root->left);
	
	return temp;	
}

// Tong cac nut cua cay nhi phan:
int Sum(struct Btree *root)
{
	if (root == NULL)
		return 0;
	return root->data + Sum(root->left) + Sum(root->right);
}

// Tim gia tri chan lon nhat tren cay nhi phan: 
int EvenMax(struct Btree *root)
{
	int L, R, temp;
	if (root == NULL) return INT_MIN;
	
	L = EvenMax(root->left);
	R = EvenMax(root->right);
	
	temp = (L > R) ? L : R;
	if (root->data % 2 == 0) 
		if (root->data > temp) temp = root->data;
	
	return temp;
}

// Chieu cao cua Node
int highNode(struct Btree *root)
{
	int hL, hR;
	if (root == NULL) return 0;
	
	hL = highNode(root->left);
	hR = highNode(root->right);
	
	return ((hL > hR)? hL : hR) + 1;
}

// Kiem tra cay nhi phan can bang: 
int IsBST(struct Btree *root)
{
	int L, R;
	if (root == NULL) // Cay rong la cay can bang! 
		return 1;
	
	if (root->left == NULL && root->right == NULL) // Node la la mot cay can bang
		return 1;
	
	L = highNode(root->left);
	R = highNode(root->right);
	
	if (abs(L - R) < 2)
	{
		return IsBST(root->left) * IsBST(root->right);
	}
	else 
		return 0;
	
}

// Duong kinh di qua Node
int Diam(struct Btree *Node)
{
	if (Node->left != NULL)
		if (Node->right != NULL)
		{
			return highNode(Node->left) + highNode(Node->right) + 1;
		}
		
	return 0;
}

// Tinh duong kinh cua cay nhi phan:
int BT_Diam(struct Btree *root)
{
	int dL, dR, dN, max;
	if (root == NULL)
		return 0;
		
	max = dN = Diam(root);
	dL = BT_Diam(root->left);
	dR = BT_Diam(root->right);
	
	if(dL > max) 
		max = dL;
	if (dR > max)
		max = dR;
	
	return max;
}

// Kiem tra can tren gia tri: xem co phai tat ca cac node deu co gia tri nho hon k?
int IsLess(struct Btree *root, int k)
{
	if (root == 0) // coi nhu nut rong thoa man <chinh la nut sau nut la>
		return 1;
		
	if (root->data < k)
	{
		return IsLess(root->left, k)*IsLess(root->right, k);
	}
	else 
		return 0;
}

//Dua ra menu chon:
void menu()
{
	int ch;
	
	while (1)
	{
		// system("cls");
		printf("\n =================== MENU ===================");
		printf("\n0. Thoat!");
		printf("\n1. Xuat du lieu:");
		printf("\n2. Dem so nut la chan: ");
		printf("\n3. Dem so nut co gia tri lon hon mot so nguyen: ");
		printf("\n4. Dem so nut la cua cay: ");
		printf("\n5. Tong cac nut le trong cay: ");
		printf("\n6. Xoa mot Node tren cay co gia tri cho truoc: ");
		printf("\n7. Lay phan xa guong cua cay hien tai: ");
		printf("\n8. Tong cac nut cua cay nhi phan: ");
		printf("\n9. Tim gia tri chan lon nhat tren cay nhi phan: ");
		printf("\n10. Kiem tra cay nhi phan can bang: ");
		printf("\n11. Tinh duong kinh cua cay: ");
		printf("\n12. Kiem tra cac node co nho hon 1 gia tri cho truoc: ");
		printf("\n ============================================");
		
		scanf("%d", &ch);
		if (ch == 0) 
		{
			break;
		}
		else if (ch == 1) 
		{
			printf("\n Xuat cay theo thu tu truoc: ");
			Xuat_NLR(root);
			getch();
		}
		else if (ch == 2)
		{
			printf("\n So nut la chan la: %d", EvenLeaf(root));
			getch();
		}
		else if (ch == 3)
		{
			int k;
			printf("\n Nhap vao so nguyen k: "); scanf("%d", &k);
			printf("\n So nut co gia tri lon hon %d la: %d", k, countNodes(root, k));
			getch();
		}
		else if (ch == 4)
		{
			printf("\n So luong nut la cua cay la: %d", countLeaft(root));
			getch();
		}
		else if (ch == 5)
		{
			printf("\n Tong cac nut le trong cay la: %d", OddSum(root));
			getch();
		}
		else if (ch == 6)
		{
			int k;
			printf("\n Nhap gia tri cua node can xoa: ");
			scanf("%d", &k);
			XoaNode(root, k);
			printf("\n Da xoa thanh cong  node co gia tri %d!", k); 
			getch();
		}
		else if (ch == 7)
		{
			printf("\n Phan xa guong cua cay hien tai: ");
			struct Btree *Mirror = mirror(root);
			printf("\n ----> "); Xuat_NLR(Mirror);
			printf("\n Hoan tat!"); 
			getch();
		}
		else if (ch == 8)
		{
			printf("\n Tong cac nut cua cay nhi phan la: %d", Sum(root));
			getch();
		}
		else if (ch == 9)
		{
			printf("\n Gia tri chan lon nhat tren cay nhi phan la: %d", EvenMax(root));
			getch();
		}
		else if(ch == 10)
		{
			if (IsBST(root) == 1) 
			{
				printf("\n Cay nhi phan da cho la can bang!"); 
				getch();
			}
			else 
			{
				printf("\n Cay nhi phan da cho la khong can bang!");
				getch();
			}
		}
		else if (ch == 11)
		{
			printf("\n Duong kinh cua cay nhi phan la: %d", BT_Diam(root));
			getch();
		}
		else if (ch == 12)
		{
			if (root == NULL)
			{
				printf("\n Cay rong!");
				getch();
			}
			else
			{
				int k;
				printf("\n Nhap gia tri k: "); scanf("%d", &k);
				
				if (IsLess(root, k))
					printf("\n Cac node tren cay deu nho hon %d!", k);
				else 
					printf("\n Co it nhat mot node tren cay lon hon %d!", k);
				getch();
			}
		}
		else 
		{
			printf("\n Nhap lai!"); getch();
		}
	}		
}


int main()
{
	Build_B_Tree_fromFILE();
	menu();
	getch();
	return 0;
}

// Tao file du lieu de xay dung BTree:
void TaoFile()
{
	FILE *fp = fopen("Btree.txt", "wt");
	int a[18] = {1, 4, 5, 2, 7, 6, 13, 12, 8, 6, 22, 21, 0, 19, 7, 88, 17, 18};
	
	for (int i = 0; i<18; i++) // Bat dau ghi file:
		fwrite(&(a[i]), sizeof(int), 1, fp);
	
	fclose(fp);
	printf("\n Ghi FILE thanh cong!"); getch();
	return;
}
