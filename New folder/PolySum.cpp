struct PolyNode{
	int coeff;
	int pow;
	struct PolyNode *link;
};
typedef struct PolyNode Polynom;
// Viet ham tinh tong hai da thuc:
Polynom *PolySum(Polynom *Poly1, Polynom *Poly2)
{
	Polynom *p1, *p2, *head, *p;
	p1 = Poly1;
	p2 = Poly2;
	while (p1 != NULL && p2 != NULL)
	{
		
		if (p2 == NULL || p1->pow > p2->pow)
		{
			if (head == NULL)
			{
				head = new Polynum;
				p = head;
			}
			else 
			{
				p->next = new Polynum;
				p = p->next;
			}
			p->pow = p1->pow;
			p->coeff  = p1->coeff;
			p->next = NULL;
			p1 = p1->next;
		}
		else if (p1 == NULL || p1->pow < p2->pow)
		{
			if (head == NULL)
			{
				head = new Polynum;
				p = head;
			}
			else 
			{
				p->next = new Polynum;
				p = p->next;
			}
			p->pow = p2->pow;
			p->coeff  = p2->coeff;
			p->next = NULL;
			p2 = p2->next;
		}
		else 
		{
			if (head == NULL)
			{
				head = new Polynum;
				p = head;
			}
			else 
			{
				p->next = new Polynum;
				p = p->next;
			}
			p->pow = p1->pow + p2->pow;
			p->coeff  = p1->coeff + p2->coeff;
			p->next = NULL;
			p1 = p1->next;
			p2 = p2->next;
		}	
	}
}
// Cach 2: chi can khai head 1 lan duy nhat khi code;
Polynum *PolySum(Polynum *Poly1, Polynum *Poly2)
{
	Polynum *head, *p1, *p2, *p3;
	p = new Polynum;
	p1 = Poly1; 
	p2 = Poly2;
	head = p;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->pow > p2->pow)
		{
			p->coeff = p1->coeff;
			p->pow = p1->pow;
			p1 = p1->next;
		}
		else if 
		{
			p->coeff = p2->coeff;
			p->pow = p2->pow;
			p2 = p2->next;
		}
		else 
		{
			p->coeff = p2->coeff + p1->coeff;
			p->pow = p2->pow + p1->pow;
			p2 = p2->next; 
			p1 = p1->next;
		}	
		p->next = new Polynum;
		p = p->next;
	}
	
	if (p1 == NULL)
		while (p2 != NULL)
		{
			p->coeff = p2->coeff;
			p->pow = p2->pow;
			p->next = new Polynum;
			p = p->next;
			p2 = p2->next;
		}
	else if (p2 == NULL)
		while (p1 != NULL)
		{
			p->coeff = p1->coeff;
			p->pow = p1->pow;
			p->next = new Polynum;
			p = p->next;
			p1 = p1->next;
		}
	delete p;
	p = NULL;
}
