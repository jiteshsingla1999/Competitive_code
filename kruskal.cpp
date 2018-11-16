#include<bits/stdc++.h>
using namespace std;
class edge
{
	public:
		int source, destination,weight;
		
};
class subset
{
	public:
	int parent, rank;
};
int find(subset subsets[], int i)
{
	if(subsets[i].parent!=i)
	subsets[i].parent = find(subsets, subsets[i].parent);
	
	return subsets[i].parent;
}
void Union(subset subsets[], int x, int y)
{
	int xroot= find(subsets, x);
	int yroot = find(subsets,y);
	
	if(subsets[xroot].rank < subsets[yroot].rank)
	subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank>subsets[yroot].rank)
	subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
int myComp(const void *a, const void *b)
{
	edge *a1 = (edge *)a;
	edge *b1 = (edge *)b;
	return a1->weight >b1->weight;
}
class Graph
{
	public:
	int V,E;
	edge * list_edge;
	
		Graph(int V, int E)
		{
		this->V=V;	
		list_edge = new edge[E];
		}
		
	void add_edge(int a, int b, int weight)
	{
		list_edge[a].source=a;
		list_edge[a].destination = b;
		list_edge[a].weight=weight;
	}
	
	
	
	
	
};
void KruskalMST(Graph * graph)
	{
		int V = graph->V;
		edge result[V];
		int e=0,i=0;
		for(int i=0;i<V;i++)
		cout << graph->list_edge[i].weight << endl;
		qsort(graph->list_edge, graph->E, sizeof(graph->list_edge[0]), myComp);
		
		for(int i=0;i<V;i++)
		cout << graph->list_edge[i].weight << endl;
		subset subsets[V];
		for(int v=0;v<V;v++)
		{
			subsets[v].parent = v;
			subsets[v].rank = 0;
		}
		
		while(e<V-1)
		{
			edge next_edge = graph->list_edge[i++];
			
			int x = find(subsets, next_edge.source);
			int y = find(subsets, next_edge.destination);
			
			if(x!=y)
			{
				result[e++]=next_edge;
				Union(subsets, x, y);
			}
		}
		printf("Following are the edges in the constructed MST\n");
		for(int i=0;i<e;i++)
		printf("%d -- %d == %d\n", result[i].source, result[i].destination, result[i].weight);

	return;

	}
int main()
{
int V = 4;  // Number of vertices in graph 
    int E = 5;  // Number of edges in graph 
	Graph* graph = new Graph(V, E); 
  
  
    // add edge 0-1 
    graph->list_edge[0].source = 0; 
    graph->list_edge[0].destination = 1; 
    graph->list_edge[0].weight = 10; 
  
    // add list_edge 0-2 
    graph->list_edge[1].source = 0; 
    graph->list_edge[1].destination = 2; 
    graph->list_edge[1].weight = 6; 
  
    // add list_edge 0-3 
    graph->list_edge[2].source = 1; 
    graph->list_edge[2].destination = 2; 
    graph->list_edge[2].weight = 5; 
  
    // add list_edge 1-3 
    graph->list_edge[3].source = 1; 
    graph->list_edge[3].destination = 3; 
    graph->list_edge[3].weight = 1; 
  
    // add list_edge 2-3 
    graph->list_edge[4].source = 2; 
    graph->list_edge[4].destination = 3; 
    graph->list_edge[4].weight = 2; 
  
    KruskalMST(graph); 
  
    return 0; 
} 

