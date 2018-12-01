#include<iostream>
#include<cstring>
using namespace std;


char nonRepeatingCharacter(string str){
  
  char start = str[0];
  int arr[150];
  for(int i=0;i<150;i++)
    arr[i]=0;
  
  for(int i=0;i<str.size();i++)
    arr[int(str[i])]++;
  
  char output = '1';
  for(int i=0;i<str.size();i++)
  {
    if(arr[int(str[i])]==1)
    {output=str[i];break;}
  }
	if(output!='1')
      return output;
  else
    return start;
}


int main(){

  string str;
  cin >> str;

  char ch = nonRepeatingCharacter(str);

  cout << ch << endl;

}


