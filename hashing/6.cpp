//Union and Intersection of two Linked Lists
#include<bits/stdc++.h>
using namespace std;
typedef struct node 
{
	int key;
	node *next;
}node;
void newnode(node **head_ref, int val)
{
	node *root;
	root=(node *)malloc(sizeof(node));
	root->key=val;
	root->next=NULL;
	if(*head_ref!=NULL)
		root->next=(*head_ref);
	(*head_ref)=root;
	return;
}
void union_12(node *head1, node *head2)
{
	map<int, bool> m;
	map<int, bool>::iterator it;
	while(head1!=NULL)
	{
		m[head1->key]=true;
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		it=m.find(head2->key);
		if(it==m.end())
			m[head2->key]=true;
		head2=head2->next;
	}
	cout << "Union of Linked List 1 and 2 is : \n";
	for(it=m.begin();it!=m.end();it++)
		cout << it->first << "   ";
	cout << endl;
	return;
}
void intersection_12(node *head1, node *head2)
{
	map<int, bool> m;
	map<int, bool>::iterator it;
	while(head1!=NULL)
	{
		m[head1->key]=false;
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		it=m.find(head2->key);
		if(it!=m.end())
			it->second=true;
		head2=head2->next;
	}
	cout << "Intersection of Linked List 1 and 2 is : \n";
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second==true)
			cout << it->first << "  ";
	}
	cout << endl;
	return;
}
int main()
{
	node *head1=NULL, *head2=NULL;
	newnode(&head1,20);
	newnode(&head1,4);
	newnode(&head1,15);
	newnode(&head1,10);

	newnode(&head2,10);
	newnode(&head2,2);
	newnode(&head2,4);
	newnode(&head2,8);

	union_12(head1,head2);
	intersection_12(head1,head2);
	return 0;
}
