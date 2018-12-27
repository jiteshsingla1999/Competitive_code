#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long countt=0;
void merge_util(int A[], int start, int mid, int stop)
{
  int n1 = mid-start+1;
  int n2 = stop-mid;
  int * arr3 = new int[1000000];
  
  int *arr1  = new int[n1];
  int *arr2 = new int[n2];
  for(int i=0;i<n1;i++)
    arr1[i] = A[i+start];
  for(int j=0;j<n2;j++)
    arr2[j] = A[j+mid+1];
  int i=0,j=0;
  int k = start;
  while(i<n1 && j<n2)
  {
    if(arr1[i]<arr2[j])
    {
      countt+=(arr1[i]*(n2-j));
      arr3[k++] = arr1[i++];
    }
    else
    {
      arr3[k++]= arr2[j++];
    }
      
  }
  while(i<n1)
  {
   arr3[k++] =arr1[i++];
  }
  while(j<n2)
  {
    arr3[k++] = arr2[j++];
  }
}
void merge_sort_util(int A[], int start, int stop)
{
  if(start<stop)
  {
    int mid = start + (stop-start)/2;
    merge_sort_util(A, start,mid);
    merge_sort_util(A, mid+1, stop);
    merge_util(A,start,mid,stop);
  }
}

long long solve(int A[], int n)
{
  merge_sort_util(A,0,n-1);
  return countt;
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		countt=0;
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}
}
