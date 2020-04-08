typedef struct Node
{
	int Inf;
	struct Node *next;
} LIST;
void OddEven(LIST *NumList)
{
	LIST *p;
	int odd, even;
	odd = 0; even = 0;
	p = NumList;
	while ( p != NULL)
	{
		if (p->Inf %2 == 0) even ++;
		else odd ++;
		p = p->next;
	}
	printf("\n Trong day co %d so chan, va %d so le!", even, odd);
	return;
}
