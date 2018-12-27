#include<bits/stdc++.h>
using namespace std;
bool func(long long int * arr, long long int n, long long int num, long long int k)
{
  long long int count=k;
  long long int temp=0;
  long long int i=0;
  for(i=0;i<n;i++)
  {
    long long int quot = arr[i]/num;
    count-=quot;
    if(count<=0)
      break;   
    
  }
//  cout << "count : " << count << endl;
  if(count<=0)
    return true;
  else
      return false;
}

int main() {

	// Write your code here
  long long int test;
  cin >> test;
  while(test--)
  {
    long long int n,k;
    cin >> n >> k;
    long long int * arr  = new long long int[n];
    for(long long int i=0;i<n;i++)
      cin >> arr[i];
    
    sort(arr,arr+n);
    
    long long int min = arr[0];
    long long int max = arr[n-1];
    while(min!=max)
    {
      long long int num = (min+max)/2;
      if(num==min)
        num++;
   //   cout << "num : " << num << endl;
      bool b = func(arr,n, num ,k );
      if(b==true)
        min = num;
      else
        max=num-1;
    //  cout << "b : " << b << endl;
      
    }
    cout << min << endl;
  }
}
