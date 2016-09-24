//Perfect binary tree specific level order traversal//
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
void levelorder1(tree *root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout << root->val << " ";
	else if(level>1)
	{
		levelorder1(root->left,level-1);
		levelorder1(root->right,level-1);
	}
	return;
}
void levelorder2(tree *root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout << root->val << " ";
	else if(level>1)
	{
		levelorder2(root->right,level-1);
		levelorder2(root->left,level-1);
	}
	return;
}
void specific(tree *root, int h)
{
	int i;
	cout << root->val << " ";
	for(i=1;i<h;i++)
	{
		levelorder1(root->left,i);
		levelorder2(root->right,i);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int h=4;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->left->left->left=newnode(8);
	root->left->left->right=newnode(9);
	root->left->right->left=newnode(10);
	root->left->right->left=newnode(11);
	root->right->left->left=newnode(12);
	root->right->left->right=newnode(13);
	root->right->right->left=newnode(14);
	root->right->right->right=newnode(15);
	
	cout << "SPECIFIC LEVEL ORDER TRAVERSAL OF A PERFECT BINARY TREE IS : ";
	specific(root,h);
	cout << endl;
	return 0;
}
	
