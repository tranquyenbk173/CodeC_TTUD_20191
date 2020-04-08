/* Dem so luong la cua cay*/

int countLeaf(treeNode *RootTree)
{
	int LC, RC;
	if (RootTree == NULL) return 0;
	if (RootTree->left == NULL && RootTree->right == NULL) return 1;
	LC = countLeaf(RootTree->left);
	RC = countLeaf(RootTree->right);
	return LC + RC;
}
