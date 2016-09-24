//maximum path sum in a binary tree//
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
void max_path_sum1(tree *root, int *max_sum, int sum)
{
	if(root==NULL)
		return;
	if(sum+root->val > (*max_sum))
		(*max_sum)=sum+root->val;
	max_path_sum1(root->left,max_sum,sum+root->val);
	max_path_sum1(root->right,max_sum,sum+root->val);
	return;
}
int max_path_sum(tree *root)
{
	int max_sum_left=0,sum=0,max_sum_right=0;
	max_path_sum1(root->left,&max_sum_left,sum);
	max_path_sum1(root->right,&max_sum_right,sum);
	if(root->val>0)
		return max_sum_left+max_sum_right+root->val;
	return max_sum_left+max_sum_right;
}
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	root=newnode(10);
	root->left=newnode(2);
	root->right=newnode(10);
	root->left->left=newnode(20);
	root->left->right=newnode(1);
	root->right->right=newnode(-25);
	root->right->right->left=newnode(3);
	root->right->right->right=newnode(4);

	cout << "THE MAXIMUM PATH SUM OF THE GIVEN TREE IS : " << max_path_sum(root) << endl;
	return 0;
}

