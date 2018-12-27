#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long countt=0;
void merge_util(int A[], int start, int mid, int stop)
{
	//cout << "count : " << countt  << endl;
	//cout << "start : " << start  << endl;
	//cout << "mid : " << mid  << endl;
	//cout << "stop : " << stop  << endl;
  int n1 = mid-start+1;
  int n2 = stop-mid;
  //cout << "n1 : " << n1 << endl;
  //cout << "n2 : " << n2 << endl;
  
  int *arr1  = new int[n1];
  int *arr2 = new int[n2];
  for(int i=0;i<n1;i++)
    arr1[i] = A[i+start];
  for(int j=0;j<n2;j++)
    arr2[j] = A[j+mid+1];
  //cout << "cdsc\n";
  int i=0,j=0;
  int k = start;
  while(i<n1 && j<n2)
  {
    if(arr1[i]<=arr2[j])
      A[k++] = arr1[i++];
    else
    {
      countt+=(n1-i);
      A[k++]= arr2[j++];
    }
      
  }
  //cout << "cdsc\n";
  while(i<n1)
  {
   A[k++] =arr1[i++];
  }
  while(j<n2)
  {
    A[k++] = arr2[j++];
  }
 // cout << "cdsc\n";
  
  //	cout << "count : " << countt  << endl;
}
void merge_sort_util(int A[], int start, int stop)
{
  if(start<stop)
  {
    int mid = start + (stop-start)/2;
   // cout << "mid : " << mid << endl;
    merge_sort_util(A, start,mid);
    merge_sort_util(A, mid+1, stop);
    merge_util(A,start,mid,stop);
    //cout << "Done\n";
  }
}

long long solve(int A[], int n)
{
  merge_sort_util(A,0,n-1);
  return countt;
}

int main()
{
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}
