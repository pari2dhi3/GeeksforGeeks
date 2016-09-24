//function of 11 not working
//by sachin and paridhi
#include<stdio.h>
#include<stdlib.h>
typedef struct elem
{
	int a;
	struct elem *next;
}node;
void insert(int n, node *start)
{
	while(start->next!=NULL)
		start=start->next;
	start->next=(node *)malloc(sizeof(node));
	start=start->next;
	start->next=NULL;
	start->a=n;
	return;
}
void display(node *start)
{
	start=start->next;
	while(start->next!=NULL)
	{
		if(start->a!=(-1))
			printf("%d ",start->a);
		start=start->next;
	}
	if(start->a!=(-1))
		printf("%d\n",start->a);
	return;
}
void count(node *start)
{
	int count=0;
	start=start->next;
	while(start->next!=NULL)
	{
		start=start->next;
		count++;
	}
	printf("%d\n",count+1);
	return;
}
void ebwt(int n,int j, node *start)
{
	int i;
	node *p;
	for(i=1;i<j;i++)
		start=start->next;
	p=start;
	p=p->next;
	start->next=(node *)malloc(sizeof(node));
	start=start->next;
	start->a=n;
	start->next=p;
	return;
}
void delete(int j, node *start)
{
	int i;
	node *p;
	for(i=1;i<j;i++)
		start=start->next;
	p=start;
	p=p->next;
	start->next=start->next->next;
	free(p);
	return;
}
void search(int n,node *start)
{
	int count;
	count=1;
	start=start->next;
	while(start!=NULL)
	{
		if(start->a==n)
		{
			printf("FOUND AT INDEX %d\n",count);
			return;
		}
		else
			start=start->next;
		count++;
	}
	printf("NOT FOUND\n");
	return;
}
int count_recursive(node *start)
{
	if(start->next==NULL)
		return 0;
	else
		return 1+count_recursive(start->next);
}
int search_recursively(node *start, int n)
{
	int c;
	if(start==NULL)
		return -1;
	else if(start->a==n)
		return 0;
	else 
	{
		c=search_recursively(start->next,n);
		if(c==(-1))
			return -1;
		else
			return c+1;
	}
}
void find_middle(node *start)
{
	node *c,*b;
	b=start;
	c=start;
	while(c!=NULL)
	{
		c=c->next;
		if(c!=NULL)
			c=c->next;
		b=b->next;
	}
	printf("%d\n",b->a);
}
void print_reverse(node *start)
{
	if(start==NULL)
		return;
	else
	{
		print_reverse(start->next);
		if(start->a!=(-1))
			printf("%d ",start->a);
		return;
	}
}
node* reverse(node *start)
{
	int flag;
	node *p,*q,*r,*temp;
	p=start->next;
	q=start->next->next;
	r=q->next;
	free(start);
	p->next=NULL;
	flag=0;
	while(1)
	{
		if(q!=NULL)
			q->next=p;
		if((p==NULL)&&(r==NULL)&&(q!=NULL))
		{
			flag=2;
			break;
		}
		if((p!=NULL)&&(r==NULL)&&(q==NULL))
		{
			flag=1;
			break;
		}
		if((p==NULL)&&(r!=NULL)&&(q==NULL))
		{
			flag=3;
			break;
		}
		if(r!=NULL)
		{
			p=r->next;		
			if((p==NULL)&&(r==NULL)&&(q!=NULL))
			{
				flag=2;
				break;
			}
			if((p!=NULL)&&(r==NULL)&&(q==NULL))
			{
				flag=1;
				break;
			}
			if((p==NULL)&&(r!=NULL)&&(q==NULL))
			{
				flag=3;
				break;
			}
			r->next=q;
		}
		if((p==NULL)&&(r==NULL)&&(q!=NULL))
		{
			flag=2;
			break;
		}
		if((p!=NULL)&&(r==NULL)&&(q==NULL))
		{
			flag=1;
			break;
		}
		if((p==NULL)&&(r!=NULL)&&(q==NULL))
		{
			flag=3;
			break;
		}
		if(p!=NULL)
		{
			q=p->next;
			if((p==NULL)&&(r==NULL)&&(q!=NULL))
			{
				flag=2;
				break;
			}
			if((p!=NULL)&&(r==NULL)&&(q==NULL))
			{
				flag=1;
				break;
			}
			if((p==NULL)&&(r!=NULL)&&(q==NULL))
			{
				flag=3;
				break;
			}
			p->next=r;
		}
		if((p==NULL)&&(r==NULL)&&(q!=NULL))
		{
			flag=2;
			break;
		}
		if((p!=NULL)&&(r==NULL)&&(q==NULL))
		{
			flag=1;
			break;
		}
		if((p==NULL)&&(r!=NULL)&&(q==NULL))
		{
			flag=3;
			break;
		}
		if(q!=NULL)
			r=q->next;
		if((p==NULL)&&(r==NULL)&&(q!=NULL))
		{
			flag=2;
			break;
		}
		if((p!=NULL)&&(r==NULL)&&(q==NULL))
		{
			flag=1;
			break;
		}
		if((p==NULL)&&(r!=NULL)&&(q==NULL))
		{
			flag=3;
			break;
		}
	}
	temp=(node *)malloc(sizeof(node));
	temp->a=-1;
	if(flag==1)
		temp->next=p;
	else if(flag==2)
		temp->next=q;
	else if(flag==3)
		temp->next=r;
	return temp;
}
int main()
{
	node *start;
	int n,i,j,total,index;
	start=(node *)malloc(sizeof(node));
	start->a=-1;
	start->next=NULL;
	printf("ENTER -1 TO TERMINATE THE PROGRAM\nENTER 1 TO INSERT A NUMBER\nENTER 2 TO DISPLAY\nENTER 3 TO COUNT\nENTER 4 TO INSERT NUMBER AT AN INDEX\nENTER 5 TO DELETE NUMBER AT AN INDEX\nENTER 6 TO SEARCH AN ELEMENT\nENTER 7 TO COUNT RECURSIVELY\nENTER 8 TO SEARCH RECURSIVELY\nENTER 9 TO GET MIDDLE DIGIT\nENTER 10 TO PRINT IN REVERSE ORDER\nENTER 11 TO REVERSE THE LINK LIST\n");
	while(i!=(-1))
	{
		scanf("%d",&i);
		if(i==1)
		{
			printf("ENTER NUMBER TO BE INSERTED\n");
			scanf("%d",&n);
			insert(n,start);
		}
		else if(i==2)
		{
			printf("LIST IS\n");
			display(start);
		}
		else if(i==3)
		{
			printf("COUNT IS\n");
			count(start);
		}
		else if(i==4)
		{
			printf("ENTER NUMBER TO BE ENTERED\n");
			scanf("%d",&n);
			printf("ENTER THE INDEX NUMBER AT WHICH THIS IS TO BE INSERTED\n");
			scanf("%d",&j);
			ebwt(n,j,start);
		}
		else if(i==5)
		{
			printf("ENTER THE INDEX NUMBER AT WHICH THE NUMBER IS TO BE DELETED\n");
			scanf("%d",&j);
			delete(j,start);
		}
		else if(i==6)
		{
			printf("ENTER ELEMENT TO BE SEARCHED\n");
			scanf("%d",&n);
			search(n,start);
		}
		else if(i==7)
		{
			printf("COUNT IS\n");
			total=count_recursive(start);
			printf("%d\n",total);
		}
		else if(i==8)
		{
			printf("ENTER ELEMENT TO BE SEARCHED\n");
			scanf("%d",&n);
			index=search_recursively(start,n);
			printf("%d\n",index);
		}
		else if(i==9)
		{
			find_middle(start);
		}
		else if(i==10)
		{
			printf("REVERSE ORDER IS\n");
			print_reverse(start);
		}
		else if(i==11)
		{
			start=reverse(start);
		}
	}
	return 0;
}
