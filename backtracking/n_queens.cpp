#include<bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<int> > a, int row, int col, int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(a[i][col]==1)
			return false;
	}
	i=row;
	j=col;
	while(i>=0 && j>=0)
	{
		if(a[i][j]==1)
			return false;
		i--;
		j--;
	}
	i=row;
	j=col;
	while(i<n && j<n)
	{
		if(a[i][j]==1)
			return false;
		i++;
		j++;
	}
	i=row;
	j=col;
	while(i>=0 && j<n)
	{
		if(a[i][j]==1)
			return false;
		i--;
		j++;
	}
	i=row;
	j=col;
	while(i<n && j>=0)
	{
		if(a[i][j]==1)
			return false;
		i++;
		j--;
	}
	return true;
}
int place_queen(vector<vector<int> > &a, int row, int n)
{
	int col;
	int flag=0;
	if(row<n)
	{
		for(col=0;col<n;col++)
		{
			if(is_safe(a,row,col,n))
			{
				a[row][col]=1;
				flag=place_queen(a,row+1,n);
				if(flag==0)
					a[row][col]=0;
				if(flag==1)
					return 1;
			}
		}
		return 0;
	}
	else
		return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,i,j,ans;
	cout << "ENTER THE VALUE OF N\n";
	cin >> n;
	vector< vector<int> > a (n,vector<int>(n));
	ans=place_queen(a,0,n);
	if(ans)
	{
		cout << "The matrix is : " << endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	else
		cout << "cannot place " << n << " queens on a board" << endl;
	return 0;
}
