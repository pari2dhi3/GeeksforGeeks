#include<bits/stdc++.h>
using namespace std;
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
	q.push(1);
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
				if(vis[i]==0)
				{
					q.push(i+1);
					vis[i]=1;
				}
			}
		}
	}
	cout << endl;
	return 0;
}
