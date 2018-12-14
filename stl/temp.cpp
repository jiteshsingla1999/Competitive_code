#include<iostream>
#include<map>
using namespace std;
#include <vector>
#include<algorithm>

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
  
  
  map<int, int> aa;
  for(int i=0;i<n;i++)
  {
    aa.insert(make_pair(arr[i],i));
  }
  

	
	sort(arr,arr+n);
	
	int max=0,count=1,start_index=0, current_index=0;
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1]+1)
		{
			count++;
		}
		else
		{
			//cout << " max : " << max << "   count : " << count << endl;
			if(max==count)
			{
				if(aa[arr[start_index]] > aa[arr[current_index]])
				{
					max=count;
					start_index=current_index;
					
				}
			}
			else if(max<count)
			{
				max=count;
				start_index=current_index;
			}
			
			count=1;
			current_index=i;
		}
	}
	if(max<count)
			{
				max=count;
				start_index=current_index;
			}
			
			
	
	if(max==count)
			{
				if(aa[arr[start_index]] > aa[arr[current_index]])
				{
					max=count;
					start_index=current_index;
					
				}
			}
	
	vector<int> ss;
  for(int ii=start_index;ii<start_index+max;ii++)
  {
    ss.push_back(arr[ii]);
  }
  return ss;
	
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	vector<int> output = longestSubsequence(input, n);
	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}

