//Find count of single valued subtree//
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
bool fxn1(tree *root, int *count)
{
	if(root==NULL)
		return false;
	if(root->left==NULL && root->right==NULL)
	{
		(*count)+=1;
		return true;
	}
	if(fxn1(root->left,count)==fxn1(root->right,count) && root->val==root->left->val && root->val==root->right->val)
	{
		(*count)+=1;
		return true;
	}
}
int fxn(tree *root)
{
	int count=0;
	fxn1(root,&count);
	return count; 
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(5);
	root->left=newnode(1);
	root->right=newnode(5);
	root->left->left=newnode(5);
	root->left->right=newnode(5);
	root->right->right=newnode(5);

	cout << "THE NUMBER OF SUBTREES WITH SINGLE VALUES IS : "<< fxn(root) << endl;
	return 0;
}

