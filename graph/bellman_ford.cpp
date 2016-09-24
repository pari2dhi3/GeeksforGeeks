#include<bits/stdc++.h>
using namespace std;
void bellman(vector<int> &src, vector<int> &dest, vector<int> &weight, vector<int> parent, int source, int v, int e)
{
	int i,j;
	vector<int> dist(v,INT_MAX);
	dist[source]=0;
	for(i=1;i<=v-1;i++)
	{
		for(j=0;j<e;j++)
		{
			if(dist[src[j]]!=INT_MAX && dist[src[j]]+weight[j]<dist[dest[j]])
			{
				dist[dest[j]]=dist[src[j]]+weight[j];
				parent[dest[j]]=src[j];
			}
		}
	}
	for(j=0;j<e;j++)
	{
		if(dist[src[j]]!=INT_MAX && dist[src[j]]+weight[j]<dist[dest[j]])
		{
			cout << "Graph has negative cycle\n";
		}
	}
	for(i=0;i<v;i++)
		cout << dist[i] << "  ";
	cout << endl;
	return;
}
int main()
{
	int i,v,s,d,w,source,n,e;
	cout << "Enter number of vertices in a graph.\n";
	cin >> v;
	cout << "Enter number of edges in a graph.\n";
	cin >> e;
	vector<int> src;
	vector<int> dest;
	vector<int> weight;
	vector<int> parent(v,-1);
	cout << "Enter source, destination and weight\n";
	for(i=0;i<e;i++)
	{
		cin >> s >> d >> w;
		src.push_back(s);
		dest.push_back(d);
		weight.push_back(w);
	}
	cout << "Enter the source.\n";
	cin >> source;
	bellman(src,dest,weight,parent,source,v,e);
	return 0;
}
