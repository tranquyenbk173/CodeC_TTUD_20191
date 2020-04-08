struct ListNode
{
	int info;
	struct ListNode *next;
};

ListNode *removeDupes(ListNode *list)
{
	ListNode *head, *a1, *a2;
	head = list;
	a1 = head; a2 =  a1->next;
	while (a2 != NULL)
	{
		while (a1->info == a2->info)
		{
			a1->next = a2->next;
			delete a2; 
			a2 = a1->next;
		}
		a1 = a2; a2 = a1->next;
	}
	return head;
}
