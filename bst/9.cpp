//Sorted order printing of a given array that represents a BST
#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int start, int end)
{
	if(start>end)
		return;
	print(arr,2*start+1,end);
	cout << arr[start] << " ";
	print(arr,2*start+2,end);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[] = {4, 2, 5, 1, 3};
	int size = 5;
	print(arr, 0, size-1);
	cout << endl;
	return 0;
}
