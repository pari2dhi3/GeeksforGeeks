#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int i,l,r,max,sum,n;
	cin >> n;
	vector <int> c(n,0);
	for(i=0;i<n;i++)
		cin >> c[i];
	sum=accumulate(c.begin(), c.end(), 0);
	max=sum;
	l=0;
	r=c.size()-1;
	for(i=0;i<c.size();i++)
	{
		if(c[l]<c[r])
		{
			sum-=c[l];
			l++;
		}
		else
		{
			sum-=c[r];
			r--;
		}
		if(sum>max)
			max=sum;
	}
	cout << max << endl;
	return 0;
}
		

	
