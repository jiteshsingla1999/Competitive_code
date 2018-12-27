#include<bits/stdc++.h>
using namespace std;
bool check(int *arr, int i, int c, int n)
{
  int count=1;
  int start = arr[0];
  for(int j=1;j<n;j++)
  {
    int imm = arr[j];
    if(i<=(imm-start))
    {
   //   cout << "dif : " << imm-start << endl;
      count++;
      start = arr[j];
      
    }
  }
//  cout << "COUNT : " << count << endl;
  if(count>=c)
    return true;
  else
    return false;
  
}
int main() {

	// Write your code here
  int test;
  cin >> test;
  while(test--)
  {
    int n,c;
    cin >> n >> c;
    
    int * arr = new int[n];
    
    for(int i=0;i<n;i++)
      cin >> arr[i];
    sort(arr,arr+n);
    
    int max = arr[n-1]-arr[0];
    int result = 1; 
    int start = 1;
    int stop =  max;
    while(start!=stop)
    {
    	int mid = start + (stop-start)/2;
    //	cout << "mid : " << mid << endl;
    	if(mid==start)
    	mid=start+1;
      if(check(arr,mid,c,n)==true)
        start=mid;
      else
        stop=mid-1;
    }
    cout << start << endl;
    
  }
  
}
