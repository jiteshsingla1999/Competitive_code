#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a=b;
  b=temp;
}
int partition(int input[], int start, int stop)
{
  int pivot = input[start];
  int i=start+1;
  int j=i;
  while(j<=stop)
  {
    if(input[j]>pivot)
    {
      j++;
    }
    else
    {
      swap(input[i],input[j]);
      i++;j++;
    }
  }
  swap(input[start],input[i-1]);
  return i-1;
}

void quickSortUtil(int input[], int start, int stop)
{
  if(start<stop)
  {
    
    int pi = partition(input,start,stop);
    quickSortUtil(input,start,pi-1);
    quickSortUtil(input,pi+1,stop);
  }
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */

quickSortUtil(input,0,size-1);
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


