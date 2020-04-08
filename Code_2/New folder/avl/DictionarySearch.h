//file Header DictionarySearch.h luu tr? các hàm th?c hi?n các yêu c?u trong d? bài

#ifndef _DICTIONARY_H
#define _DICTIONARY_H
#include "AVLTree.h"
#include "AVL.h"
AVLNode* SearchWord(AVLTree &T, WORD ws)
{
if(T)
{
if(T->Info.Word.find(ws.Word) == 0)
return T;
if(T->Info.Word[0] >= ws.Word[0])
return SearchWord(T->pLeft, ws);
else return SearchWord(T->pRight, ws);
}
return NULL;
}
void Output_AVLTree(AVLTree &T, ofstream &fo, int count, int& Flag)
{
if(T != NULL)
{
Flag = 1;
if(count == 1)
{
fo << "Goc: " << T->Info.Word << endl << "{" << endl;
count++;
}
if(T->pLeft != NULL && T->pRight != NULL)
fo << T->Info.Word << ", " << T->Info.Meaning << ", " << T->pLeft->Info.Word << ", " << T->pRight->Info.Word << endl;
else if(T->pLeft == NULL && T->pRight != NULL)
fo << T->Info.Word << ", " << T->Info.Meaning << ", NULL, " << T->pRight->Info.Word << endl;
else if(T->pRight == NULL && T->pLeft != NULL)
fo << T->Info.Word << ", " << T->Info.Meaning << ", " << T->pLeft->Info.Word << ", NULL" << endl;
else fo << T->Info.Word << ", " << T->Info.Meaning << ", NULL, NULL" << endl;
if(T->pLeft != NULL)
Output_AVLTree(T->pLeft, fo, count, Flag);
if(T->pRight != NULL)
Output_AVLTree(T->pRight, fo, count, Flag);
}
else if(T == NULL && count == 1)
{
fo << "Goc: NULL" << endl;
Flag = 0;
}
}
#endif
