typedef struct Node
{
	int data;
	struct Node *next;
}Node;

int Count (Node *ptr)
{
	int a = ptr ->data, c = 1;
	Node *temp;
	temp = ptr -> next;
	while (temp->data != a) c++;
	return c;
}
