#include<bits/stdc++.h>
using namespace std;
int flag=0;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
typedef struct dll
{
	dll *next;
	dll *prev;
	int val;
}dll;
dll *start;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(node));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
dll * make_dll(tree *root, dll **head)
{
	dll *node;
	node=(*head);
	if(flag==0)
	{
		node=(dll *)malloc(sizeof(dll));
		node->next=NULL;
		node->prev=NULL;
		node->val=root->val;
		start=node;
		flag=1;
	}
	else
	{
		node->next=(dll *)malloc(sizeof(dll));
		node->next->next=NULL;
		node->next->prev=head;
		node->val=root->val;
		node=node->next;
	}
	return node;
}
void tree_to_dll(tree *root, dll **head1)
{
	if(!root)
		return;
	tree_to_dll(root->left,&head);
	(*head1)=make_dll(root,&head);
	tree_to_dll(root->right,&head);
}
void print(dll *start)
{
	if(!start)
		return;
	cout << start->val << "  ";
	print(start->next);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int i;
	dll *head=NULL;
	tree *root;
	root=newnode(10);
	root->left=newnode(12);
	root->right=newnode(15);
	root->left->left=newnode(25);
	root->left->right=newnode(30);
	root->right->left=newnode(36);
	tree_to_dll(root,&head);
	print(start);
	return 0;
}
