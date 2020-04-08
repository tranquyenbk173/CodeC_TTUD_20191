struct ClassNode
{
	char name[30];
	ClassNode *next;
	StudentNode *students;
};
struct StudentNode
{
	char name[30];
	StudentNode *next;
};
// So sinh vien trong mot lop theo dia chi
int NumClassStudents(ClassNode *ClPoint)
{
	int count = 0;
	p = Clpoint;
	while (p != NULL)
	{
		count ++; 
		p = p->next;
	}
	return count;
}
// Tra lai so luong sinh vien theo ten
int NumClassStudents(ClassNode *list, char *name)
{
	int count = 0;
	p = list;
	while (strcmp(p ->name, name)!= 0) p = p->next;
	if (p == NULL)
	{
		printf("\n Lop khong ton tai!");
		getch(); return 0;
	}
	else return NumClassStudents(p);
}
