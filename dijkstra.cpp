#include<bits/stdc++.h>
using namespace std;
const int v=9;
int min_dist(int dist[], bool included[])
{
	int min=INT_MAX;
	int min_index;
	for(int i=0;i<v;i++)
	{
		if(included[i]==false && dist[i]<min)
		{min=dist[i];min_index=i;}
	}
	return min_index;
}
void dijkstra(int graph[v][v], int n)
{
	int dist[v];
	bool included[v];
	for(int i=0;i<v;i++)
	{included[i]=false;dist[i]=INT_MAX;}
	
	dist[n]=0;
	
	for(int count=1;count<v;count++)
	{
		int u = min_dist(dist,included);
		cout << u << endl;
		included[u]=true;
		for(int i=0;i<v;i++)
		{
			
			if(graph[u][i] && dist[u] + graph[u][i]<dist[i])
			dist[i] = dist[u] + graph[u][i];
		}
	}	
	cout << "Shortest distanve of all vertices from " << n << " is\n";
	for(int i=0;i<v;i++)
	cout << "vertex - " << i << " distance - " << dist[i] <<endl;
}
int main()
{
	 int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(graph, 0); 
}
