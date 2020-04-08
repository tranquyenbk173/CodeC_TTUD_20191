struct Node 
{
	int Inf;
	struct Node *next;
};
typedef struct Node LIST;
LIST *OddList (LIST *Linp)
{
	LIST *head, *p, *del;
	// Xoa phan tu dau tien:
	p = head = Linp;
	head = head ->next;
	delete(p);
	// Xoa cac phan tu o vi tri chan con lai!
	p = head;
	while (p != NULL)
	{
		del = p->next;
		p->next = p->next->next;
		delete (del);
		p = p->next;
	}
	return head;
}

