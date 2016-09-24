#include<stdio.h>
#include<stdlib.h>
typedef struct elem
{
	int a;
	struct elem *next;
	struct elem *prev;
}node;
void insert(int n,node *start)
{
	if(start->next!=NULL)
		insert(n,start->next);
	else
	{
		start->next=(node *)malloc(sizeof(node));
		start->next->prev=start;
		start=start->next;
		start->a=n;
		start->next=NULL;
	}
	return;
}
void display(node *start)
{
	if(start!=NULL)
	{
		printf("%d ",start->a);
		display(start->next);
	}
	return;
}
void delete(node *start,int n)
{
	if(start->a==n)
	{
		start->prev->next=start->next;
		start->next->prev=start->prev;
		free(start);
	}
	else
		delete(start->next,n);
	return;

}
node* reverse(node *start)
{
	node *p;
	if(start!=NULL)
	{
		p=start->prev;
		start->prev=start->next;
		start->next=p;
		if(start->prev!=NULL)
			return reverse(start->prev);
		else
			return start;
	}
}
int main()
{
	int i,n;
	node *start;
	start=(node *)malloc(sizeof(node));
	start->a=-1;
	start->next=NULL;
	start->prev=NULL;
	i=1;
	printf("ENTER -1 TO END PROGRAM\nENTER 1 TO INSERT A NUMBER\nENTER 2 TO DISPLAY THE LINK LIST\nENTER 3 TO DELETE A NUMBER\nENTER 4 TO REVERSE THE LINK LIST\n");
	while(i!=(-1))
	{
		scanf("%d",&i);
		if(i==1)
		{
			printf("ENTER NUMBER TO BE INSERTED\n");
			scanf("%d",&n);
			insert(n,start);
		}
		if(i==2)
		{
			printf("THE LIST IS\n");
			display(start->next);
			printf("\n");
		}
		if(i==3)
		{
			printf("ENTER NUMBER TO BE DELETED\n");
			scanf("%d",&n);
			delete(start,n);
		}
		if(i==4)
		{
			start=reverse(start);
		}
	}
	return 0;
}

