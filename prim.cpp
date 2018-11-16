#include<bits/stdc++.h>
using namespace std;
const int v=5;
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX;
	int minindex;
	
	for(int qq=0;qq<v;qq++)
	{
		if(mstSet[qq]==false && key[qq]<min)
		{
			min=key[qq];minindex=qq;
		}
	}
	return minindex;
}
void primMST(int graph[v][v])
{
	int parent[v],key[v];
	bool mstSet[v];
	
	for (int i = 0; i < v; i++) 
        key[i] = INT_MAX, mstSet[i] = false;
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<v-1;count++)
	{
		int u = minKey(key,mstSet);
		mstSet[u] = true;
	//	cout << u << endl;
	for(int i=0;i<v;i++)
	{
		if(graph[u][i] && mstSet[i]==false && graph[u][i]<key[i])
		{parent[i]=u;key[i]=graph[u][i]; }
	}
	
	

}
	printf("Edge \tWeight\n");
	for(int i=1;i<v;i++)
	{
		printf("%d - %d \t%d \n", parent[i],i, graph[i][parent[i]]);
	}


}


int main() 
{ 
/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | /     \ | 
    (3)-------(4) 
            9         */
int graph[v][v] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}}; 
  primMST(graph);
    
    
}
