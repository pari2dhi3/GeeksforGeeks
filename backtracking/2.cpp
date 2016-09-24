//Backtracking | Set 1 (The Knight’s tour problem)
#include<bits/stdc++.h>
using namespace std;
bool is_solve(vector<vector<int> > &a, int x, int y, int n)
{
	if(x>=0 && x<n && y>=0 && y<n && a[x][y]==-1)
		return true;
	else
		return false;
}
bool knight(int n, vector<vector<int> > &a, int count, int x, int y)
{
	int i,c,r;
	if(count==(n*n))
		return true;
	int X[8]={2,1,-1,-2,-2,-1,1,2};
	int Y[8]={1,2,2,1,-1,-2,-2,-1};
	for(i=0;i<8;i++)
	{
		r=x+X[i];
		c=y+Y[i];
		if(is_solve(a,r,c,n))
		{
			a[r][c]=count;
			if(knight(n,a,count+1,r,c))
				return true;
			else
			{
				a[r][c]=-1;
			}
		}
	}
	return false;
}
void printvector(vector<vector<int> > &a)
{
	int i,j,n;
	n=a.size();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,i,j;
	cin >> n;
	vector< vector<int> > a (n,vector<int>((n),-1));
	int count=1, x=0, y=0;
	a[0][0]=0;
	if(knight(n,a,count,x,y))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	}
	else
		cout << "It cannot be possible\n";
	return 0;
}
