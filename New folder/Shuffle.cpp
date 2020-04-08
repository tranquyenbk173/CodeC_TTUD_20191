struct Node 
{
	int info;
	struct Node *next;
};
void Shuffle (Node *list)
{
	Node *head, *p, *q, *temp;
	head = p = new Node;
	q = list;
	while (q != NULL)
	{
		q = q->next;
		if (q != NULL)
		{
			p->info = q->info;
			p->next = new Node;
			p = p->next;
			temp = q;
			q = q->next;
			delete temp;
		}
	}
	for (q = list; q != NULL;)
	{
		p->info = q->info;
		p->next = new Node;
		p = p->next;
		temp = q;
		q = q->next;
		delete temp;
	}
	p = head;
	while (p != NULL)
	{
		printf("\t %d", p->info);
	}
	getch();
	return;
}
