//Iterative search for a key 'x' in Binary Tree//
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
stack<tree *> s;
bool iterative_search(tree *root, int key)
{
	tree *new_node=NULL;
	int flag=0;
	if(root==NULL)
		return false;
	while(!s.empty()||flag==0||root!=NULL)
	{
		flag=1;
		while(root!=NULL)
		{
			if(root->val==key)
				return true;
			s.push(root);
			root=root->left;
		}
		new_node=s.top();
		s.pop();
		root=new_node->right;
	}
	return false;
}
bool found(tree *root, int key)
{
	return iterative_search(root,key);
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
	root->left->right->left=newnode(1);
	root->left->right->right=newnode(11);
        root->right->right=newnode(9);
	root->right->right->left=newnode(4);
	cout << "ENTER THE KEY\n";
	cin >> key;
	if(found(root,key))
		cout << "FOUND\n";
	else
		cout << "NOT FOUND\n";
	return 0;
}
