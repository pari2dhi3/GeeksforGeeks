#include<bits/stdc++.h>
using namespace std;
void ss(int a[], int size, int index)
{
	if(index==(size-1))
		return;
	int min=INT_MAX,indx=-1,temp,i;
	for(i=index;i<size;i++)
	{	
		if(a[i]<min)
		{
			min=a[i];
			indx=i;
		}
	}
	temp=a[index];
	a[index]=a[indx];
	a[indx]=temp;
	ss(a,size,index+1);
	return;
}
int main()
{
	int arr[]={64, 25, 12, 22, 11};
	int size=(sizeof(arr)/sizeof(arr[0]));
	int i;
	ss(arr, size, 0);
	for(i=0;i<size;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
