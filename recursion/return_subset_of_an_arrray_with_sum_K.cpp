/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<queue>
#include<iostream>
using namespace std;
int count=0;
int subsetSumToK_util(int input[], int n, int output[][50], int k, queue<int> ss)
{
  if(k==0)
  {
    int l=1;
    while(!ss.empty())
    {
     // cout << "front : " << ss.front() << endl;
        output[count][l++] = ss.front();
     	ss.pop();
    }
   // cout << "Done\n";
    output[count][0] = l-1;
    count++;
    return 1;
  }
  else if(n>0)
  {
  	if(input[0]<=k)
  	{
      	//cout << "\nFdf\n";
    	int temp1 = subsetSumToK_util(input+1,n-1,output,k,ss);
      	ss.push(input[0]);
      //	cout << ss.front() << endl;
      	int temp2 = subsetSumToK_util(input+1,n-1,output,k-input[0],ss);
      	return temp1 + temp2;
 	}
  	else
    	return subsetSumToK_util(input+1,n-1,output,k,ss);
  
  }
  return 0;
}



int subsetSumToK(int input[], int n, int output[][50], int k) {
	queue<int> ss;
	return subsetSumToK_util(input, n, output, k, ss);
   
}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

  




