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
void preorder(tree *root)
{
	stack<tree *> s;
	tree *curr=NULL, *temp=NULL;
	curr=root;
	while(!s.empty() || curr!=NULL)
	{
		while(curr!=NULL)
		{
			cout << curr->key << "  ";
			s.push(curr);
			curr=curr->left;
		}
		temp=s.top();
		s.pop();
		curr=temp->right;
	}
	return;
}
int main()
{
	tree *root=NULL;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	cout << "Preorder traversal is : ";
	preorder(root);
	cout << endl;
	return 0;
}
