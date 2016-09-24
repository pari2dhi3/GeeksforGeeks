#include<bits/stdc++.h>
using namespace std;
void DFS_util(int &i, vector< vector<int> > &mat, vector<bool> &vis)
{
	int j;
	vis[i]=true;
	for(j=0;j<mat[i].size();j++)
	{
		if(mat[i][j]!=0)
			DFS_util(j,mat,vis);
	}
	return;
}
int DFS(vector< vector<int> > &mat, vector<bool> &vis)
{
	int i,last=0;
	for(i=0;i<mat.size();i++)
	{
		if(vis[i]==false)
		{
			DFS_util(i,mat,vis);
			last=i;
		}
	}
	for(i=0;i<vis.size();i++)
		vis[i]=false;
	DFS_util(last,mat,vis);
	for(i=0;i<vis.size();i++)
	{
		if(vis[i]==false)
			return -1;
	}
	return last;
}
int main()
{
	int i,j,row,p,last;
	vector< vector<int> > mat;
	vector<bool> vis(5,false);
	stack<int> s;
	for(i=0;i<7;i++)
	{
		vector<int> ans;
		for(j=0;j<7;j++)
		{
			cin >> p;
			ans.push_back(p);
		}
		mat.push_back(ans);
	}
	cout << "Matrix looks like : " << endl;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
			cout << mat[i][j] << "  ";
		cout << endl;
	}
	last = DFS(mat,vis);
	if(last==-1)
		cout << "There is no mother vertex.\n";
	else
		cout << last << " is the mother vertex.\n";
	return 0;
}
