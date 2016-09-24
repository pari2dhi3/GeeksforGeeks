//find maximum or minimum in a binary tree//
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
void find_max1(tree *root, int *max_ref)
{
	if(root==NULL)
		return ;
	if(root->val>(*max_ref))
		(*max_ref)=root->val;
	find_max1(root->left,max_ref);
	find_max1(root->right,max_ref);
	return;
}
int find_max(tree *root)
{
	int max=0;
	find_max1(root, &max);
	return max;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(2);
	root->left=newnode(7);
	root->right=newnode(5);
	root->left->right=newnode(6);
	root->left->right->left=newnode(1);
	root->left->right->right=newnode(11);
	root->right->right=newnode(9);
	root->right->right->left=newnode(4);
	cout << "THE MAXIMUM OF THE B-TREE IS : " << find_max(root) << endl;
	return 0;
}
