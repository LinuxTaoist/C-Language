#include<stdio.h>
#include<malloc.h>

typedef int ELEMTYPE;
typedef int STATUS;

#define LIST_INSERT_NUM 6
#define LIST_INSERT_INDEX 3
#define LIST_DELETE_INDEX 4
typedef struct SList
{
	ELEMTYPE data;
	struct SList * next;
}NODE, *pSLIST;
void slist_init(NODE *p);
void push_front(NODE *p, int num);
void push_tail(NODE *p, int num);
void insert_addr(NODE *p, int index);
void delete_addr(NODE *p, int index);
void delete_value(NODE *p, int value, int ordinal_num);
int  find_value(NODE *p, int value, int ordinal_num);
void modify_value(NODE *p, int index, int new_value);
void show_slist(NODE *p);

ELEMTYPE main(void)
{
	NODE linklist;
	int i = 0, value;
	slist_init(&linklist);
	push_front(&linklist, LIST_INSERT_NUM);
	//push_tail(&linklist, LIST_INSERT_NUM);
	//insert_addr(&linklist, LIST_INSERT_INDEX);
	//delete_addr(&linklist, LIST_DELETE_INDEX);
	//printf("Please input modify index : \n");
	//scanf("%d", &value);
	//find_value(&linklist, value, 1);
	//delete_value(&linklist, value, 1);
	//modify_value(&linklist, value, 1);
	show_slist(&linklist);
	printf("over!\n");
	return 0;
}

void slist_init(NODE *p)
{
	p = (NODE*)malloc(sizeof(NODE));
	if(p == NULL)
	{
		printf("Error: Space application failed!\n");
	}
	p->next = NULL;
}

void push_front(NODE *p, int num)
{
	int i = 0;
	for(; i < num; i++)
	{
		NODE *new;
		new = (NODE *)malloc(sizeof(NODE));
		if(new == NULL)
		{
			printf("Error: Space application failed!\n");
		}

		printf("Please input date: \n");	
		scanf("%d",&new->data);
		new->next = p->next;
		p->next =new;
	}
}

void push_tail(NODE *p, int num)
{
	int i = 0;
	NODE *list_addr = p;
	while(list_addr->next != NULL)
	{
		list_addr = list_addr->next;
	}
	for(; i < num; i++)
	{
		NODE *new;
		new = (NODE *)malloc(sizeof(NODE));
		if(new == NULL)
		{
			printf("Error: Space application failed!\n");
		}	
		printf("Please input date: \n");	
		scanf("%d",&new->data);
		new->next = list_addr->next;
		list_addr->next = new;
		list_addr = list_addr->next;
	}
}

void show_slist(NODE *p)
{
	NODE *list = p->next;
	while(list != NULL)
	{
		printf("%d -> ", list->data);
		list = list->next;
	}
}

void insert_addr(NODE *p, int index)
{
	int i = 0;
	NODE *new;
	NODE *list = p->next;
	for(i = 0; i < index - 2; i++)
	{
		if(list->next == NULL)
		{
			printf("Error: single list attachs to end!\n");
			return ;
		}
		list = list->next;
	}	
	new = (NODE *)malloc(sizeof(NODE));
	if(new == NULL)
	{
			printf("Error: Space application failed!\n");
	}	
	printf("Please input insert date at %d: \n", index);	
	scanf("%d",&new->data);
	new->next = list->next;
	list->next =new;
}

void delete_addr(NODE *p, int index)
{
	int i = 0;
	NODE *new ;
	NODE *list = p;
	printf("Delete data at %d\n", index);
	for(i = 0; i < index - 1; i++)
	{
		if(list->next == NULL)
		{
			printf("Error: out of list!\n");
			return ;
		}
		list = list->next;		
	}
	new = list->next;
	list->next = list->next->next;
	free(new);
}

void delete_value(NODE *p, int value, int ordinal_num)
{
	NODE *list = p;
	int find_index = 0;
	find_index = find_value(list, value, ordinal_num);
	if(find_index != 0)
	{
		delete_addr(list, find_index);
	}
}

int find_value(NODE *p, int value, int ordinal_num)
{
	NODE *list =p->next;
	int count = 0, list_addr = 0;
	while(list != NULL)
	{
		list_addr++;
		if(list->data == value)
		{
			count++;
			if(count == ordinal_num)
			{
				break;
			}
		}
		list = list->next;
	}
	if(count == ordinal_num)	
	{
		printf("Find it's index at %d\n", list_addr);
		return list_addr;
	}
	else
	{
		printf("Error: Not find\n!");	
		return 0;
	}
}

void modify_value(NODE *p, int index, int new_value)
{
	int i = 0;
	NODE *new, *tmp;
	NODE *list = p->next;
	for(i = 0; i < index - 2; i++)
	{
		if(list->next == NULL)
		{
			printf("Error: single list attachs to end!\n");
			return ;
		}
		list = list->next;
	}	
	new = (NODE *)malloc(sizeof(NODE));
	if(new == NULL)
	{
			printf("Error: Space application failed!\n");
	}	
	tmp = list->next;
	new->data = new_value;
	new->next = list->next->next;
	list->next =new;
	free(tmp);
}

















