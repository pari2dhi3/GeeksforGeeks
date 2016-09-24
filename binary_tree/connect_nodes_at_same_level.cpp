#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int val;
	tree *left;
	tree *right;
	tree *next_right;
}tree;
tree * newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->val=data;
	node->left=NULL;
	node->right=NULL;
	node->next_right=NULL;
	return(node);
}
void connect_recur(tree *node)
{
        if(!node)
		return;
	if(node->left)
		node->left->next_right=node->right;
	if(node->right)
	{
        	if(node->next_right!=NULL)
           		node->right->next_right=node->next_right->left;
  	      else
        	        node->right->next_right=NULL;
	}
        connect_recur(node->left);
        connect_recur(node->right);
        return;
}
void connect(tree *node)
{
	node->next_right=NULL;
	connect_recur(node);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int data;
	tree *root;
	root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	connect(root);
	cout << root->val << endl;
	cout << root->left->val << root->left->next_right->val << endl;
	cout << root->left->left->val << root->left->left->next_right->val << root->left->left->next_right->next_right->val << root->left->left->next_right->next_right->next_right->val << endl;
	return 0;
}
	
