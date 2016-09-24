#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
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
void ancestors(tree *node, int key)
{
	if(node==NULL)
		return;
	if(node->val==key)
	{
		cout << "ancestors using recursion\n";
		while(!s1.empty())
		{
			cout << s1.top() << " ";
			s1.pop();
		}
		cout << endl;
	}
	s1.push(node->val);
	ancestors(node->left,key);
	ancestors(node->right,key);
	if(!s1.empty())
		s1.pop();
	return;
}
void ancestors1(tree *node, int key)
{
	if(node==NULL)
		return;
	if(node->val==key)
	{
		cout << endl;
		return;
	}
	while(1)
	{
		if(key==node->val)
		{
			while(!stack.empty())
			{
				cout << s1.top() << " ";
				s1.pop();
			}
		}
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root=NULL;
	int key;
	cout << "ENTER THE KEY\n";
	cin >> key;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->left->left->left=newnode(8);
	root->left->right->right=newnode(9);
	root->right->right->left=newnode(10);
	ancestors(root,key);
	ancestors1(root,key);
	return 0;
}
