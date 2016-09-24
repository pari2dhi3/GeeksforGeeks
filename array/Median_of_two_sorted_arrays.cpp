#include<bits/stdc++.h>
using namespace std;
int median(vector<int>& arr, int n)
{
	if(n%2==0)
		return (arr[n/2-1]+arr[n/2])/2;
	return arr[n/2];
}
int getmedian(vector<int>& arr1, vector<int>& arr2, int n)
{
	int m1,m2;
	if(n==1)
		return (arr1[0]+arr2[0])/2;
	if(n==2)
		return (max(arr1[0]+arr2[0])+min(arr1[1]+arr2[1]))/2;
	m1=median(arr1,n);
	m2=median(arr2,n);
	if(m1==m2)
		return m1;
	if(m1<m2)
	{
		if(n%2==0)
			return getmedian(arr1+n/2-1,arr2,n-(n/2)+1);
		return getmedian(arr1+n/2,arr2,n-(n/2));
	}
	if(n%2==0)
		return getmedian(arr2+(n/2)-1,arr1,n-(n/2)+1);
	return getmedian(arr2+n/2,arr1,n-(n/2));
}
int main()
{
	int n,a,i,ans;
	cin >> n;
	vector<int> arr1(n,0);
	vector<int> arr2(n,0);

	for(i=0;i<n;i++)
	{
		cin >> a;
		arr1.push_back(a);
	}
	for(i=0;i<n;i++)
	{
		cin >> a;
		arr2.push_back(a);
	}
	ans=getmedian(arr1,arr2,n);
	cout << ans << endl;
	return 0;
}
