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
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int in[]={4,8,10,12,14,20,22}, level[]={20,8,22,4,12,10,14};
	make_bt(root,in,level);
	return 0;
}
