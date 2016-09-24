#include<bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
TreeLinkNode* newnode(int data)
{
	TreeLinkNode* node;
	node=(TreeLinkNode *)malloc(sizeof(TreeLinkNode));
	node->left=NULL;
	node->right=NULL;
	node->next=NULL;
	node->val=data;
	return node;
}
int height(TreeLinkNode *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(root->left==NULL)
		return height(root->right)+1;
	if(root->right==NULL)
		return height(root->left)+1;
	return max(height(root->left),height(root->right))+1;
}
void level_order(TreeLinkNode* &root, int level, vector<TreeLinkNode *> &q)
{
	if(root==NULL)
		return;
	if(level==1)
	{
		q.push_back(root);
		return;
	}
	else if(level>1)
	{
		level_order(root->left,level-1,q);
		level_order(root->right,level-1,q);
	}
}
void connect(TreeLinkNode *root) 
{
	vector<TreeLinkNode *> q;
	int i,h;
	h=height(root);
	for(i=1;i<=h;i++)
	{
		level_order(root,i,q);
		while(!q.empty())
		{
			TreeLinkNode* temp;
			temp=q.front();
			delete(q.begin());
			if(!q.empty())
				temp->next=q.front();
			else
				temp->next=NULL;
		}
	}
	return;
}
void print(TreeLinkNode* root)
{
	while(root!=NULL)
	{
		cout << root->val << " ";
		root=root->next;
	}
}
int  main()
{
	ios_base::sync_with_stdio(false);
	TreeLinkNode *root, *root1;
	int i,h;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

	connect(root);
	h=height(root);	
	for(i=1;i<=h;i++)
	{
		print(root);
		cout << endl;
	}
	return 0;
}
