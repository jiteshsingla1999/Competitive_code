#include<bits/stdc++.h>
using namespace std;

int find_box(int x)
{
  if(x<=2)
    return 0;
  else if(x<=5)
    return 3;
  else if(x<=8)
    return 6;
}


bool check(int board[][9], int size, int x , int y, int num)
{
	
	  for(int j=0;j<9;j++)
      {
        if(j==x)
          continue;
        if(board[j][y]==num)
          return false;
      }
      for(int j=0;j<9;j++)
      {
        if(j==y)
          continue;
        if(board[x][j]==num)
          return false;
      }
  	  int box_start_x = find_box(x);
      int box_start_y = find_box(y);
  
  	  for(int i=0;i<3;i++)
      {
      	for(int j=0;j<3;j++)
      	{
        	if(i==x && j==y)
          		continue;
        	if(board[box_start_x + i][box_start_y+j]==num)
          		return false;
        }
      }
  cout << "num : " << num << endl;
  return true;
}
bool sudokuSolver_util(int board[][9], int size, int x, int y)
{
	cout << "x : " << x << " y : " << y <<  endl;
  if(board[x][y]!=0)
  {
    if(y==9)
    {
      if(x==9)
        return true;
      else
        return sudokuSolver_util(board, size, x+1, y);
    }
    else
      return sudokuSolver_util(board, size, x, y+1);
  }
  else
  {
    int i=1;
    bool iter = true;
    while(iter)
    {
    	if(i>=10)
    	return false;
        bool temp = check(board, size, x, y, i);
        if(temp==true)
        {
      	    board[x][y]=i;
        	if(y==8)
        	{
          		if(x==8)
          		{
          			cout << "Done\n";
            		return true;
          		}
          		else
          		{
            		bool ff =  sudokuSolver_util(board, size, x+1, 0);
                  	if(ff==false && i==9)
                      {
					  	board[x][y]=0;
					    return false;
					  }
                    else if(ff==true)
                    	return ff;
          		}
        	}
        	else
        		{
          			bool ff =  sudokuSolver_util(board, size, x, y+1);
              		if(ff==true)
                      return true;
        		}
      }
      board[x][y]=0;
      i++;
    }
  }
}
bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
	sudokuSolver_util(board, 9, 0, 0);

}
int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}



