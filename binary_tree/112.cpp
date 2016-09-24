//Find Minimum Depth
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
int min1(tree *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(!root->left)
		return min1(root->right)+1;
	if(!root->right)
		return min1(root->left)+1;
	return min(min1(root->left),min1(root->right))+1;
}
int find_min_depth(tree *root)
{
	return min1(root);
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
	cout << "THE MINIMUM DEPTH OF THE B-TREE IS : " << find_min_depth(root) << endl;
	return 0;
}
