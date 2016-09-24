#include<bits/stdc++.h>
using namespace std;
typedef struct adjlistnode
{
	int src;
	adjlistnode *next;
}adjlistnode;
typedef struct adjlist
{
	adjlistnode *head;
}adjlist;
typedef struct graph
{
	int V;
	adjlist *array;
}graph;
graph * creategraph(int v)
{
	int i;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	g->V=v;
	g->array=(adjlist *)malloc(v*sizeof(adjlist));
	for(i=0;i<v;i++)
		g->array[i].head=NULL;
	return g;
}
adjlistnode * createnode(int des)
{
	adjlistnode *newnode=(adjlistnode *)malloc(sizeof(adjlistnode));
	newnode->src=des;
	newnode->next=NULL;
	return newnode;
}
void addedge(graph *&g, int src, int des)
{
	adjlistnode *newnode;
	newnode=createnode(des);
	newnode->next=g->array[src].head;
	g->array[src].head=newnode;
	
	adjlistnode *newnode1=createnode(src);
	newnode1->next=g->array[des].head;
	g->array[des].head=newnode1;

	return;
}
void printgraph(graph *g, int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		cout << "Vertex " << i << " : ";
		adjlistnode *temp;
		temp=g->array[i].head;
		while(temp!=NULL)
		{
			cout << temp->src << "  ";
			temp=temp->next;
		}
		cout << endl;
	}
	return;
}
int main()
{
	int v,src,des;
	graph *g;
	cout << "Enter the number of elements in a graph\n";
	cin >> v;
	g=creategraph(v);
	cout << "Enter the connections between these vertices and enter -1 to stop taking input\n";
	while(1)
	{
		cout << "Source	Destination\n";
		cin >> src >> des;
		if(src==-1 && des==-1)
			break;
		addedge(g,src,des);
	}
	printgraph(g,v);
	return 0;
}

