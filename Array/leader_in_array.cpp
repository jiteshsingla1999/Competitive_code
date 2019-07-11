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
		int arr[n];
		for(int i=0;i<n;i++)
		cin >> arr[i];
		vector<int> store;
		int mm = arr[n-1];
		store.pb(mm);
		for(int i=n-2;i>=0;i--)
		{
			if(mm<arr[i])
			{
				store.pb(arr[i]);
				mm = arr[i];
			}
		}
		for(int i=store.size()-1;i>=0;i--)
		cout << store[i] << " ";
		
		cout << endl;
	}
	
}

