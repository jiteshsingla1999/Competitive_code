#include <iostream>
#include <string>
//#include "solution.h"
using namespace std
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
  if(num==0)
  {
    output[0]="";
    return 1;
  }
  
  int substring_size = keypad(num/10,output);
  int x = num%10;
  if(x==7)
  {
    for(int j=3;j>=0;j--)
    {
      for(int i=0;i<substring_size;i++)
        {
        output[i+j*substring_size] = output[i] + (char)(97+15+j);
        }
    }
    return 4*substring_size;
  }
  else if(x==9)
  {
    for(int j=3;j>=0;j--)
    {
      for(int i=0;i<substring_size;i++)
        {
        output[i+j*substring_size] = output[i] + (char)(96+23+j);
        }
    }
    return 4*substring_size;
  }
  else if(x!=8)
  {
    for(int j=2;j>=0;j--)
    {
      for(int i=0;i<substring_size;i++)
        {
        output[i+j*substring_size] = output[i] + (char)(91+3*x+j);
        //cout << "--" << output[i] << endl;
        }
    }
    return 3*substring_size;
  }
  else
  {
    for(int j=2;j>=0;j--)
    {
      for(int i=0;i<substring_size;i++)
        {
        output[i+j*substring_size] = output[i] + (char)(116+j);
        }
    }
    return 3*substring_size;
  }
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

