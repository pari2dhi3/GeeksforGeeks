#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int key;
}tree;
tree * insert(int val)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->key=val;
	return node;
}
int main()
{
	tree *root=NULL;
	stack<tree *> s;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->left=insert(6);
	root->right->right=insert(7);
	root->left->left->right=insert(8);
	root->right->right->left=insert(9);

	cout << "Enter the element : ";
	cin >> p;
	curr=root;
	if(root!=NULL && root->key==p)
		s.push(root);
	while(1)
	{
		if(s.top()->key==p)
		{
			s.pop();
			cout << "The ancestors are : ";
			while(!s.empty())
			{
				cout << s.top()->key << "  ";
				s.pop();
			}
		}
		else if(s.top()->left)
			s.push(s.top()->left);
		else if(s.top()->right)
			s.push(s.top()->right);
		else
		{
			s.pop();
			if(s.top() && s.top()->right
	}

		




