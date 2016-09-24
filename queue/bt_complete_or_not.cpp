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
}
bool complete_or_not(tree *root)
{
	bool flag=false;
	queue<tree *> q;
	if(root==NULL)
		return true;
	q.push(root);
	while(!q.empty())
	{
		tree *temp;
		temp=q.front();
		q.pop();
		if(temp->left)
		{
			if(flag==true)
				return false;
			q.push(temp->left);
		}
		else
			flag=true;
		if(temp->right)
		{
			if(flag==true)
				return false;
			q.push(temp->right);
		}
		else
			flag=true;
	}
	return true;
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

	if(complete_or_not(root))
		cout << "The tree is a complete BT\n";
	else
		cout << "The tree is not a complete BT\n";
	return 0;
}

