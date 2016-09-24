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
int find_max(int arr[], int start, int end)
{
	int i,max_ind,max;
	max=arr[start];
	max_ind=start;
	for(i=start+1;i<=end;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			max_ind=i;
		}
	}
	return max_ind;
}
tree * build_tree(int arr[], int start, int end)
{
	if(end<start)
		return NULL;
	int i;
	tree *node;
	i=find_max(arr,start,end);
	node=newnode(arr[i]);
	if(start==end)
		return node;
	node->left=build_tree(arr, start, i-1);
	node->right=build_tree(arr, i+1, end);
}
void print(tree *node)
{
	if(node==NULL)
		return;
	print(node->left);
	cout << node->val << " ";
	print(node->right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[100], len, i;
	tree *root;
	cout << "ENTER THE NUMBER OF ELEMENTS IN AN ARRAY\n";
	cin >> len;
	cout << "ENTER THE ELEMENTS\n";
	for(i=0;i<len;i++)
		cin >> arr[i];
	root=build_tree(arr, 0, len-1);
	cout << "THE INORDER TRAVERSAL OF THE BUILT TREE IS : ";
	print(root);
	cout << endl;
	return 0;
}
