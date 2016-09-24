#include<bits/stdc++.h>
using namespace std;
int bs(int a[], int l, int r, int key)
{
	int index;
	if(l>r)
		return -1;
	index=(l+r)/2;
	if(a[index]==key)
		return index;
	if(a[index]>key)
	{
		r=index-1;
		return bs(a,l,r,key);
	}
	if(a[index]<key)
	{
		l=index+1;
		return bs(a,l,r,key);
	}
}
int main()
{
	int a[10]={1,3,5,7,9,11,13,15,17,19};
	int i,size,ans,key;
	size=(sizeof(a)/sizeof(a[0]));
	cin >> key;
	ans=bs(a,0,size-1,key);
	if(ans==-1)
		cout << "NOT FOUND\n";
	else
		cout << "FOUND AT INDEX : " << ans+1 << endl;
	return 0;
}

