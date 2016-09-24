#include<bits/stdc++.h>
using namespace std;
void topological_util_order(int i,vector< vector<int> > &mat, vector<bool> &vis, stack<int> &s)
{
	int j;
	vis[i]=true;
	for(j=0;j<mat[i].size();j++)
	{
		if(vis[j]==false && mat[i][j]!=0)
			topological_util_order(j,mat,vis,s);
	}
	s.push(i);
	return;
}
vector<int> topological_order(vector< vector<int> > &mat, vector<bool> &vis)
{
	int i;
	vector<int> vec;
	stack<int> s;
	for(i=0;i<mat.size();i++)
	{
		if(vis[i]==false)
			topological_util_order(i,mat,vis,s);
	}
	cout << "Topological Sort : ";
	while(!s.empty())
	{
		vec.push_back(s.top());
		s.pop();
	}
	return vec;
}
void longest_path(int s, vector< vector<int> > &mat, vector<int> &topology_sorted, vector<bool> &vis)
{
	int i,flag=0,j;
	vector<int> dist(topology_sorted.size(),-1);
	for(i=0;i<topology_sorted.size();i++)
	{
		if(topology_sorted[i]==s && flag==0)
		{
			dist[i]=0;
			flag=1;
		}
		if(flag==1)
		{
			for(j=0;j<mat[i].size();j++)
			{
				if(mat[i][j]!=0)
				{
					dist[j]=((dist[i]+mat[i][j])>dist[j]) ? dist[i]+mat[i][j] : dist[j];
				}
			}
		}
	}
	cout << "The longest path distance : ";
	for(i=0;i<dist.size();i++)
		cout << dist[i] << "  ";
	cout << endl;
	return;
}
int main()
{
	int i,j,p,vertex;
	vector< vector<int> > mat;
	vector<bool> vis(5,false);
	vector<int> topology_sorted;
	for(i=0;i<6;i++)
	{
		vector<int> ans;
		for(j=0;j<6;j++)
		{
			cin >> p;
			ans.push_back(p);
		}
		mat.push_back(ans);
	}
	cout << "Matrix looks like : " << endl;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
			cout << mat[i][j] << "  ";
		cout << endl;
	}
	topology_sorted = topological_order(mat,vis);
	for(i=0;i<topology_sorted.size();i++)
		cout << topology_sorted[i] << "  ";
	cout << endl;
	cout << "Enter the vertex from which you want to calculate longest path\n";
	cin >> vertex;
	longest_path(vertex,mat,topology_sorted,vis);
	return 0;
}
