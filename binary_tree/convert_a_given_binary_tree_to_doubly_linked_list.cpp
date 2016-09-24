#include<bits/stdc++.h>
using namespace std;
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
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
dll * make_dll(dll **head_ref, int data)
{
	dll *head;
	head=*head_ref;
	if(!head)
	{
		head=(dll *)malloc(sizeof(dll));
		head->next=NULL;
		head->right=NULL;
		head->val=data;
		return head;
	}
	if(head)
	{
		head->next=(dll *)malloc(sizeof(dll));
		head->next->next=NULL;
		head->next->prev=head;
		head->next->val=data;
		head=head->next;
		*head_ref=head;
		return (*head_ref);
	}
}
void bt_to_dll(tree *root)
{
	dll *start=NULL, *head=NULL;
	if(root==NULL)
		return;
	bt_to_dll(root->left);
	start=make_dll(&head, root->val);
	head=start;
	bt_to_dll(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(10);
	root->left=newnode(12);
	root->right=newnode(15);
	root->left->left=newnode(25);
	root->left->right=newnode(30);
	root->right->left=newnode(36);
	bt_to_dll(root);
	print(head);
	return 0;
}



