
#include <iostream>
#include <vector>
///#include "solution.h"
using namespace std;
int partition(vector<int> &arr,int start, int stop)
  {
    int pivot = arr[start];
    int i=start+1;
    int j=i;
    while(j<stop)
    {
      if(arr[j]>pivot)
        {j++;}
      else
      {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j++;i++;
      }
    }
    
    int temp = arr[i-1];
    arr[i-1]=arr[start];
    arr[start] = temp;
    
    return i-1;
    
  }
  int quicksort(vector<int> &arr, int start, int stop, int k)
  {
    int pi = partition(arr,start,stop);
    //cout << pi << "  " << stop - k  << endl;
    //cout << endl;
  //  for(int i=0;i<6;i++)
  //  cout << arr[i] << "  ";
 //   cout << endl;
    if(pi==stop-k)
    {
      return arr[pi];
    }
    else if(pi<stop-k)
    {
      return quicksort(arr,pi+1,stop,k);
    }
    else
    {
      return quicksort(arr,0,pi,k-(stop-pi));
    }
  }
int kthLargest (vector<int> &arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  
  
  return quicksort(arr,0,n,k);
    
}

int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}
