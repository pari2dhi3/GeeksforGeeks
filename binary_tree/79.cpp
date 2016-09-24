//Check if a given Binary Tree is a height balanced like a Red-Black Tree//
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
int flag=0;
bool check1(tree *root, int level, int *level_max, int *level_min)
{
	if(root==NULL)
	{
		if(!flag)
		{
			(*level_min)=level-1;
			flag=1;
		}
		return true;
	}
	if((*level_max)<level)
		(*level_max)=level;
	if(root->left==NULL && root->right==NULL)
	{
		if((*level_max)<=(2*(*level_min)))
		{
			if((*level_min<=level)&&(*level_max>=level))
			{
				if(flag==0)
				{
					(*level_min)=level;
					flag=1;
				}
				return true;
			}
			if(level<(*level_min))
				(*level_min)=level;
			if(level>(*level_max))
				(*level_max)=level;
		}
		else
			return false;
	}
	return (check1(root->left,level+1,level_max,level_min) && check1(root->right,level+1,level_max,level_min));
}
bool check(tree *root)
{
	int level=1, level_max=1, level_min=1;
	return check1(root,level,&level_max,&level_min);
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(40);
	root->right=newnode(100);
	root->right->right=newnode(150);
	if(check(root))
		cout << "THE GIVEN TREE IS HEIGHT BALANCED RED-BLACK TREE\n";
	else
		cout << "THE GIVEN TREE IS NOT A HEIGHT BALANCED RED-BLACK TREE\n";
	return 0;
}
