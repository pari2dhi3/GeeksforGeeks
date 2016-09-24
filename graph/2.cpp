#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v1,v2,i,edges,vertices;
	cout << "enter number of vertices\n";
	cin >> vertices;
	cout << "enter the number of edges\n";
	cin >> edges;
	vector< vector<int> > a(vertices+1);
	vector<bool> vis(vertices+1,0);
	cout << "enter the connections\n";
	for(i=0;i<edges;i++)
	{
		cin >> v1 >> v2;
		a[v1].push_back(v2);
	}
	cout << "Breadth First traversal of the graph is : ";
	for(i=0;i<vertices;i++)
	{
		vector<int>::iterator it=a[i].begin();
		while(it!=a[i].end())
		{
			if(vis[*it]!=1)
			{
				cout << *it << " ";
				vis[*it]=1;
			}
			it++;
		}
	}
	cout << endl;
	return 0;
}

