#include <bits/stdc++.h>
using namespace std;

void printKeypad(int num, string output = ""){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
  int v = num%10;
  if(v==0)
  {
    reverse(output.begin(),output.end());
    cout << output << endl;
    return ;
  }
  if(v==2)
  {
    printKeypad(num/10,output+"a");
    printKeypad(num/10,output+"b");
    printKeypad(num/10,output+"c");
  }
  else if(v==3)
  {
    printKeypad(num/10,output+"d");
    printKeypad(num/10,output+"e");
    printKeypad(num/10,output+"f");
  }
  else if(v==4)
  {
    printKeypad(num/10,output+"g");
    printKeypad(num/10,output+"h");
    printKeypad(num/10,output+"i");
  }
  else if(v==5)
  {
    printKeypad(num/10,output+"j");
    printKeypad(num/10,output+"k");
    printKeypad(num/10,output+"l");
  }
  else if(v==6)
  {
    printKeypad(num/10,output+"m");
    printKeypad(num/10,output+"n");
    printKeypad(num/10,output+"o");
  }
  else if(v==7)
  {
    printKeypad(num/10,output+"p");
    printKeypad(num/10,output+"q");
    printKeypad(num/10,output+"r");
    printKeypad(num/10,output+"s");
  }
  else if(v==8)
  {
    printKeypad(num/10,output+"t");
    printKeypad(num/10,output+"u");
    printKeypad(num/10,output+"v");
  }
  else if(v==9)
  {
    printKeypad(num/10,output+"w");
    printKeypad(num/10,output+"x");
    printKeypad(num/10,output+"y");
    printKeypad(num/10,output+"z");
  }
}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

