/* Tong cac so le tren cay*/

int OddSumT(treeNode *root)
{
	int SumL, SumR;
	if (root == NULL) return 0;
	SumL = OddSumT(root->left);
	SumR = OddSumT(root->right);
	if (root->key % 2 != 0) return (root->key + SumL + SumR);
	else return SumL + SumR;
}
