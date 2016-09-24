#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m,  int r)
{
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	int i,j,k;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)	
		L[i]=a[l+i];
	for(i=0;i<n2;i++)
		R[i]=a[m+1+i];
	i=0;
	j=0;
	k=0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else if(L[i]>R[j])
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
	return;
}
void merge_sort(int a[], int l, int r)
{
	int m;
	if(l<r)
	{
		m=l+(r-l)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
	}
	return;
}
int main()
{
	int a[]={38,27,43,3,9,82,10};
	int size=sizeof(a)/sizeof(a[0]);
	int i;
	merge_sort(a,0,size-1);
	for(i=0;i<size;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
