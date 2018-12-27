#include<bits/stdc++.h>
using namespace std;
void printsol(int maze[][20], int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    	if(maze[i][j]==-1)
      		cout << 1 << " ";
      	else
      		cout << 0 << " ";
  }
  cout << endl;
}
void ratInMaze_util(int maze[][20], int n, int x, int y)
{
  //cout << "x : " << x << " y : " << y << endl;
  if(x==n-1 && y==n-1)
  {printsol(maze,n);
  	return;}
  
  int newx = x-1;
  int newy = y-1;
  //UP
  if(newx>=0 && newx<n && maze[newx][y]>0)
  {
  	maze[newx][y]=-1;
    ratInMaze_util(maze, n, newx, y);
	maze[newx][y]=1;
  }
  
  newx = x+1;
  //DOWN
  if(newx>=0 && newx<n && maze[newx][y]>0)
  {
  	maze[newx][y]=-1;
    ratInMaze_util(maze, n, newx, y);
	maze[newx][y]=1;
  }
  //LEFT
  
  if(newy>=0 && newy<n && maze[x][newy]>0)
  {
  	maze[x][newy]=-1;
    ratInMaze_util(maze, n, x, newy);
    maze[x][newy]=1;
  }
  
  newy = y+1;
  
  //RIGHT
  //cout << "Check1\n";
  if(newy>=0 && newy<n && maze[x][newy]>0)
  {
  	maze[x][newy]=-1;
    ratInMaze_util(maze, n, x, newy);
    maze[x][newy]=1;
  }
  
  return;
  
}
void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  	int x,y;
  	x=0;
  	y=0;
  	maze[0][0]=-1;
 	ratInMaze_util(maze, n, x,y);
      

}
int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}



