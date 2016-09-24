#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={12, 11, 13, 5, 6};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i,j=1;
	while(j!=size)
	{
		for(i=0;i<j;i++)
		{
			if(arr[j]<arr[i])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
		j++;
	}
	for(i=0;i<size;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}


