/* Tra ve so nut tren cay co gia tri lon hon k */
int CountNodes(treeNode *RootTree, int k)
{
	int LC, RC;
	if (RootTree == NULL) return 0;
	LC = CountNodes(treeNodes->left, k);
	RC = CountNodes(treeNodes->right, k);
	if (treeNode->key > k) return 1 + LC + RC;
	else return LC + RC;
}
