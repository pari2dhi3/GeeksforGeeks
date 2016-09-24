//Sorted Array to Balanced BST
#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;
}TreeNode;
TreeNode* newnode(int data)
{
         TreeNode* root;
         root=(TreeNode *)malloc(sizeof(TreeNode));
         root->left==NULL;
         root->right==NULL;
         root->val=data;
         return root;
}
TreeNode* insert(TreeNode* &root, int data)
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
TreeNode* tree(vector<int>& nums, int l, int r)
{
	TreeNode *root;
	if(r<l)
		return NULL;
	int i;
	i=(l+r)/2;
	root=newnode(nums[i]);
	root->left=tree(nums,l,i-1);
	root->right=tree(nums,i+1,r);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	int l=0, r=nums.size()-1;
	TreeNode* root=NULL;
	if(nums.size()!=0)
		root=tree(nums,l,r);
	return root;
}
void print(TreeNode* root)
{
	if(root==NULL)
		return;
	print(root->left);
	cout << root->val << " ";
	print(root->right);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	TreeNode* root=NULL;
	int i;
	vector<int> nums;
	for(i=1;i<5;i++)
		nums.push_back(i);
	root=sortedArrayToBST(nums);
	print(root);
	cout << endl;
	return 0;
}
