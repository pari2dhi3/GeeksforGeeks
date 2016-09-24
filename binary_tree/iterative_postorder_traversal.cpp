//Iterative Postorder traversal using 2 stacks
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
	node=(tree *)malloc(sizeof(node));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
void postorder(tree *node)
{
	stack<tree *> s1, s2;
	tree *temp;
	s1.push(node);
	while(!s1.empty())
	{
		temp=s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
	}
	while(!s2.empty())
	{
		temp=s2.top();
		s2.pop();
		cout << temp->val << " ";
	}
	cout << endl;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	postorder(root);
	return 0;
}
