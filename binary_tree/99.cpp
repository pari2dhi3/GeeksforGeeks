//To check whether the tree is a Full Binary Tree or not//
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
bool full(tree *root)
{
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right==NULL)
		return true;
	if(root->left==NULL || root->right==NULL)
		return false;
	return (full(root->left)&&full(root->right));
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
	if(full(root))
		cout << "THE B-TREE IS FULL\n";
	else
		cout << "THE B-TREE IS NOT FULL\n";
	return 0;
}
