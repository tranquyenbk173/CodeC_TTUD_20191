#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct sv
{
	char *ht;
	int mssv;
	char *lop;
};
struct sv1
{
	char ht[30];
	int mssv;
	char lop[30];
};
struct sv *a;
int n = 0;
int max = 0;

void Create_New_List()
{
	struct sv *temp;
	int i;
	
	temp = new struct sv[n + 50];
	max = max + 50;
	
	for (i = 0; i < n; i++)
		temp[i] = a[i];
		
	delete[] a;
	
	a = temp;
}

void Read_File()
{
	FILE *fp = fopen("sv1.dat", "rb");
	struct sv1 temp;
	
	/* Kiem tra file rong!*/
	if (fp == NULL)
	{
		printf("\n FILE rong!"); 
		printf("\n Ban co the bo sung them!"); getch();
		return;
	}	
	
	/* Khoi tao mang ban dau: */
	a = new struct sv[50];
	
	/* Doc file*/
	while (fread(&temp, sizeof(struct sv1), 1, fp) > 0)
	{
		if (n >= max)
			Create_New_List();
		 
		a[n].ht = new char[strlen(temp.ht) + 1]; 
		strcpy(a[n].ht, temp.ht);
		a[n].lop = new char [strlen(temp.lop) + 1];
		strcpy(a[n].lop, temp.lop);
		a[n].mssv = temp.mssv;
		n ++;	
		
	}
	
	fclose(fp);
	
	printf("\n Doc file thanh cong! \n Co tat ca %d ban ghi!", n); getch();
}

void Bo_Sung()
{
	char s[30];
	
	system("cls");
	
	while (1)
	{
		printf("\n Nhap ho ten: (Nhan ENTER de dung nhap!) ");
		fflush(stdin); gets(s);
		if (s[0] == '\0') 
			break; 
		if (n >= max) 
			Create_New_List();
				
		a[n].ht = new char [strlen(s) + 1];
		strcpy(a[n].ht, s);
		
		printf("\n MSSV: "); scanf("%d", &(a[n].mssv));
		
		printf("\n Lop: "); fflush(stdin); gets(s);
		a[n].lop = new char [strlen(s) + 1];
		strcpy(a[n].lop, s);
		n++;
	}
}

void Sap_Xep()
{
	struct sv temp;
	int i, j, k;
	for (i = 0; i<n-1; i++)
	{
		k = i;
		for (j = i+1; j<n; j++)
			if (strcmp(a[k].ht, a[j].ht) > 0) 
				k = j;
		if (k != i)
		{
			printf("\n %s \t %s", a[i].ht, a[k].ht); getch();
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			printf("\n %s \t %s", a[i].ht, a[k].ht); getch();
		}
	}
}

void In_Ds()
{
	int i;
	// system("cls");
	
	printf("\n %5s %30s %10s %20s", "STT", "Ho va ten", "MSSV", "Lop");
	
	for (i = 0; i<n; i++)
		printf("\n %5d %30s %10d %20s", i, a[i].ht, a[i].mssv, a[i].lop);
		
	getch();
}

void Write_File()
{
	FILE *fp = fopen("sv1.dat", "wb");
	struct sv1 temp;
	int i;
	for (i = 0; i < n; i++)
	{
		strcpy(temp.ht, a[i].ht);
		strcpy(temp.lop, a[i].lop);
		temp.mssv = a[i].mssv;
		
		fwrite(&temp, sizeof(struct sv1), 1, fp);
	}
	fclose(fp);
	
	printf("\n Ghi file thanh cong! \n Co tat ca %d ban ghi", n); getch();
}
int main()
{
	char ch;
	Read_File();
	
	/* Dua Menu ra man hinh: */
	while (1)
    {
        // system("cls");
        printf("\n \n \n \n \n");
        printf("\n \t \t    CHUONG TRINH QUAN LI SINH VIEN!");
        printf("\n \t \t ===================================== ");
        printf("\n \t \t 1. Bo sung danh sach!");
        printf("\n \t \t 2. Sap xep danh sach theo ten!");
        printf("\n \t \t 3. In danh sach ra man hinh!");
        printf("\n \t \t =====================================");
        printf("\n \t \t Nhan chon 1 - 3 de lua chon, phim khac de thoat! \t ");
        fflush(stdin); ch = getch();
        if (ch == '1') Bo_Sung();
        else if (ch == '2') Sap_Xep();
        else if (ch == '3') In_Ds();
        else
        {
            printf("\n Chan roi a? Y/...");
            fflush(stdin);
            ch = getch();
            if (ch == 'y' || ch == 'Y') break;
        }
    }
    
    Write_File();
    
    return 0;
}
