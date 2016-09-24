//Change a Binary Tree so that every node stores sum of all nodes in left subtree
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree *newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
int suum(tree *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->val;
	return(suum(root->left)+suum(root->right)+root->val);
}
void inorder(tree *root)
{
	int sum=0;
	if(root==NULL)
		return;
	inorder(root->left);
	root->val=suum(root->left)+root->val;
	inorder(root->right);
	return;
}
void modify(tree *root)
{
	inorder(root);
	return;
}
void print(tree *root)
{
	if(root==NULL)
		return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
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
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	modify(root);
	cout << "THE MODIFIED TREE IS : ";
	print(root);
	cout << endl;
	return 0;
}
