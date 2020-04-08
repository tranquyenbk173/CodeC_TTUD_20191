#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct sv
{
	char *ht, *lop, *gt;
	int mssv, ns;
	float diem;
	struct sv *next;
};
struct sinhvien
{
	char ht[30],lop[30];
	int gt, mssv, ns;
	float diem;
};
struct sinhvien tam;
struct sv *pdau, *pcuoi;
char m[4] = "Nam", f[3] = "Nu";
int n = 0;
void freee()
{
	struct sv *p;
	if (pdau == NULL) return;
	while (pdau != NULL){
	p = pdau;
	pdau = p->next;
	delete[] p->ht;
	delete[] p->lop;
	delete p;
	}
	pdau = NULL;
	pcuoi = NULL;
	printf("\n Giai phong thanh cong!"); getch();
}
void docfile()
{
	FILE *fp = fopen("sinhvien.dat", "rb");
	struct sv *p;
	system("cls");
	if (fp == NULL)
	{
		printf("\n File khong ton tai!"); getch(); return;
	}
	freee();
	fseek(fp, 0, 0); 
	while (feof(fp)==0)
	{
		fread(&tam, sizeof(tam), 1, fp);
		if (pdau == NULL)
		{
			pdau = new sv;
			p = pdau;
		}
		else 
		{
			p->next = new sv;
			p = p->next;
		}
		p->ht = new char[strlen(tam.ht)+1];
		p->lop = new char[strlen(tam.lop)+1];
		strcpy(p->ht, tam.ht);
		strcpy(p->lop, tam.lop);
		if (tam.gt == 1) p->gt = m;
		else if (tam.gt == 0) p->gt = f;
		p->mssv = tam.mssv;
		p->ns = tam.ns;
		p->diem = tam.diem;
		p->next = NULL;
	}
	pcuoi = p;
	fclose(fp);
	printf("\n Doc file thanh cong!"); getch();
}
void luufile()
{
	FILE *fp = fopen("sinhvien.dat", "wb");
	struct sv *p;
	system("cls");
	if (pdau == NULL) {
		printf("\n Danh sach rong!"); getch(); return;
	}
	p = pdau;
	while (p != NULL)
	{
		strcpy(tam.ht, p->ht);
		strcpy(tam.lop, p->lop);
		if (p->gt == "Nam") tam.gt = 1;
		else if (p->gt == "Nu") tam.gt = 0;
		tam.mssv = p->mssv;
		tam.ns = p->ns;
		tam.diem = p->diem;
		p = p->next;
		fwrite(&tam, sizeof(tam), 1, fp);
	}
	fclose(fp);
	printf("\n Ghi file thanh cong!"); getch();
}
void bosung()
{
	struct sv *p;
	char s[30];
	int g;
	system("cls");
	printf("\n Bo sung them danh sach sinh vien: ");
	while (1)
	{
		printf("\n Ho ten sinh vien thu %d: (Nhan ENTER de ket thuc nhap) ", n+1); fflush(stdin); gets(s);
		if (s[0] == '\0') break;
		if (pdau == NULL)
		{
			pdau = new sv;
			p = pdau; 
		}
		else 
		{
			p = pcuoi;
			p->next = new sv;
			p = p->next;
		}
		p->ht = new char[strlen(s) + 1]; strcpy(p->ht, s);
		gender: printf("\n Gioi tinh (Nam-1, Nu-0): "); scanf("%d", &g);
		if (g != 1 && g != 0) goto gender;
		if (g == 1) p->gt = m; 
		else p->gt = f;
		printf("\n Lop sinh vien: "); fflush(stdin); gets(s);
		p->lop = new char[strlen(s) + 1]; strcpy(p->lop, s);
		printf("\n MSSV: "); scanf("%d", &(p->mssv));
		printf("\n Nam sinh: "); scanf("%d", &(p->ns));
		printf("\n Diem: "); scanf("%f", &(p->diem));
		p->next = NULL; n++; pcuoi = p;
	}
}
int sosanh(char *s1, char *s2)
{
	int i = strlen(s1) - 1, j = strlen(s2) - 1;
	while (i>0)
	{
		if (s1[i] !=' ' && s1[i-1] == ' ') break;
		i--;
	}
	while (j>0)
	{
		if (s2[j] !=' ' && s2[j-1] == ' ') break;
		j--;
	}
	if (strcmp(&s1[i-1], &s2[j-1])>0) return 1;
	else if (strcmp(&s1[i-1], &s2[j-1])<0) return -1;
	else return strcmp(s1, s2);
}
void swapnode(struct sv *p1, struct sv *p2)
{
	struct sv *pp1, *pp2, *tg, *p;
	if (p1 == pdau) 
	{ 
		 
		pp1 = new sv; pp1->next = pdau;
	}
	else 
	{
		p = pdau;
		while (p->next != p1) p = p->next;
		pp1 = p;
	}
	p = pdau;
	while (p->next != p2) p = p->next; 
	pp2 = p; 
	tg = p1->next; p1->next = p2->next; p2->next = tg;
	tg = pp1->next; pp1->next = pp2->next; pp2->next = tg;
	if (p1 == pdau) pdau = p2;
	p = pdau;
	while (p->next != NULL) p  = p->next; 
	pcuoi = p;
 }
void sapxep()
{
	struct sv *ps, *pe, *tg, *p, *p1;
	system("cls");
	if (pdau == NULL)
	{
		printf("\n Chua co danh sach!"); getch(); return;
	}
	ps = pdau;
	while (ps != NULL)
	{
		p = ps->next; pe = p1 = ps;
		while (p != NULL)
		{
			if (sosanh(p1->ht, p->ht)>0) pe = p;
			p = p->next; 		
		}
		if (pe != p1) 
		{
			swapnode(p1, pe); 
			ps = pe;	
		}
		ps = ps->next;
	}
	printf("\n Da sap xep xong!"); getch();
}
void inds()
{
	struct sv *p;
	int i = 1;
	system("cls");
	if (pdau == NULL)
	{
		printf("\n Danh sach hien tai rong!"); getch(); return;
	}
	p = pdau;
	printf("\n %4s\t %8s %30s %10s\t %8s %15s \t%5s","STT", "MSSV", "Ho ten", "Gioi tinh", "Nam sinh", "Lop", "Diem");
	while(p != NULL)
	{
		printf("\n %4d\t %8d %30s %10s\t %8d %15s \t%5.1f", i++, p->mssv, p->ht, p->gt, p->ns, p->lop, p->diem);
		p = p->next;
	}
	getch();
}

int main()
{
	char ch;
	while (1)
	{
		system("cls");
		printf("\n Chuong trinh quan li sinh vien!");
		printf("\n ===============================");
		printf("\n 1. Doc du lieu tu file!");
		printf("\n 2. Nhap them du lieu!");
		printf("\n 3. Sap xep danh sach theo ten!");
		printf("\n 4. In danh sach!");
		printf("\n 5. Luu danh sach ra file!");
		printf("\n ===============================");
		printf("\n Chon tu 1 - 5 de thao tac. Chon phim khac de thoat chuong trinh!");
		fflush(stdin); ch = getch();
		if (ch == '1') docfile();
		else if (ch == '2') bosung();
		else if (ch == '3') sapxep();
		else if (ch == '4') inds();
		else if (ch == '5') luufile();
		else 
		{
			printf("\n Chan roi a? ");
			fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break;
		}
	}
	printf("\n See again!"); getch();
	freee();
	return 0;
}
