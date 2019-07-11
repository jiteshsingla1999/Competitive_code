#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	while(test--)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin >> arr[i];
	    int min_index = 0;
	    int max_index = n-1;
	    int max_val = arr[n-1]+1;
	   
	    for(int i=0;i<n;i++)
	    {
	        if(i%2==1)
	        {
	            arr[i]+=((arr[min_index]%max_val)*max_val);
	            min_index++;
	        }
	        else
	        {
	            arr[i]+=((arr[max_index]%max_val)*max_val);
	            max_index--;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {arr[i]/=max_val;
	    cout << arr[i] << " ";}
	    cout << endl;
	}
	return 0;
}
