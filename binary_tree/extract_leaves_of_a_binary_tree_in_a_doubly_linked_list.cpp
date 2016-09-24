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
void newnode_dll(int data, tree **head_ref)
{
	tree *node;
	node=(*head_ref);
	if(!node)
	{
		node=(tree *)malloc(sizeof(tree));
		node->left=NULL;
		node->right=NULL;
		node->val=data;
		(*head_ref)=node;
		return;
	}
	node->right=(tree *)malloc(sizeof(tree));
	node->right->right=NULL;
	node->right->left=node;
	node->right->val=data;
	node=node->right;
	(*head_ref)=node;
	return;
}
void leaves_in_dll(tree *root, tree **head_ref)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		newnode_dll(root->val,head_ref);
		root=NULL;
		return;
	}
	leaves_in_dll(root->left,head_ref);
	leaves_in_dll(root->right,head_ref);
	return;
}
void print_dll(tree *head)
{
	if(head==NULL)
		return;
	print_dll(head->left);
	cout << head->val << " ";
	return;
}
void print_bt(tree *root)
{
	if(root==NULL)
		return;
	print_bt(root->left);
	cout << root->val << " ";
	print_bt(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL, *head=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->right=newnode(6);
	root->left->left->left=newnode(7);
	root->left->left->right=newnode(8);
	root->right->right->left=newnode(9);
	root->right->right->right=newnode(10);
	leaves_in_dll(root,&head);
	cout << "LEAVES IN A DOUBLY LINKED LIST : ";
	print_dll(head);
	cout << endl;
	cout << "MODIFIED TREE'S INORDER TRAVERSAL : ";
	print_bt(root);
	cout << endl;
	return 0;
}

