#include<bits/stdc++.h>
using namespace std;
void add_edge(list<int> adj[], int m, int n)
{
	adj[m].push_back(n);
}
void dfs_util(bool * visited, list<int> adj[], int n);
void dfs(list<int> adj[],int size, int n)
{
	
	bool * visited = new bool[size];
	for(int i=0;i<size;i++)
	visited[i]=false;
	dfs_util(visited,adj,n);
	
	
}
void dfs_util(bool * visited, list<int> adj[], int n)
{
	visited[n]=true;
	cout << n << "-->";
	list<int>:: iterator i;
	for(i=adj[n].begin();i!=adj[n].end();++i)
	{
		if(!visited[*i])
		dfs_util(visited,adj,*i);
	}
}
void bfs_util(list<int> adj[], bool * visited, queue<int> ss);
void bfs(list<int> adj[], int n, int size)
{
	bool * visited = new bool[size];
	
	for(int i=0;i<size;i++)
	visited[i]=false;
	queue<int> ss;
	ss.push(n);
	bfs_util(adj,visited,ss);
	 
}
void bfs_util(list<int> adj[], bool * visited, queue<int> ss)
{
	while(!ss.empty())
	{int n = ss.front();
	ss.pop();
	cout << n << "-->";
	if(visited[n]==false)
	{
		visited[n]=true;
	list<int>:: iterator i;
	
	for(i=adj[n].begin();i!=adj[n].end();++i)
	ss.push(*i);
}}
	
}
int main()
{
	int V=5;
	list<int> adj[V];
	add_edge(adj,1,2);
	dfs(adj,2,2);
	cout << endl;
	bfs(adj,1,2);
}

