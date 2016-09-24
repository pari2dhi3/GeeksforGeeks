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
	node=(tree *)malloc(sizeof(node));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return(node);
}
void max_sum(tree *node, int sum, int max)
{
	if(node==NULL)
		return;
	sum=sum+node->val;
	max_sum(node->left,sum,max);
	max_sum(node->right,sum,max);
	cout << sum << " ";
	sum=sum-node->val;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=NULL;
	root=newnode(10);
	root->left=newnode(-2);
	root->right=newnode(7);
	root->left->left=newnode(8);
	root->left->right=newnode(-4);
	max_sum(root,0,0);
	return 0;
}
