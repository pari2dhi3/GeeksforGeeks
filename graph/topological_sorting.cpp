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
void topological_order(vector< vector<int> > &mat, vector<bool> &vis)
{
	int i;
	stack<int> s;
	for(i=0;i<mat.size();i++)
	{
		if(vis[i]==false)
			topological_util_order(i,mat,vis,s);
	}
	cout << "Topological Sort : ";
	while(!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	cout << endl;
	return;
}
int main()
{
	int i,j,p;
	vector< vector<int> > mat;
	vector<bool> vis(5,false);
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
	topological_order(mat,vis);
	return 0;
}
