#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int l, int m, int r)
{
	int n1,n2,i,n,j,k;
	n1=m-l+1;
	n2=r-m;
	vector<int> L(n1,0), R(n2,0);
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
	for(i=0;i<n2;i++)
		R[i]=a[m+1+i];
	i=0;
	j=0;
	k=0;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			a[l+k]=L[i];
			i++;
			k++;
		}
		else
		{
			a[l+k]=R[j];
			j++;
			k++;
		}
	}
	if(i>=n1)
	{
		while(j!=n2)
		{
			a[l+k]=R[j];
			k++;
			j++;
		}
	}
	else if(j>=n2)
	{
		while(i!=n1)
		{
			a[l+k]=L[i];
			i++;
			k++;
		}
	}
}
void mergesort(vector<int> &a, int l, int r)
{
	int m;
	if(l<r)
	{
		m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void print(vector<int> &a, int s)
{
	int i;
	for(i=0;i<=s;i++)
		cout << a[i]<< " ";
	cout << "\n";
}
int main()
{
	int i,size,p;
	cout << "enter size\n";
	cin >> size;
	vector<int> a(0,size);
	cout << "enter array\n";
	for(i=0;i<size;i++)
	{
		cin >> p;
		a.push_back(p);
	}
	mergesort(a,0,size-1);
	print(a,size-1);
	return 0;
}
