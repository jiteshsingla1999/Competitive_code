#include <iostream>
using namespace std;
void merge(int input[], int start, int middle, int stop)
{
  int l1 = middle-start+1;
  int l2 = stop-middle;
  int temp1[l1];
  int temp2[l2];
  int m=0,n=0;
  for(int i=start;i<=middle;i++)
    temp1[m++] = input[i];
  for(int j=middle+1;j<=stop;j++)
    temp2[n++] = input[j];
  
  m=0;n=0;
  int k = start;
  while(m<l1 && n<l2)
  {
    if(temp1[m]<temp2[n])
      input[k++]=temp1[m++];
    else
      input[k++]=temp2[n++];
  }
  while(m<l1)
    input[k++]=temp1[m++];
  while(n<l2)
    input[k++]=temp2[n++];
  
  
}
void mergeSortUtil(int input[], int start, int stop)
{
  if(start>=stop)
    return;
  int middle = start + (stop-start)/2;
  mergeSortUtil(input,start,middle);
  mergeSortUtil(input,middle+1,stop);
  merge(input,start,middle,stop);
  return;
}


void mergeSort(int input[], int size){
	// Write your code here
     mergeSortUtil(input,0,size-1);
  
  
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

