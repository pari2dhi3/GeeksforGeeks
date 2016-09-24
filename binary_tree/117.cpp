//Iterative Search for a key ‘x’ in Binary Tree//
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
	tree *root;
	root=(tree *)malloc(sizeof(tree));
	root->left=NULL;
	root->right=NULL;
	root->val=data;
	return root;
}
stack<tree *>s;
bool find(tree *root, int key)
{
	if(root==NULL)
		return false;
	while(!s.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		if(root==NULL && (!s.empty()))
		{
			root=s.top();
			s.pop();
			if(root->val==key)
				return true;
			root=root->right;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	int key;
	root=newnode(2);
	root->left=newnode(7);
	root->right=newnode(5);
	root->left->right=newnode(6);
	root->right->right=newnode(9);
	root->left->right->left=newnode(1);
	root->left->right->right=newnode(11);
	root->right->right->left=newnode(4);
	cout << "ENTER THE KEY YOU WANT TO SEARCH\n";
	cin >> key;
	if(find(root,key))
		cout << "FOUND\n";
	else
		cout << "NOT FOUND\n";
	return 0;
}
