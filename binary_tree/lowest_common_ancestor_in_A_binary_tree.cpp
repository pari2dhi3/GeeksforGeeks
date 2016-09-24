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
tree *lca(tree *root, int n1, int n2)
{
	tree *left_lca, *right_lca;
	if(root==NULL)
		return NULL;
	if(root->val==n1 || root->val==n2)
		return root;
	left_lca=lca(root->left,n1,n2);
	right_lca=lca(root->right,n1,n2);
	if(left_lca && right_lca)
		return root;
	return ((left_lca!=NULL)? left_lca : right_lca);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int n1, n2;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	cout << "ENTER 2 KEYS WHOSE LOWER ANCESTOR IS EVALUATED\n";
	cin >> n1 >> n2;
	cout << "THE LOWEST ANCESTOR IS : " << lca(root,n1,n2)->val << endl;
	return 0;
}
