#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct sv{
	char *ht, *lop, *gt;
	int mssv, ns;
	float diem;
	struct sv *next;
};
struct sinhvien{
	char ht[30], lop[30];
	int mssv, ns, gt;
	float diem;
};
struct sv *pdau, *pcuoi;
struct sinhvien tam;
char f[3] = "Nu", m[4] = "Nam";
void giaiphong()
{
	struct sv *p;
	if (pdau == NULL) return;
	while (pdau != NULL)
	{
		p = pdau;
		pdau = p->next;
		delete [] p->ht;
		delete [] p->lop;
		delete p;
	}
	pdau = NULL;
	pcuoi = NULL;
}
void docfile()
{
	FILE *fp = fopen("sinhvien1.dat", "rb");
	struct sv *p;
	char s[30];
	int g;
	if (fp == NULL) 
	{
		printf("\n File khong ton tai!"); getch(); return;
	}
	giaiphong(); rewind(fp);
	while (feof(fp)!=0)
	{
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
		fread(&tam, sizeof(sinhvien), 1, fp);
		strcpy(s, tam.ht); p->ht = new char[strlen(s)+1]; strcpy(p->ht, s);
		strcpy(s, tam.lop); p->lop = new char[strlen(s)+1]; strcpy(p->lop, s);
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
void ghifile()
{
	FILE *fp = fopen("sinhvien1.dat", "wb");
	struct sv *p;
	system("cls");
	if (pdau == NULL)
	{
		printf("\n Danh sach rong!"); getch(); return;
	}
	p = pdau;
	// Sao chep tu p -> tam; Sau do ghi tam len file. Lan luot cho den khi het danh sach
	while (p!= NULL)
	{
		strcpy(tam.ht, p->ht);
		strcpy(tam.lop, p->lop);
		if (p->gt == "Nam") tam.gt = 1;
		else if (p->gt == "Nu") tam.gt = 0;
		tam.mssv = p->mssv;
		tam.ns = p->ns;
		tam.diem = p->diem;
		fwrite(&tam, sizeof(sinhvien), 1, fp);
		p = p->next;
	}
	fclose(fp);
	printf("\n Ghi file thanh cong!");
}
void bosung()
{
	struct sv *p;
	int i = 1, g;
	float d;
	char s[30];
	system("cls");
	printf("\n Bo sung them danh sach!");
	while (1)
	{
		printf("\n Sinh vien thu %d", i++);
		printf("\n \t- Ho ten (ENTER de dung nhap): "); fflush(stdin); gets(s);
		if (s[0] == '\0') break;
		if (pdau == NULL)
		{
			pdau = new sv;
			p = pdau;
		}
		else 
		{
			p = pcuoi;
			p ->next =  new sv;
			p = p->next;
		}
		p->ht = new char[strlen(s)+1]; strcpy(p->ht, s);
		printf("\n \t- Lop: "); fflush(stdin);gets(s);
		p->lop = new char[strlen(s)+1]; strcpy(p->lop, s);
		printf("\n \t- Gioi tinh (Nam-1, Nu-0): "); 
		gender: scanf("%d", &g); 
		if (g != 0 && g!= 1) goto gender;
		if (g==1) p->gt = m;
		else p->gt = f;
		printf("\n \t- MSSV: "); scanf("%d", &g); p->mssv = g;
		printf("\n \t- Nam sinh: "); scanf("%d", &g); p->ns = g;
		printf("\n \t- Diem: "); scanf("%f", &d); p->diem = d;
		p->next = NULL; pcuoi = p;
	}
}
void swap(struct sv *p1, struct sv *p2)
{
	struct sv *pp1, *pp2, *tg, *p;
	/// Sau chuong trinh nay, vi tri tro cua p1 va p2 khong thay doi. Chi co thu tu lien ket trong danh sach moc noi bi thay doi
	if (p1 == pdau)
	{
		// tim pp2, lien truoc p2. Cho no chi toi p1
		p = pdau;
		while (p->next != p2) p = p->next;
		pp2 = p;
		pp2 ->next = p1;
		// doi cau truc lien sau cua p1 va p2
		tg = p1->next;
		p1->next = p2 ->next;
		p2->next = tg;
	}
	else
	{
		// tim pp1 va thay doi
		p = pdau;
		while (p->next != p1) p = p->next;
		pp1 = p; pp1->next = p2;
		// tim pp2 va thay doi
		p = pdau;
		while (p->next != p2) p = p->next;
		pp2 = p; pp2 ->next = p1;
		// Doi cho cau truc lien sau p1 va p2
		tg = p1->next;
		p1->next = p2->next;
		p2->next = tg;
	}
}
int sosanh(char *s1, char *s2)
{
	int i, j;
	// So sanh firstname roi moi den lastname
	i = strlen(s1) - 1; j = strlen(s2) - 1;
	while (i>0)
	{
		if (s1[i]!=' ' && s1[i-1]==' ') break;
		i--;
	}
	while (j>0)
	{
		if (s2[j]!=' ' && s2[j-1]==' ') break;
		j--;
	}
	if (strcmp(&s1[i], &s2[j])>0) return 1;
	else if (strcmp(&s1[i], &s2[j])<0) return -1;
	else return strcmp(s1, s2);
}
void sapxep()
{
	struct sv *tg, *pi, *pj, *pk;
	// Best sort - Thay doi thu tu tro de tao danh sach moi.
	if (pdau == NULL)
	{
		printf("\n Danh sach rong!"); getch(); return;
	}
	pi = pdau;
	while (pi != NULL)
	{
		pj = pi->next; pk = pi; 
		while (pj != NULL)
		{
			if (sosanh(pk->ht, pj->ht)>0) pk = pj;
			pj = pj->next;
		}
		if (pk != pi) 
		{
			tg = pi;
			swap(tg, pk);
			pi = pk;
		}
		pi = pi->next;
	}
	printf("\n Da sap xep xong!");
	getch();
}
void inds()
{
	struct sv *p;
	int i = 1;
	if (pdau == NULL)
	{
		printf("\n Danh sach rong!"); getch(); return;
	}
	p = pdau;
	printf("\n Danh sach sinh vien: ");
	printf("\n %5s %30s %13s %13s %13s %25s %15s", "STT", "Ho va ten", "MSSS", "Nam sinh", "Gioitinh", "Lop", "Diem");
	while (p!=NULL)
	{
		printf("\n %5d %30s %13d %13d %13s %25s %15.2f", i++, p->ht, p->mssv, p->ns, p->gt, p->lop, p->diem);
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
		printf("\n 2. Ghi file!");
		printf("\n 3. Bo sung danh sach!");
		printf("\n 4. Sap xep danh sach theo ten tieng Viet!");
		printf("\n 5. In danh sach ra man hinh!");
		printf("\n ===============================");
		fflush(stdin); ch = getch();
		if (ch == '1') docfile();
		else if (ch == '2') ghifile();
		else if (ch == '3') bosung();
		else if (ch == '4') sapxep();
		else if (ch == '5') inds();
		else
		{
			printf("\n Chan roi a? Y/ ... "); fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break;
		}
	}
	return 0;
}
