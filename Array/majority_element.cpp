#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define mk make_pair
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define inf 1e18
#define PI 3.14159265
using namespace std;
int arr[1000001];
signed main()
{
	boost;
	int test;
	cin >> test;

	
	while(test--)
	{
		int n,temp;
		memset(arr,0, sizeof(arr));
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> temp;
			arr[temp]++;
						
		}
		temp=-1;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>n/2)
			{
				temp=i;
				break;
			}
		}
		cout << temp << endl;
	}
	
	
}

