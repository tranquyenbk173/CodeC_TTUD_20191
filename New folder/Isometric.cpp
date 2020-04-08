/* Kiem tra hai cay nhi phan dang cau*/

int Isometric (BTNode *T1, BTNode *T2)
{
	int checkL, checkR;
	if (T1 == NULL)
		if (T2 == NULL) return 1;
		else return 0;
	if (T2 == NULL)
		if (T1 == NULL) return 1;
		else return 0;
	checkL = Isometric (T1->left, T2->left);
	checkR = Isometric (T1->right, T2->right);
	return checkL * checkR;
}
