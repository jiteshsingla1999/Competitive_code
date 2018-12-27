#include<bits/stdc++.h>
using namespace std;
int arr[11][11];

bool check(int M, int m, int n)
{
	//cout << "Check 4 : m : "<< m << " n : " << n;
  for(int i=0;i<M;i++)
  {
    if(i==m)
      continue;
    if(arr[i][n]==1)
      return false;
  }
 // cout << "Check1\n";
  for(int j=0;j<M;j++)
  {
    if(j==n)
      continue;
    if(arr[m][j]==1)
      return false;
  }
  //cout << "Check2\n";
  int i=m;
  int j=n;
  i++;j++;
  while(i<M && j<M)
  {
    if(arr[i][j]==1)
      return false;
    i++;
    j++;
  }
  i=m;
  j=n;
  i--;j--;
  while(i>=0 && j>=0)
  {
    if(arr[i][j]==1)
      return false;
    i--;
    j--;
  }
  i=m;
  j=n;
  i--;
  j++;
  while(i>=0 && j<M)
  {
    if(arr[i][j]==1)
      return false;
    i--;
    j++;
  }
  i=m;j=n;
  i++;
  j--;
  while(i<M && j>=0)
  {
    if(arr[i][j]==1)
      return false;
    i++;
    j--;
  }
  
  //cout << " True\n"; 
  return true;
}
void printsol( int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      cout << arr[i][j] << " ";
  }
  cout << endl;

}
void placeNQueens(int n, int row)
{
  if(row==n)
  {
  //	cout << "Check3\n";
    printsol(n);
    return;
  }
  //cout << "Fdvf\n";
  for(int j=0;j<n;j++)
  {
  	
    if(check(n,row,j)==true)
    {
      arr[row][j]=1;
     // cout << "j : " << j << endl;
      placeNQueens(n,row+1);
      arr[row][j]=0;
    }
  }
}


void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  memset(arr,0,11*11*sizeof(int));  
  placeNQueens(n,0);
    


}
int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}



