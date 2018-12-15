#include <iostream>
#include "solution.h"
using namespace std;
bool checkAB_util(char input[])
{
  if(input[0]=='\0')
    return true;
  else
  {
    if(input[0]=='a')
    {
      if(input[1]=='\0' || input[1]=='a' || input[1]=='b' )
      {
        return checkAB_util(input+1);
      }
    }
    else if(input[0]=='b' && input[1]=='b')
    {
      if(input[2]=='a' || input[2]=='\0')
        return checkAB_util(input+2);
    }
  }
  return false;
  
}
bool checkAB(char input[]) {
  
	// Write your code here
  if(input[0]=='a')
  {
    return checkAB_util(input+1);
  }
  return false;
}
int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}


