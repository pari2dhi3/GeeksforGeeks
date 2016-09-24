#include<bits/stdc++.h>
using namespace std;
int arr[50];
queue <int> q0;
queue <int> q1;
queue <int> q2;
int compare (const void * a, const void * b)
{
	  return ( *(int*)b - *(int*)a );
}
int multiple_of_three(int size)
{
	int flag1, flag2, i, sum;
	flag1=0;
	flag2=0;
	sum=0;
	cout << "ENTER THE NUMBER\n";
	for(i=0;i<size;i++)
	{
		cin >> arr[i];
		sum=sum+arr[i];
		if(arr[i]%3==0)
			q0.push(arr[i]);
		else if(arr[i]%3==1)
			q1.push(arr[i]);
		else if(arr[i]%3==2)
			q2.push(arr[i]);
	}
	i=0;
	if(sum%3==0)
	{
		while(!q0.empty())
		{
			arr[i]=q0.front();
			q0.pop();
			i++;
		}
		while(!q1.empty())
		{

			arr[i]=q1.front();
			q1.pop();
			i++;
		}
		while(!q2.empty())
		{
			arr[i]=q2.front();
			q2.pop();
			i++;
		}
		qsort(arr, size, sizeof(int), compare);
		flag1=0;
		return(flag1);
	}
	else if(sum%3==1)
	{
		while(!q0.empty())
		{
			arr[i]=q0.front();
			q0.pop();
			i++;
		}
		if(!q1.empty())
		{
			q1.pop();
			while(!q1.empty())
			{
				arr[i]=q1.front();
				q1.pop();
				i++;
			}
		}
		else
		{
			flag1=1;
		}
		if(flag1==1)
		{
			if(q2.size()>=2)
			{
				q2.pop();
				q2.pop();
			}
			if(q2.empty())
				flag2=1;
		}
		while(!q2.empty())
		{
			arr[i]=q2.front();
			q2.pop();
			i++;
		}
		if(flag1==1 && flag2==1)
			flag1=-1;
		else if(flag1==0 && flag2==0)
		{
			qsort(arr, size-1, sizeof(int), compare);
			flag1=1;
		}
		else if(flag1==1 && flag2==0)
		{
			qsort(arr, size-2, sizeof(int), compare);
			flag1=2;
		}
		return(flag1);
	}
	else if(sum%3==2)
	{
		while(!q0.empty())
		{
			arr[i]=q0.front();
			q0.pop();
			i++;
		}
		if(!q2.empty())
		{
			q2.pop();
			while(!q2.empty())
			{
				arr[i]=q2.front();
				q2.pop();
				i++;
			}
		}
		else
			flag1=1;
		if(flag1==1)
		{
			if(q1.size()>=2)
			{
				q1.pop();
				q1.pop();
			}
			if(q1.empty())
				flag2=1;
		}
		while(!q1.empty())
		{
			arr[i]=q1.front();
			q1.pop();
			i++;
		}
		if(flag1==1 && flag2==1)
			flag1=-1;
		else if(flag1==0 && flag2==0)
		{
			qsort(arr, size-1, sizeof(int), compare);	
			flag1=1;
		}
		else if(flag1==1 && flag2==0)
		{
			qsort(arr, size-2, sizeof(int), compare);
			flag1=2;
		}
		return(flag1);
	}
}
int fxn2(int size)
{
	int i,count,ind,sum;
	i=0;
	count=0;
	ind=1;
	sum=0;
	while((count!=size)&&(ind!=size+1))
	{
		if(sum+arr[i]>=0)
		{
			sum=sum+arr[i];
			count++;
			i++;
		}
		else if(sum+arr[i]<0)
		{
			sum=0;
			count=0;
			ind++;
			i++;
		}
	}
	if((count==size)&&(ind!=size+1))
		return ind;
	else
		return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int i,size,w;
	cout << "PRESS 0 TO TERMINATE THIS PROGRAM\n";
	cout << "PRESS 1 TO FIND THE LARGEST MULTIPLE OF 3 FROM THE ENTERED NUMBER\n";
	cout << "PRESS 2 TO FIND THE FIRST CIRCULAR TOUR THAT VISITS ALL THE PETROL PUMPS\n";
	while(true)
	{
		cin >> i;
		if(i==1)
		{
			cout << "ENTER THE SIZE OF THE NUMBERS\n";
			cin >> size;
			w=multiple_of_three(size);
			if(w==-1)
				cout << "NOT POSSIBLE\n";
			else
			{
				if(w==0)
					w=size;	
				else if(w==1)
					w=size-1;
				else if(w==2)
					w=size-2;
				for(i=0;i<w;i++)
					cout << arr[i];
				cout << endl;
			}
		}
		if(i==2)
		{
			cout << "ENTER THE NUMBER OF PAIRS\n";
			cin >> size;
			cout << "ENTER THE PAIRS\n";
			for(i=0;i<size;i++)
			{
				cin >> a >> b;
				arr[i]=a-b;
			}
			w=fxn2(size);
			if(w==-1)
				cout << "NOT POSSIBLE\n";
			else
				cout << "START WITH INDEX " << w << endl;
		}
		if(i==0)
		{
			break;
		}
	}
	return 0;
}






