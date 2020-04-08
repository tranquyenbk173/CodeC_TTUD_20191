#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int **a, **b, **c, m, n, p, q, cc;
int test()
{
    int i, j;
    if (m == 0 || p == 0)
    {
        printf("\n Ma tran khong ton tai!"); getch();
        return 0;
    }
    else
    {
        printf("\n Ma tran A: ");
        for (i=0; i<m; i++)
        {
            printf("\n ");
            for (j=0; j<n; j++)
                printf("\t %d", a[i][j]);
        }
        printf("\n Ma tran B: ");
        for (i=0; i<p; i++)
        {
            printf("\n ");
            for (j=0; j<q; j++)
                printf("\t %d", b[i][j]);
        }
    }
    getch();
}
void free_p()
{
    int i;
    for (i=0; i<m; i++)
        delete[] a[i];
    delete[] a;
    for (i=0; i<p; i++)
        delete[] b[i];
    delete[] b;
}
void nhap2()
{
    int i, j;
    system("cls");
    printf("\n Nhap vao hai ma tran: "); getch();
    printf("\n Nhap ma tran A: ");
    a = new int *[m];
    for (i=0; i<m; i++)
        {
            a[i] = new int [n];
            for (j=0; j<n; j++)
            {
                printf("\n Nhap a[%d][%d] = ", i+1, j+1); scanf("%d", &a[i][j]);
            }
        }
    printf("\n Nhap ma tran B: ");
    b = new int *[p];
    for (i=0; i<p; i++)
        {
            b[i] = new int [q];
            for (j=0; j<q; j++)
            {
                printf("\n Nhap b[%d][%d] = ", i+1, j+1); scanf("%d", &b[i][j]);
            }
        }
}
void cong()
{
    int i, j;
    char ch;
    printf("\n Ban co muon thuc hien tinh toan voi ma tran truoc do? Y/..."); fflush(stdin); ch = getch();
    if (ch == 'y' || ch == 'Y')
        if (test() != 0) goto beg;
    nhap: system("cls");
    printf("\n Nhap kich thuoc cua hai ma tran can tinh tong (Kich thuoc phai giong nhau)!");
    printf(("\n Ma tran A: "));
    printf("\n \t - So hang: "); scanf("%d", &m);
    printf("\n \t - So cot: "); scanf("%d", &n);
    printf(("\n Ma tran B: "));
    printf("\n \t - So hang: "); scanf("%d", &p);
    printf("\n \t - So cot: "); scanf("%d", &q);
    if (m!=p || n!=q)
    {
        printf("\n Kich thuoc khong phu hop, yeu cau nhap lai!"); getch(); goto nhap;
    }
    else nhap2();
    beg: c = new int *[m];
    for (i=0; i<m; i++)
        {
            c[i] = new int [n];
            for (j=0; j<n; j++) c[i][j] = a[i][j] + b[i][j];
        }
    system("cls"); printf("\n Ket qua cua phep toan: ");
    for (i=0; i<m; i++)
    {
        printf("\n");
        for (j=0; j<n; j++) printf("\t %d", a[i][j]);
    }
    printf("\n *");
    for (i=0; i<p; i++)
    {
        printf("\n");
        for (j=0; j<q; j++) printf("\t %d", b[i][j]);
    }
    printf("\n ___________________________________");
    for (i=0; i<m; i++)
    {
        printf("\n");
        for (j=0; j<q; j++) printf("\t %d", c[i][j]);
    }
    getch();
    for (i=0; i<m; i++)
        delete [] c[i];
    delete[] c;
}
void nhan()
{
    int i, j, ch;
    printf("\n Ban co muon su dung tinh toan voi ma tran truoc do? Y/..."); fflush(stdin); ch = getch();
    if (ch == 'y' || ch == 'Y')
        if (test() != 0) goto beg;
    system("cls");
    nhap: printf("\n Nhap kich thuoc cua hai ma tran can tinh tich!");
    printf(("\n Ma tran A: "));
    printf("\n \t - So hang: "); scanf("%d", &m);
    printf("\n \t - So cot: "); scanf("%d", &n);
    printf(("\n Ma tran B: "));
    printf("\n \t - So hang: "); scanf("%d", &p);
    printf("\n \t - So cot: "); scanf("%d", &q);
    if (n!=p)
    {
        printf("\n Kich thuoc khong phu hop, yeu cau nhap lai!"); getch(); goto nhap;
    }
    else nhap2();
    beg: c = new int *[m];
    for (i=0; i<m; i++)
        {
            c[i] = new int [q];
            for (j=0; j<q; j++) c[i][j] = 0;
        }
    for (i=0; i<m; i++)
        for (j=0; j<q; j++)
    {
        ch = 0;
        c[i][j] = a[i][ch] * b[ch][j];
    }
    system("cls"); printf("\n Ket qua cua phep toan: ");
    for (i=0; i<m; i++)
    {
        printf("\n");
        for (j=0; j<n; j++) printf("\t %d", a[i][j]);
    }
    printf("\n *");
    for (i=0; i<p; i++)
    {
        printf("\n");
        for (j=0; j<q; j++) printf("\t %d", b[i][j]);
    }
    printf("\n ___________________________________");
    for (i=0; i<m; i++)
    {
        printf("\n");
        for (j=0; j<q; j++) printf("\t %d", c[i][j]);
    }
    getch();
    for (i=0; i<m; i++)
        delete [] c[i];
    delete[] c;
}
void nhap()
{
    int i, j;
    system("cls");
    printf("\n Nhap mot ma tran vuong!");
    printf("\n\t Kich thuoc: "); scanf("%d", &cc);
    c = new int *[cc];
    for (i=0; i<cc; i++)
    {
        c[i] = new int[cc];
        for (j=0; j<cc; j++)
            {printf("\n c[%d][%d] = ", i+1, j+1); scanf("%d", &c[i][j]);}
    }
}
int** child(int **d, int dd, int i, int j)
{
    int m = 0, n;
    int **child = new int *[dd-1];
    for (m = 0; m<dd-1; m++) child[m] = new int [dd-1];
    for (m = 0 ; m<dd-1; m++)
        for (n = 0; n<dd-1; n++)
        if (m >= i && n >= j) child[m][n] = d[i+1][j+1];
        else if (m >= i && n < j) child[m][n] = d[i+1][j];
        else if (m < i && n >= j) child[m][n] = d[i][j+1];
    return child;
}
int det(int **d, int dd)
{
    int i, j, s  = 0;
    for (i=0; i<dd; i++)
        for (j=0; j<dd; j++)
            s += pow(d[i][j], i+j) * det (child(d, dd, i, j), dd-1);
    return s;
}
void dinhthuc()
{
    char ch, j;
    beg: system("cls");
    printf("\n Ban co muon su dung ma tran truoc do? A/ B/ ... (Nhap moi)!");
    if (test() != 0){
            fflush(stdin); ch = getch();
        if (ch == 'A' || ch == 'a')
        {
            if (m==n) {c = a; cc = m;}
            else
            {
                printf("\n Kich thuoc khong phu hop!");
                goto beg;
            }
        }
        else if (ch == 'B' || ch == 'b')
        {
            if (p==q) {c = b; cc = p;}
            else
            {
                printf("\n Kich thuoc khong phu hop!");
                goto beg;
            }
        }}
    else nhap();
    printf("\n Gia tri dinh thuc cua ma tran C la: ");
    for (ch = 0; ch<cc; ch++)
    {
        printf("\n \t |");
        for (j = 0; j<cc; j++)
        {
            printf("\t%d", c[ch][j]);
        }
        printf("|");
        if (ch==0) printf("\t = \t %d", det(c, cc));
    }
    getch();
    for (ch=0; ch<cc; ch++)
        delete [] c[ch];
    delete[] c;
}
int main()
{
    char ch;
    while (1)
    {
        system("cls");
            printf("\n m = %d \t n = %d", m, n);
        printf("\n \t\t CHUONG TRINH LAM VIEC VOI MA TRAN NGUYEN");
        printf("\n \t\t ========================================");
        printf("\n \t 1. Cong hai ma tran!");
        printf("\n \t 2. Nhan hai ma tran!");
        printf("\n \t 3. Tinh dinh thuc cua ma tran!");
        printf("\n \t\t ========================================");
        printf("\n Chon 1 - 3 de thuc hien tinh toan, nhan phim khac de thoat!");
        fflush(stdin); ch = getch();
        if (ch == '1') cong();
        else if (ch == '2') nhan();
        else if (ch == '3') dinhthuc();
        else
        {
            printf("\n Chan roi a? Y/y or ...");
            fflush(stdin); ch = getch();
            if (ch == 'y' || ch == 'Y') break;
        }
    }
    free_p();
}
