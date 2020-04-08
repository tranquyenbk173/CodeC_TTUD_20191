/* 02/03/2019
Tran Thi Quyen - 20173333
Chuong trinh quan li sinh vien
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char **p, a[30], n = 0;
void bosung();
int sosanh(char *s1, char *s2);
void sapxep();
void inds();
void luufile();
void nhap();


int main()
{
    char ch, *pp;
    pp = a + 30; p = &pp;
    while (1)
    {
        system("cls");
        printf("\n \n \n \n \n");
        printf("\n \t \t    CHUONG TRINH QUAN LI SINH VIEN!");
        printf("\n \t \t ===================================== ");
        printf("\n \t \t 1. Bo sung danh sach!");
        printf("\n \t \t 2. Sap xep danh sach theo ten!");
        printf("\n \t \t 3. In danh sach ra man hinh!");
        printf("\n \t \t 4. Luu danh sach ra file!");
        printf("\n \t \t =====================================");
        printf("\n \t \t Nhan chon 1 - 4 de lua chon, phim khac de thoat! \t ");
        fflush(stdin); ch = getch();
        if (ch == '1') nhap();
        else if (ch == '2') sapxep();
        else if (ch == '3') inds();
        else if (ch == '4') luufile();
        else
        {
            printf("\n Chan roi a? Y/...");
            fflush(stdin);
            ch = getch();
            if (ch == 'y' || ch == 'Y') goto ketthuc;
        }
    }
    ketthuc: printf("\n Thank you!");

    delete []p;
}

void bosung()
{
    system("cls");
    printf("\n ==> Giao dien bo sung danh sach: \n ");
    while (n<1000)
    {
        printf("\n Nhap ho ten sinh vien thu %d: ", n+1);
        fflush(stdin); gets(a);
        if (a[0]=='\0') break;
        p[n] = new char[strlen(a)+1];
        strcpy(p[n], a); n++;
    }
}

void nhap()
{
    while (n<100)
    {
        printf("\n Nhap ho ten sinh vien thu %d: ", n+1);
        fflush(stdin); gets(a);
        if (a[0] == '\0') break;
        p[n] = new char[strlen(a)+1];
        strcpy(p[n], a); printf("\n --> p[%d] = %s", n, p[n]); n++;
    }
}
int sosanh(char *s1, char *s2)
{
    int i = strlen(s1)-1, j = strlen(s2)-1;
    system("cls");
    /*char *p = &s1[i];
    char *q = &s2[j];
    int comp = 0;
    while( *p || *q)
    {
        if(comp = *p-- - *p--)
            break;
    }*/
    while (1)
    {
        if (s1[i]!=' ' && s1[i-1]==' ') break;
        i--;
    }
    while (1)
    {
        if (s2[j]!=' ' && s2[j-1]==' ') break;
        j--;
    }
    if (strcmp(&s1[i], &s2[j])==0) return strcmp(s1, s2);
    return strcmp(&s1[i], &s2[j]);
}
void sapxep()
{
    char *tg;
    int i, j, k;
    system("cls");
    for (i=0; i<n-1; i++)
    {
        k = i;
        for (j=i+1; j<n; j++)
            if (sosanh(p[k], p[j])>0) k = j;
        if (k > i)
        {
            tg = p[i];
            p[i] = p[k];
            p[k] = tg;
        }
    }
    printf("\n Da sap xep thanh cong!"); getch();
}
void inds()
{
    int i;
    printf("\n ------------------------");
    printf("\n Danh sach sinh vien hoan chinh la: ");
    for (i=0; i<n; i++)
        printf("\n %d. %s", i+1, p[i]);
    getch();
}
void luufile()
{
    FILE *fp = fopen("sinhvien.text", "wb");
    int i;
    for (i=0; i<n; i++)
    {
        fwrite(p[i], strlen(p[i]), 1, fp);
    }
    printf("\n Da luu file thanh cong!");
    getch();
}
