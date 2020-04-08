// File header AVL.h luu các hàm th?c hi?n thao tác t?o cây AVL
#ifndef AVL_H
#define AVL_H
#include "AVLTree.h"



int SearchStandFor(AVLTree &P, AVLTree &Q, AVLTree& T)
{
int Res;
if(Q->pLeft)
{
Res = SearchStandFor(P, Q->pLeft, T);
if(Res < 2)
return Res;
switch(Q->BalFactor)
{
case -1: Q->BalFactor = 0; return 2;
case 0: Q->BalFactor = 1; return 1;
case 1: return BalanceRight(T);
}
}
else
{
P->Info = Q->Info;
P = Q;
Q = Q->pRight;
return 2;
}
}
int DeleteNode(AVLTree &T, WORD W)
{
int Res, i=0;
if(T == NULL)
return 0;
while(i < T->Info.Word.length() || i < W.Word.length())
{
if(T->Info.Word[i] > W.Word[i])
{
Res = DeleteNode(T->pLeft, W);
if(Res < 2)
return Res;
switch(T->BalFactor)
{
case -1: T->BalFactor = 0; return 2;
case 0: T->BalFactor = 1; return 1;
case 1: return BalanceRight(T);
}
}
else if(T->Info.Word[i] < W.Word[i])
{
Res = DeleteNode(T->pRight, W);
if(Res < 2)
return Res;
switch(T->BalFactor)
{
case 1: T->BalFactor = 0; return 2;
case 0: T->BalFactor = -1; return 1;
case -1: return BalanceLeft(T);
}
}
else
{
i++; continue;
}
}
if(T->Info.Word.find(W.Word) == 0)
{
AVLNode* p = T;
if(T->pLeft == NULL)
{
T = T->pRight; Res = 2;
}
else if(T->pRight == NULL)
{
T = T->pLeft; Res = 2;
}
else
{
Res = SearchStandFor(p, T->pRight,T);
if(Res < 2)
return Res;
switch(T->BalFactor)
{
case 1: T->BalFactor = 0; return 2;
case 0: T->BalFactor = -1; return 1;
case -1: return BalanceLeft(T);
}
}
delete p;
return Res;
}
}
#endif
