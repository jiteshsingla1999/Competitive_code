#include<bits/stdc++.h>
using namespace std;
int func(int * arr,  int n)
{
  for(int m=0;m<n;m++)
  {
    int temp1 = arr[m];
    int temp2 = arr[n-1];
    int diff = temp2-temp1;
    if(diff>temp1)
    {
      continue;
    }
    else
    {
      return temp1;
    }
  }
}
int main() {

	// Write your code here
  int test;
  cin >> test;
  while(test--)
  {
    int n,k;
    cin >> n >> k;
    int * arr  = new int[n];
    for(int i=0;i<n;i++)
      cin >> arr[i];
    
    sort(arr,arr+n);
    
    if(k<n)
    {
      int diff = n-k;
      cout << func(arr+(diff), k);
    }
    else if(n==k)
    {
      cout << func(arr,n);
    }
    else
    {
      
    }
  }
}
