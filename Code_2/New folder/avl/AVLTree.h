// File Header AVLTree.h luu tr? c�c khai b�o c?n thi?t

#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
typedef struct WORD
{
string Word;
string Meaning;
} WORD;
typedef struct tagAVLNode
{
int BalFactor;
WORD Info;
struct tagAVLNode* pLeft;
struct tagAVLNode* pRight;
} AVLNode;
typedef AVLNode *AVLTree;
#endif
