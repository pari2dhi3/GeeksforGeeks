#include<bits/stdc++.h>
using namespace std;
void quicksort(int a[], int pivot, int l, int r)
{
	int divider=l-1;
	int i;
	int temp;
	if(r<=l)
		return;
	for(i=l;i<r;i++)
	{
		if(a[i]<pivot)
		{
			if(i==divider+1)
				divider++;
			else if(i!=(divider+1))
			{
				temp=a[i];
				a[i]=a[divider+1];
				a[divider+1]=temp;
				divider++;
			}
		}
	}
	temp=a[i];
	a[i]=a[divider+1];
	a[divider+1]=temp;
	divider++;
	quicksort(a,a[divider-1],l,divider-1);
	quicksort(a,a[r],divider+1,r);
	return;
}
int main()
{
	int a[]={10, 7, 8, 9, 1, 5};
	int size=sizeof(a)/sizeof(a[0]);
	int pivot=a[(size-1)];
	int i;
	quicksort(a,pivot,0,(size-1));
	for(i=0;i<size;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
	
