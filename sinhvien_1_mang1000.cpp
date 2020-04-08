#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char a[30], **p, n = 0;
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
void inds()
{
    int i;
    printf("\n ------------------------");
    printf("\n Danh sach sinh vien hoan chinh la: ");
    for (i=0; i<n; i++)
        printf("\n %d. %s", i+1, p[i]);
}
int sosanh(char *s1, char *s2)
{
    int i = strlen(s1)-1, j = strlen(s2)-1;
    system("cls");
    while (1)
    {
        if (s1[i]!=' ' && s1[i-1]==' ') break;
        i--;
    }
    while (1)
    {
        if (s2[j]!=' ' && s2[i-1]==' ') break;
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
            if (sosanh(p[i], p[j])>0) k = j;
        if (k > i)
        {
            tg = p[i];
            p[i] = p[k];
            p[k] = tg;
        }
    }
    printf("\n Da sap xep thanh cong!");getch();
}
int main()
{
    char *pp, ch;
    pp = a+30; p = &pp;
    nhap();
    inds();

    getch();
}
