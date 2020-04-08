/* Tra lai gia tri nut chan lon nhat*/

int EvenMax(treeNode *root)
{
	int ML, MR, Rval, max;
	if (root == NULL) return -100000;
	max = root->key;
	ML = EvenMax(root->left);
	MR = EvenMax(root->right);
	if (ML > max) max = ML;
	if (MR > max) max = MR;
	return max;
}
