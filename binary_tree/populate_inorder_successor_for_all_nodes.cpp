/*Populating the next pointer according to inorder tree traversal by using reversed inorder tree traversal*/
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int val;
	tree *left;
	tree *right;
	tree *next;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	node->next=NULL;
	return(node);
}
void populate_the_next(tree *node)
{
	tree *next=NULL;
	if(node)
	{
		populate_the_next(node->right);
		node->next=next;
		next=node;
		populate_the_next(node->left);
	}
}
void print(tree *node)
{
	if(!node)
		return;
	if(node)
		print(node->left);
	while(node)
	{
		cout << node->val << " ";
		node=node->next;
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->right->right->left=newnode(8);
	root->right->right->right=newnode(9);
	populate_the_next(root);
	print(root);
	return 0;
}

