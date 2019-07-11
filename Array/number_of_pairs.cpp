#include <bits/stdc++.h>
using namespace std;
int binary_search(int *arr, int start, int stop, int num)
{
    if(start==stop)
    return start+1;
    if(start>stop)
    return 0;
    
    int mid = start + (stop-start)/2;
    if(mid==start)
    return start;
    if(pow(num,arr[mid]) > pow(arr[mid], num))
    return binary_search(arr, mid, stop, num);
    else
    return binary_search(arr, start, mid-1, num);
}
int func(int *arr1, int n, int * arr2, int m)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int num = arr1[i];
        int pos = binary_search(arr2, 0, m-1, num);
        cout << pos << endl;
        count+=pos;
    }
    return count;
}
int main() {
	//code
	int test;
	cin >> test;
	while(test--)
	{
	    int n,m;
	    cin >> n >> m;
	    int arr1[n],arr2[m];
	    for(int i=0;i<n;i++)
	    cin >> arr1[i];
	    for(int i=0;i<m;i++)
	    cin >> arr2[i];
	    
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+n);
	    cout << func(arr1, n, arr2, m);
	   
	}
	return 0;
}
