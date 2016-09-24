#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,row,p;
	vector< vector<int> > mat;
	vector<int> dist(5,0);
	vector<int> parent(5,-1);
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
	q.push(1);
	dist[0]=0;
	parent[0]=-1;
	vis[0]=true;
	cout << "BFS : ";
	while(!q.empty())
	{
		row=q.front();
		cout << row << "  ";
		q.pop();
		for(i=0;i<5;i++)
		{
			if(mat[row-1][i]!=0)
			{
				if(dist[i]==0 && i>0)
				{
					parent[i]=row;
					dist[i]=mat[row-1][i]+dist[parent[i]-1];
				}
				else if(dist[i]>dist[row-1]+mat[row-1][i])
				{
					dist[i]=dist[row-1]+mat[row-1][i];
					parent[i]=row;
				}
				if(vis[i]==0)
				{
					q.push(i+1);
					vis[i]=1;
				}
			}
		}
	}
	cout << endl;
	cout << "Distance array : ";
	for(i=0;i<dist.size();i++)
		cout << dist[i] << "  ";
	cout << endl;
	cout << "Parent array : ";
	for(i=0;i<parent.size();i++)
		cout << parent[i] << "  ";
	cout << endl;
	return 0;
}


