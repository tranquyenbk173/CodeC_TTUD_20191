struct PolyNode
{
	int coeff;
	int pow;
	struct PolyNode *next;
};
typedef struct PolyNode Polynum;
// ham tinh tich hai da thuc:
void Delete(Polynum *head)
{
	Poly *p;
	while (head != NULL)
	{
		p = head;
		head = head ->next;
		delete (p);
	}
}
Polynum *PolyMult (Polynum *Poly1, Polynum *Poly2)
{
	Polynum *Poly, *p, *p1, *p2, *Temp;
	p1 = Poly1;
	p2 = Poly2;
	if (p1 == NULL || p2 == NULL)
	{
		pritnf("\n Dap so: 0"); getch(); return;
	}
	while (p1 != NULL)
	{
		p = Temp = new Poly;
		for (p2 = Poly2; p2 != NULL; p2 = p2->next)
		{
			p->coeff = p1->coeff * p2 ->coeff;
			p->pow = p1->pow + p2->pow;
			p->next = new Poly;
			p = p->next;
		}
		p = PolySum(Temp, Poly);
		Delete (Temp); Delete (Poly);
		Poly = p;
		p1 = p1->next;
	}
	return Poly;
}
