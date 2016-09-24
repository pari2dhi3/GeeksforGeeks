#include<bits/stdc++.h>
using namespace std;
void DFS_Util(int &s, int &v, vector< vector<int> > &mat, vector< vector<int> > &tc)
{
	int i;
	tc[s][v]=1;
	for(i=0;i<mat[v].size();i++)
	{
		if(mat[v][i]!=0 && tc[s][i]==0) 
			DFS_Util(s,i,mat,tc);
	}
}
void DFS(vector< vector<int> > &mat)
{
	vector< vector<int> > tc(mat.size(), vector<int>(mat.size(),0));
	int i,j;
	for(i=0;i<mat.size();i++)
	{
		DFS_Util(i,i,mat,tc);
	}
	cout << "Transitive Matrtix looks like : \n";
	for(i=0;i<tc.size();i++)
	{
		for(j=0;j<tc[0].size();j++)
			cout << tc[i][j] << "  ";
		cout << endl;
	}
	return;
}
int main()
{
	int i,j,row,p;
	vector< vector<int> > mat;
	vector<bool> vis(4,false);
	for(i=0;i<4;i++)
	{
		vector<int> ans;
		for(j=0;j<4;j++)
		{
			cin >> p;
			ans.push_back(p);
		}
		mat.push_back(ans);
	}
	cout << "Matrix looks like : " << endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			cout << mat[i][j] << "  ";
		cout << endl;
	}
	DFS(mat);	
	return 0;
}
