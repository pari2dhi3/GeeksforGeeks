//convert a given binary tree to doubly linked list//
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void make_dll(tree *root, tree **head_ref)
{
	tree *node;
	if(!*head_ref)
	{
		node=(tree *)malloc(sizeof(tree));
		node->left=NULL;
		node->right=NULL;
		node->val=root->val;
		(*head_ref)=node;
		return;
	}
	node=(tree *)malloc(sizeof(tree));
	node->left=(*head_ref);
	node->right=NULL;
	node->val=root->val;
	(*head_ref)=node;
	return;
}
void convert(tree *root, tree **head_ref)
{
	if(root==NULL)
		return;
	convert(root->left,head_ref);
	make_dll(root,head_ref);
	convert(root->right,head_ref);
	return;
}
void print(tree *head)
{
	if(!head)
		return;
	print(head->left);
	cout << head->val << " ";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root, *head=NULL;
	root=newnode(10);
	root->left=newnode(12);
	root->right=newnode(15);
	root->left->left=newnode(25);
	root->left->right=newnode(30);
	root->right->left=newnode(36);
	convert(root, &head);
	print(head);
	return 0;
}
