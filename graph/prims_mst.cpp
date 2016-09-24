#include<bits/stdc++.h>
using namespace std;
int min_key(vector<int> &key, vector<bool> mst)
{
	int i;
	int mini=INT_MAX;
	int mini_index=0;
	for(i=0;i<key.size();i++)
	{
		if(mst[i]==false && key[i]<mini)
		{
			mini=key[i];
			mini_index=i;
		}
	}
	return mini_index;
}
void prims(vector< vector<int> > &mat)
{
	int i,j;
	vector<int> parent(mat.size());
	vector<int> key(mat.size(),INT_MAX);
	vector<bool> mst(mat.size(),false);

	key[0]=0;
	parent[0]=-1;

	for(i=0;i<mst.size();i++)
	{
		int u;
		u=min_key(key,mst);
		mst[u]=true;
		for(j=0;j<mat.size();j++)
		{
			if(mat[u][j]!=0 && mst[j]==false && mat[u][j]<key[j])
			{
				key[j]=mat[u][j];
				parent[j]=u;
			}
		}
	}
	cout << "Parent vector : ";
	for(i=0;i<parent.size();i++)
		cout << parent[i] << "   ";
	cout << endl;
	cout << "Key vector : ";
	for(i=0;i<key.size();i++)
		cout << key[i] << "   ";
	cout << endl;
	return;
}
int main()
{
	int i,j,row,p;
	vector< vector<int> > mat;
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
	prims(mat);
	return 0;
}

