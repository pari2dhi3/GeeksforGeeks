#include<bits/stdc++.h>
using namespace std;
int fact(int val)
{
	int x=1,i;
	for(i=1;i<=val;i++)
	{
		x=x*i;
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,w;
	cin >> n;
	w=(fact(2*n)/(fact(n+1)*fact(n)));
	cout << w << endl;
	return 0;
}

