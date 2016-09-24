#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *left;
	tree *right;
	int val;
}tree;
void insert(tree **
int main()
{
	ios_base::sync_with_stdio(false);
	tree *root;
	for(i=1;i<=10;i++)
		insert(&root,i);
