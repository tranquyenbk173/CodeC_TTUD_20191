#include<stdio.h>
#include<conio.h>
int n, count, a[20], t[20];
void init()
{
	int i;
	count = 0;
	printf("\n Nhap vao so phan tu cua mang: "); scanf("%d", &n);
	for (i = 1; i<=n; i++) t[i] = 1;
}
void result() {
	int i;
	printf("\n Mat thu thu thu %d: ", ++count);
	for (i=1; i<=n; i++)
		printf("\t %d", a[i]);
}
void mem(int k) {
	int i;
	for (i=1; i<=n; i++)
		if (t[i]!=0 && i!=k)
		{
			a[k] = i; t[i] = 0;
			if (k==n) result();
			else mem(k+1);
			t[i] = 1;
		}
}
int main() {
	init();
	mem(1);
	getch();
	return 0;
}
