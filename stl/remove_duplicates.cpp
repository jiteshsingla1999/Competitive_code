#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDuplicates(vector<int> input){

    // Write your code here
  bool arr[10000];
  for(int i=0;i<10000;i++)
    arr[i]=false;
  vector<int>:: iterator it;
  for(it=input.begin();it!=input.end();)
  {
    if(arr[*it]==true)
    {
      it++;
      input.erase(it-1);
      it--;
    }
      
    else
    {arr[*it]=true;it++;}
  }
	return input;
}



int main(){
    
    int size;
    cin >> size;
    
    vector<int> input;
    
    for(int i = 0; i < size; i++){
        int a;
	cin >> a;
        input.push_back(a);
    }
    
    vector<int> output = removeDuplicates(input);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
}
