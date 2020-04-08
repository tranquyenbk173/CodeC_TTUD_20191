/* Tra lai tong gia tri trong cac nut*/

int SumT(treeNode *root)
{
	int SL, SR;
	if (root == NULL) return 0;
	SL = SumT(root->left);
	SR = SumT(root->right);
	return (root->data + SL + SR);
}
