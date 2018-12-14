#include<iostream>

using namespace std;
int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(size==0)
    return -1;
  int temp = lastIndex(input+1,size-1,x);
  if(input[0]==x)
  {
    if(temp==-1)
      return 0;
    else
      return temp+1;
      
  }
  else if(temp!=-1)
    return temp + 1;
  else
    return temp;

}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}



