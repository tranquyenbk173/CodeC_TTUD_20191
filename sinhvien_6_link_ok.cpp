#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct sv
{
	char *ht;
	int mssv;
	char *lop;
	struct sv *next;
};
struct sv1
{
	char ht[30];
	char lop[30];
	int mssv;
};
struct lop
{
	char *name;
	struct lop *next;
};
int n = 0;
struct sv *pdau, *pcuoi;
struct lop *headc;
int docfile()
{
	struct sv1 temp;
	struct sv *p;
	struct lop *q;
	FILE *f = fopen("sinhvien2.dat", "rb");
	if (f == NULL)
	{
		printf("\n FILE chua ton tai! \n Hay nhap bo sung! "); getch(); return 1;
	}
	while (fread(&temp, sizeof(sv1), 1, f)>0)
	{
		n++;
		if (pdau == NULL)
		{
			pdau = new struct sv;
			p = pdau;
		}
		else
		{
			p->next = new struct sv;
			p = p->next;
		}
		p->ht = new char[strlen(temp.ht)+1];
		strcpy(p->ht, temp.ht);
		if (headc == NULL)
		{
			headc = new struct lop;
			q = headc;
		}
		else
		{
			q->next = new struct lop;
			q = q->next;
		}
		q->name = new char[strlen(temp.lop)+1];
		strcpy(q->name, temp.lop);
		q->next = NULL;
		p->lop = q->name;
		p->mssv = temp.mssv;
		p->next = NULL;
	}
	pcuoi = p;
	fclose(f);
	printf("\n Doc file thanh cong. Co tat ca %d ban ghi", n);
	getch();
	return 0;
}
void inds()
{
	struct sv *p;
	int i = 0;
	// system("cls");
	if (pdau == NULL)
	{
		printf("\n Danh sach rong!"); getch();
		return;
	}
	p = pdau;
	printf("\n %5s %30s %15s %18s", "STT", "Ho va ten", "MSSV", "Lop");
	while (p != NULL)
	{
		printf("\n %5d %30s %15d %18s",++i, p->ht, p->mssv, p->lop);
		p = p->next;
	}
	getch();
}
void bosung()
{
	struct sv *p;
	struct lop *q;
	char s[30];
	int mssv;
	system("cls");
	while (1)
	{
		printf("\n Nhap ho ten sinh vien thu %d (Nhan ENTER de dung nhap): ", n);
		fflush(stdin); gets(s);
		if (s[0] == '\0') break;
		if (pdau == NULL)
		{
			pdau = new struct sv;
			p = pdau;
		}
		else
		{
			p = pcuoi;
			p->next = new struct sv;
			p = p->next;
		}
		p->ht = new char[strlen(s) + 1];
		strcpy(p->ht, s);
		printf("\n Lop: "); fflush(stdin); gets(s);
		if (headc == NULL)
		{
			headc = new struct lop;
			q = headc;
			q->name = new char [strlen(s)+1];
			strcpy(q->name, s);
			q->next = NULL;
		}
		else
		{
			q = headc;
			while (q->next != NULL)
            {
                if (strcmp(q->name, s)==0) goto add;
                q = q->next;
            }
            if (strcmp(q->name, s)==0) goto add;
            q->next = new struct lop;
            q = q->next;
            q->name = new char [strlen(s)+1];
            strcpy(q->name, s);
            q->next = NULL;
		}
		add: p->lop = q->name;
		printf("\n MSSV: "); scanf("%d", &mssv); p->mssv = mssv;
		p->next = NULL; n++;
		pcuoi = p;
	}
}
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
void swap(struct sv *p1, struct sv *p2)
{
	struct sv temp, *next1, *next2;
	char *s;
	int tg;
	next1 = p1->next;
	next2 = p2->next;
	temp = *p1; *p1 = *p2; *p2 = temp;
	p1->next = next1;
	p2->next = next2;
}
void sapxep()
{
	struct sv *i, *j, *k;
	if (pdau == NULL)
	{
		printf("\n Danh sach rong!"); getch(); return;
	}
	for (i = pdau; i != pcuoi; i = i->next)
	{
		k = i;
		for (j = i->next; j != NULL; j = j->next)
			if (sosanh(k->ht, j->ht)>0) k = j;
		if ( k!= i)
		{
			swap(i, k);
		}
	}
	printf("\n Da sap xep xong!"); getch();
}
void ghifile()
{
	FILE *f;
	struct sv1 *temp;
	struct sv *p;
	int d = 0;
	f = fopen("sinhvien2.dat", "wb");
	p = pdau;
	temp = new struct sv1;
	while (p!=NULL)
	{
		strcpy(temp->ht, p->ht);
		strcpy(temp->lop, p->lop);
		temp->mssv = p->mssv;
		fwrite(temp, sizeof(sv1), 1, f); d++;
		p = p->next;
	}
	fclose(f);
	printf("\n Ghi file thanh cong! Ghi tat ca %d ban ghi", d);getch();
}
int main()
{
	char ch;
	docfile();
	while (1)
	{
		//system("cls");
		printf("\n Tuy chon theo stt duoi day: ");
		printf("\n ----------------------------");
		printf("\n 1. Bo sung danh sach!");
		printf("\n 2. Sap xep theo ten!");
		printf("\n 3. In ra man hinh!");
		fflush(stdin); ch = getch();
		if (ch == '1') bosung();
		else if (ch == '2') sapxep();
		else if (ch == '3') inds();
		else
		{
			printf("\n Chan roi a? Y/ ...");
			fflush(stdin); ch = getch();
			if (ch == 'y' || ch == 'Y') break;
		}
	}
	ghifile();
	return 0;
}
