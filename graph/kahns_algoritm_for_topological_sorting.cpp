#include<bits/stdc++.h>
using namespace std;
void kahns(vector< vector<int> > &mat, vector<bool> vis)
{
	int i,j;
	vector<int> incoming(mat.size(),0);
	for(i=0;i<mat.size();i++)
	{
		for(j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]==1)
				incoming[j]+=1;
		}
	}
	queue<int> q;
	for(i=0;i<incoming.size();i++)
	{
		if(incoming[i]==0)
			q.push(i);
	}
	vector<int> topo_order;
	int vis_count=0,u;
	while(!q.empty())
	{
		u=q.front();
		vis_count++;
		q.pop();
		topo_order.push_back(u);
		for(i=0;i<mat.size();i++)
		{
			if(mat[u][i]==1)
			{
				if(incoming[i]>0)
					incoming[i]-=1;
				if(incoming[i]==0)
					q.push(i);
			}
		}
	}
	if(vis_count==mat.size())
	{
		cout << "Topological Order : ";
		for(i=0;i<topo_order.size();i++)
			cout << topo_order[i] << "  ";
		cout << endl;
	}
	return;
}
int main()
{
	int i,j,row,p;
	vector< vector<int> > mat;
	vector<bool> vis(5,false);
	queue<int> q;
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
	kahns(mat,vis);
	return 0;
}
