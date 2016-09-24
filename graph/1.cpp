//Graph and its representations
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int total,v1,v2,i,edges,vertices;
	cout << "enter number of vertices\n";
	cin >> vertices;
	cout << "enter the number of edges\n";
	cin >> edges;
	vector< vector<int> > a(vertices+1);
	for(i=0;i<edges;i++)
	{
		cin >> v1 >> v2;
		a[v1].push_back(v2);
		a[v2].push_back(v1);
	}
	cout << "the graph is : \n";
	for(i=0;i<vertices;i++)
	{
		cout << i << " node is connected to : ";
		vector<int>::iterator it=a[i].begin();
		while(it!=a[i].end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	return 0;
}

