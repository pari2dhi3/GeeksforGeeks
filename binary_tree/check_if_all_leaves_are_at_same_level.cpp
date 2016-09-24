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
bool check1(tree *root, int level, int *leaflevel)
{
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right==NULL)
	{
		if((*leaflevel)==0)
		{
			*leaflevel=level;
			return true;
		}
		if((*leaflevel)==level)
			return true;
		return false;
	}
	return (check1(root->left,level+1,leaflevel) && check1(root->right,level+1,leaflevel));
}
bool check(tree *root)
{
	int level=0, leaflevel=0;
	return check1(root,level,&leaflevel);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(12);
	root->left=newnode(5);
	root->right=newnode(7);
	root->left->left=newnode(3);
	if(check(root))
		cout << "ALL LEAVES ARE AT SAME LEVEL\n";
	else
		cout << "LEAVES ARE NOT AT SAME LEVEL\n";
	return 0;
}
