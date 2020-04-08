#include <iostream>
#include <string>

int main()
{
  int a = 3;
  int b = a;  // g�n bi?n th�ng thu?ng
  int &r = a;  // t?o tham chi?u (reference) c?a bi?n a (t?o alias cho bi?n a)
  int *p = &a; // t?o con tr? (pointer) t?i bi?n a

  printf("dia chi cua bien (variable) a: %d\n", &a);
  printf("gi� tri cua bien a: %d\n\n", a);

  printf("dia chi cua tham chieu (reference) r: %d\n", &r);
  printf("gi� tri cua tham chieu r: %d\n\n", r);

  printf("dia chi cua con tro (pointer) p: %d\n", &p);
  printf("gi� tri cua con tro p: %d\n", p);
  printf("gi� tri cua bien ma con tro p dang tro toi: %d\n", *p);
}
