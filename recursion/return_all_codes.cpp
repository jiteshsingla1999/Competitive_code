#include<bits/stdc++.h>
using namespace std;
string ss[27] = {"f","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
int countt=0;
int getCodes_util(string input, string temp, string output[], int start)
{
  if(start==input.length())
  {
    output[countt]=temp;
    countt++;
    return 1;
  }
  else if(start == input.length()-1)
  {
  	int bb = (int)input[start]-48;
  	//cout << bb;
    temp+=ss[bb]; 
    //cout << temp;
    return getCodes_util(input,temp,output,start+1);
  }
  else
  {
   string temp2 = temp;
   int cc = ((int)input[start]-48)*10;
   cc += ((int)input[start+1]- 48);
   //cout << "cc : " << cc << endl;
   temp2 = temp2+ss[cc];
   temp+=ss[(int)input[start] - 48 ]; 
  // cout << "temp2 : "  << temp2 << endl;
  // cout << "temp : " << temp << endl; 
   return getCodes_util(input, temp2, output,start+2) + getCodes_util(input,temp,output,start+1);
  }
  
}
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  string temp;
 // cout << "hi";
  return getCodes_util(input,temp,output,0);
  
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

