#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int x;
	node *prev;
	node *next;
}node;
void push(node **headref, int d)
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->x=d;
	newnode->next=NULL;
	newnode->prev=NULL;
	if((*headref)!=NULL)
		newnode->next=(*headref);
	(*headref)=newnode;
	return;
}
void insert(node **headref, int index, int data)
{
	node *curr, *fwd;
	int count;
	curr=(*headref);
	count=1;
	if(index==1)
	{
		curr=(node *)malloc(sizeof(node));
		curr->x=data;
		curr->next=(*headref);
		curr->prev=NULL;
		(*headref)=curr;
		return;
	}
	while((count!=index-1)&&(curr->next!=NULL))
	{
		curr=curr->next;
		count++;
	}
	if(curr->next!=NULL)
	{
		fwd=curr->next;
		curr->next=(node *)malloc(sizeof(node));
		curr->next->x=data;
		curr->next->next=fwd;
		curr->next->prev=curr;
		curr->next->next->prev=curr->next;
		return;
	}
	curr->next=(node *)malloc(sizeof(node));
	curr->next->x=data;
	curr->next->next=NULL;
	curr->next->prev=curr;
	return;
}
void append(node **headref, int d)
{
	node *newnode, *curr;
	curr=(*headref);
	newnode=(node *)malloc(sizeof(node));
	newnode->x=d;
	newnode->next=NULL;
	if((*headref)==NULL)
	{
		newnode->prev=NULL;
		(*headref)=newnode;
		return;
	}
	while((curr->next)!=NULL)
	{
		curr=curr->next;
	}
	curr->next=newnode;
	newnode->prev=curr;
	return;
}
void before_node(node **headref, int data, int d)
{
	node *newnode, *curr, *fwd;
	curr=(*headref);
	newnode=(node *)malloc(sizeof(node));
	newnode->x=d;
	while(curr->next->x!=data)
		curr=curr->next;
	fwd=curr->next;
	curr->next=(node *)malloc(sizeof(node));
	curr->next->x=d;
	curr->next->prev=curr;
	curr->next->next=fwd;
	return;
}
void print(node **headref)
{
	node *curr;
	curr=(*headref);
	while(curr!=NULL)
	{
		cout << curr->x << " ";
		curr=curr->next;
	}
	cout << endl;
	return;
}
void delete_node(node **headref, int index)
{
	node *curr;
	curr=(*headref);
	if(index==1)
	{
		(*headref)=curr->next;
		free(curr);
		return;
	}
	index--;
	while((index--)&&(curr->next!=NULL))
	{
		curr=curr->next;
	}
	if(curr->next==NULL)
	{
		curr->prev->next=NULL;
		free(curr);
		return;
	}
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	free(curr);
	return;
}
void reverse(node **headref)
{
	node *curr, *temp;
	curr=(*headref);
	while(curr!=NULL)
	{
		temp=curr->prev;
		curr->prev=curr->next;
		curr->next=temp;
		curr=curr->prev;
	}
	(*headref)=temp->prev;
	return;
}
void swap_k_nodes(node **headref)
{

int main()
{
	ios_base::sync_with_stdio(false);
	node *head=NULL;
	int i,d, index, data;
	cout << "PRESS 0 TO TERMINATE\n";
	cout << "PRESS 1 TO INSERT AN ELEMENT USING PUSH\n";
	cout << "PRESS 2 TO INSERT A NODE AT A PARTICULAR INDEX\n";
	cout << "PRESS 3 TO APPEND THE ELEMENT IN DLL\n";
	cout << "PRESS 4 TO INSERT A NODE BEFORE A GIVEN NODE'S DATA IN  DLL\n";
	cout << "PRESS 5 TO DISPLAY DLL\n";
	cout << "PRESS 6 TO DELETE A NODE AT AN INDEX IN DLL\n";
	cout << "PRESS 7 TO REVERSE A DLL\n";
	while(true)
	{
		cin >> i;
		if(i==1)
		{
			cout << "ENTER THE ELEMENT TO PUCH IN DLL\n";
			cin >> d;
			push(&head,d);
		}
		if(i==2)
		{
			cout << "ENTER THE INDEX AT WHICH YOU WANT TO INSERT AND DATA OF THE NEW NODE\n";
			cin >> index >> data;
			insert(&head,index,data);
		}
		if(i==3)
		{
			cout << "ENTER THE ELEMENT TO APPEND IN DLL\n";
			cin >> d;
			append(&head,d);
		}
		if(i==4)
		{
			cout << "ENTER THE DATA OF THE NODE BEFORE WHICH YOU WANT TO INSERT A NEW NODE AND THE DATA OF THE NEW NODE\n";
			cin >> data >> d;
			before_node(&head,data,d);
		}
		if(i==5)
		{
			cout << "THE DLL IS :";
			print(&head);
		}
		if(i==6)
		{
			cout << "ENTER THE INDEX OF THE NODE YOU WANT TO DELETE\n";
			cin >> index;
			delete_node(&head,index);
		}
		if(i==7)
		{
			reverse(&head);
		}
		if(i==0)
			break;
	}
	return 0;
}
