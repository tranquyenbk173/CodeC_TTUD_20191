struct dllNode
{
	int info;
	dllNode *next;
	dllNode *prev;
};
void Remove(ddlNode *dlist, int key)
{
	dllNode *temp, *p;
	// Xet phan tu dau: 
	while (dlist->info == key)
	{
		temp = dlist;
		dlist = dlist -> next;
		dlist -> prev = NULL;
		delete temp;
	}
	// Xet cac phan tu sau do:
	temp = dlist;
	while (temp != NULL)
	{
		if (temp->info == key)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			p = temp;
			temp = temp->next;
			delete p;
		}
	}
}
