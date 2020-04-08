/* Lay phan xa guong voi cay co goc la Root*/

BTree *mirror (BTree *root)
{
	BTree *temp;
	if (root == NULL) return NULL;
	if (root->left == NULL) return root;
	if (root->right == NULL) return root; 
	temp->right = BTree(root->left);
	temp->left = BTree(root->right);
	return temp;
}
