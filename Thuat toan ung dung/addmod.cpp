#include<stdio.h>

int M = 1000000007;

int addmod(int a, int b){
    a = a % M;
    b = b % M;
    int c = M - a;
    if (c > b) return (b + a);
    else  return (b - c);
}

int main(){
    long a, b, c;
    scanf("%d%d", &a, &b);
    printf("%d", addmod(a, b));
}
