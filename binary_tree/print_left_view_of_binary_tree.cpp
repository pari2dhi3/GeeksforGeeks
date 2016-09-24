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
void left_view1(tree *root, int level, int *level_max)
{
	if(root==NULL)
		return;
	if((*level_max)<level)
	{
		cout << root->val << " ";
		*level_max=level;
	}
	left_view1(root->left,level+1,level_max);
	left_view1(root->right,level+1,level_max);
}
void left_view(tree *root)
{
	int level=1, level_max=0;
	left_view1(root,level, &level_max);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(12);
	root->left=newnode(10);
	root->right=newnode(30);
	root->right->left=newnode(25);
	root->right->right=newnode(40);
	cout << "THE LEFT VIEW OF BINARY TREE IS : ";
	left_view(root);
	cout << endl;
	return 0;
}
