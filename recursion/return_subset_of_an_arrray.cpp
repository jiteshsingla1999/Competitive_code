#include <iostream>
//#include "solution.h"
using namespace std;
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
int count=1;

int subset(int input[], int n, int output[][20]) {
    // Write your code here
  if(n==0)
    return count;
  for(int i=0;i<count;i++)
  {
    output[i+count][0] = output[i][0]+1;
    int j=1;
    for(;j<=output[i][0];j++)
      output[i+count][j] = output[i][j];
    output[i+count][j] = input[0];
  }
  count*=2;
  subset(input+1,n-1,output);
  return count;
    

}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

