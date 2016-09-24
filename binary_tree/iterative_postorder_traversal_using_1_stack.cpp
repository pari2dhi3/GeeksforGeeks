#include<bits/stdc++.h>
#include<stack>
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
	return (node);
}
void postorder_traversal(tree *root)
{
	stack<tree *> s1;
	do
	{
		while(root)
		{
			if(root->right)
				s1.push(root->right);
			s1.push(root);
			root=root->left;
		}
		root=s1.top();
		s1.pop();
		if(root->right && (!s1.empty()) && s1.top()==root->right)
		{
			s1.pop();
			s1.push(root);
			root=root->right;
		}
		else
		{
			cout << root->val << " ";
			root=NULL;
		}
	}
	while(!s1.empty());
	cout << endl;
	return;
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
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	postorder_traversal(root);
	return 0;
}
