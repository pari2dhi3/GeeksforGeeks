//Leet code codes //
#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;
}TreeNode;
TreeNode *newnode(int data)
{
	TreeNode *root;
	root=(TreeNode *)malloc(sizeof(TreeNode));
	root->left=NULL;
	root->right=NULL;
	root->val=data;
	return root;
}
    bool check_left(TreeNode* root, int min, int max)
    {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(root->right==NULL)
        {
            if(root->left->val<root->val && root->left->val >= min)
                return check_left(root->left,min,root->val);
            else
                return false;
        }
        if(root->left==NULL)
        {
            if(root->right->val>root->val && root->right->val<max)
                return check_left(root->right,root->val,max);
            else 
                return false;
        }
        if(root->left->val<root->val && root->left->val>=min && root->right->val>root->val && root->right->val<max)
            return (check_left(root->left,min,root->val)&&check_left(root->right,root->val,max));
         return false;
    }
    bool check_right(TreeNode* root, int min, int max)
    {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(root->right==NULL)
        {
            if(root->left->val<root->val && root->left->val>min)
                return check_right(root->left,min,root->val);
            else
                return false;
        }
        if(root->left==NULL)
        {
            if(root->right->val>root->val && root->right->val<=max)
                return check_right(root->right,root->val,max);
            else
                return false;
        }
        if(root->left->val<root->val && root->left->val>min && root->right->val>root->val && root->right->val<=max)
            return(check_right(root->left,min,root->val)&&check_right(root->right,root->val,max));
        return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(root->left==NULL)
        {   
            if(root->right->val>root->val)
                return check_right(root->right,root->val,INT_MAX);
            else
                return false;
        }
        if(root->right==NULL)
        {
            if(root->left->val<root->val)
                return check_left(root->left,INT_MIN,root->val);
            else
                return false;
        }
        if(root->left->val<root->val && root->right->val>root->val)
        {
            return check_left(root->left,INT_MIN,root->val) && check_right(root->right,root->val,INT_MAX);
        }
        return false;
    }
int  main()
{
	ios_base::sync_with_stdio(false);
	TreeNode *root, *root1;
	root=newnode(3);
	root->left=newnode(1);
	root->right=newnode(5);
	root->left->left=newnode(0);
	root->left->right=newnode(2);
	root->right->left=newnode(4);
	root->right->right=newnode(6);
	root->left->right->right=newnode(3);
	if(isValidBST(root))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
