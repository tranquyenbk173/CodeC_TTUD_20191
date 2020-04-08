struct Node 
{
	int Inf;
	struct Node *next;
};
typedef struct Node LIST;
// Ham
LIST * OddList(LIST *Linp)
{
	Node *head, *p, *q;
	if (Linp == NULL)
	{
		printf("\n List rong!"); getch(); return;
	}
	p = Linp;
	while (p !=NULL)
	{
		if (p->Inf %2 != 0)
		{
			if (head == NULL)
			{
				head = new Node;
				q = head;
			}
			else 
			{
				q->next = new Node;
				q = q->next;
			}
			q ->Inf = p->Inf;
			q->next = NULL;
		}
		p = p->next;
	}
	return head;
}
