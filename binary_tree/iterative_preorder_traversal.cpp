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
void stack_preorder(tree *node)
{
	stack<tree *> sta;
	tree *root;
	if(node==NULL)
		return;
	sta.push(node);
	while(!sta.empty())
	{
		root=sta.top();
		cout << root->val << " ";
		sta.pop();
		if(root->right)
			sta.push(root->right);
		if(root->left)
			sta.push(root->left);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(10);
	root->left=newnode(8);
	root->right=newnode(2);
	root->left->left=newnode(3);
	root->left->right=newnode(5);
	root->right->left=newnode(2);
	stack_preorder(root);
	cout << endl;
	return 0;
}
