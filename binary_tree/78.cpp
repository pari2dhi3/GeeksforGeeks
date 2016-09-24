//Print all nodes that are at distance k from a leaf node//
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
int fxn(tree *root, int k)
{
	int w=0;
	if(root==NULL)
		return -1;
	w=fxn(root->left,k);
	if(w+1==k)
		cout << root->val << " ";
	w=fxn(root->right,k);
	if(w+1==k)
		cout << root->val << " ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int k=0;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->right->left->right=newnode(8);
	cout << "ENTER THE VALUE OF K\n";
	cin >> k;
	cout << "THE NODES AT K DISTANCE AWAY ARE : ";
	fxn(root,k);
	cout << endl;
	return 0;
}

