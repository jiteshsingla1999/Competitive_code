#include <string>
#include<iostream>
using namespace std;
int count=0;
int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  if(input.length()==1)
  {
    output[count++]=input;
   // cout << "dsf : " << output[count] << endl;
    return 1;
  }
  if(input.length()>0)
  {
  	for(int i=0;i<input.length();i++)
    {
      string temp;
      if(i==1)
      	 temp = input[0] + input.substr(i+1,input.length()-1);
      else if(i>1)
         temp = input.substr(0,i-1) + input.substr(i+1,input.length()-1);
      else if(i==0)
         temp = input.substr(i+1,input.length()-1);
    //  cout << temp << endl;
      int cc = returnPermutations(temp, output);
      for(int j=count-1;j>=(count-cc);j--)
        {
		output[j] = input[i] + output[j];
      //a cout << "out : " << output[j] << endl;
        } 
     // cout << count << endl;
     }
     
     return count;
  
  
  
}}
int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

