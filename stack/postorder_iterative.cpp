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
void postorder(tree *root)
{
	tree *curr=NULL, *temp=NULL;
	curr=root;
	stack<tree *> s;
	while(!s.empty() || curr!=NULL)
	{
		while(curr!=NULL)
		{
			cout << curr->key << "  ";
			s.push(curr);
			curr=curr->right;
		}
		temp=s.top();
		s.pop();
		curr=temp->left;
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
	root->right->left=insert(6);
	root->right->right=insert(7);
	cout << "Postorder traversal : "; 	
	postorder(root);
	cout << endl;
	return 0;
}
