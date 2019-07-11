#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define mk make_pair
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define inf 1e18
#define PI 3.14159265
using namespace std;
signed main()
{
	boost;
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		int arr[n], arr1[n], arr2[n];
		
		for(int i=0;i<n;i++)
		cin >> arr[i];
		
		arr1[0]=arr[0];arr2[n-1]=arr[n-1];
	//	cout << arr[0] << endl;
		for(int i=1;i<n;i++)
		{
			arr1[i] = arr1[i-1] + arr[i];
			arr2[n-i-1] = arr2[n-i] + arr[n-i-1];	
		}
	cout << endl;
		for(int i=0;i<n;i++)
		cout << arr1[i] << " ";
		cout << endl;
		for(int j=0;j<n;j++)
		cout << arr2[j] << " ";
		cout << endl;
		bool res=0;
		int i=1;
		for(;i<n-1;i++)
		{
			if(arr1[i-1]==arr2[i+1])
			{res=1;break;}
		}
		if(res)
		cout << i << endl;
		else
		cout << -1 << endl;
	}
	
}

