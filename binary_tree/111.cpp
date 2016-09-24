//Symmetric Tree (Mirror Image of itself)
#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
tree *newnode(int data)
{
	tree *node;
	node=(tree *)malloc(sizeof(tree));
	node->left=NULL;
	node->right=NULL;
	node->val=data;
	return node;
}
int height(tree *root, int *max_l, int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
	{
		if((*max_l)<level)
		{
			(*max_l)=level;
			return (*max_l);
		}
		return level;
	}
	return max(height(root->left,max_l,level+1),height(root->right,max_l,level+1));
}
stack<int> s;
void level_order(tree *root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
	{
		s.push(root->val);
		return;
	}
	else if(level>1)
	{
		level_order(root->left,level-1);
		level_order(root->right,level-1);
	}
	return;
}
bool check_level_order(tree *root, int level)
{
	if(root==NULL)
		return true;
	if(level==1)
	{
		if(s.top()==root->val)
		{
			s.pop();
			return true;
		}
		else
			return false;
	}
	else if(level>1)
		return check_level_order(root->left,level-1) && check_level_order(root->right,level-1);
}
bool is_mirror(tree *root)
{
	int flag=0,h=0,max_l=0,i,level=1;
	h=height(root,&max_l,level);
	for(i=2;i<=h;i++)
	{
		level_order(root->left,i);
		if(check_level_order(root->right,i))
			continue;
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(2);
	root->left->left=newnode(3);
	root->left->right=newnode(4);
	root->right->left=newnode(5);
	root->right->right=newnode(3);
	if(is_mirror(root))
		cout << "IT IS A SYMMETRIC TREE\n";
	else
		cout << "IT IS NOT A SYMMETRIC TREE\n";
	return 0;
}
