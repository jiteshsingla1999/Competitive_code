#include <iostream>
using namespace std;
#include "solution.h"

void print_solution(int input[], int size)
{
  for(int i=0;i<size;i++)
    cout << input[i] << " ";
  cout << "\n";
}
void printSubsetsOfArray(int input[], int size,int output[], int output_size) {
	// Write your code here
  if(size==0)
  {
    print_solution(output,output_size);
    return;
  }
  printSubsetsOfArray(input+1 , size-1 , output , output_size);
  output[output_size++]=input[0];
  printSubsetsOfArray(input+1 , size-1 , output , output_size);
  return;
    
}
void printSubsetsOfArray(int input[], int size) {
  int output[100000];
  int output_size=0;
  printSubsetsOfArray(input, size,output,output_size);
  }

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

