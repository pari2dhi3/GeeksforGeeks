#include<bits/stdc++.h>
using namespace std;
bool iscycle_util(int &i, vector< vector<int> > &mat, vector<bool> &vis, int &parent)
{
	int j;
	vis[i]=true;
	for(j=0;j<mat[i].size();j++)
	{
		if(mat[i][j]!=0)
		{
			if(vis[j]==false)
				return iscycle_util(j,mat,vis,i);
			else if(vis[j]==true && parent!=j)
				return true;
		}
	}
	return false;
}
bool iscycle(vector< vector<int> > &mat, vector<bool> &vis)
{
	int i,parent=-1;
	for(i=0;i<mat.size();i++)
	{
		if(vis[i]==false)
			return iscycle_util(i,mat,vis,parent);
	}
}
int main()
{
	int i,j,row,p;
	vector< vector<int> > mat;
	vector<bool> vis(5,false);
	queue<int> q;
	for(i=0;i<5;i++)
	{
		vector<int> ans;
		for(j=0;j<5;j++)
		{
			cin >> p;
			ans.push_back(p);
		}
		mat.push_back(ans);
	}
	cout << "Matrix looks like : " << endl;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			cout << mat[i][j] << "  ";
		cout << endl;
	}
	if(iscycle(mat,vis))
		cout << "graph has a cycle\n";
	else
		cout << "graph doesn't have a cycle\n";
	return 0;
}
