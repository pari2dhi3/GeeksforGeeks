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
	tree *node=NULL;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->key=val;
	return node;
}
void inorder(tree *root)
{
	tree *curr, *temp=NULL;
	curr=root;
	stack<tree *> s;
	while(!s.empty() || curr!=NULL)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		temp=s.top();
		cout << temp->key << "  ";
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
	cout << "Inorder traversal is : ";
	inorder(root);
	cout << endl;
	return 0;
}

