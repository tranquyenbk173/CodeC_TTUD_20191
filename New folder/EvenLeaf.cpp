struct Tnode
{
	int key;
	struct Tnode *left;
	struct Tnode *right;
};
typedef struct Tnode treeNode;

int EvenLeaf (treeNode *RootTree)
{
	int Lcount, Rcount;

	if (RootTree == NULL) return 0;
	if (RootTree->left == NULL && RootTree->right == NULL)
			if (RootTree->key % 2 == 0) return 1;
	
	Lcount = EvenLeaf(RootTree->left);
	Rcount = EvenLeaf(RootTree->right);
	return (Lcount + Rcount);
}
