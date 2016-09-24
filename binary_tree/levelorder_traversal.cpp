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
int height(tree *node)
{
	int rdepth, ldepth;
	if(node==NULL)
		return 0;
	else
	{
		ldepth=height(node->left);
		rdepth=height(node->right);
		if(ldepth>rdepth)
			return (ldepth+1);
		else
			return (rdepth+1);
	}
}
void inorder_traversal1(tree *node, int i)
{
	if(node==NULL)
		return;
	if(i==1)
		cout << node->val << " ";
	else if(i>1)
	{
		inorder_traversal1(node->left,i-1);
		inorder_traversal1(node->right,i-1);
	}
	return;
}
void inorder_traversal(tree *node)
{
	int i;
	int h=height(node);
	cout << "height is : " <<  h << endl; 
	for(i=1;i<=h;i++)
		inorder_traversal1(node,i);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	inorder_traversal(root);
	return 0;
}
