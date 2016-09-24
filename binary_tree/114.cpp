//Expression tree
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	char val;
}tree;
tree *newnode(char data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void fxn(tree *root)
{
	if(root==NULL)
		return;
	fxn(root->left);
	cout << root->val;
	fxn(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode('+');
	root->left=newnode('3');
	root->right=newnode('*');
	root->right->left=newnode('+');
	root->right->left->left=newnode('5');
	root->right->left->right=newnode('9');
	root->right->right=newnode('2');
	fxn(root);
	cout << endl;
	return 0;
}
