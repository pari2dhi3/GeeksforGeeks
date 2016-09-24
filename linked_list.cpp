#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int x;
	node *next;
}node;
void insert_node(node *start, int n)
{
	while(start->next!=NULL)
		start=start->next;
	start->next=(node*)malloc(sizeof(node));
	start=start->next;
	start->x=n;
	start->next=NULL;
	return;
}
void delete_node(node *start, int index)
{
	node *p;
	int i;
	for(i=1;i<index;i++)
		start=start->next;
	p=start->next;
	start->next=p->next;
	free(p);
	return;
}
void delete_node_key(node *start, int key)
{
	node *p;
	while(start->next->x!=key)
		start=start->next;
	p=start->next;
	start->next=p->next;
	free(p);
	return;
}
int length(node *start)
{
	if(start->next==NULL)
		return 0;
	else
		return 1+length(start->next);
}
int search(node *start, int num)
{
	int w=0;
	start=start->next;
	while((start->x!=num)&&(start->next!=NULL))
	{
		start=start->next;
		w++;
	}
	if(start->next==NULL)
	{
		if(start->x==num)
			return w+1;
		else
			return -1;
	}
	else 
		return w+1;
}
void print(node *start)
{
	start=start->next;
	while(start!=NULL)
	{
		printf("%d ",start->x);
		start=start->next;
	}
	printf("\n");
	return;
}
int middle(node *start)
{
	node *fast;
	start=start->next;
	fast=start;
	while((fast!=NULL)&&(fast->next!=NULL))
	{
		start=start->next;
		fast=fast->next->next;
	}
	return start->x;
}
int node_end(node *start, int index1)
{
	int i;
	node *ref;
	ref=start;
	for(i=0;i<index1;i++)
	{	ref=ref->next;
		if(ref==NULL)
		{
			printf("LINKED LIST IS OF SMALLER LENGTH THAN PROVODED INDEX\n");
			return -1;
		}
	}
	while(ref!=NULL)
	{
		ref=ref->next;
		start=start->next;
	}
	return start->x;
}
node *reverse(node *start)
{
	node *p;
	node *past;
	node *current;
	node *future;
	past=start;
	current=start->next;
	p=current;
	while(current!=NULL)
	{
		future=current->next;
		current->next=past;
		past=current;
		current=future;
	}
	free(start);
	p->next=NULL;
	start=(node *)malloc(sizeof(node));
	start->next=past;
	start->x=-1;
	return start;
}
int loop_detection(node *start)
{
	node *p1, *p2;
	p1=start;
	p2=p1->next->next;
	while((p1!=p2)||(p2!=NULL))
	{
		p1=p1->next;
		p2=p2->next->next;
	}
	if(p2==NULL)
		return 0;
	else if(p1==p2)
		return 1;
}
int pallindrome(node *start)
{
	int flag=0;
	node *prev, *midnode, *p, *w, *head, *fast;
	start=start->next;
	head=start;
	fast=start;
	while((fast!=NULL)||(fast->next!=NULL))
	{
		fast=fast->next->next;
		start=start->next;
	}
	prev->next=start;
	if(fast==NULL)
		midnode=NULL;
	else
	{
		midnode=start;
		start=start->next;
		midnode->next=NULL;
	}
	prev->next=NULL;
	p=(node *)malloc(sizeof(node));
	p->x=-1;
	p->next=start;
	start=p;
	w=reverse(start);
	w=w->next;
	while((w!=NULL)&&(head!=NULL))
	{
		if((w->x)==(head->x))
		{
			flag=0;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(midnode!=NULL)
	{
		prev->next=midnode;
		midnode->next=start;
	}
	else
	{
		prev->next=start;
	}
	if(flag==0)
		return 1;
	else if(flag==1)
		return 0;
}
void insert_sorted(node *start, int e)
{
	node *p, *head;
	head=start;
	start=start->next;
	if(e<=start->x)
	{
		p=(node *)malloc(sizeof(node));
		p->x=e;
		p->next=start;
		head->next=p;
		start=p;
		return;
	}
	else
	{
		node *fwd, *back;
		fwd=start->next;
		back=start;
		while((fwd->x<e)&&(fwd->next!=NULL))
		{
			fwd=fwd->next;
			back=back->next;
		}
		if(fwd->next==NULL)
		{
			if(e>fwd->x)
			{
				p=(node *)malloc(sizeof(node));
				p->x=e;
				p->next=NULL;
				fwd->next=p;
			}
			else
			{
				p=(node *)malloc(sizeof(node));
				p->x=e;
				p->next=fwd;
				back->next=p;
			}
		}
		else
		{
			p=(node *)malloc(sizeof(node));
			p->x=e;
			p->next=fwd;
			back->next=p;
		}
		return;
	}
}
void print_reverse(node *start)
{
	if(start==NULL)
		return;
	print_reverse(start->next);
	printf("%d ", start->x);
	return;
}
void delete_duplicate(node *start)
{
	node *p;
	start=start->next;
	while(start->next!=NULL)
	{
		if(start->x==start->next->x)
		{
			p=start->next;
			start->next=p->next;
			free(p);
		}
		else
			start=start->next;
	}
	return;
}
void swap_pairwise(node *start)
{
	int p;
	if((start!=NULL)&&(start->next!=NULL))
	{
		p=start->x;
		start->x=start->next->x;
		start->next->x=p;
		swap_pairwise(start->next->next);
	}
	return;
}
void last_to_front(node *start)
{
	int flag;
	node *head, *w, *q, *p;
	head=start;
	start=start->next;
	w=start;
	q=start;
	flag=0;
	while(start->next!=NULL)
	{
		start=start->next;
		if(flag==1)
			q=q->next;
		flag=1;
	}
	p=(node *)malloc(sizeof(node));
	p->x=start->x;
	free(start);
	q->next=NULL;
	p->next=w;
	head->next=p;
	start=head;
	return;
}
void delete_alternate(node *start)
{
	node *d;
	d=start->next;
	while((start->next!=NULL)&&(d->next!=NULL))
	{
		start->next=d->next;
		free(d);
		start=start->next;
		if(start->next!=NULL)
			d=start->next;
		else
			break;
	}
	return;
}
void del_right_grtr(node *start)
{
	node *bkwd, *fwd, *curr;
	curr=start->next;
	bkwd=start;
	while(curr!=NULL)
	{
		fwd=curr->next;
		if(fwd==NULL)
			return;
		else if(fwd->x>curr->x)
		{
			bkwd->next=fwd;
			free(curr);
			curr=fwd;
		}
		else
		{
			bkwd=curr;
			curr=curr->next;
		}
	}
	return;
}
void fxn_19(node *start)
{
	node *bkwd, *curr, *fwd, *end, *p;
	int val;
	end=start->next;
	while(end->next!=NULL)
	{
		end=end->next;
	}
	p=end;
	curr=start->next;
	bkwd=start;
	fwd=curr->next;
	while(curr!=end)
	{
		if(curr->x%2!=0)
		{
			bkwd->next=fwd;
			val=curr->x;
			free(curr);
			curr=fwd;
			fwd=fwd->next;
			p->next=(node *)malloc(sizeof(node));
			p=p->next;
			p->x=val;
			p->next=NULL;
		}
		else if(curr->x%2==0)
		{
			curr=curr->next;
			if(fwd!=NULL)
				fwd=fwd->next;
			bkwd=bkwd->next;

		}
	}
	if(curr->x%2!=0)
	{
		bkwd->next=fwd;
		val=curr->x;
		free(curr);
		p->next=(node *)malloc(sizeof(node));
		p=p->next;
		p->x=val;
		p->next=NULL;
	}
	return;
}
int loop_detection_and_removal(node *start)
{
	node *slow, *fast, *check;
	int count=0,flag,i;
	slow=start->next;
	fast=start->next->next;
	while((slow!=NULL)&&(fast!=NULL)&&(slow!=fast)&&(fast->next!=NULL))
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	if(slow==NULL||fast==NULL)
		return 0;
	else if(slow==fast)
	{
		check=slow->next;
		flag=0;
		while((check!=slow))
		{
			check=check->next;
			count++;
		}
		slow=start->next;
		fast=start->next;
		for(i=0;i<=count;i++)
		{
			fast=fast->next;
		}
		while(fast!=slow)
		{
			fast=fast->next;
			slow=slow->next;
		}
		fast->next=NULL;
		return 1;
	}
}
void rotate(node *start, int k)
{
	node *p0, *p1, *p2, *p3;
	p0=start->next;
	p1=start->next;
	p2=start->next;
	p3=start->next;
	k--;
	while(k--)
	{
		p1=p1->next;
		p2=p2->next;
		p3=p3->next;
	}
	p2=p2->next;
	while(p3->next!=NULL)
		p3=p3->next;
	p1->next=NULL;
	start->next=p2;
	p3->next=p0;
	return;
}
node *delmaftern (node *start, int m, int n)
{
	node *head, *past, *curr, *fwd;
	int i, j, flag;
	head=start;
	past=head;
	curr=head->next;
	flag=0;
	while(true)
	{
		i=m;
		while((i--)&&(curr!=NULL))
		{
			curr=curr->next;
			past=past->next;
		}
		if(curr==NULL)
			return head->next;
		j=n;
		while((j--)&&(curr!=NULL))
		{
			fwd=curr->next;	
			free(curr);
			curr=fwd;
		}
		if(curr==NULL)
			return head->next;
		past->next=fwd;
	}
}
void swapk(node *head, int k)
{
	node *curr, *p1, *p2, *prevp1, *prevp2, *temp;
	curr=head->next;
	p1=curr;
	p2=curr;
	prevp1=NULL;
	prevp2=curr;
	int len,i,flag,count;
	len=1;
	i=k-1;
	while(curr!=NULL)
	{
		curr=curr->next;
		len++;
	}
	if(len<k)
		return;
	if(len==(2*k-1))
		return;
	curr=head;
	flag=0;
	count=0;
	while(curr!=NULL)
	{
		curr=curr->next;
		if(count>k)
		{
			p2=p2->next;
			if(flag==1)
			{
				prevp2=prevp2->next;
			}
			flag=1;
		}
		count++;
	}
	flag=0;
	while(i--)
	{
		p1=p1->next;
		if(flag==1)
			prevp1=prevp1->next;
		else
			prevp1=head->next;
		flag=1;
	}
	prevp1->next=p2;
	prevp2->next=p1;
	temp=p2->next;
	p2->next=p1->next;
	p1->next=temp;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	node *start, *p, *f;
	int y,n,i,j,total,index,w,num,a,key,mid,index1,q,m,b,e,k,r,t;
	start=(node*)malloc(sizeof(node));
	start->x=-1;
	start->next=NULL;
	printf("PRESS 1 TO INSERT A NODE\nPRESS 2 TO DELETE A NODE AT PARTICULAR INDEX\nPRESS 3 TO DELETE A NODE WITH A PARTICULAR KEY\nPRESS 4 TO FIND THE LENGTH OF THE LINKED LIST\nPRESS 5 TO SEARCH AN ELEMENT IN A LINKED LIST\nPRESS 6 TO DISPLAY THE LINKED LIST\nPRESS 7 TO FIND THE MIDDLE ELEMENT\nPRESS * TO FIND THE ELEMENT GY PROVIIDING INDEX FROM THE LAST OF THE LINKED LIST\n");
	printf("PRESS 9 TO REVERSE A LINKED LIST\nPRESS 10 FOR LOOP DETECTION\nPRESS 11 TO DETECT WHETHER THE LINKED LIST IS A PALLINDROME OR NOT\nPRESS 12 TO INSER A NUMBER IN A SORTED LINKED LIST\nPRESS 13 TO PRINT THE LINKED LIST IN REVERSE ORDER\nPRESS 14 TO DELETE DUPLICATES IN A SORTED LINKED LIST\n");
	printf("PRESS 15 TO SWAP THE ELEMENTS PAIRWISE IN A LINKED LIST\nPRESS 16 TO BRING LAST ELEMENT TO THE FRONT OF THE LINKED LIST\nPRESS 17 TO DELETE THE NODES ALTERNATIVELY\nPRESS 18 TO DELETE THE NODES WHICH ARE AMALLER OR EQUAL TO THEIR RIGHT NODE\nPRESS 19 TO SEPARATE EVEN AND ODD NODES IN A LINKED LIST\n");
	printf("PRESS 20 TO DETECT AND REMOVE A LOOP IN A LINKED LIST\nPRESS 21 TO ROTATE THE LINKED LIST COUNTER CLOCK WISE BY K NODES\nPRESS 22 TO DELETE N NODES AFTER M NODES REPEATATIVELY\nPRESS 23 TO SWAP KTH NODE FROM STARTING TO KTH NODE FROM END\nPRESS 0 TO TERMINATE THE PROGRAM\n");
	i=1;
	while(i)
	{
		scanf("%d", &i);
		if(i==1)
		{
			printf("ENTER THE DATA OF THE NODE TO BE INSERTED\n");
			scanf("%d", &n);
			insert_node(start,n);
		}
		else if(i==2)
		{
			printf("ENTER THE INDEX OF THE NODE WHICH IS TO BE DELETED\n");
			scanf("%d", &index);
			delete_node(start,index);
		}
		else if(i==3)
		{
			printf("ENTER THE KEY WHICH IS TO BE DELETED\n");
			scanf("%d", &key);
			delete_node_key(start, key);
		}
		else if(i==4)
		{
			w=length(start);
			printf("THE LENGTH OF THE LINKED LIST IS %d \n", w);
		}
		else if(i==5)
		{
			printf("ENTER THE ELEMENT TO BE SEARCHED\n");
			scanf("%d", &num);
			a=search(start,num);
			if(a!=-1)
				printf("NUMBER IS FOUND AT NODE %d IN LINKED LIST\n", a);
			else
				printf("NUMBER NOT FOUND IN LINKED LIST\n");
		}
		else if(i==6)
		{
			print(start);
		}
		else if(i==7)
		{
			mid=middle(start);
			printf("THE MIDDLE ELEMENT OF LINKED LIST IS %d\n", mid);
		}
		else if(i==8)
		{
			printf("ENTER THE INDEX OF THE NODE FROM THE END OF LINKED LIST\n");
			scanf("%d", &index1);
			q=node_end(start,index1);
			if(q!=-1)
				printf("%d\n", q);
		}
		else if(i==9)
		{
			p=reverse(start);
			printf("THE REVERSE LINKED LIST IS : ");
			print(start);
		}
		else if(i==10)
		{
			m=loop_detection(start);
			if(m==1)
				printf("LOOP IS PRESENT\n");
			else 
				printf("LOOP IS NOT PRESENT\n");
		}
		else if(i==11)
		{
			b=pallindrome(start);
			if(b==0)
				printf("LINKED LIST IS NOT A PALLINDROME\n");
		}
		else if(i==12)
		{
			printf("ENTER THE NUMBER YOU WANT TO INSERT IN A SORTED LINKED LIST\n");
			scanf("%d", &e);
			insert_sorted(start,e);
		}
		else if(i==13)
		{
			print_reverse(start->next);
		}
		else if(i==14)
		{
			delete_duplicate(start);
		}
		else if(i==15)
		{
			swap_pairwise(start->next);
		}
		else if(i==16)
		{
			last_to_front(start);
		}
		else if(i==17)
		{
			delete_alternate(start->next);
		}
		else if(i==18)
		{
			del_right_grtr(start);
		}
		else if(i==19)
		{
			fxn_19(start);
		}
		else if(i==20)
		{
			y=loop_detection_and_removal(start);
			if(y==0)
				printf("LOOP NOT DETECTED\n");
			if(y==1)
				printf("LOOP DETECTED AND REMOVED\n");
		}
		else if(i==21)
		{
			printf("ENTER THE NUMBER OF NODES TO BE ROTATED COUNTER CLOCK WISE\n");
			cin >> k;
			rotate(start,k);
		}
		else if(i==22)
		{
			printf("ENTER THE VALUES OF M AND N\n");
			cin >> r >> t;
			f=delmaftern(start,r,t);
		}
		else if(i==23)
		{
			printf("ENTER THE NODE INDEX THAT YOU WANT TO SWAP\n");
			cin >> k;
			swapk(start,k);
		}

	}
	return 0;
}










