#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int val;
	tree *left;
	tree *right;
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
tree * link(tree *root, tree **head_ref)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL)
		return root;
	(*head_ref)->right=link(root->left,head_ref);
	if((*head_ref)->right!=NULL)
		(*head_ref)=(*head_ref)->right;
	(*head_ref)->right=link(root->right,head_ref);
	if((*head_ref)->right!=NULL)
		(*head_ref)=(*head_ref)->right;
}
void print(tree **node)
{
	if((*node)==NULL)
		return;
	cout << (*node)->val << " ";
	print((*node)->right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL, *head=NULL, *ptr=NULL;
	head=newnode(-1);
	ptr=head;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	link(root,&head);
	print(&ptr->right);
	cout << endl;
	return 0;
}
