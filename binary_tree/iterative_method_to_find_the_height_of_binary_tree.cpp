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
int height(tree *node)
{
	int h=0, nodecount=0;
	if(node==NULL)
		return 0;
	queue<tree *> q;
	q.push(node);
	while(1)
	{
		nodecount=q.size();
		if(nodecount==0)
			return h;
		else
			h=h+1;
		while(nodecount>0)
		{
			tree *temp=NULL;
			temp=q.front();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			q.pop();
			nodecount--;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int h;
	tree *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right==newnode(5);
	h=height(root);
	cout << "The height of the tree is " << h << endl; 
	return 0;
}
