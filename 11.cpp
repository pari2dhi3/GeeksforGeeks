//Find k-th smallest element in BST (Order Statistics in BST)
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
		tree *left;
			tree *right;
				int val;
}tree;
tree* newnode(int data)
{
		tree* node;
			node=(tree* )malloc(sizeof(tree));
				node->left=NULL;
					node->right=NULL;
						node->val=data;
							return node;
}
tree* insert(tree* &root, int data)
{
		if(root==NULL)
				{
							root=newnode(data);
									return root;
										}
			else if(data>root->val)
						return insert(root->right,data);
				else if(data<root->val)
							return insert(root->left,data);
}

