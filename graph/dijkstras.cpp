#include<bits/stdc++.h>
using namespace std;
int dist_min(vector<int> &dist, vector<bool> &sp)
{
	int i,mini=INT_MAX, mini_index=0;
	for(i=0;i<dist.size();i++)
	{
		if(dist[i]<mini && sp[i]==false)
		{
			mini=dist[i];
			mini_index=i;
		}
	}
	return mini_index;
}
void dijkstras(vector< vector<int> > &mat)
{
	int i,j,u;
	vector<bool> sp(mat.size(),false);
	vector<int> dist(mat.size(),INT_MAX);
	dist[0]=0;
	for(i=0;i<sp.size();i++)
	{
		u=dist_min(dist,sp);
		sp[u]=true;
		for(j=0;j<mat[u].size();j++)
		{
			if(mat[u][j]!=0 && dist[j]>dist[u]+mat[u][j])
				dist[j]=dist[u]+mat[u][j];
		}
	}
	cout << "Distance vector : ";
	for(i=0;i<dist.size();i++)
		cout << dist[i] << "   ";
	cout << endl;
	return;
}	
int main()
{
	int i,j,row,p;
	vector< vector<int> > mat;
	for(i=0;i<9;i++)
	{
		vector<int> ans;
		for(j=0;j<9;j++)
		{
			cin >> p;
			ans.push_back(p);
		}
		mat.push_back(ans);
	}
	cout << "Matrix looks like : " << endl;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			cout << mat[i][j] << "  ";
		cout << endl;
	}
	dijkstras(mat);
	return 0;
}
